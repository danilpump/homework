#include<stdio.h>
#include<stdlib.h>

void main() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, a = 0;
	do {
		printf("Enter the first cell coordinates x,y 1 to 8 (the real-time position of the figure):\n");
		scanf("%d", &x1);
		scanf("%d", &y1);
		printf("Enter the second cell coordinates x,y 1 to 8 (the cell where the figure need to move):\n");
		scanf("%d", &x2);
		scanf("%d", &y2);
	} while ((x1 < 1) || (x1 > 8) || (y1 < 1) || (y1 > 8) || (x2 < 1) || (x2 > 8) || (y2 < 1) || (y2 > 8));
	do {
		printf("Choose the figure you want:\n");
		printf("1 - Knight\n");
		printf("2 - Bishop\n");
		printf("3 - King\n");
		printf("4 - Queen\n");
		printf("5 - Rook\n");
		scanf("%d", &a);
	} while ((a > 5) || (a < 1));
	switch (a) {
	case 1:
		if (((x2 - x1 == 2) && (y2 - y1 == 1)) || ((x2 - x1 == 1) && (y2 - y1 == 2))) {
			printf("The Knight can move to the selected cell\n");
			a = -1;
		}
		else
			printf("The Knight can't move to the selected cell\n");
		break;
	case 2:
		if (x2 - x1 == y2 - y1) {
			printf("The Bishop can move to the selected cell\n");
			a = -1;
		}
		else
			printf("The Bishop can't move to the selected cell\n");
		break;
	case 3:
		if ((x2 - x1 <= 1) && (y2 - y1 <= 1)) {
			printf("The King can move to the selected cell\n");
			a = -1;
		}
		else
			printf("The King can't move to the selected cell\n");
		break;
	case 4:
		if ((x2 - x1 == y2 - y1) || ((y2 - y1 >= 1) && (x2 - x1 == 0)) || ((x2 - x1 >= 1) && (y2 - y1 == 0))) {
			printf("The Queen can move to the selected cell\n");
			a = -1;
		}
		else
			printf("The Queen can't move to the selected cell\n");
		break;
	case 5:
		if (((y2 - y1 >= 1) && (x2 - x1 == 0)) || ((x2 - x1 >= 1) && (y2 - y1 == 0))) {
			printf("The Rook can move to the selected cell\n");
			a = -1;
		}
		else
			printf("The Rook can't move to the selected cell\n");
		break;
	}
	if (a != -1) {
		if (((x2 - x1 == 2) && (y2 - y1 == 1)) || ((x2 - x1 == 1) && (y2 - y1 == 2)))
			printf("The Knight can move to the selected cell\n");
		if (x2 - x1 == y2 - y1)
			printf("The Bishop can move to the selected cell\n");
		if ((x2 - x1 <= 1) && (y2 - y1 <= 1))
			printf("The King can move to the selected cell\n");
		if ((x2 - x1 == y2 - y1) || ((y2 - y1 >= 1) && (x2 - x1 == 0)) || ((x2 - x1 >= 1) && (y2 - y1 == 0)))
			printf("The Queen can move to the selected cell\n");
		if (((y2 - y1 >= 1) && (x2 - x1 == 0)) || ((x2 - x1 >= 1) && (y2 - y1 == 0)))
			printf("The Rook can move to the selected cell\n");
	}
	getchar();
	getchar();
}