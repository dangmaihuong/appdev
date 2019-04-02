#include <stdlib.h>	//for random numbers
#include "screen.h"
#include <time.h>	// for randomrization using system time
#include <stdio.h>
#include "sound.h"

int main(){
	FILE *f = fopen("test.wav", "r");
	short sd[80000];
	for(;;){ 	//if there is no condition in for so for is true
		system(RCMD);
		f = fopen("test.wav", "r");
		if(f == NULL){
			printf("Cannot open the file\n");
			return 1;
		}

/*	int dec[COL];		//80 pieces of sound decibels
	srand(time(NULL));
	for(int i=0; i<COL; i++)	dec[i]=rand()%70+30;	//from 32-99
*/
		clearScreen();
		setColors(CYAN, bg(WHITE));
/*	barChart(dec)
	printf("Message from main\n");
*/
		struct WAVHDR hdr;
		fread(&hdr, sizeof(hdr), 1, f);		//read WAV header
		fread(&sd, sizeof(sd), 1, f);		//read WAV data
//		displayWAVdata
		fclose(f);
		displayWAVHDR(hdr);
	}

	resetColors();
	getchar();
//	printf("Message from main\n");

}
