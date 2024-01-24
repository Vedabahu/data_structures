#include <stdio.h>

#define MAX_SIZE 500

char stack[MAX_SIZE];
int top = -1;

int isEmpty() { return top == -1; }

int isFull() { return top == MAX_SIZE - 1; }

void push(char element) {
    if (isFull()) {
        return;
    }
    stack[++top] = element;
}

char pop() {
    if (isEmpty()) {
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (isEmpty()) {
        return '\0';
    }
    return stack[top];
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return -1;
    }
}

void infixToPostfix(const char* infix, char* postfix) {
    int i = 0, j = 0;
    char temp;

    while (infix[i] != 0) {

        if (infix[i] == ' ' || infix[i] == '\t') {
            i++;
            continue;
        }

        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix[j++] = infix[i++];
            continue;
        }

        if (infix[i] == '(') {
            push(infix[i++]);
            continue;
        }

        if (infix[i] == ')') {
            while (!isEmpty() && peek() != '(') {
                temp = pop();
                postfix[j++] = temp;
            }

            if (!isEmpty() && peek() != '(') {
                return;
            }
            pop();
            i++;
            continue;
        }

        while (!isEmpty() && precedence(peek()) >= precedence(infix[i])) {
            temp = pop();
            postfix[j++] = temp;
        }

        push(infix[i++]);
    }

    while (!isEmpty()) {
        temp = pop();
        postfix[j++] = temp;
    }

    postfix[j] = '\0';
}

int main(void) {
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    scanf("%[^\n]s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
