//---------------------------------------------------------------------------


#pragma hdrstop

#include <classes.hpp>
#include <string>

#include <IniFiles.hpp>
#include "KarisanStreamerConfig.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

KarisanStreamerConfig::KarisanStreamerConfig()
{
	DEFAULT_CONFIG_NAME = "KarisanStreamer" ;
	CONFIG_FILENAME = "KarisanStreamer.ini" ;

	_config_file = auto_ptr<TIniFile>(new TIniFile(UnicodeString(CONFIG_FILENAME.c_str()))) ;

	_allstreams = new map<int, StreamConfig *>() ;
}
//---------------------------------------------------------------------------

KarisanStreamerConfig::~KarisanStreamerConfig()
{
	destroy() ;
}
//---------------------------------------------------------------------------

bool KarisanStreamerConfig::saveStreamNames()
{
	bool ret = true ;
	TStringList *stream_names = new TStringList() ;

	for(int idx = 0 ; idx < _allstreams->size() ; idx++) {
		StreamConfig *stream = (*_allstreams)[idx] ;

		stream_names->Add(UnicodeString(stream->getName().c_str())) ;
		saveStream(stream) ;
	}

	_config_file->WriteString(DEFAULT_CONFIG_NAME, "streams", stream_names->CommaText) ;

	delete stream_names ;
	return(ret) ;
}
//---------------------------------------------------------------------------

bool KarisanStreamerConfig::loadStreams()
{
	StreamNames *stream_names = new StreamNames() ;
	bool ret ;

	getStreamNames(stream_names) ;
	if(stream_names->Count <= 0)
		return(false) ;

	for(int idx = 0 ; idx < stream_names->Count ; idx++) {
		UnicodeString stream = stream_names->Strings[idx] ;
		StreamConfig *stream_config = new StreamConfig() ;

		stream_config->setName(stream.t_str()) ;

		loadStream(stream_config) ;
		_allstreams->insert(pair<int, StreamConfig *>(idx, stream_config)) ;
	}
	delete stream_names ;

	return(true) ;
}
//---------------------------------------------------------------------------

void KarisanStreamerConfig::addStream(StreamConfig *stream)
{
	int idx = getNumStreams() ;

	_allstreams->insert(pair<int, StreamConfig *>(idx, stream)) ;
	saveStream(stream) ;
}
//---------------------------------------------------------------------------

StreamConfig* KarisanStreamerConfig::getStream(int idx)
{
	if(idx < 0 || idx > _allstreams->size()) {
		return(NULL) ;
	}

	return((*_allstreams)[idx]) ;
}
//---------------------------------------------------------------------------

StreamConfig* KarisanStreamerConfig::getStream(string name, int *idx)
{
	map<int, StreamConfig *>::iterator it ;
	for(it = _allstreams->begin() ; it != _allstreams->end() ; ++it) {
		StreamConfig *stream = it->second ;
		if(stream != NULL) {
			if(stream->getName() == name) {
				if(idx != NULL) {
					*idx = it->first ;
				}
				return(stream) ;
			}
		}
	}
	return(NULL) ;
}
//---------------------------------------------------------------------------

map<int, StreamConfig *>* KarisanStreamerConfig::getStreams()
{
	return(_allstreams) ;
}
//---------------------------------------------------------------------------

int KarisanStreamerConfig::getNumStreams()
{
	if(_allstreams->empty()) {
		return(0) ;
	} else {
		return(_allstreams->size()) ;
    }
}
//---------------------------------------------------------------------------

