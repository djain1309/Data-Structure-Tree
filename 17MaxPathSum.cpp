#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node (int value) {
        data = value;
        left = right = nullptr;
    }
};

int maxPathSum(Node* root, int& maxSum) {
    if (!root) return 0;
    int currSum = 0;
    int ls = maxPathSum(root->left, maxSum);
    int rs = maxPathSum(root->right, maxSum);
    currSum = max(root->data, max(ls + root->data, rs + root->data));
    maxSum = max(ls+rs+root->data, max(maxSum, currSum));
    return currSum;
}

int main () {

    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    int maxSum = -1e9;

    maxPathSum(root, maxSum);
    cout << "MAX Path Sum = " << maxSum;

    return 0;
}