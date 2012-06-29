//---------------------------------------------------------------------------


#pragma hdrstop

#include <stdlib.h>
#include <string.h>
#include "Base64.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

char *Base64::encode(char *data)
{
	int		len = strlen(data);
	char	*out = (char *) malloc(len * 4 / 3 + 4);
	char	*result = out;
	int		chunk;

	while(len > 0) {
		chunk = (len > 3) ? 3 : len;
		*out++ = base64table[(*data & 0xFC) >> 2];
		*out++ = base64table[((*data & 0x03) << 4) | ((*(data + 1) & 0xF0) >> 4)];
		switch(chunk) {
			case 3:
				*out++ = base64table[((*(data + 1) & 0x0F) << 2) | ((*(data + 2) & 0xC0) >> 6)];
				*out++ = base64table[(*(data + 2)) & 0x3F];
				break;

			case 2:
				*out++ = base64table[((*(data + 1) & 0x0F) << 2)];
				*out++ = '=';
				break;

			case 1:
				*out++ = '=';
				*out++ = '=';
				break;
		}

		data += chunk;
		len -= chunk;
	}

	*out = 0;

	return result;
}
//---------------------------------------------------------------------------

char *Base64::decode(unsigned char *input)
{
	int			len = strlen((char *) input);
	char		*out = (char *) malloc(len * 3 / 4 + 5);
	char		*result = out;
	signed char vals[4];

	while(len > 0) {
		if(len < 4) {
			free(result);
			return(0) ;	/* Invalid Base64 data */
		}

		vals[0] = base64decode[*input++];
		vals[1] = base64decode[*input++];
		vals[2] = base64decode[*input++];
		vals[3] = base64decode[*input++];

		if(vals[0] < 0 || vals[1] < 0 || vals[2] < -1 || vals[3] < -1) {
			continue;
		}

		*out++ = vals[0] << 2 | vals[1] >> 4;
		if(vals[2] >= 0)
			*out++ = ((vals[1] & 0x0F) << 4) | (vals[2] >> 2);
		else
			*out++ = 0;

		if(vals[3] >= 0)
			*out++ = ((vals[2] & 0x03) << 6) | (vals[3]);
		else
			*out++ = 0;

		len -= 4;
	}

	*out = 0;

	return result;
}
//---------------------------------------------------------------------------