void KarisanStreamerConfig::saveStream(StreamConfig *stream)
{
	UnicodeString stream_name ;

	stream_name = stream->getName().c_str() ;

	if(_config_file->SectionExists(stream_name))
		_config_file->EraseSection(stream_name) ;

	_config_file->WriteString(stream_name, "Name", stream->getName().c_str()) ;

	_config_file->WriteInteger(stream_name, "BitRate", stream->getBitRate()) ;

	_config_file->WriteInteger(stream_name, "Quality", stream->getQuality()) ;

	_config_file->WriteInteger(stream_name, "SampleRate", stream->getSampleRate()) ;

	_config_file->WriteString(stream_name, "Channels", UnicodeString(stream->getChannels().c_str())) ;

	_config_file->WriteString(stream_name, "EncoderType", UnicodeString(stream->getEncoderType().c_str())) ;

//	_config_file->WriteBool(stream_name, "JointStereo", stream->getJointStereo()) ;

	_config_file->WriteString(stream_name, "ServerType", UnicodeString(stream->getServerType().c_str())) ;

	_config_file->WriteString(stream_name, "ServerIP", UnicodeString(stream->getServerIP().c_str())) ;

	_config_file->WriteInteger(stream_name, "ServerPort", stream->getServerPort()) ;

	_config_file->WriteString(stream_name, "Password", UnicodeString(stream->getPassword().c_str())) ;

	_config_file->WriteString(stream_name, "MountPoint", UnicodeString(stream->getMountPoint().c_str())) ;

	_config_file->WriteInteger(stream_name, "ReconnectInterval", stream->getReconnectInterval()) ;

	_config_file->WriteFloat(stream_name, "Attenuation", stream->getAttenuation()) ;

	_config_file->WriteBool(stream_name, "PublicServer", stream->getPublicServer()) ;

	_config_file->WriteString(stream_name, "StreamName", UnicodeString(stream->getYPStreamName().c_str())) ;

	_config_file->WriteString(stream_name, "StreamDescription", UnicodeString(stream->getStreamDescription().c_str())) ;

	_config_file->WriteString(stream_name, "StreamURL", UnicodeString(stream->getStreamURL().c_str())) ;

	_config_file->WriteString(stream_name, "StreamGenre", UnicodeString(stream->getStreamGenre().c_str())) ;

	_config_file->WriteBool(stream_name, "SaveStream", stream->getSaveStream()) ;

	_config_file->WriteBool(stream_name, "SaveAsWAV",	stream->getSaveAsWAV()) ;

	_config_file->WriteString(stream_name, "ArchiveDirectory", UnicodeString(stream->getArchiveDirectory().c_str())) ;

	_config_file->WriteInteger(stream_name, "LogLevel", stream->getLogLevel()) ;

	_config_file->WriteString(stream_name, "LogFile", UnicodeString(stream->getLogFile().c_str())) ;

	// _config_file->UpdateFile() ;
}
//---------------------------------------------------------------------------


void KarisanStreamerConfig::loadStream(StreamConfig *stream)
{
	UnicodeString stream_name ;

	stream_name = stream->getName().c_str() ;

	stream->setName(_config_file->ReadString(stream_name, "Name", "").t_str()) ;

	stream->setBitRate(_config_file->ReadInteger(stream_name, "BitRate", 0)) ;

	stream->setQuality(_config_file->ReadInteger(stream_name, "Quality", 0)) ;

	stream->setSampleRate(_config_file->ReadInteger(stream_name, "SampleRate", 0)) ;

	stream->setChannels(_config_file->ReadString(stream_name, "Channels", "").t_str()) ;

	stream->setEncoderType(_config_file->ReadString(stream_name, "EncoderType", "").t_str()) ;

//	stream->setJointStereo(_config_file->ReadBool(stream_name, "JointStereo", FALSE)) ;

	stream->setServerType(_config_file->ReadString(stream_name, "ServerType", "").t_str()) ;

	stream->setServerIP(_config_file->ReadString(stream_name, "ServerIP", "").t_str()) ;

	stream->setServerPort(_config_file->ReadInteger(stream_name, "ServerPort", 0)) ;

	stream->setPassword(_config_file->ReadString(stream_name, "Password", "").t_str()) ;

	stream->setMountPoint(_config_file->ReadString(stream_name, "MountPoint", "").t_str()) ;

	stream->setReconnectInterval(_config_file->ReadInteger(stream_name, "ReconnectInterval", 0)) ;

	stream->setAttenuation(_config_file->ReadFloat(stream_name, "Attenuation", 0.0)) ;

	stream->setPublicServer(_config_file->ReadBool(stream_name, "PublicServer", FALSE)) ;

	stream->setYPStreamName(_config_file->ReadString(stream_name, "YPStreamName", "").t_str()) ;

	stream->setStreamDescription(_config_file->ReadString(stream_name, "StreamDescription", "").t_str()) ;

	stream->setStreamURL(_config_file->ReadString(stream_name, "StreamURL", "").t_str()) ;

	stream->setStreamGenre(_config_file->ReadString(stream_name, "StreamGenre", "").t_str()) ;

	stream->setSaveStream(_config_file->ReadBool(stream_name, "SaveStream", FALSE)) ;

	stream->setSaveAsWAV(_config_file->ReadBool(stream_name, "SaveAsWAV", FALSE)) ;

	stream->setArchiveDirectory(_config_file->ReadString(stream_name, "ArchiveDirectory", "").t_str()) ;

	stream->setLogLevel(_config_file->ReadInteger(stream_name, "LogLevel", 0)) ;

	stream->setLogFile(_config_file->ReadString(stream_name, "LogFile", "").t_str()) ;
}
//---------------------------------------------------------------------------

