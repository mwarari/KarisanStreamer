//---------------------------------------------------------------------------


#pragma hdrstop

#include "SongInfo.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

__fastcall TSongInfo::TSongInfo()
{

}
//---------------------------------------------------------------------------

__fastcall TSongInfo::TSongInfo(const TSongInfo &copy)
{
	this->_title = copy._title ;
	this->_artist = copy._artist ;
	this->_album = copy._album ;
	this->_track_no = copy._track_no ;
	this->_length = copy._length ;
	this->_genre = copy._genre ;
	this->_year = copy._year ;
	this->_filename = copy._filename ;
}
//---------------------------------------------------------------------------

__fastcall TSongInfo::~TSongInfo()
{

}
//---------------------------------------------------------------------------

TSongInfo& TSongInfo::operator=(const TSongInfo &copy)
{
	this->_title = copy._title ;
	this->_artist = copy._artist ;
	this->_album = copy._album ;
	this->_track_no = copy._track_no ;
	this->_length = copy._length ;
	this->_genre = copy._genre ;
	this->_year = copy._year ;
	this->_filename = copy._filename ;

	return(*this);
}
//---------------------------------------------------------------------------

