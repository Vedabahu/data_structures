// Sort the elements of tht queue using a Stack.

#include <stdio.h>

#define MAX 50

int stack[MAX], queue[MAX];
int top = -1;
int front = 0, rear = 0, count = 0;

void enqueue(int element) {
	if ( count == MAX ) {
		printf("The queue is full!!");
		return;
	}
	queue[rear] = element;
	count++;
	rear = (rear + 1) % MAX;
}

int dequeue() {
	if ( count == 0 ) {
		printf("The queue is empty!!");
	}
	int temp = queue[front];
	front = (front + 1) % MAX;
	count--;
	return temp;
}

void push(int element) {
	if (top == MAX - 1){
		printf("The stack is full!!");
		return;
	}
	stack[++top] = element;
}

int pop() {
	if (top == -1){
		printf("The stack is empty!!");
	}
	return stack[top--];
}

void accept_elements() {
	int number, temp;
	printf("Enter the number of elements in the queue (MAX %d) : ", MAX);
	scanf("%d", &number);
	printf("Please enter the elements of the queue : ");
	for (int i = 0; i < number; i++) {
		scanf("%d", &temp);
		enqueue(temp);
	}
	return;
}

int main(void) {
	accept_elements();
	while (count > 0) {
		if (queue[front] < queue[front + 1]){
			enqueue(dequeue());
		} else if (queue[front] >= queue[front + 1]) {
			push(dequeue());
		}
	}
	
	while(top != -1) {
		enqueue(pop());
	}
	
	// // for ascending order
	// while (count != 0) {
		// push(dequeue());
	// }
	
	// while (top != -1) {
		// enqueue(pop());
	// }
	// // end ascending order

	
	printf("The elements of the sorted queue : ");
	for(int i = front, j = 0; j < count; j++) {
		printf(" %d ", queue[i]);
		i = (i + 1) % MAX;
	}
	return 0;
}