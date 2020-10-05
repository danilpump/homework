#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main() {
	double d = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, r1 = 0, r2 = 0;
	printf("Enter the coordinates of the first circle(x, y):\n");
	scanf("%d", &x1);
	scanf("%d", &y1);
	printf("Enter the coordinates of the second circle(x, y):\n");
	scanf("%d", &x2);
	scanf("%d", &y2);
	printf("Enter the radius of the first circle:\n");
	scanf("%d", &r1);
	printf("Enter the radius of the second circle:\n");
	scanf("%d", &r2);
	d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	if (d > r1 + r2)
		printf("The circles are not intersection\n");
	else if (d == r1 + r2)
		printf("The circles have one intersection point\n");
	else if ((r1 >= r2 + d) && (d != 0))
		printf("The second circle is inside the first\n");
	else if ((r2 >= r1 + d) && (d != 0))
		printf("The first circle is inside the second\n");
	else if ((d == 0) && (r1 == r2))
		printf("One circle lies on the another and all points are insection");
	else if (d < r1 + r2)
		printf("The circles have two intersection points\n");
	getchar();
	getchar();
}