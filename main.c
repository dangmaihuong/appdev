#include <stdlib.h>	//for random numbers, and system () function
#include "screen.h"
//#include <time.h>	// for randomrization (using system time)
#include <stdio.h>
#include "sound.h"
#include <signal.h>
#include "comm.h"
int main(){
	FILE *f = fopen("test.wav", "r");
	short sd[RATE];
	for(;;){ 	//if there is no condition in for so for is true
		int ret = system(RCMD);
		if(ret == SIGINT)	break;
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
//		setColors(BLACK, bg(WHITE));
/*	barChart(dec)
	printf("Message from main\n");
*/
		struct WAVHDR hdr;
		fread(&hdr, sizeof(hdr), 1, f);		//read WAV header
		fread(&sd, sizeof(sd), 1, f);		//read WAV data
		fclose(f);
		displayWAVHDR(hdr);
		displayWAVdata(sd);
		sendDATA(sd);
	}
	resetColors();
//	getchar();
//	printf("Message from main\n");
}
