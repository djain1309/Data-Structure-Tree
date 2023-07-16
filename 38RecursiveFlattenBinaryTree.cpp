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

void RecursivelyFlattenBinaryTree(Node* root, Node** prev) {
    if (!root) return;

    RecursivelyFlattenBinaryTree(root->right, prev);
    RecursivelyFlattenBinaryTree(root->left, prev);

    root->right = *prev;
    root->left = nullptr;
    *prev = root;

}

int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    Node* prev = nullptr;
    RecursivelyFlattenBinaryTree(root, &prev);

    while (root) {
        cout << root->data << " -> ";
        root = root->right;
    }

    return 0;
}


/***************CHAT GPT SOLLUTION*******************/

/**
 * 
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* RecursiveFlattenBinaryTree(Node* root) {
    if (!root) return nullptr;
    if (!root->left && !root->right) return root;

    Node* leftTail = RecursiveFlattenBinaryTree(root->left);
    Node* rightTail = RecursiveFlattenBinaryTree(root->right);

    if (leftTail) {
        leftTail->right = root->right;
        root->right = root->left;
        root->left = nullptr;
    }

    return rightTail ? rightTail : leftTail;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    RecursiveFlattenBinaryTree(root);

    while (root) {
        cout << root->data << endl;
        root = root->right;
    }

    return 0;
}

*/