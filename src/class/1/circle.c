#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

typedef struct cross {
    node* val;
    struct cross* next;
} cross;

void identify(node* head) {
    cross* has_crossed = (cross*)malloc(sizeof(cross));
    cross* temp_cross = has_crossed;
    has_crossed->val = head;
    has_crossed->next = NULL;
    node* temp = head;
    while (temp->next != NULL) {
        temp_cross = has_crossed;
        while (temp_cross->next != NULL) {
            if (temp == temp_cross->val) {
                printf("The list is cyclic!!\n");
                return;
            }
            temp_cross = temp_cross->next;
        }
        temp = temp->next;
        cross* new = (cross*)malloc(sizeof(cross));
        new->val = temp;
        new->next = has_crossed;
        has_crossed = new;
    }
    printf("The list is not cyclic.\n");
}

int main(void) {
    node* ll = (node*)malloc(sizeof(node));
    ll->val = 10;
    ll->next = ll;
    identify(ll);
    node* ll2 = (node*)malloc(sizeof(node));
    ll2->val = 90;
    ll2->next = NULL;
    identify(ll2);
}
