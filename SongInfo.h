//---------------------------------------------------------------------------

#ifndef SongInfoH
#define SongInfoH

#include <string>
//---------------------------------------------------------------------------

using namespace std ;

class TSongInfo
{
	public:
		__fastcall TSongInfo() ;
		__fastcall TSongInfo(const TSongInfo &copy) ;
		__fastcall ~TSongInfo() ;

		TSongInfo& operator=(const TSongInfo &copy) ;

		string __fastcall getTitle() { return(_title) ; }
		void __fastcall setTitle(string value) { _title = value ; }

		string __fastcall getArtist() { return(_artist) ; }
		void __fastcall setArtist(string value) { _artist = value ; }

		string __fastcall getAlbum() { return(_album) ; }
		void __fastcall setAlbum(string value) { _album = value ; }

		int __fastcall getTrackNo() { return(_track_no) ; }
		void __fastcall setTrackNo(int value) { _track_no = value ; }

		int __fastcall getLength() { return(_length) ; }
		void __fastcall setLength(int value) { _length = value ; }

		string __fastcall getGenre() { return(_genre) ; }
		void __fastcall setGenre(string value) { _genre = value ; }

		int __fastcall getYear() { return(_year) ; }
		void __fastcall setYear(int value) { _year = value ; }

		string __fastcall getFilename() { return(_filename) ; }
		void __fastcall setFilename(string value) { _filename = value ; }

	private:
		string _title ;
		string _artist ;
		string _album ;
		int _track_no ;
		int _length ;
		string _genre ;
		int _year ;
		string _filename ;
};
#endif
