#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *createNode(int data) {
    node *n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

void push(node *head, int data) {
    node *n = createNode(data);

    node *tmp = head->next;
    if (tmp == NULL) {
        head->next = n;
        return;
    }

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = n;
}

void pop(node *head) {
    if (head->next == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *tmp = head->next;
    if (tmp->next == NULL) {
        head->next = NULL;
        free(tmp);
        return;
    }

    while(tmp->next->next != NULL) {
        tmp = tmp->next;
    }

    free(tmp->next);
    tmp->next = NULL;
}

void display(node *head) {
    if (head == NULL) {
        printf("\n");
        return;
    }

    printf("%d ", head->data);
    display(head->next);
}

int main(void) {
    int op, n, pos, flag = 0;
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;
    
    while (1) {
        printf("1. Push\n2. Pop\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Enter the number: ");
                scanf("%d", &n);
                push(head, n);
                display(head->next);
                break;

            case 2:
                pop(head);
                display(head->next);
                break;

            case 3: 
                flag = 1;
                break;
        }

        if (flag) break;
    }
}