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

void inOrder(Node *root) {
    if (!root) return;
    stack<Node*> st;
    while (true) {
        if (root != nullptr) {
            st.push(root);
            root = root->left;
        } else {
            if (st.empty()) break;
            root = st.top();
            st.pop();
            cout << root->data << " ";
            root = root->right;
        }
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

    inOrder(root);

    return 0;
}