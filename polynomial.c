#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
    int coeff;
    int exponent;
} polynomial;

void display(polynomial *, int);

int main(void) {
    polynomial *p1, *p2;
    int n, m;
    printf("Enter the terms of polynomial 1: ");
    scanf("%d", &n);
    p1 = (polynomial*)malloc(n*sizeof(polynomial));
    for (int i = 0; i < n; i++) {
        printf("Coefficient: ");
        scanf("%d", &p1[i].coeff);
        printf("Exponent: ");
        scanf("%d", &p1[i].exponent);
        printf("\n");
    }

    printf("Enter the terms of polynomial 2: ");
    scanf("%d", &m);
    p2 = (polynomial*)malloc(m*sizeof(polynomial));
    for (int i = 0; i < m; i++) {
        printf("Coefficient: ");
        scanf("%d", &p2[i].coeff);
        printf("Exponent: ");
        scanf("%d", &p2[i].exponent);
        printf("\n");
    }

    printf("Polynomial 1: ");
    display(p1, n);
    printf("Polynomial 2: ");
    display(p2, m);

    int f1, f2, f3;
    f1 = f2 = f3 = 0;
    polynomial *sum = (polynomial*)malloc(sizeof(polynomial)*(n+m));
    while (f1 != n || f2 != m) {
        if (p1[f1].exponent == p2[f2].exponent) {
            sum[f3].coeff = p1[f1].coeff + p2[f2].coeff;
            sum[f3].exponent = p1[f1].exponent;
            f1++; 
            f2++;
        }

        else if (p1[f1].exponent > p2[f2].exponent) {
            sum[f3].coeff = p1[f1].coeff;
            sum[f3].exponent = p1[f1].exponent;
            f1++;
        }

        else {
            sum[f3].coeff = p2[f2].coeff;
            sum[f3].exponent = p2[f2].exponent;
            f2++;
        }
        f3++;
    }

    while (f1 != n) {

    }

    printf("Resultant: ");
    display(sum, f3);
}

void display(polynomial *p, int n) {
    for (int i = 0; i < n; i++) {
        p[i].exponent ? (p[i].exponent != 1 ? printf("%dx^%d", p[i].coeff, p[i].exponent) : printf("%dx", p[i].coeff)) : printf("%d", p[i].coeff);
        if (i != n-1) printf("+");
    }
    printf("\n");
}