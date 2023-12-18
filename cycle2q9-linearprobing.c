#include <stdio.h>
#define SIZE 10

int hash(int key) {
    return key % SIZE;
}

void insert(int hashTable[], int key) {
    int index = hash(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}

void display(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int hashTable[SIZE], n, a;
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    printf("Enter number of elements to be inserted: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter number: ");
        scanf("%d", &a);
        insert(hashTable, a);
        display(hashTable);
    }

    display(hashTable);

    return 0;
}
