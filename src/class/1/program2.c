//Sort the elements of tht queue using a Stack.

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
		return 0;
	}
	stack[++top] = element;
}

int pop() {
	if (top == -1){
		printf("The stack is empty!!");
	}
	return stack[top--];
}

int peek_rear() {
	if (count == 0) {
		printf("Nothing to return.\n");
	}
	if (rear == 0)
		return queue[MAX - 1];
	else
		return queue[rear - 1];
	
}

void accept_elements() {
	int number, temp;
	printf("Enter the number of elements in the queue (MAX %d) : ", MAX);
	scanf("%d", &number);
	printf("Please enter the elements of the queue : ");
	for (int i = 0; i < number; i++) {
		scanf("%d", &temp);
		push(temp);		
	}
	return;
}

int main(void) {
	accept_elements();
	int temp_count;
	
	// Sorting Part
	enqueue(pop());
	while (top != -1) {
		if (stack[top] >= peek_rear()) {
			enqueue(pop());
		} else if (stack[top] < peek_rear()) {
			temp_count = count;
			while (stack[top] > queue[front]) {
				enqueue(dequeue());
				temp_count--;
			}
			enqueue(pop());
			while (temp_count--) {
				enqueue(dequeue());
			}
		}
	}
	
	printf("The sorted elements are : ");
	for (int i = front, j = 0; j < count; j++) {
		printf("%d ", queue[i]);
		i = (i + 1) % MAX;
	}
}
