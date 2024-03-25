#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int val;
    struct tree *left, *right;
} tree;

// Convert an array into a Linked List version of the tree.
tree* Tree(int* base, int* pos, int level) {
    if (level <= 0) {
        return NULL;
    }

    tree* temp = malloc(sizeof(tree));
    temp->val = *pos;
    temp->left = Tree(base, base + 2 * (pos - base) + 1, level - 1);
    temp->right = Tree(base, base + 2 * (pos - base) + 2, level - 1);

    return temp;
}

void pprint(tree* root, int space) {
    if (!root) {
        return;
    }
    space += 5;
    pprint(root->right, space);

    printf("\n");
    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    if (root->val) {
        printf("%d\n", root->val);
    } else {
        printf("NaN\n");
    }
    pprint(root->left, space);
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5, 6, 0, 8, 9, 10, 0, 12, 13, 14, 15};
    tree* root = Tree(a, a, 4);
    pprint(root, 0);
    printf("Done");
    return 0;
}