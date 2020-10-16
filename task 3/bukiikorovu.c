#include<stdlib.h>
#include<stdio.h>

void main() {
	int mass[] = { 0,0,0,0,0 }, mass2[] = { 1,2,3,4,0 };
	int input, i = 0, end = 0, mid = 0, max = 0;
	int a = 0, b = 0, c = 0;
	int cow = 0, bull = 0; 
	
	printf("Enter the number of digits 2 to 5:\n");
	scanf("%d", &max);

	srand(time(NULL));

	mass[0] = 1 + rand() % 8;
	for (int r = 1; r < max; r++) {
		do {
			c = 0;
			mass[r] = rand() % 9;
			for (int k = 0; k < max; k++) {

				if (mass[r] == mass[k])
					c++;
			}
		} while (c != 1);
	}

	printf("Hidden number: ");
	for (int r = 0; r < max; r++) {
		printf("%d", mass[r]);
	}
	printf("\n");

	do {
		cow = 0;
		bull = 0;
		max = 0;
		end = 0;

		printf("Enter the number:\n");
		scanf("%d", &input);
		while (input>0) {
			mass2[max] = input % 10;
			input = input / 10;
			max++;
		}

		mid = max - 1;
		for (int r = 0; r < max / 2; r++) {
			i = mass2[r];
			mass2[r] = mass2[mid];
			mass2[mid] = i;
			mid--;
		}

		for (int r = 0; r < max; r++) {
			if (mass[r] == mass2[r]) {
				bull++;
			}
			for (int j = 0; j < max; j++) {
				if ((mass[r] == mass2[j]) && (r != j)) {
					cow++;
				}
			}
		}

		while (end < max) {
			if (mass[end] == mass2[end])
				end++;
			else
				break;
		}
		printf("Cows: %d  Bulls: %d\n", cow, bull);
	} while (end != max);
	printf("WIN!!");
}