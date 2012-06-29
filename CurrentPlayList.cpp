//---------------------------------------------------------------------------


#pragma hdrstop

#include "CurrentPlayList.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

__fastcall TCurrentPlayList::TCurrentPlayList()
{

}
//---------------------------------------------------------------------------

__fastcall TCurrentPlayList::~TCurrentPlayList()
{

}
//---------------------------------------------------------------------------

int __fastcall TCurrentPlayList::addSong(TSongInfo value)
{
	_list.insert(_list.end(), value) ;
	return(_list.size()) ;
}
//---------------------------------------------------------------------------

TSongInfo __fastcall TCurrentPlayList::getSong(int idx)
{
	return(_list.at(idx)) ;
}
//---------------------------------------------------------------------------

int __fastcall TCurrentPlayList::getNumSongs()
{
	return(_list.size()) ;
}
//---------------------------------------------------------------------------

void __fastcall TCurrentPlayList::clear()
{
	_list.clear() ;
}
//---------------------------------------------------------------------------
