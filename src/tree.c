#include <stdio.h>
#include <stdlib.h>

#define COUNT 2

typedef struct node {
    int val;
    struct node *left, *right;
} node;

node* addNode(int val) {
    node* temp = malloc(sizeof(node));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void configureNode(node* root, node* tree1, node* tree2) {
    root->left = tree1;
    root->right = tree2;
}

void pprint_super(node* root, int space) {
    if (root == NULL) {
        return;
    }

    space += COUNT;

    pprint_super(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf("\t");
        printf("%d\n", root->val);
    }

    pprint_super(root->left, space);
}

void pprint(node* root) { pprint_super(root, 0); }

int main(void) {

    node* tree1 = addNode(1);
    node* tree2 = addNode(1);
    node* tree3 = addNode(1);
    configureNode(tree1, tree2, tree3);

    pprint(tree1);

    return 0;
}