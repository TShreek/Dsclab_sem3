//Infix to postfic Conversion
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char stack[50];
char infix[30];
char postfix[30];
int top = -1;

void push(char c) {
    top++;
    stack[top] = c;
}

char pop() {
    if(top == -1)
        return -1;
    else {
        char c = stack[top];
        top--;
        return c;
    }
}

int isEmpty() {
    if(top == -1)
        return 1;
    else
        return 0;
}

int getPriority(char c) {
    switch(c) {
        case '(':
            return 0;
            break;
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '%':
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
        default:
            return 0;
    }
}

int main() {
    printf("Enter the Infix expression: ");
    scanf("%s", infix);
    char symbol, next;
    for(int i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        if(symbol == ' ' || symbol == '\t')
            continue;
        switch(symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next = pop()) != '(')
                    postfix[strlen(postfix)] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while(!isEmpty() && getPriority(stack[top]) >= getPriority(symbol))
                    postfix[strlen(postfix)] = pop();
                push(symbol);
                break;
            default:
                postfix[strlen(postfix)] = symbol;
        }
    }
    while(!isEmpty())
        postfix[strlen(postfix)]=pop();
    postfix[strlen(postfix)] = '\0';
    printf("\nPostfix: %s\n", postfix);
    return 0;
}
