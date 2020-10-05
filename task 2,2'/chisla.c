#include <stdio.h>
#include <stdlib.h>

void main() {
	int chislo = 0, x = 0, otvet = -1, high = 1000, low = 0, pop = 0;
	char znak = NULL;
	printf("Select mode:\n1-You guess the number\n2-Program guesses the number\n");
	scanf("%d", &x);
	switch (x) {
	case 1:
		srand(time(NULL));
		chislo = (rand() % 999) + 1;
		printf("Enter the number:\n");
		while (chislo != otvet) {
			scanf("%d", &otvet);
			if (chislo > otvet)
				printf("The hidden number is greater\n");
			else if (chislo < otvet)
				printf("The hidden number is less\n");
			pop++;
		}
		printf("You guessed!\n");
		printf("Count of attempts: %d", pop);
		break;
	case 2:
		printf("Enter the hidden number:\n");
		scanf("%d", &chislo);
		while (znak != '=') {
			otvet = (high + low) / 2;
			printf("%d ?\n", otvet);
			getchar();
			znak = getchar();
			switch (znak) {
			case '<':
				high = otvet;
				break;
			case '>':
				low = otvet;
				break;
			}
			pop++;
		}
		printf("The number is guessed: %d\n", otvet);
		printf("Count of attempts: %d", pop);
		break;
	}
}