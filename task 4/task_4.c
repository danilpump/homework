#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
char mass[5];

int input(struct product* p, int i) {
    double disc = 0;
    printf("Enter the barcode\n");
    scanf("%s", &mass);
    if (check(p, mass) == -1) {
        for (int j = 0; j < 5; j++) {
            p[i].kod[j] = mass[j];
        }
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
        p[i].disc_price = p[i].total_price - (p[i].total_price * disc) ;
    }
    else {
        printf("This product is already in the database\n");
        return -1;
    }
}

int check(struct product* p) {
    int k = -1;
    for (int i = 0; i < n+3; i++) {
        if ((p[i].kod[0] == mass[0]) && (p[i].kod[1] == mass[1]) && (p[i].kod[2] == mass[2]) && (p[i].kod[3] == mass[3]))
            k=i;
    }
    return k;
}

void list(struct product* p, int r) {
    printf("\n   ID            NAME   PRICE COUNT TOTAL_PRICE DISCOUNT_PRICE\n");
    for (int i = 0; i < r; i++) {
        printf("%5s %15s %7d %5d %11d %14d\n", p[i].kod, p[i].name, p[i].price, p[i].count, p[i].total_price, p[i].disc_price);
    }
    for (int i = n; i < n + 3; i++) {
        printf("%5s %15s %7d %5d %11d %14d\n", p[i].kod, p[i].name, p[i].price, p[i].count, p[i].total_price, p[i].disc_price);
    }
    printf("\n\n");
}

void base(struct product *p) {
    strcpy_s(p[n].kod, 5, "0001");
    strcpy_s(p[n].name, 15, "Chicken");
    p[n].price = 120;
    p[n].count = 1;
    p[n].total_price = p[n].count * p[n].price;
    p[n].disc_price = p[n].total_price - p[n].total_price * 0.1;

    strcpy_s(p[n+1].kod, 5, "0002");
    strcpy_s(p[n+1].name, 15, "Bread");
    p[n + 1].price = 40;
    p[n + 1].count = 1;
    p[n + 1].total_price = p[n + 1].count * p[n + 1].price;
    p[n + 1].disc_price = p[n + 1].total_price - p[n + 1].total_price * 0;

    strcpy_s(p[n+2].kod, 5, "0003");
    strcpy_s(p[n+2].name, 15, "Fish");
    p[n + 2].price = 150;
    p[n + 2].count = 2;
    p[n + 2].total_price = p[n + 2].count * p[n + 2].price;
    p[n + 2].disc_price = p[n + 2].total_price - p[n + 2].total_price * 0.15;
}

void main() {
    int var = -1;
    int r = 0;
    int j = 0;
    struct product p[n+3];
    int CHECK[30];

    base(p);

    do {
        printf("\n\nChoose the option\n1-Scan product\n2-Show the list\n3-Add product in the check\n4-Show the check\n5-Make the chek\n");
        scanf("%d", &var);
        switch (var) {
        case 1: 
            if ((input(p, r) != -1) && (r < n))
                r++;
            else if (r >= n)
                printf("You have reached the maximum number of products\n");
            break;
        case 2: 
            list(p, r);
            break;
        case 3:
            printf("\nEnter the barcode\n");
            scanf("%s", mass);
            if ((check(p) != -1) && (j < 30)) {
                CHECK[j] = check(p);
                j++;
            }
            else if (j >= 30)
                printf("You have reached the maximum number of products in the check\n");
            else
                printf("This product is not exist\n");
            break;
        case 4:
            printf("\n   ID            NAME   PRICE COUNT TOTAL_PRICE DISCOUNT_PRICE\n");
            for (int i = 0; i < j; i++) {
                printf("%5s %15s %7d %5d %11d %14d\n", p[CHECK[i]].kod, p[CHECK[i]].name, p[CHECK[i]].price, p[CHECK[i]].count, p[CHECK[i]].total_price, p[CHECK[i]].disc_price);
            }
            printf("\n\n");
            break;
        }
    } while (var != 5);

    printf("\n   ID            NAME   PRICE COUNT TOTAL_PRICE DISCOUNT_PRICE\n");
    for (int i = 0; i < j; i++) {
        printf("%5s %15s %7d %5d %11d %14d\n", p[CHECK[i]].kod, p[CHECK[i]].name, p[CHECK[i]].price, p[CHECK[i]].count, p[CHECK[i]].total_price, p[CHECK[i]].disc_price);
        total_disc += p[CHECK[i]].total_price - p[CHECK[i]].disc_price;
        total_price += p[CHECK[i]].disc_price;
    }
    printf("TOTAL DISCOUNT: %d TOTAL PRICE:%d\n\n", total_disc, total_price);
}

