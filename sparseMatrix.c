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

term *addTuples(term *a, term *b) {
    int a_pos = 1;
    int b_pos = 1;
    term *result = (term*)malloc(sizeof(term));
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        printf("Matrices can't be added");
        return result;
    }
    result[0].row = a[0].row;
    result[0].col = a[0].col;
    result[0].value = 0;

    while (a_pos <= a[0].value && b_pos <= b[0].value) {
        if (a[a_pos].row > b[b_pos].row || a[a_pos].row == b[b_pos].row && a[a_pos].col > b[b_pos].col) {
            result[0].value++;
            int pos = result[0].value;
            result = (term*)realloc(result, pos+1*sizeof(term));
            result[pos].row = b[b_pos].row;
            result[pos].col = b[b_pos].col;
            result[pos].value = b[b_pos].value;
            b_pos++;
        }
        else if (a[a_pos].row < b[b_pos].row || a[a_pos].row == b[b_pos].row && a[a_pos].col < b[b_pos].col) {
            result[0].value++;
            int pos = result[0].value;
            result = (term*)realloc(result, pos+1*sizeof(term));
            result[pos].row = a[a_pos].row;
            result[pos].col = a[a_pos].col;
            result[pos].value = a[a_pos].value;
            a_pos++;
        }
        else {
            result[0].value++;
            int pos = result[0].value;
            result = (term*)realloc(result, pos+1*sizeof(term));
            result[pos].row = a[a_pos].row;
            result[pos].col = a[a_pos].col;
            result[pos].value = a[a_pos].value + b[b_pos].value;
            a_pos++;
            b_pos++;
        }
    }

    while(a_pos <= a[0].value) {
        result[0].value++;
        int pos = result[0].value;
        result = (term*)realloc(result, pos+1*sizeof(term));
        result[pos].row = a[a_pos].row;
        result[pos].col = a[a_pos].col;
        result[pos].value = a[a_pos].value;
        a_pos++;
    }

    while(b_pos <= b[0].value) {
        result[0].value++;
        int pos = result[0].value;
        result = (term*)realloc(result, pos+1*sizeof(term));
        result[pos].row = b[b_pos].row;
        result[pos].col = b[b_pos].col;
        result[pos].value = b[b_pos].value;
        b_pos++;
    }

    return result;
}

int main(void) {
    int n, m, a, b;
    printf("Enter rows of first matrix: ");
    scanf("%d", &n);
    printf("Enter columns of first matrix: ");
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

    printf("Enter rows of second matrix: ");
    scanf("%d", &a);
    printf("Enter columns of second matrix: ");
    scanf("%d", &b);

    int **arr1 = (int**)malloc(a*sizeof(int));
    for (int i = 0; i < a; i++) {
        arr1[i] = (int*)malloc(b*sizeof(int));
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("Enter number at (%d, %d): ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("First matrix: \n");
    int size = getSize(arr, n, m);
    term *smatrix = convertToTuple(arr, n, m, size);
    printTuple(smatrix);

    printf("Second matrix: ");
    int size2 = getSize(arr1, a, b);
    term *smatrix1 = convertToTuple(arr1, a, b, size2);
    printTuple(smatrix1);

    term *result = addTuples(smatrix1, smatrix);
    printf("On addition: \n");
    printTuple(result);
}