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

node *delete(node *root, int data) {
    if (root == NULL) {
        return root;
    }

    if (root->data > data) {
        root->left = delete(root->left, data);
        return root;
    }

    else if (root->data < data) {
        root->right = delete(root->right, data);
        return root;
    }

    if (root->left == NULL) {
        node *temp = root->right;
        free(root);
        return temp;
    }

    else if (root->right == NULL) {
        node *temp = root->left;
        free(root);
        return temp;
    }

    else {
        node *succParent = root;
        node *succ = root->right;

        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != succ) {
            succParent->left = succ->right;
        }
        else {
            succParent->right = succ->right;
        }

        root->data = succ->data;
        free(succ);
        return root;
    }
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
    inorder(root);
}