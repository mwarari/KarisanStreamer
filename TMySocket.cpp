//---------------------------------------------------------------------------


#pragma hdrstop

#include "TMySocket.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


TMySocket::TMySocket()
{

	WORD version_requested ;
	WSADATA data ;
	int err;


	version_requested = MAKEWORD(1, 1);
	_error_code = WSAStartup(version_requested, &data);
	_initialized = false ;

	if(_error_code != 0) {
		throw new TMySocketException("cannot find winsock.dll") ;
	}

	if (LOBYTE(data.wVersion) != 1 || HIBYTE(data.wVersion) != 1 ) {
		throw new TMySocketException("winsock.dll is an old version");
	}

	_initialized = true ;

	_socket = -1 ;
}
//---------------------------------------------------------------------------

TMySocket::~TMySocket()
{
	if(_initialized == true) {
		if(_socket != -1)
			closesocket(_socket) ;
		WSACleanup() ; // TODO: Check return code.
	}
}
//---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
//
// socketErrorExit
//
// Description
//   Print supplied error message and exit the program.
//
// Parameters
//   error - Error message text
//
void TMySocket::socketErrorExit(string error)
{
 	return ;
}
//---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
//
// doListen
//
// Description
//   Code to create, bind and listen to socket; Originally from bzs@bu-cs.bu.edu
//
// Parameters
//   portnum - local port to listen for connections
//
// Return
//   Socket created on success, -1 on error.
//
#define MAXHOSTNAME 1024
SOCKET TMySocket::doListen(unsigned short portnum)
{
	char   myname[MAXHOSTNAME+1];
	SOCKET s;
	struct sockaddr_in sa;
	struct hostent *hp;

	memset(&sa, 0, sizeof(struct sockaddr_in)); /* clear our address */
	gethostname(myname, MAXHOSTNAME);           /* who are we? */
	hp= gethostbyname(myname);                  /* get our address info */
	if (hp == NULL)                             /* we don't exist !? */
		return(-1);

	sa.sin_family= hp->h_addrtype;              /* this is our host address */
	sa.sin_port= htons(portnum);                /* this is our port number */
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) /* create socket */
		return(-1);

	if (bind(s,(struct sockaddr *)&sa,sizeof(struct sockaddr_in)) < 0) {
		closesocket(s);
		return(-1);                               /* bind address to socket */
	}

	listen(s, SOMAXCONN);                               /* max # of queued connects */
	return(s);
}
//---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
//
// doAccept
//
// Description
//   Performs an accept() on the supplied socket.
//
// Parameters
//   s - listen()'ing socket to call accept() on.
//
// Return
//   Returns the accept()'d socket on success, -1 on error.
//
SOCKET TMySocket::doAccept(SOCKET s)
{
	SOCKET t;                  /* socket of connection */
	int	namelen = 0;

	if ((t = accept(s,NULL,NULL)) < 0)   /* accept connection if there is one */
		return(-1);

/*
	memset(&connectedIP, '\000', sizeof(connectedIP));
	namelen = sizeof(connectedIP);
	int ret = getpeername(t, (struct sockaddr *)&connectedIP, &namelen);
	if (ret == SOCKET_ERROR) {
		int error = WSAGetLastError();
	}
*/
//	MessageBox(NULL, inet_ntoa(connectedIP.sin_addr), "Connected To", MB_OK);
	return(t);
}
//---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
//
// doConnect
//
// Description
//   Performs a generic socket() and connect()
//
// Parameters
//   hostname - host to connect() to.
//   portnum - port number for connect().
//
SOCKET TMySocket::doConnect(string hostname, unsigned short portnum)
{
	struct sockaddr_in sa;
	struct hostent     *hp;

	if ((hp = gethostbyname(hostname.c_str())) == NULL) { /* do we know the host's */
		SetLastError(WSAECONNREFUSED);
		return(-1);                                /* no */
	}

	memset(&sa, 0, sizeof(sa));
	memcpy((char *)&sa.sin_addr,hp->h_addr,hp->h_length);     /* set address */
	sa.sin_family = hp->h_addrtype;
	sa.sin_port = htons((u_short)portnum);

	if ((_socket = socket(hp->h_addrtype,SOCK_STREAM,0)) < 0)     /* get socket */
		return(-1);

	int optval = 10000;
	setsockopt(_socket, SOL_SOCKET, SO_SNDTIMEO, (const char *)&optval, sizeof(optval));
	setsockopt(_socket, SOL_SOCKET, SO_RCVTIMEO, (const char *)&optval, sizeof(optval));

	if (connect(_socket, (struct sockaddr *)&sa, sizeof sa) < 0) { /* connect */
		long err = WSAGetLastError();

		closesocket(_socket);
		return(-1);
	}
	return(_socket);
}
//---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
//
// checkSocketError
//
// Description
//   Checks the iError input for SOCKET_ERROR, if an error exists, print
//   the supplied szMessage and exit the program
//
// Parameters
//
void TMySocket::checkSocketError(int error, string message)
{
	if (error == SOCKET_ERROR) {
		socketErrorExit(message);
		return;
	}
}
//---------------------------------------------------------------------------
































