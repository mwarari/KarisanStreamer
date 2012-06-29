//---------------------------------------------------------------------------


#pragma hdrstop

#include "AudioStreamer.h"

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

BOOL AudioStreamer::connect()
{
	return(FALSE) ;
}
//---------------------------------------------------------------------------

BOOL AudioStreamer::connect(string host, string port, string username, string password)
{
	return(FALSE) ;
}
//---------------------------------------------------------------------------

BOOL AudioStreamer::disconnect()
{
	return(FALSE) ;
}
//---------------------------------------------------------------------------

BOOL AudioStreamer::startStreaming()
{
	return(FALSE) ;
}
//---------------------------------------------------------------------------

BOOL AudioStreamer::stopStreaming()
{
	return(FALSE) ;
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

void AudioStreamer::setPort(string value)
{
	_port = value ;
}
//---------------------------------------------------------------------------

string AudioStreamer::getPort()
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

void AudioStreamer::setType(string value)
{
	_type = value ;
}
//---------------------------------------------------------------------------

string AudioStreamer::getType()
{
	return(_type) ;
}
//---------------------------------------------------------------------------
