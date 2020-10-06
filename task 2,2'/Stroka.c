#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main() {
    int slova = 0, chisla = 0, i = 0;
    char stroka[255];
    printf("Enter the string:");
    fgets(stroka, 255, stdin);
    while (i < strlen(stroka)) {
        if ((stroka[i] == ' ') || (stroka[i] == '.') || (stroka[i] == ',') || (stroka[i] == '\n')) {
            if (((stroka[i - 1] >= 'a') && (stroka[i - 1] <= 'z')) || ((stroka[i - 1] >= 'A') && (stroka[i - 1] <= 'Z')))
                slova++;
            else if ((stroka[i - 1] >= '0') && (stroka[i - 1] <= '9'))
                chisla++;
        }
        i++;
    }
    printf("Count of words = %d\n", slova);
    printf("Count of numbers = %d\n", chisla);
	getchar();
	getchar();
}