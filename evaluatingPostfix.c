#include <stdio.h>
#include <ctype.h>
#include <string.h>

char postfix[50];
char eval[50];
int top = -1;
int result;

void push(int c) {
    eval[++top] = c;
}

int pop() {
    return (eval[top--]);
}

int isEmpty() {
    if(top == -1)
        return 1;
    else
        return 0;
}

void main() {
    printf("Enter a postfix Expression: ");
    char ch;
    int x = 0, y = 0, z = 0;
    scanf("%s", postfix);
    for(int i = 0; i < strlen(postfix); i++) {
        ch = postfix[i];
        if(isdigit(ch))
            push(ch - '0');
        else {
            y = pop();
            x = pop();
            switch(ch) {
                case '+':
                    z = x + y;
                    break;
                case '-':
                    z = x - y;
                    break;
                case '*':
                    z = x * y;
                    break;
                case '/':
                    z = x / y;
                    break;
                case '%':
                    z = x % y;
                    break;
                default:
                    return 0;
            }
            push(z);
        }
    }
    result = pop();
    printf("\nThe result is %d\n", result);
}
