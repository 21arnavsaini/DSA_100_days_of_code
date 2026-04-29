#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    TreeNode* root = newNode(arr[0]);
    TreeNode* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        TreeNode* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (root == NULL || root->val == n1 || root->val == n2)
        return root;

    TreeNode* left = findLCA(root->left, n1, n2);
    TreeNode* right = findLCA(root->right, n1, n2);

    if (left && right)
        return root;

    return left ? left : right;
}

int main() {
    int N;
    scanf("%d", &N);

    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    TreeNode* root = buildTree(arr, N);
    TreeNode* lca = findLCA(root, n1, n2);

    if (lca)
        printf("%d\n", lca->val);
    else
        printf("-1\n");

    return 0;
}