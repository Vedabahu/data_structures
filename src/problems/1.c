// Determine is 2 trees are identicle
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool flag = true;

typedef struct tree {
    int val;
    struct tree *left, *right;
} tree;

tree* Tree(int* arr, int* pos, int level) {
    if (!level) {
        return NULL;
    }
    tree* root = malloc(sizeof(tree));
    root->val = *pos;
    root->left = Tree(arr, arr + 2 * (pos - arr) + 1, level - 1);
    root->right = Tree(arr, arr + 2 * (pos - arr) + 2, level - 1);
    return root;
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

void checkValues(tree* root1, tree* root2) {
    if ((!root1 || !root2) && (root1 == root2)) {
        return;
    }
    if (!root1 || !root2) {
        flag = false;
        return;
    }

    if (root1->val != root2->val) {
        flag = false;
        return;
    }

    checkValues(root1->left, root2->left);
    checkValues(root1->right, root2->right);
    return;
}

int main(void) {
    int l1;
    printf("Enter the level of the first tree: ");
    scanf("%d", &l1);
    int size = pow(2, l1) - 1;
    int t1[size];
    printf("Enter the elements of the tree : ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &t1[i]);
    }

    int l2;
    printf("Enter the level of the second tree: ");
    scanf("%d", &l2);
    size = pow(2, l2) - 1;
    int t2[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &t2[i]);
    }

    checkValues(Tree(t1, t1, l1), Tree(t2, t2, l2));

    if (flag) {
        printf("\nThe Trees are equal.\n");
    } else {
        printf("\nThe Trees are not equal.\n");
    }

    return 0;
}
