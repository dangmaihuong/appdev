#include <stdio.h>
#include "sound.h"
#include <math.h>
#include "screen.h"

void showID(char *idname, char *id){
	int i;
	printf("%s: ", idname);
	for(i=0; i<4; i++)		printf("%c", id[i]);
	puts("");
}

void displayWAVHDR(struct WAVHDR h){
/*	int i;
	for(i=0; i<4; i++)		printf("%c", h.chunkID[i]);
	puts("");
	printf("Chunk Size: %d\n", h.chunkSize);
	for(i=0; i<4; i++)		printf("%c", h.subChunk1ID[i]);
	puts("");
	// to be continued for other fields
*/
#ifdef DEBUG
	showID("chunkID", h.chunkID);
	printf("Chunk size: %d\n", h.chunkSize);
	showID("Format", h.format);

	showID("Subchunk1 ID", h.subChunk1ID);
	printf("Subchunk 1 size: %d\n", h.subChunk1Size);
	printf("Audio format: %d\n", h.audioFormat);
	printf("Number of channels: %d\n", h.numChannels);
	printf("Sample rate: %d\n", h.sampleRate);
	printf("Byte rate: %d\n", h.byteRate);
	printf("Block Align: %d\n", h.blockAlign);
	printf("Bits per sample: %d\n", h.BitsPerSample);

	showID("Sub chunk 2 ID", h.subChunk2ID);
	printf("Subchunk 2 size: %d\n", h.subChunk2Size);
#else
	setColors(WHITE, bg(RED));
	printf("\033[1;1H");
	printf("test.wav           ");
	setColors(YELLOW, bg(BLUE));
	printf("\033[1;21H");
	printf("Sample rate:%dHz	 ", h.sampleRate);
	setColors(CYAN, bg(MAGENTA));
	printf("\033[1;41H");
	printf("Duration:%.2f     ", (float)h.subChunk2Size/h.byteRate);
	setColors(RED, bg(YELLOW));
	setColors(BLACK, bg(WHITE));
	printf("\033[1;59H");
	printf("Number of peak:     ");
#endif


}

//this function gets 1 second of sample (16000 samples) and calculate 80 pieces of decimal values
//we know we need to calculate 1 decimal value from 200 samples, decibel vaule is calculated by RMS formula
void displayWAVdata(short s[]){
	double rms[80];
	int dB[80];		//used to send decibel values to barchart
	short *ptr = s;		//we use a pointer, pointing to the beginning of array
	int i, j;			//for nested loop counter, outer loop repeats 80 times
						//inner loop repeats 200 times
	for(i=0; i<80; i++){
		double sum = 0;		//accumulate the sum of square
		for(j=0; j<200; j++){
			sum += (*ptr) * (*ptr);
			ptr++;			//pointing to the next sample
		}
		rms[i] = sqrt(sum/200);
#ifdef DEBUG
		printf("RMS[%d] = %f\n", i, rms[i]);
#endif
		dB[i] = 20*log10(rms[i]);
	}
#ifndef DEBUG
	barChart(dB);
#endif
}
