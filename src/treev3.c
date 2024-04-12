#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int val;
	struct tree* left;
	struct tree* right;
	struct tree* father;
} tree;


void insertNode(tree** root, int val, tree* father) {
	if (*root == NULL) {
		*root = malloc(sizeof(tree));
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*root)->father = father;
		return;
	}

	if (val > (*root)->val && ) {
		
	}
}