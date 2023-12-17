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

void insertAtBeginning(node *head, int data) {
    node *n = createNode(data);
    node *tmp = head->next;

    head->next = n;
    n->next = tmp;
}

void insertAtPosition(node *head, int data, int pos) {
    node *n = createNode(data);
    node *tmp = head->next;

    while (tmp != NULL) {
        if (tmp->data == pos) {
            n->next = tmp->next;
            tmp->next = n;
            return;
        }
        tmp = tmp->next;
    }

    printf("The element was not found.\n");
    return;
}

void insertAtEnd(node *head, int data) {
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
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from Beginning\n5. Delete from end\n6. Delete from position\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Enter the number: ");
                scanf("%d", &n);
                insertAtBeginning(head, n);
                display(head);
                break;

            case 2:
                printf("Enter the number: ");
                scanf("%d", &n);
                insertAtEnd(head, n);
                display(head);
                break;

            case 3:
                printf("Enter the number: ");
                scanf("%d", &n);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insertAtPosition(head, n, pos);
                display(head);
                break;

        }
    }
}