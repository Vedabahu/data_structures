#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure definition
typedef struct {
    int top;
    unsigned capacity;
    char* array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Stack is full when the top is equal to the last index
int isFull(Stack* stack) { return stack->top == stack->capacity - 1; }

// Stack is empty when the top is equal to -1
int isEmpty(Stack* stack) { return stack->top == -1; }

// Function to add an item to the stack. It increases the top by 1
void push(Stack* stack, char item) {
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to remove an item from the stack. It decreases the top by 1
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->array[stack->top--];
}

// Function to return the top from the stack without removing it
char peek(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->array[stack->top];
}

// Function to check the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;

        case '*':
        case '/': return 2;

        case '^': return 3;

        default: return -1;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(const char* infix, char* postfix) {
    Stack* stack = createStack(strlen(infix));
    int i = 0, j = 0;
    char temp;

    while (infix[i] != '\0') {
        if (infix[i] == ' ' || infix[i] == '\t') {
            i++;
            continue;
        }

        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix[j++] = infix[i++];
            continue;
        }

        if (infix[i] == '(') {
            push(stack, infix[i++]);
            continue;
        }

        if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                temp = pop(stack);
                postfix[j++] = temp;
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                return; // invalid infix expression
            }
            pop(stack); // pop '('
            i++;
            continue;
        }

        // If an operator is encountered
        while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i])) {
            temp = pop(stack);
            postfix[j++] = temp;
        }

        push(stack, infix[i++]);
    }

    while (!isEmpty(stack)) {
        temp = pop(stack);
        postfix[j++] = temp;
    }

    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    scanf("%[^\n]s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
