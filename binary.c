#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binary(char buffer[50][50], int len, char key[50]) {
    int l = 0;
    int r = len-1;
    int mid;
    while (l <= r) {
        mid = l + (r - l)/2;
        if (strcmp(buffer[mid], key) == 0) {
            printf("\nThe name was found at position %d", mid);
            return;
        }

        else if (strcmp(buffer[mid], key) > 0) {
            l = mid+1;
        }

        else {
            r = mid-1;
        }
    }
    printf("Not found\n");
    return;
}

void bubble(char buffer[50][50], int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-i-1; j++) {
            if (strcmp(buffer[j], buffer[j+1]) > 0) {
                char tmp[50];
                strcpy(tmp, buffer[j]);
                strcpy(buffer[j], buffer[j+1]);
                strcpy(buffer[j+1], tmp);
            }
        }
    }
}

int main(void) {
    FILE *fptr;
    char *line = NULL;
    int len = 0;
    char buffer[50][50];

    fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        printf("Couldn't open file");
        return 1;
    }

    printf("Given input: ");
    while (fgets(buffer[len], 50, fptr)) {
        printf("%s", buffer[len]);
        len++;
    }

    fclose(fptr);

    binary(buffer, len, "John\n");

    printf("\nOn sorting: \n");
    bubble(buffer, len);
    for (int i = 0; i < len; i++) {
        printf("%s", buffer[i]);
    }
}