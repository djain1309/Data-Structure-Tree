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

int maxDepth(Node* root) {
    if (!root) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + max(left, right);
}

int checkBalance(Node *root) {
    if (!root) return 0;
    int lh = checkBalance(root->left);
    if (lh == -1) return -1;
    int rh = checkBalance(root->right);
    if (rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1;
    return 1 + max(lh, rh);
}

int calDia(Node* root, int &dia) {
    if (!root) return 0;
    int lh = calDia(root->left, dia);
    int rh = calDia(root->right, dia);
    dia = max(dia, lh + rh);
    return 1 + max(lh, rh);
}

int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(8);
    root->right->left->left = new Node(5);
    root->right->left->left->left = new Node(6);
    root->right->left->left->left->left = new Node(7);
    int depth = 0;

    // int balH = checkBalance(root);
    // if (balH == -1) {
    //     cout << "UNBALANCE";
    // } else {
    //     cout << "BALANCE";
    // }

    int dia = 0;
    calDia(root, dia);

    cout << "DIAMETER of a tree : " << dia << endl;

    return 0;
}