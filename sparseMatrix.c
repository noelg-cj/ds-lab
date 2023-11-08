#include <stdio.h>
#include <stdlib.h>

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

int **convertToTuple(int **arr, int n, int m, int size) {
    int 
}