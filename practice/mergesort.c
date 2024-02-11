#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i = 0;
    int j = 0;
    int k = l;

    int n1 = m - l + 1;
    int n2 = r - m;

    int *larr = (int*)malloc((n1)*sizeof(int));
    int *rarr = (int*)malloc((n2)*sizeof(int));

    for (int a = 0; a < n1; a++) {
        larr[a] = arr[l + a];
    }

    for (int a = 0; a < n2; a++) {
        rarr[a] = arr[m + a + 1];
    }

    while (i < n1 && j < n2) {
        if (larr[i] <= rarr[j]) {
            arr[k] = larr[i];
            i++; k++;
        }
        else {
            arr[k] = rarr[j];
            j++; k++;
        }
    }

    while (i < n1) {
        arr[k] = larr[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = rarr[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(void) {
    int arr[] = { 1, 3, 4, 2, 7, 6, 9, 5, 8, 10 };
    mergeSort(arr, 0, 9);
    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
}