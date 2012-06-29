//---------------------------------------------------------------------------

#ifndef CurrentPlayListH
#define CurrentPlayListH
//---------------------------------------------------------------------------

#include <memory>
#include <vector>

#include "SongInfo.h"

using namespace std ;

class TCurrentPlayList
{
	public:
		__fastcall TCurrentPlayList() ;
		__fastcall ~TCurrentPlayList() ;

		int __fastcall addSong(TSongInfo value) ;
		TSongInfo __fastcall getSong(int idx) ;
		int __fastcall getNumSongs() ;
		void __fastcall clear() ;

	private:
		vector<TSongInfo> _list ;
};
#endif
