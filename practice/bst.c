#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} node;

node *newNode(int data) {
    node *n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

node *insert(node *node, int data) {
    if (node == NULL) {
        return newNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    }

    else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(void) {
    struct node *root = NULL;

    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 12);
    insert(root, 3);
    insert(root, 6);
}