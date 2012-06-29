//---------------------------------------------------------------------------

#ifndef StreamerH
#define StreamerH
//---------------------------------------------------------------------------

#include <string>

using namespace std ;

class AudioStreamer
{
public:
	Streamer() ;
	~Streamer() ;

	BOOL connect() ;
	BOOL connect(string host, string port, string username, string password) ;
	BOOL disconnect() ;
	BOOL startStreaming() ;
	BOOL stopStreaming() ;

	void setHost(string value) ;
	string getHost() ;

	void setPort(string value) ;
	string getPort() ;

	void setUsername(string value) ;
	string getUsername() ;

	void setPassword(string value) ;
	string getPassword() ;

	void setType(string value) ;
	string getType() ;

protected:
	string _host ;
	string _port ;
	string _username ;
	string _password ;
	string _type ;

private:
};

#endif
