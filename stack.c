#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int *arr;
    int top;
    int size;
} stack;

void push (stack *s, int n) {
    if (s->top < s->size-1) {
        s->arr[++s->top] = n;
    }
    else {
        printf("Stack is full\n");
    }
}

void pop (stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    s->top--;
}

void display (stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
    }
    else {
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

int main(void) {
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    printf("Enter maximum size of stack: ");
    scanf("%d", &s->size);
    s->arr = (int*)malloc(s->size * sizeof(int));
    int op, n, flag = 0;
    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1: 
                printf("Enter the element to be pushed: ");
                scanf("%d", &n);
                push(s, n);
                display(s);
                break;

            case 2: 
                pop(s);
                display(s);
                break;

            case 3:
                display(s);
                break;
            
            case 4: 
                flag = 1;
        }

        if (flag) break;
    }
    return 0;
}