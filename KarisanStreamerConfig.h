//---------------------------------------------------------------------------

#ifndef KarisanStreamerConfigH
#define KarisanStreamerConfigH
//---------------------------------------------------------------------------
#include <string>
#include <memory>
#include <map>
#include <classes.hpp>

#include "StreamConfig.h"

using namespace std ;

class StreamNames : public TStringList
{
	public:
		StreamNames() { ::TStringList() ; StrictDelimiter = true ; }
		virtual __fastcall ~StreamNames() { }
};


class KarisanStreamerConfig
{
	public:
		KarisanStreamerConfig() ;
		~KarisanStreamerConfig() ;

		bool save() ;
		bool load() ;
		bool saveStreamNames() ;
		bool loadStreams() ;
		void addStream(StreamConfig *) ;
		StreamConfig* getStream(int) ;
		// bool getStream(string, StreamConfig *) ;
		StreamConfig* getStream(string, int* idx = NULL) ;
		bool deleteStream(StreamConfig *) ;
		bool deleteStream(int) ;
		map<int, StreamConfig *>* getStreams() ;
		void update() ;
		int getNumStreams() ;
		void updateStream(int idx, string old_name) ;

	private:
		void saveStream(StreamConfig *) ;
		void loadStream(StreamConfig *) ;
		bool loadConfig() ;
		void getStreamNames(StreamNames *streams) ;
		void setStreamNames(StreamNames *streams) ;
		void destroy() ;

		UnicodeString DEFAULT_CONFIG_NAME ;
		UnicodeString CONFIG_FILENAME ;
		map<int, StreamConfig *> *_allstreams ;
		auto_ptr<TIniFile> _config_file ;
};


#endif