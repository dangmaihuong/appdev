#include <stdlib.h>	//for random numbers
#include "screen.h"
#include <time.h>
#include<stdio.h>

int main(){
	int dec[COL];		//80 pieces of sound decibels
	srand(time(NULL));
	for(int i=0; i<COL; i++)	dec[i]=rand()%70+30;	//from 32-99
	clearScreen();
	setColors(BLACK, bg(WHITE));
	barChart(dec);
//	printf("Message from main\n");
	resetColors();
	getchar();
//	printf("Message from main\n");

}
