#include <stdio.h>
#include <string.h>

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

void reverse_str(char* string, int length) {
    int i = 0, j = length - 1;
    char temp;
    while (i <= j) {
        temp = string[i];
        string[i++] = string[j];
        string[j--] = temp;
    }
    i = 0;
    while (string[i] != '\0') {
        if (string[i] == ')') {
            string[i] = '(';
        } else if (string[i] == '(') {
            string[i] = ')';
        }
    }
}

int main(void) {

    char infix[500], postfix[500];

    printf("Enter a infix string : ");
    scanf("%[^\n]s", infix);

    reverse_str(infix, strlen(infix));

    printf("%s\n", infix);

    infixToPostfix(infix, postfix);

    reverse_str(postfix, strlen(postfix));

    printf("The postfix version is : %s", postfix);

    return 0;
}
