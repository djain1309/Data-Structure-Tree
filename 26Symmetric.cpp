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

bool checkSymmetry (Node* left, Node* right) {
    if ((!left && right) || (left && !right) ||(left && right && left->data != right->data)) return false;
    if (!left && !right) return true;
    return (checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left));
}

int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    bool check = checkSymmetry(root->left, root->right);
    if (check) {
        cout << "Tree is Symmetric";
    } else {
        cout << "NOT SYMMETRIC";
    }
    return 0;
}