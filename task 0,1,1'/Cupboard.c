#include<stdio.h>
#include<stdlib.h>

void main() {
	double x = 0;
	double dvp = 0, dsp = 0, wood = 0;
	int h = 0, w = 0, d = 0;
	int zad, bok, verh, dver, polki;
	printf("Enter the height (180 to 220cm):\n");
	scanf("%d", &h);
	printf("Enter the width (80 to 120cm):\n");
	scanf("%d", &w);
	printf("Enter the depth (50 to 90cm):\n");
	scanf("%d", &d);
	printf("Enter DVP density g/cm^3:\n");
	scanf("%lf", &dvp);
	printf("Enter DSP density g/cm^3:\n");
	scanf("%lf", &dsp);
	printf("Enter wood density g/cm^3:\n");
	scanf("%lf", &wood);
	if ((180 <= h) && (h <= 220) && (80 <= w) && (w <= 120) && (50 <= d) && (d <= 90)) {
		zad = h * w * 0, 5 * dvp;
		bok = 2 * h * d * 1, 5 * dsp;
		verh = 2 * w * d * 1, 5 * dsp;
		dver = h * w * wood;
		polki = (h / 40) * d * (w - 3) * dsp;
		x = (zad + bok + verh + dver + polki) / 1000;
		printf("Cupboard's weight is %.0lf kg \n", x);
	}
	else
		printf("The entered data is out of range.");
	getchar();
	getchar();
}