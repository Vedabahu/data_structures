#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int val;
    struct tree *left, *right;
} tree;

// Helper Functions

tree* newElement(int val)
{
    tree* newRoot = (tree*)malloc(sizeof(tree));
    newRoot->val  = val;
    newRoot->left = newRoot->right = NULL;

    return newRoot;
}

// Traversals

void preOrder(tree* root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d, ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(tree* root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    printf("%d, ", root->val);
    inOrder(root->right);
}

void postOrder(tree* root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d, ", root->val);
}

// BST

tree* searchBST(tree* root, int val)
{
    // Searches the value 'val' in the binary search tree 'root'
    if (root == NULL)
    {
        return root;
    }

    if (root->val == val)
    {
        return root;
    }

    searchBST(root->left, val);
    searchBST(root->right, val);

    return NULL;
}

tree* insertInBST(tree* root, int val)
{
    if (root == NULL)
    {
        return newElement(val);
    }
    else if (root->val > val)
    {
        root->left = insertInBST(root->left, val);
    }
    else if (root->val < val)
    {
        root->right = insertInBST(root->right, val);
    }

    return root;
}

tree* findMin(tree* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

tree* findMax(tree* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

// Some Helpers

bool isLeaf(tree* root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return false;
}

bool hasOneChild(tree* root)
{
    if (root->left == NULL && root->right != NULL)
    {
        return true;
    }
    else if (root->right == NULL && root->left != NULL)
    {
        return true;
    }

    return false;
}

tree* getDad(tree* root, int val)
{
    if (root == NULL || isLeaf(root))
    {
        return root;
    }

    // Single child problem
    if (hasOneChild(root))
    {
        if (root->right == NULL && root->left->val == val)
        {
            return root;
        }
        else if (root->left == NULL && root->right->val == val)
        {
            return root;
        }
    }

    if (root->left->val == val || root->right->val == val)
    {
        return root;
    }

    if (val > root->val)
    {
        return getDad(root->right, val);
    }
    if (val < root->val)
    {
        return getDad(root->left, val);
    }

    return NULL;
}

////////////////////

void deleteNode(tree* root, int val)
{
    // Return of root is null or if root is a leaf node
    if (root == NULL || isLeaf(root))
    {
        return;
    }

    // Dealing with leaf nodes

    // Value is left leaf child
    if (isLeaf(root->left) && root->left->val == val)
    {
        free(root->left);
        root->left = NULL;
        return;
    }
    // Value is right leaf child
    else if (isLeaf(root->right) && root->right->val == val)
    {
        free(root->right);
        root->right = NULL;
        return;
    }

    // Dealing with single child problem

    // Left child has one child
    if (hasOneChild(root->left) && root->left->val == val)
    {
        tree* temp = root->left;
        // temp has the left child
        if (temp->right == NULL)
        {
            root->left = temp->left;
        }
        // temp has right child
        else if (temp->left == NULL)
        {
            root->left = temp->right;
        }

        free(temp);
    }
    // right child has one child
    else if (hasOneChild(root->right) && root->right->val == val)
    {
        tree* temp = root->right;
        // temp has the left child
        if (temp->right == NULL)
        {
            root->right = temp->left;
        }
        // temp has right child
        else if (temp->left == NULL)
        {
            root->right = temp->right;
        }

        free(temp);
    }

    // Dealing with multiple children problem

    if (root->val == val)
    {
        tree* replacement = findMax(root->left);
        tree* temp        = getDad(root, replacement->val);
        if (temp == NULL)
        {
            printf("Can not delete the root node!\n");
            return;
        }
        root->val   = replacement->val;
        temp->right = NULL;
        free(replacement);
    }

    if (val > root->val)
    {
        deleteNode(root->right, val);
    }
    else if (val < root->val)
    {
        deleteNode(root->left, val);
    }

    return;
}

void pprint(tree* root, int space)
{
    // Pretty printing the BST
    if (root == NULL)
    {
        return;
    }

    space += 5;
    pprint(root->right, space);

    printf("\n");
    for (int i = 0; i < space; i++)
    {
        printf(" ");
    }
    if (root)
    {
        printf("%d\n", root->val);
    }
    else
    {
        printf("NaN\n");
    }

    pprint(root->left, space);
}

// AVL Tree

int avlHeight(tree* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int height_left  = 0;
    int height_right = 0;

    if (root->left != NULL)
    {
        height_left = avlHeight(root->left);
    }
    if (root->right != NULL)
    {
        height_right = avlHeight(root->right);
    }

    return height_right > height_left ? ++height_right : ++height_left;
}

int avlBalancingFactor(tree* root)
{
    int bf = 0;

    if (root->left != NULL)
    {
        bf += avlHeight(root->left);
    }
    if (root->right != NULL)
    {
        bf -= avlHeight(root->right);
    }

    return bf;
}

tree* avl_Left_Left_Rotate(tree* root)
{
    tree* a  = root;
    tree* b  = a->left;

    a->left  = b->right;
    b->right = a;

    return b;
}

tree* avl_Right_Right_Rotate(tree* root)
{
    tree* a  = root;
    tree* b  = a->right;

    a->right = b->left;
    b->left  = a;

    return b;
}

tree* avl_Left_Right_Rotate(tree* root)
{
    tree* a  = root;
    tree* b  = a->left;
    tree* c  = b->right;

    a->left  = c->right;
    b->right = c->left;
    c->left  = b;
    c->right = a;

    return c;
}

tree* avl_Right_Left_Rotate(tree* root)
{
    tree* a  = root;
    tree* b  = a->right;
    tree* c  = b->left;

    a->right = c->left;
    b->left  = c->right;
    c->right = b;
    c->left  = a;

    return c;
}

tree* avl_balance_node(tree* root)
{
    tree* newRoot = NULL;

    if (root->left != NULL)
    {
        root->left = avl_balance_node(root->left);
    }

    if (root->right != NULL)
    {
        root->right = avl_balance_node(root->right);
    }

    int bf = avlBalancingFactor(root);

    if (bf >= 2)
    {
        if (avlBalancingFactor(root->left) <= -1)
        {
            newRoot = avl_Left_Right_Rotate(root);
        }
        else
        {
            newRoot = avl_Left_Left_Rotate(root);
        }
    }
    else if (bf <= -2)
    {
        if (avlBalancingFactor(root->right) >= 1)
        {
            newRoot = avl_Right_Left_Rotate(root);
        }
        else
        {
            newRoot = avl_Right_Right_Rotate(root);
        }
    }
    else
    {
        newRoot = root;
    }

    return newRoot;
}

void avl_balance(tree** root)
{
    tree* newRoot = avl_balance_node(*root);

    if (newRoot != *root)
    {
        *root = newRoot;
    }
}

tree* avl_insert_element(tree** root, int val)
{
    if (*root == NULL)
    {
        return newElement(val);
    }
    else if ((*root)->val > val)
    {
        (*root)->left = avl_insert_element(&((*root)->left), val);
    }
    else if ((*root)->val < val)
    {
        (*root)->right = avl_insert_element(&((*root)->right), val);
    }

    avl_balance(root);

    return *root;
}

tree* avl_search(tree* root, int val) { return searchBST(root, val); }

void avl_delete(tree** root, int val)
{
    deleteNode(*root, val);
    avl_balance(root);
}

/////////////

int main(void)
{
    // tree* root         = newElement(1);
    // root->left         = newElement(2);
    // root->right        = newElement(3);
    // root->left->left   = newElement(4);
    // root->left->right  = newElement(5);
    // root->right->left  = newElement(6);
    // root->right->right = newElement(7);

    // tree* BST          = NULL;
    // BST                = insertInBST(BST, 8);
    // insertInBST(BST, 4);
    // insertInBST(BST, 10);
    // insertInBST(BST, 2);
    // insertInBST(BST, 6);
    // insertInBST(BST, 9);
    // insertInBST(BST, 11);
    // insertInBST(BST, 1);
    // insertInBST(BST, 3);
    // insertInBST(BST, 5);
    // insertInBST(BST, 7);
    // insertInBST(BST, 12);

    // pprint(BST, 5);

    // deleteNode(BST, 4);
    // printf("\n\n\n");

    // pprint(BST, 5);

    // tree* AVL = NULL;
    // AVL       = avl_insert_element(&AVL, 1);
    // avl_insert_element(&AVL, 2);
    // avl_insert_element(&AVL, 3);

    tree* AVL = NULL;
    AVL       = avl_insert_element(&AVL, 21);
    avl_insert_element(&AVL, 26);
    avl_insert_element(&AVL, 30);
    avl_insert_element(&AVL, 9);
    avl_insert_element(&AVL, 4);
    avl_insert_element(&AVL, 14);
    avl_insert_element(&AVL, 28);
    avl_insert_element(&AVL, 18);
    avl_insert_element(&AVL, 15);
    avl_insert_element(&AVL, 10);
    avl_insert_element(&AVL, 2);
    avl_insert_element(&AVL, 3);
    avl_insert_element(&AVL, 7);

    pprint(AVL, 5);

    return 0;
}
