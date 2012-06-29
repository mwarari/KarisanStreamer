//---------------------------------------------------------------------------

#ifndef TMySocketH
#define TMySocketH

#include <string>
#include <exception>

#include <windows.h>

#ifndef SOCKET
	#define SOCKET int
#endif
//---------------------------------------------------------------------------

using namespace std ;

class TMySocket
{
	public:
		TMySocket();
		virtual ~TMySocket() ;

		void socketErrorExit(string error) ;
		SOCKET doListen(unsigned short portnum) ;
		SOCKET doAccept(SOCKET s) ;
		SOCKET doConnect(string host, unsigned short portnum) ;
		int doClose() ;
		void checkSocketError(int error, string message) ;
		void cleanAndExit(int error) ;
		SOCKET getSocket() ;
		int getErrorCode() ;
		int receive(char* buf, int len, int flags) ;
		int send(char *data, int length, int flags) ;

	protected:
		SOCKET _socket ;

	private:
		bool _initialized ;
		int _error_code ;

};

class TMySocketException : public exception
{
	public:
		TMySocketException(string error) { _error = error ; }
		virtual ~TMySocketException() throw(){ }
		virtual const char *what() const throw () { return(_error.c_str()) ; }

	private:
		string _error ;

};
#endif
