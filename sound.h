// constants definition
//#define DEBUG		//in developing mode or not, conditional compilation
#define RATE 16000
#define DUR 5
#define RCMD "arecord -r16000 -c1 -f S16_LE -d1 -q test.wav"
#define PI 3.14159

// data structures
struct WAVHDR{
	char chunkID[4];	// must be RIFF
	int chunkSize;
	char format[4];		// must be WAVE

	char subChunk1ID[4]; 	// must be fmt
	int subChunk1Size;		// should be 16
	short audioFormat;		// should be 1
	short numChannels;		// should be 1
	int sampleRate;		// we will use 16000
	int byteRate;		// calculated by SR, NS, B/S
	short blockAlign; 	// calculated
	short BitsPerSample; 	// should be 16

	char subChunk2ID[4]; 	// must be data
	int subChunk2Size; 		// calculated
};

// function declarations
void displayWAVHDR(struct WAVHDR);
void showID(char *, char *);
void displayWAVdata(short[]);
void testTone(int ch, int fl, int fr, float dur);
