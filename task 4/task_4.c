#include <stdio.h>
#include <stdlib.h>

struct product {
    char name[15];
    char kod[5];
    int price;
    int count;
    int total_price;
    int disc_price;
};

#define n 15
int total_price = 0;
int total_disc = 0;

void input(struct product *p, int i) {
    double disc = 0;
    printf("Enter the barcode\n");
    scanf("%s", &p[i].kod);
    printf("Enter the name\n");
    scanf("%s", &p[i].name);
    printf("Enter the price\n");
    scanf("%d", &p[i].price);
    printf("Enter the count\n");
    scanf("%d", &p[i].count);
    printf("Enter the discount in percent\n");
    scanf("%lf", &disc);
    disc = disc / 100;
    p[i].total_price = p[i].price * p[i].count;
    p[i].disc_price = (p[i].price - (p[i].price*disc))* p[i].count;
    total_disc += p[i].total_price * disc;
    total_price += p[i].total_price;
}

void main() {
    int var = -1;
    int r = 0;
    struct product p[n];

    do {
        printf("Choose the option\n1-Scan product\n2-Make the chek\n");
        scanf("%d", &var);
        if (var == 1) {
            input(p, r);
            r++;
        }
    } while ((var != 2) && (r < n));

    printf("   ID            NAME   PRICE COUNT TOTAL_PRICE DISCOUNT_PRICE\n");
    for (int i = 0; i < r; i++) {
        printf("%5s %15s %7d %5d %11d %14d\n",p[i].kod, p[i].name, p[i].price, p[i].count, p[i].total_price,p[i].disc_price);
    }
    printf("TOTAL DISCOUNT: %d TOTAL PRICE:%d\n\n",total_disc, total_price);
}

