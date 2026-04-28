#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return newNode(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    
    return root;
}

int findLCA(Node* root, int n1, int n2) {
    while (root != NULL) {
        if (root->data > n1 && root->data > n2)
            root = root->left;
        else if (root->data < n1 && root->data < n2)
            root = root->right;
        else
            return root->data;
    }
    return -1;
}

int main() {
    int N;
    scanf("%d", &N);
    
    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }
    
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    
    int lca = findLCA(root, n1, n2);
    printf("%d\n", lca);
    
    return 0;
}