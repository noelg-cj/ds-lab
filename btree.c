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
        return;
    }

    q->arr[q->front] = n;
    q->front++;
}

node *dequeue(queue *q) {
    node *n;
    if (q->rear == q->front) {
        return NULL;
    }
    n = q->arr[q->rear];
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
    node *n = createNode(data);

    if (!root) {
        root = n;
        return root;
    }

    queue *q = (queue*)malloc(sizeof(queue));
    q->arr = (node**)malloc(sizeof(node*)*100);
    q->front = q->rear = -1;

    enqueue(q, root);

    while (q->front != q->rear) {
        node *curr = dequeue(q);

        if (!curr->left) {
            curr->left = n;
            break;
        }

        else {
            enqueue(q, curr->left);
        }

        if (!curr->right) {
            curr->right = n;
            break;
        }

        else {
            enqueue(q, curr->right);
        }
    }
    printf("%d insertion successful\n", data);
    return root;
}

void inorder(node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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
    head = insert(head, 12);
    head = insert(head, 11);
    head = insert(head, 13);
    inorder(head);
    printf("\n");
    preorder(head);
    printf("\n");
    postorder(head);
    printf("\n");
}