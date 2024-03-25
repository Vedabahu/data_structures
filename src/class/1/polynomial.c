// Use -fsanitize=address to detect any leaks or other things.
#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
    int coefficient;
    int exponent;
    struct polynomial* next;
} polynomial;

void accept_polynomial(polynomial** head, int max) {
    for (int i = max; i >= 0; i--) {
        printf("Enter the coefficient of x^%d : ", i);
        polynomial* temp = (polynomial*)malloc(sizeof(polynomial));
        temp->next = *head;
        temp->exponent = i;
        scanf("%d", &temp->coefficient);
        *head = temp;
    }
}

void add_polynomial(polynomial** ans_head, polynomial* poly1, polynomial* poly2) {
    int sum = 0;
    while (poly1 != NULL) {
        sum = poly1->coefficient + poly2->coefficient;
        polynomial* temp = (polynomial*)malloc(sizeof(polynomial));
        temp->next = *ans_head;
        temp->coefficient = sum;
        temp->exponent = poly1->exponent;
        *ans_head = temp;
        poly1 = poly1->next;
        poly2 = poly2->next;
    }
}

void free_all(polynomial* head) {
    polynomial* temp = head;
    while (temp != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }
}

int main(void) {
    polynomial* poly1 = NULL;
    polynomial* poly2 = NULL;
    polynomial* ans_poly = NULL;

    printf("Enter the maximum exponent : ");
    int max;
    scanf("%d", &max);
    printf("Polynomial 1 :- \n");
    accept_polynomial(&poly1, max);
    printf("Polynomial 2 :- \n");
    accept_polynomial(&poly2, max);
    add_polynomial(&ans_poly, poly1, poly2);

    printf("\nThe answer is : ");

    polynomial* temp = ans_poly;
    while (temp != NULL) {
        if (temp->coefficient == 0) {
            if (temp->next == NULL) {
                printf("\b\b");
            }
            temp = temp->next;
            continue;
        }
        if (temp->next != NULL) {
            printf("%dx^%d + ", temp->coefficient, temp->exponent);
        } else {
            printf("%d\n", temp->coefficient);
        }
        temp = temp->next;
    }

    free_all(poly1);
    free_all(poly2);
    free_all(ans_poly);
    return 0;
}
