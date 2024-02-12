#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high) {
    int temp;
    int pivot = arr[high];
    int i = low-1;

    for (int j = low; j <= high; j++) {
        if (arr[j] > pivot) {
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi, high);
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

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