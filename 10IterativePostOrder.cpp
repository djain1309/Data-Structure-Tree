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


void iterativePostOrder(Node *root) {
    if (!root) return;
    stack<Node *> stk1;
    stack<Node *> stk2;
    stk1.push(root);
    while (stk1.empty() == false) {
        Node *curr = stk1.top();
        stk2.push(curr);
        stk1.pop();
        if (curr->left) {
            stk1.push(curr->left);
        }
        if (curr->right) {
            stk1.push(curr->right);
        }
    }
    while (stk2.empty() == false) {
        cout << stk2.top()->data << " ";
        stk2.pop();
    }
}


int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    iterativePostOrder(root);

    return 0;
}