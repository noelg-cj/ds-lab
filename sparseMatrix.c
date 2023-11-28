#include <stdio.h>
#include <stdlib.h>

typedef struct term {
    int row;
    int col;
    int value;
} term;

int getSize(int **arr, int n, int m) {
    int size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) {
                size++;
            }
        }
    }

    return size;
}

term *convertToTuple(int **arr, int n, int m, int size) {
    int counter = 1;
    term *smatrix = (term*)malloc((size+1)*sizeof(term));

    smatrix[0].row = n;
    smatrix[0].col = m;
    smatrix[0].value = size;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) {
                smatrix[counter].row = i;
                smatrix[counter].col = j;
                smatrix[counter].value = arr[i][j];
                counter++;
            }
        }
    }

    return smatrix;
}

void printTuple(term *smatrix) {
    for (int i = 1; i < smatrix[0].value+1; i++) {
        printf("%d %d %d\n", smatrix[i].row, smatrix[i].col, smatrix[i].value);
    }
}

term *transposeTuple(term *smatrix) {
    term *transpose = (term*)malloc((smatrix[0].value+1)*sizeof(term));

    int t = smatrix[0].value;
    transpose[0].row = smatrix[0].col;
    transpose[0].col = smatrix[0].row;
    transpose[0].value = t;
    int count = 1;
    for (int i = 0; i < smatrix[0].col; i++) {
        for (int j = 1; j <= t; j++) {
            if (smatrix[j].col == i) {
                transpose[count].row = smatrix[j].col;
                transpose[count].col = smatrix[j].row;
                transpose[count].value = smatrix[j].value;
                count++;
            }
        }
    }
    return transpose;
}

int main(void) {
    int n, m;
    printf("Enter rows: ");
    scanf("%d", &n);
    printf("Enter columns: ");
    scanf("%d", &m);

    int **arr = (int**)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(m*sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter number at (%d, %d): ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int size = getSize(arr, n, m);
    term *smatrix = convertToTuple(arr, n, m, size);
    printTuple(smatrix);

    printf("\nTranspose of the matrix: \n");
    term *transpose = transposeTuple(smatrix);
    printTuple(transpose);
}