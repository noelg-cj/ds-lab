#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stack {
    int top;
    char arr[100];
} stack;

int precedence (char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char *toPostfix(char *infix) {
    int count = 0;
    int len = strlen(infix);
    char *postfix = (char*)malloc(sizeof(char)*(len+2));
    stack s;
    s.top = -1;

    for (int i = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t') {
            continue;
        }

        if (isalnum(infix[i])) {
            postfix[count++] = infix[i];
        }

        else if (infix[i] == '(') {
            s.arr[++s.top] = infix[i];
        }

        else if (infix[i] == ')') {
            while (s.top > -1 && s.arr[s.top] != '(') {
                postfix[count++] = s.arr[s.top--];
                s.top--;
            }
        }

        else if (isOperator(infix[i])) {
            while(s.top > -1 && precedence(infix[i]) <= precedence(s.arr[s.top])) {
                postfix[count++] = s.arr[s.top--];
            }
            s.arr[++s.top] = infix[i];
        }
    }

    while(s.top > -1) {
        postfix[count++] = s.arr[s.top--];
    }
    postfix[count] = '\0';
    return postfix;
}

int evaluate(char *postfix) {
    stack s;
    s.top = -1;

    for (int i = 0; i < strlen(postfix); i++) {
        if (isdigit(postfix[i])) {
            s.arr[++s.top] = postfix[i] - '0';
        }

        else {
            int a = s.arr[s.top--];
            int b = s.arr[s.top--];
            switch(postfix[i]) {
                case '+':
                    s.arr[++s.top] = a+b;
                    break;
                case '-':
                    s.arr[++s.top] = a-b;
                    break;
                case '*':
                    s.arr[++s.top] = a*b;
                    break;
                case '/': 
                    s.arr[++s.top] = a/b;
                    break;
            }
        }
    }
    return s.arr[s.top--];
}

int main(void) {
    int op, flag = 0;
    char infix[50];
    char *postfix;
    char post[50];

    while(1) {
        printf("1. Expression to postfix\n2. Postfix evaluation\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch(op) {
            case 1: 
                printf("Enter the expression: ");
                scanf("%s", infix);
                postfix = toPostfix(infix);
                printf("Postfix expression: %s\n", postfix);
                break;

            case 2: 
                printf("Enter the expression: ");
                scanf("%s", post);
                printf("Evaluation: %d\n", evaluate(post));

            case 3: 
                flag = 1;
        }

        if (flag) break;
    }
    return 0;
}