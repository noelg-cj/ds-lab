#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
    int coeff;
    int exp;
} polynomial;

int input(polynomial *poly) {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Coeff: ");
        scanf("%d", &poly[i].coeff);
        printf("Exponent: ");
        scanf("%d", &poly[i].exp);
    }

    return n;
}

int display(polynomial *poly, int n) {
    for (int i = 0; i < n; i++) {
        if (poly[i].exp) {
            if (poly[i].exp != 1) {
                printf("%dx^%d+", poly[i].coeff, poly[i].exp);
            }
            else {
                printf("%dx+", poly[i].coeff);
            }
        }
        else {
            printf("%d", poly[i].coeff);
        }
    }
}

int main(void) {
    polynomial poly[50];
    int n = input(poly);
    display(poly, n);
    return 0;
}