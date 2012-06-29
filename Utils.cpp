//---------------------------------------------------------------------------


#pragma hdrstop

#include "Utils.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Utils::Utils()
{
//	char	base64table[64] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/' };

//	signed char	base64decode[256] = { -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 62, -2, -2, -2, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -2, -2, -2, -1, -2, -2, -2, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -2, -2, -2, -2, -2, -2, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2 };
}
//---------------------------------------------------------------------------

Utils::~Utils()
{

}
//---------------------------------------------------------------------------

/*
 =======================================================================================================================
	This isn't efficient, but it doesn't need to be
 =======================================================================================================================
 */
string Utils::base64Encode(string data)
{
	int len = data.length();
	string out ;
	int	chunk;
	int o_idx = 0 ;
	int d_idx = 0 ;

	while(len > 0) {
		chunk = (len > 3) ? 3 : len;
		out.append(1, base64table[(data[d_idx] & 0xFC) >> 2]) ;
		out.append(1, base64table[((data[d_idx] & 0x03) << 4) | (((data[d_idx + 1]) & 0xF0) >> 4)]) ;
		switch(chunk) {
			case 3:
				out.append(1, base64table[(((data[d_idx + 1]) & 0x0F) << 2) | (((data[d_idx + 2]) & 0xC0) >> 6)]) ;
				out.append(1, base64table[((data[d_idx + 2])) & 0x3F]) ;
				break;

			case 2:
				out.append(1, base64table[(((data[d_idx + 1]) & 0x0F) << 2)]);
				out.append(1, '=') ;
				break;

			case 1:
				out.append(1, '=') ;
				out.append(1, '=') ;
				break;
		}

		d_idx += chunk;
		len -= chunk;
	}
	// out.append(1, '\0') ;

	return out ;
}
//---------------------------------------------------------------------------

string Utils::base64Decode(string input)
{
	int	len = input.length() ;
	string out ;
	signed vals[4] ;
	int i_idx = 0 ;
	int o_idx = 0 ;

	while(len > 0) {
		if(len < 4) {
			return out ;	/* Invalid Base64 data */
		}

		vals[0] = base64decode[input[i_idx++]];
		vals[1] = base64decode[input[i_idx++]];
		vals[2] = base64decode[input[i_idx++]];
		vals[3] = base64decode[input[i_idx++]];

		if(vals[0] < 0 || vals[1] < 0 || vals[2] < -1 || vals[3] < -1) {
			continue;
		}

		out[o_idx++] = vals[0] << 2 | vals[1] >> 4;
		if(vals[2] >= 0)
			out[o_idx++] = ((vals[1] & 0x0F) << 4) | (vals[2] >> 2);
		else
			out[o_idx++] = 0;

		if(vals[3] >= 0)
			out[o_idx++] = ((vals[2] & 0x03) << 6) | (vals[3]);
		else
			out[o_idx++] = 0;

		len -= 4;
	}

	out[o_idx] = 0 ;
	out.resize(o_idx) ;

	return out ;
}
//---------------------------------------------------------------------------

string Utils::urlEncode(string source)
{
	map<string, string> url_chars = getURLReplacements() ;
	map<string, string>::iterator iter ;
	string result = source ;

	for(iter = url_chars.begin() ; iter != url_chars.end() ; ++iter) {
		size_t pos = 0 ;

		pos = result.find(iter->first) ;
		while(pos != string::npos) {
			result.erase(pos, pos + (iter->first).length()) ;
			result.insert(pos, iter->second) ;
			pos = result.find(iter->first) ;
		}
	}
	return (result) ;
}
//---------------------------------------------------------------------------

map<string, string> Utils::getURLReplacements()
{
	map<string, string> url_chars ;

	url_chars.insert(pair<string, string>("%", "%25")) ;

	url_chars.insert(pair<string, string>(";", "%3B")) ;

	url_chars.insert(pair<string, string>("/", "%2F")) ;

	url_chars.insert(pair<string, string>("?", "%3F")) ;

	url_chars.insert(pair<string, string>(":", "%3A")) ;

	url_chars.insert(pair<string, string>("@", "%40")) ;

	url_chars.insert(pair<string, string>("&", "%26")) ;

	url_chars.insert(pair<string, string>("=", "%3D")) ;

	url_chars.insert(pair<string, string>("+", "%2B")) ;

	url_chars.insert(pair<string, string>(" ", "%20")) ;

	url_chars.insert(pair<string, string>("\"", "%22")) ;

	url_chars.insert(pair<string, string>("#", "%23")) ;

	url_chars.insert(pair<string, string>("<", "%3C")) ;

	url_chars.insert(pair<string, string>(">", "%3E")) ;

	url_chars.insert(pair<string, string>("!", "%21")) ;

	url_chars.insert(pair<string, string>("*", "%2A")) ;

	url_chars.insert(pair<string, string>("'", "%27")) ;

	url_chars.insert(pair<string, string>("(", "%28")) ;

	url_chars.insert(pair<string, string>(")", "%29")) ;

	url_chars.insert(pair<string, string>(",", "%2C")) ;

	return(url_chars) ;
}
//---------------------------------------------------------------------------


