#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float acc, sum = 0, fact = 1;
int elem;

float factorial(float p)
{
	if ((p <= 1))
		return 1;
	else
		return p * factorial(p - 1);
}

float bernul(float p)
{
	if (p <= 0)
		return 1;
	else
	{
		float s = 0;
		for (float k = 1; k <= p; k++) 
			s += (1.* factorial(p + 1) / factorial(k + 1) / factorial((p + 1) - (k + 1))) * bernul(p - k);
		return -1 / (p + 1) * s;
	}
}

float ctgns(float x)
{
	float j = 1;
	int n = 0;
	printf("  Terms count: Sum:      Reference value:  Difference:\n");
	while (n < elem)
	{
		j = (bernul(n) *pow(2, 2 * n) * pow(x, 2 * n - 1) / factorial(2 * n));
		if (fabs(j) < acc)
			break;
		sum += j;
		n++;
	}
	printf(" %4d          %f  %f          %f\n", n, sum, 1/tan(x), fabs(sum - (1/tan(x))));
}

float ctgns2(float x)
{
	float j = 1;
	int n = 0;
	printf("  Terms count: Sum:      Difference:   Reference value: ");
	printf("%f\n", 1 / tan(x));
	while (n < elem)
	{
		j = (bernul(n) * pow(2, 2 * n) * pow(x, 2 * n - 1) / factorial(2 * n));
		sum += j;
		printf(" %4d          %f  %f\n", n + 1, sum, fabs(sum - 1 / tan(x)));
		n++;
	}
}

float expon(float x)
{
	float j = 1;
	int n = 0;
	printf("  Terms count: Sum:      Reference value:  Difference:\n");
	while (n < elem)
	{
		j = pow(x, n) / factorial(n);
		if (fabs(j) < acc)
			break;
		sum += j;
		n++;
	}
	printf(" %4d          %f  %f          %f\n", n, sum, exp(x), fabs(sum - exp(x)));
}

float expon2(float x)
{
	float j = 1;
	int n = 0;
	printf("  Terms count: Sum:      Difference:   Reference value: ");
	printf("%f\n", exp(x));
	while (n < elem)
	{
		j = pow(x, n) / factorial(n);
		sum += j;
		printf(" %4d          %f  %f\n", n + 1, sum, fabs(sum - exp(x)));
		n++;
	}
}

float cosin(float x)
{
	float j = 1;
	int n = 0;
	printf("  Terms count: Sum:      Reference value:  Difference:\n");
	while (n < elem)
	{
		j = pow(-1, n) * (pow(x, 2 * n) / factorial(2 * n));
		if (fabs(j) < acc)
			break;
		sum += j;
		n++;
	}
	printf(" %4d          %f  %f          %f\n", n, sum, cos(x), fabs(sum - cos(x)));
}

float cosin2(float x)
{
	float j = 1;
	int n = 0;
	printf("  Terms count: Sum:      Difference:   Reference value: ");
	printf("%f\n", cos(x));
	while (n < elem)
	{
		j = pow(-1, n) * (pow(x, 2 * n) / factorial(2 * n));
		sum += j;
		printf(" %4d          %f  %f\n", n + 1, sum, fabs(sum - cos(x)));
		n++;
	}
}

float sinus1(float x)
{
	float j = 1;
	int n = 0;
	printf("  Terms count: Sum:      Reference value:  Difference:\n");
	while (n < elem)
	{
		j = pow(-1, n) * (pow(x, 2 * n + 1) / factorial(2 * n + 1));
		if (fabs(j) < acc)
			break;
		sum += j;
		n++;
	}
	printf(" %4d          %f  %f          %f\n", n, sum, sin(x), fabs(sum - sin(x)));
}

float sinus2(float x)
{
	float j = 1;
	int n = 0;
	printf("  Terms count: Sum:      Difference:   Reference value: ");
	printf("%f\n", sin(x));
	while (n < elem)
	{
		j = pow(-1, n) * (pow(x, 2 * n + 1) / factorial(2 * n + 1));
		sum += j;
		printf(" %4d          %f  %f\n", n + 1, sum, fabs(sum - sin(x)));
		n++;
	}
}

void mode1()
{
	int sw = -1;
	float x = 0;
	float (*func)(float);
	
	while (1)
	{
		printf("Enter the x:\n");
		scanf("%f", &x);
		printf("Enter calculation accuracy (No less than 0.000001):\n");
		scanf("%f", &acc);
		printf("Enter count of elements (1 to 1000):\n");
		scanf("%d", &elem);
		printf("Select the function:\n1-sin(x)\n2-cos(x)\n3-exp(x)\n4-ctg(x)\n5-Back\n");
		scanf("%d", &sw);
		switch (sw)
		{
		    case 1: func = sinus1; func(x); break;
		    case 2: func = cosin; func(x); break;
		    case 3: func = expon; func(x); break;
		    case 4: func = ctgns; func(x); break;
		    default: return;
		}
		sum = 0;
	}
}

void mode2()
{
	int sw = -1;
	float x = 0;
	float (*func)(float);

	while (1)
	{
		printf("Enter the x:\n");
		scanf("%f", &x);
		printf("Enter count of elements (1 to 25):\n");
		scanf("%d", &elem);
		printf("Select the function:\n1-sin(x)\n2-cos(x)\n3-exp(x)\n4-ctg(x)\n5-Back\n");
		scanf("%d", &sw);
		switch (sw)
		{
		    case 1: func = sinus2; func(x); break;
		    case 2: func = cosin2; func(x); break;
		    case 3: func = expon2; func(x); break;
		    case 4: func = ctgns2; func(x); break;
			default: return;
		}
		sum = 0;
	}
}

void main()
{
	int sw = -1;
	while (1)
	{
		printf("Select operating mode:\n1-Computation of one function\n2-Serial experiment\n3-Quit the program\n");
		scanf("%d", &sw);
		switch (sw)
		{
		    case 1: mode1(); break;
		    case 2: mode2(); break;
		    default: return;
		}
	}
}
