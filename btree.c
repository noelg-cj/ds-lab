#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

typedef struct queue {
    int size;
    int front;
    int rear;
    node **arr;
} queue;

void enqueue(queue *q, node *n) {
    if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
    } 

    if (q->front == q->size) {
        printf("Queue is full\n");
        return;
    }

    q->arr[q->front] = n;
    q->front++;
}

node *dequeue(queue *q) {
    node *n;
    printf("hi");
    if (q->rear == q->front) {
        printf("Queue is empty.\n");
        return NULL;
    }
    n = q->arr[q->rear];
    printf("bye");
    q->rear++;
    return n;
}

node *createNode(int data) {
    node *n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

node *insert(node *root, int data) {
    printf("starting insert..\n");
    node *n = createNode(data);

    if (!root) {
        printf("Root was empty - ");
        root = n;
        printf("%d\n", root->data);
        return root;
    }

    queue *q = (queue*)malloc(sizeof(queue));
    q->arr = (node**)malloc(sizeof(node**)*100);
    printf("Memory allocated\n");

    enqueue(q, root);
    printf("Root enqueued\n");

    while (q->front != q->rear) {
        printf("loop entered\n");
        node *curr = dequeue(q);
        printf("%d dequeued\n", curr->data);

        if (!curr->left) {
            curr->left = n;
        }

        else if (!curr->right) {
            curr->right = n;
        }

        else {
            enqueue(q, curr->left);
            enqueue(q, curr->right);
        }
    }
    return root;
}

void inorder(node *root) {
    if (root == NULL) {
        printf("head is empty");
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(void) {
    node *head = (node*)malloc(sizeof(node));
    head = NULL;

    head = insert(head, 5);
    head = insert(head, 6);
    head = insert(head, 7);
    head = insert(head, 8);
    head = insert(head, 9);
    head = insert(head, 10);
    head = insert(head, 11);
    inorder(head);
}