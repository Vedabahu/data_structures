#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int digit, base;
    struct node* next;
} node;

void insert_front(node** head, int remainder, int base) {
    node* temp = (node*)malloc(sizeof(node));
    temp->digit = remainder;
    temp->base = base;
    temp->next = *head;
    *head = temp;
}

void pprint(node* head) {
    while (head) {
        printf("%d, %d -> ", head->digit, head->base);
        head = head->next;
    }
    printf("NULL\n");
}

void freeall(node* head) {
    node* temp = head;
    while (temp) {
        head = head->next;
        free(temp);
        temp = head;
    }
}

int main(void) {
    int num, base;
    node* head = NULL;
    do {
        printf("Enter a base (max 10): ");
        scanf("%d", &base);
    } while (base > 10 | base < 0);
    printf("Enter a number : ");
    scanf("%d", &num);
    while (num) {
        int remainder = num % base;
        insert_front(&head, remainder, base);
        num /= base;
    }
    pprint(head);
    freeall(head);
    return 0;
}
