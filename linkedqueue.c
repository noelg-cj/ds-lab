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

void enqueue(node *head, int data) {
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

void dequeue(node *head) {
    if (head->next == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *tmp = head->next;
    head->next = tmp->next;
    free(tmp);
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
        printf("1. Insert at beginning\n2. Insert at end\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Enter the number: ");
                scanf("%d", &n);
                enqueue(head, n);
                display(head->next);
                break;

            case 2:
                dequeue(head);
                display(head->next);
                break;

            case 3: 
                flag = 1;
                break;
        }

        if (flag) break;
    }
}