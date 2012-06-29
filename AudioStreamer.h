//---------------------------------------------------------------------------

#ifndef AudioStreamerH
#define AudioStreamerH
//---------------------------------------------------------------------------

#include <string>

#include "TMySocket.h"

#define HEADER_TYPE 1
#define CODEC_TYPE	2

using namespace std ;

enum AudioType {OGG, AAC, AACP, MPEG, FLAC} ;

class AudioStreamer
{
	public:
		AudioStreamer() ;
		virtual ~AudioStreamer() ;

		virtual bool connectDataChannel() ;
		virtual bool connectDataChannel(string host, unsigned int port) ;

		virtual bool connectControlChannel() ;
		virtual bool connectControlChannel(string host, unsigned int port) ;

		int closeDataChannel() ;
		int closeControlChannel() ;

		virtual bool startStreaming() ;
		virtual bool stopStreaming() ;

		void setHost(string value) ;
		string getHost() ;

		void setPort(unsigned int value) ;
		unsigned int getPort() ;

		void setUsername(string value) ;
		string getUsername() ;

		void setPassword(string value) ;
		string getPassword() ;

		void setAudioFormat(int value) ;
		int getAudioFormat() ;

		string getContentType() ;

		bool isConnected() ;

	protected:
		int sendToDataChannel(char *data, int length, int type) ;
		int sendToControlChannel(char *data, int length, int type) ;

		int receiveFromDataChannel(char *data, int length) ;
		int receiveFromControlChannel(char *data, int length) ;

	private:
		string _host ;
		unsigned int _port ;
		string _username ;
		string _password ;
		TMySocket _data_channel ;
		TMySocket _control_channel ;

		bool _connected ;
		int _audio_format ;
		string _content_type ;


};

#endif
