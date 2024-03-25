#include <iostream>

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
        std::cout << "Choose one of the below choices :- \n";
        std::cout << " 1 : Add an element to the stack.\n";
        std::cout << " 2 : Remove an element from the stack.\n";
        std::cout << " 3 : View the elements of the stack.\n";
        std::cout << " 4 : Exit the program.\n";
        std::cout << "Enter your choice : ";

        std::cin >> ch;

        switch (ch) {
            case 1: enque(); break;
            case 2: deque(); break;
            case 3: display(); break;
            case 4: return 0; break;
            default: std::cout << "Wrong Choice. Enter it properly.\n";
        }
    }
    return 0;
}

void enque() {
    if (rear == MAX - 1) {
        std::cout << "Queue overflow.\n";
        return;
    }
    int element;
    std::cout << "Enter an element : ";
    std::cin >> element;

    queue[++rear] = element;
    first += 1 * (rear == 0);
}

void deque() {
    if (first == -1 || first > rear) {
        std::cout << "Queue Underflow.\n";
        return;
    }
    std::cout << "The first element is " << queue[first++] << "\n";
}

void display() {
    for (int i = first; i < rear; i++) {
        std::cout << queue[i] << " \n";
    }
    std::cout << std::endl;
}
