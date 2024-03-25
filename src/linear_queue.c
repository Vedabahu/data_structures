#include <stdio.h>

#define MAX 5

int queue[MAX];
int first = -1;
int rear = -1;

void enque();
void deque();
void display();

int main(void) {
    int ch;
    while (1) {
        printf("Choose one of the below choices :- \n");
        printf(" 1 : Add an element to the stack.\n");
        printf(" 2 : Remove an element from the stack.\n");
        printf(" 3 : View the elements of the stack.\n");
        printf(" 4 : Exit the program.\n");
        printf("Enter your choice : ");

        scanf("%i", &ch);

        switch (ch) {
            case 1: enque(); break;
            case 2: deque(); break;
            case 3: display(); break;
            case 4: return 0; break;
            default: printf("Wrong Choice. Enter it properly.\n");
        }
    }
    return 0;
}

void enque() {
    if (rear == MAX - 1) {
        printf("Queue overflow.\n");
        return;
    }
    int element;
    printf("Enter an element : ");
    scanf("%d", &element);

    queue[++rear] = element;
    first += 1 * (rear == 0);
}

void deque() {
    if (first == -1 || first > rear) {
        printf("Queue Underflow.\n");
        return;
    }
    printf("The first element is %d.\n", queue[first++]);
}

void display() {
    for (int i = first; i < rear; i++) {
        printf(" %d ", queue[i]);
    }
    printf("\n");
}
