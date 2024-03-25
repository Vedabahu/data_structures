// Delete even nodes in circular double linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

int count = 0;

void insert_front(Node** head, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (count == 0) {}
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = *head;
    *head = new_node;
}

void insert_end(Node* head, int val) {
    Node* temp = (Node*)malloc(sizeof(Node));

    temp->val = val;
    temp->right = NULL;
    while (head->right != NULL) {
        head = head->right;
    }
    temp->left = head;
    head->right = temp;
}

void insert_at_position(Node** head, int val, int pos) {
    if (*head == NULL || pos == 1) {
        insert_front(head, val);
        return;
    }
    pos--;
    while (pos--) {
        if (*head == NULL) {
            break;
        }
        (*head) = (*head)->right;
    }
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = val;
    temp->left = (*head);
    temp->right = (*head)->right;
    (*head)->right->left = temp;
    (*head)->right = temp;
}

void delete_front(Node** head) {
    if (*head == NULL) {
        printf("No element to delete.\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->right;
    (*head)->left = NULL;
    printf("Element %d has been deleted.\n", temp->val);
    free(temp);
}

void delete_at_the_end(Node* head) {
    if (head == NULL) {
        printf("Nothing to delete.\n");
        return;
    }

    while (head->right->right != NULL) {
        head = head->right;
    }
    printf("Element %d has been deleted.\n", head->right->val);
    free(head->right);
    head->right = NULL;
}

void delete_at_position(Node** head, int* position) {
    if (*position <= 1) {
        delete_front(head);
        return;
    }
    Node* temp = *head;
    while (*position >= 1) {
        if (temp == NULL) {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->right;

        (*position)--;
    }
    printf("Element %d has been deleted.\n", temp->val);
    temp->left->right = temp->right;
    temp->right->left = temp->left;
    free(temp);
}

void display(Node* head) {
    if (head == NULL) {
        printf("Nothing to display.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->right;
    }
    printf("NULL\n");
}

void delete_even(Node* head) {
    Node* temp = head;
    while (temp->right != head) {
        temp->right = temp->right->right;
        free(temp->right->left);
        temp->right->left = temp;
    }
}

int main(void) {
    Node *doubly_linked_list = NULL, *temp = NULL;
    while (1) {
        printf("\nChoose : \n");
        printf(" 1 : Insert Front an elment.\n");
        printf(" 2 : Insert from the Back an elment.\n");
        printf(" 3 : Insert at position an elment.\n");
        printf(" 4 : Delete Front an element.\n");
        printf(" 5 : Delete from the Back an element.\n");
        printf(" 6 : Delete at position an element.\n");
        printf(" 7 : Display the list.\n");
        printf(" 8 : Exit from program.\n");
        printf(" 9 : Delete even nodes.\n");

        printf("Enter your choice : ");

        int choice, number, pos;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number : ");
                scanf("%d", &number);
                insert_front(&doubly_linked_list, number);
                break;
            case 2:
                printf("Enter a number : ");
                scanf("%d", &number);
                insert_end(doubly_linked_list, number);
                break;
            case 3:
                printf("Enter a number : ");
                scanf("%d", &number);
                printf("Enter a position : ");
                scanf("%d", &pos);
                insert_at_position(&doubly_linked_list, number, pos);
                break;
            case 4: delete_front(&doubly_linked_list); break;
            case 5: delete_at_the_end(doubly_linked_list); break;
            case 6:
                printf("Enter a position : ");
                scanf("%d", &pos);
                delete_at_position(&doubly_linked_list, &pos);
                break;
            case 7: display(doubly_linked_list); break;
            case 8:
                while (doubly_linked_list) {
                    Node* temp = doubly_linked_list;

                    doubly_linked_list =

                        doubly_linked_list->right;
                    free(temp);
                }
                return 0;
            case 9:

                delete_even(doubly_linked_list);
                printf("\nDeleted!\n");
                break;
            default: printf("Enter a correct choice please.\n");
        }
    }
}