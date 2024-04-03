// height of the binary tree
#include <stdio.h>
#include <stdlib.h>

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

void getHeight(tree* root, int count, int* height) {
    if (!root) {
        return;
    }

    if (++count > *height) {
        *height = count;
    }

    getHeight(root->left, count, height);
    getHeight(root->right, count, height);
    return;
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 15};
    int height = 0;
    getHeight(Tree(a, a, 4), 0, &height);
    printf("The height of the tree is: %d", height);
}