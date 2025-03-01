#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include  <stdlib.h>

//int main()
//{
//	printf("hello word!");
//	return 0;
//}

#define GU 0
#define CYOKI 1
#define PA 2
#define SEED 65535
#define WIN 1
#define LOSE  -1
#define DRAW  0
#define ALPHA 0.01

int hand(double rate[]);
double frand(void);

int main()
{
	int n = 0;
	int myhand, ohand;
	double rate[3] = {1,1,1};
	int gain;
	int payoffmatrix[3][3] = {
		{DRAW,WIN,LOSE},
		{LOSE,DRAW,WIN},
		{WIN,LOSE,DRAW}
	};
	
	while (scanf("%d",&ohand)!= EOF) {
		if ((ohand < GU) || (ohand > PA)) continue;
		myhand = hand(rate);
		gain = payoffmatrix[myhand][ohand];
		printf("%d,%d,%d\t",myhand,ohand,gain);
		rate[myhand] += gain * ALPHA * rate[myhand];
		printf("%lf,%lf,%lf\n", rate[GU], rate[CYOKI], rate[PA]);
	}
	return 0;
}

int hand(double rate[]) {
	double gu, cyoki, pa;
	gu = rate[GU] * frand();
	cyoki = rate[CYOKI] * frand();
	pa = rate[PA] * frand();
	if (gu > cyoki) {
		if (gu > pa) return GU;
		else return PA;
	}
	else {
		if (cyoki > pa) return CYOKI;
		else return PA;
	}
}

double frand(void) {
	return (double)rand() / RAND_MAX;
}
