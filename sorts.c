#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *insertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    return arr;
}

int *selectionSort(int *arr, int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
    return arr;
}

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    if (left < N && arr[left] > arr[largest])
        largest = left;

    if (right < N && arr[right] > arr[largest])
        largest = right;
 
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

int *heapSort(int *arr, int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }

    return arr;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*)malloc(n1*sizeof(int));
    int *R = (int*)malloc(n2*sizeof(int));
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int *mergeSort(int *arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
    return arr;
}

int partition(int *arr,int low,int high)
{ 
  int pivot=arr[high];
  int i=(low-1);
   
  for(int j=low;j<=high;j++)
  {
    if(arr[j]<pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i+1], &arr[high]);
  return (i+1);
}


int *quickSort(int *arr,int low,int high)
{
  if(low<high)
  {   
    int pi=partition(arr,low,high);

    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }

  return arr;
}

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int n, *arr, *arr1, op, flag=0;
    printf("Enter the elements in the array: ");
    scanf("%d", &n);

    arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    printf("The original array is: ");
    display(arr, n);

    while (1) {
        printf("1. Insertion sort\n2. Selection sort\n3. Heap sort\n4. Merge sort\n5. Quick sort\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch(op) {
            case 1: 
                arr1 = insertionSort(arr, n);
                printf("The sorted array is: ");
                display(arr1, n);
                break;

            case 2: 
                arr1 = selectionSort(arr, n);
                printf("The sorted array is: ");
                display(arr1, n);
                break;

            case 3: 
                arr1 = heapSort(arr, n);
                printf("The sorted array is: ");
                display(arr1, n);
                break;

            case 4: 
                arr1 = mergeSort(arr, 0, n-1);
                printf("The sorted array is: ");
                display(arr1, n);
                break;

            case 5: 
                arr1 = quickSort(arr, 0, n-1);
                printf("The sorted array is: ");
                display(arr1, n);
                break;

            case 6: 
                flag = 1;
        }

        if (flag) break;
    }
}