bool KarisanStreamerConfig::loadConfig()
{
	bool ret ;

	ret = loadStreams() ;

	return(ret) ;
}
//---------------------------------------------------------------------------

void KarisanStreamerConfig::getStreamNames(StreamNames *streams)
{
	streams->CommaText = _config_file->ReadString(DEFAULT_CONFIG_NAME, "Streams", "") ;
}
//---------------------------------------------------------------------------

void KarisanStreamerConfig::setStreamNames(StreamNames *streams)
{
	for(map<int, StreamConfig *>::iterator itr = _allstreams->begin() ; itr != _allstreams->end() ; ++itr) {
		StreamConfig *strm = (*itr).second ;
		UnicodeString strm_name = strm->getName().c_str() ;

		streams->Add(strm_name) ;
	}
}
//---------------------------------------------------------------------------

bool KarisanStreamerConfig::deleteStream(StreamConfig *stream)
{
	StreamConfig *strm ;
	UnicodeString strm_name ;

	map<int, StreamConfig *>::iterator itr =_allstreams->begin() ;
	while(itr != _allstreams->end()) {
		strm = (*itr).second ;
		if(strm->getName() == stream->getName()) {
			strm_name = strm->getName().c_str() ;
			_allstreams->erase(itr++) ;
			delete strm ;
			break ;
		} else {
			++itr ;
		}
	}

	StreamNames *stream_names = new StreamNames();
	stream_names->StrictDelimiter = true ;
	setStreamNames(stream_names) ;
	_config_file->WriteString(DEFAULT_CONFIG_NAME, "Streams", stream_names->CommaText) ;
	_config_file->EraseSection(strm_name) ;
	_config_file->UpdateFile() ;

	return(true) ;
}
//---------------------------------------------------------------------------

bool KarisanStreamerConfig::deleteStream(int idx)
{
	if(idx < 0 || idx > _allstreams->size())
		return(false) ;

	map<int, StreamConfig *>::iterator itr = _allstreams->find(idx) ;
	StreamConfig *strm = (*itr).second ;
	UnicodeString strm_name = strm->getName().c_str() ;
	_allstreams->erase(itr) ;
	delete strm ;

	StreamNames *stream_names = new StreamNames();

	setStreamNames(stream_names) ;
	_config_file->WriteString(DEFAULT_CONFIG_NAME, "Streams", stream_names->CommaText) ;
	_config_file->EraseSection(strm_name) ;
	_config_file->UpdateFile() ;

	delete stream_names ;
	return(true) ;
}
//---------------------------------------------------------------------------

void KarisanStreamerConfig::update()
{
	for(map<int, StreamConfig *>::iterator itr = _allstreams->begin() ; itr != _allstreams->end() ; ++itr) {
		StreamConfig *strm = (*itr).second ;
		saveStream(strm) ;
	}
	StreamNames *stream_names = new StreamNames();

	setStreamNames(stream_names) ;
	_config_file->WriteString(DEFAULT_CONFIG_NAME, "Streams", stream_names->CommaText) ;
	_config_file->UpdateFile() ;

	delete stream_names ;
}
//---------------------------------------------------------------------------

void KarisanStreamerConfig::destroy()
{
	for(map<int, StreamConfig *>::iterator itr = _allstreams->begin() ; itr != _allstreams->end() ; ++itr) {
		StreamConfig *strm = (*itr).second ;
		_allstreams->erase(itr) ;
		delete strm ;
	}
	delete _allstreams ;
}
//---------------------------------------------------------------------------

void KarisanStreamerConfig::updateStream(int idx, string old_name)
{
	if(idx >= 0) {
		_config_file->EraseSection(old_name.c_str()) ;

		StreamConfig *stream = (*_allstreams)[idx] ;
		saveStream(stream) ;
		update() ;

	}
}
//---------------------------------------------------------------------------
