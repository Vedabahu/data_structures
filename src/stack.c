#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 20

int stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

bool isFull() {
    if (top == (MAX_SIZE - 1)) {
        return true;
    } else {
        return false;
    }
}

void push(int element) {
    if (!isFull()) {
        top += 1;
        stack[top] = element;
    } else {
        printf("Stack is full. Can not add any element.\n");
    }
}

void pop() {
    if (!isEmpty()) {
        int x = stack[top];
        top -= 1;
        printf("Element %d has been popped.\n", x);
    } else {
        printf("The stack is empty.\n");
    }
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("|%d|\n", stack[top]);
    }
}

int main(void) {}
