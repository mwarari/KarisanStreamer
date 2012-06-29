//---------------------------------------------------------------------------


#pragma hdrstop

#include "AudioStreamer.h"
#include "bass.hpp"


//---------------------------------------------------------------------------
#pragma package(smart_init)

AudioStreamer::AudioStreamer()
{

}
//---------------------------------------------------------------------------

AudioStreamer::~AudioStreamer()
{

}
//---------------------------------------------------------------------------

bool AudioStreamer::connectDataChannel()
{
	if(_data_channel.doConnect(_host, _port) == -1) {
		return(false) ;
	} else {
		return(true) ;
    }

}
//---------------------------------------------------------------------------

bool AudioStreamer::connectDataChannel(string host, unsigned int port)
{
	_host = host ;
	_port = port ;

	return(connectDataChannel()) ;
}
//---------------------------------------------------------------------------

bool AudioStreamer::connectControlChannel()
{
	if(_control_channel.doConnect(_host, _port) == -1) {
		return(false) ;
	} else {
        return(true) ;
    }
}
//---------------------------------------------------------------------------

bool AudioStreamer::connectControlChannel(string host, unsigned int port)
{
	_host = host ;
	_port = port ;

	return(connectControlChannel()) ;
}
//---------------------------------------------------------------------------

bool AudioStreamer::startStreaming()
{
	return(false) ;
}
//---------------------------------------------------------------------------

bool AudioStreamer::stopStreaming()
{
	return(false) ;
}
//---------------------------------------------------------------------------

void AudioStreamer::setHost(string value)
{
	_host = value ;
}
//---------------------------------------------------------------------------

string AudioStreamer::getHost()
{
	return(_host) ;
}
//---------------------------------------------------------------------------

void AudioStreamer::setPort(unsigned int value)
{
	_port = value ;
}
//---------------------------------------------------------------------------

unsigned int AudioStreamer::getPort()
{
	return(_port) ;
}
//---------------------------------------------------------------------------

void AudioStreamer::setUsername(string value)
{
	_username = value ;
}
//---------------------------------------------------------------------------

string AudioStreamer::getUsername()
{
	return(_username) ;
}
//---------------------------------------------------------------------------

void AudioStreamer::setPassword(string value)
{
	_password = value ;
}
//---------------------------------------------------------------------------

string AudioStreamer::getPassword()
{
	return(_password) ;
}
//---------------------------------------------------------------------------

bool AudioStreamer::isConnected()
{
	return(_connected) ;
}
//---------------------------------------------------------------------------

void AudioStreamer::setAudioFormat(int value)
{
	_audio_format = value ;

	switch(_audio_format) {
		case OGG:
			_content_type = "audio/ogg" ;
			break ;
		case AAC:
			_content_type = "audio/aac" ;
			break ;
		case AACP:
			_content_type = "audio/aacp" ;
			break ;
		case FLAC:
			_content_type = "audio/ogg" ;
			break ;
		case MPEG:
			_content_type = "audio/mpeg" ;
			break ;
		default:
			_content_type = "audio/mpeg" ;
			break ;
    } ;
}
//---------------------------------------------------------------------------

int AudioStreamer::getAudioFormat()
{
	return(_audio_format) ;
}
//---------------------------------------------------------------------------

string AudioStreamer::getContentType()
{
	return(_content_type) ;
}
//---------------------------------------------------------------------------

int AudioStreamer::sendToDataChannel(char *data, int length, int type)
{
	int ret = 0;

	switch(type) {
		case HEADER_TYPE:
			ret = send(_data_channel.getSocket(), data, length, 0);
			break;

		case CODEC_TYPE:
			ret = send(_data_channel.getSocket(), data, length, 0);
			break;
	}

	return ret;
}
//---------------------------------------------------------------------------

int AudioStreamer::closeDataChannel()
{
	return(_data_channel.doClose()) ;
}
//---------------------------------------------------------------------------

int AudioStreamer::sendToControlChannel(char *data, int length, int type)
{
	int ret = 0;

	switch(type) {
		case HEADER_TYPE:
			ret = send(_control_channel.getSocket(), data, length, 0);
			break;

		case CODEC_TYPE:
			ret = send(_control_channel.getSocket(), data, length, 0);
			break;
	}

	return ret;
}
//---------------------------------------------------------------------------

int AudioStreamer::closeControlChannel()
{
	return(_control_channel.doClose()) ;
}
//---------------------------------------------------------------------------

int AudioStreamer::receiveFromDataChannel(char *data, int length)
{
	return(_data_channel.receive(data, length, 0)) ;
}
//---------------------------------------------------------------------------

int AudioStreamer::receiveFromControlChannel(char *data, int length)
{
	return(_control_channel.receive(data, length, 0)) ;
}
//---------------------------------------------------------------------------




