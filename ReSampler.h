//---------------------------------------------------------------------------

#ifndef ReSamplerH
#define ReSamplerH
//---------------------------------------------------------------------------

typedef float SAMPLE;

typedef struct {
	unsigned int channels, infreq, outfreq, taps;
	float *table;
	SAMPLE *pool;

	/* dynamic bits */
	int poolfill;
	int offset;
} res_state;

typedef enum {
	RES_END, RES_GAIN, /* (double)1.0 */
	RES_CUTOFF, /* (double)0.80 */
	RES_TAPS, /* (int)45 */
	RES_BETA /* (double)16.0 */
} res_parameter;

class ReSampler
{
	public:
		__fastcall ReSampler() ;
		~ReSampler() ;

		static int init(res_state *state, int channels, int outfreq, int infreq, res_parameter op1, ...);

		/*
		 * Configure *state to manage a data stream with the specified parameters.  The
		 * string 'params' is currently unspecified, but will configure the parameters
		 * of the filter.
		 *
		 * This function allocates memory, and requires that res_clear() be called when
		 * the buffer is no longer needed.
		 *
		 *
		 * All counts/lengths used in the following functions consider only the data in
		 * a single channel, and in numbers of samples rather than bytes, even though
		 * functionality will be mirrored across as many channels as specified here.
		 */

		 static int pushMaxInput(res_state const *state, size_t maxoutput);
		/*
		 *  Returns the maximum number of input elements that may be provided without
		 *  risk of flooding an output buffer of size maxoutput.  maxoutput is
		 *  specified in counts of elements, NOT in bytes.
		 */

		static int pushCheck(res_state const *state, size_t srclen);

		/*
		 * Returns the number of elements that will be returned if the given srclen
		 * is used in the next call to res_push().
		 */
		static int push(res_state *state, SAMPLE **dstlist, SAMPLE const **srclist, size_t srclen);
		static int pushInterleaved(res_state *state, SAMPLE *dest, SAMPLE const *source, size_t srclen);

		/*
		 * Pushes srclen samples into the front end of the filter, and returns the
		 * number of resulting samples.
		 *
		 * res_push(): srclist and dstlist point to lists of pointers, each of which
		 * indicates the beginning of a list of samples.
		 *
		 * res_push_interleaved(): source and dest point to the beginning of a list of
		 * interleaved samples.
		 */
		int drain(res_state *state, SAMPLE **dstlist);
		int drainInterleaved(res_state *state, SAMPLE *dest);

		/*
		 * Recover the remaining elements by flushing the internal pool with 0 values,
		 * and storing the resulting samples.
		 *
		 * After either of these functions are called, *state should only re-used in a
		 * final call to res_clear().
		 */
		static void clear(res_state *state);

		/*
		 * Free allocated buffers, etc.
		 */
		static void makeMono(float *stereo, float *mono,int num);

		/* take a single mono channel and make it into 2 stereo channels */
		static void makeStereo(float *mono,float *stereo,int num);
	protected:

	private:
};
#endif
