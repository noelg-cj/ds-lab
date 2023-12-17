#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node *createNode(int data) {
    node *n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

node *insert(node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

node *delete(node *root, int key) {
    if (root == NULL) {
        return root;
    }

    if (root->data > key) {
        root->left = delete(root->left, key);
        return root;
    }

    else if (root->data < key) {
        root->right = delete(root->right, key);
        return root;
    }

    if (root->left == NULL) {
        node *tmp = root->right;
        free(root);
        return tmp;
    }

    else if (root->right == NULL) {
        node *tmp = root->left;
        free(root);
        return tmp;
    }

    else {
        node *parent = root;
        node *succ = root->right;
        while (succ->left != NULL) {
            parent = succ;
            succ = succ->left;
        }

        if (parent != root) {
            parent->left = succ->right;
        }
        else {
            parent->right = succ->right;
        }

        root->data = succ->data;
        free(succ);
        return root;
    }
}

node *search(node *root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (root->data < key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

int main(void) {
    int op, n, flag = 0;
    node *root = NULL;
    
    while (1) {
        printf("1. Insertion\n2. Deletion\n3. Search\n4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &n);
                root = insert(root, n);
                printf("New binary tree: \n");
                inorder(root);
                break;

            case 2:
                printf("Enter number to be deleted: ");
                scanf("%d", &n);
                root = delete(root, n);
                printf("New binary tree: \n");
                inorder(root);
                break;

            case 3:
                printf("Enter number to be searched: ");
                scanf("%d", &n);
                if (search(root, n)) {
                    printf("The element was found!\n");
                }

                else {
                    printf("The element was not found!\n");
                }
                break;

            case 4:
                flag = 1;
                break;
        }

        printf("\n");
        if (flag) break;
    }
}