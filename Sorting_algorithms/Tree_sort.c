#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* create_node(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) return create_node(data);
    
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    
    return root;
}

void inorder_traversal(struct TreeNode* root, int* arr, int* index) {
    if (root != NULL) {
        inorder_traversal(root->left, arr, index);
        arr[(*index)++] = root->data;
        inorder_traversal(root->right, arr, index);
    }
}

void tree_sort(int arr[], int n) {
    struct TreeNode* root = NULL;
    
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    int index = 0;
    inorder_traversal(root, arr, &index);
}
