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

int main(void) {
    char infix[] = "a+b*(c^d-e)^(f+g*h)-i";

    char *postfix = toPostfix(infix);
    printf("%s\n", postfix);
    return 0;
}