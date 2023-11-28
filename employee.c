#include <stdio.h>
#include <stdlib.h>

typedef struct employee {
    int id;
    char name[50];
    int salary;
} employee;

int main(void) {
    int n, key;
    printf("Enter the number of records: ");
    scanf("%d", &n);
    
    employee *arr = (employee*)malloc(n*sizeof(employee));
    for (int i = 0; i < n; i++) {
        employee record;
        printf("Employee id: ");
        scanf("%d", &record.id);
        printf("Employee name: ");
        scanf("%s", record.name);
        printf("Salary: ");
        scanf("%d", &record.salary);
        arr[i] = record;
    }

    printf("Enter id to be searched: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++) {
        if (arr[i].id == key) {
            printf("Name: %s", arr[i].name);
        }
    }
}