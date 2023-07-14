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


void dfs(Node* root) {
    if (!root) return;
    deque<Node*> q;
    q.push_back(root);
    while (q.empty() == false) {
        Node *curr = q.front();
        cout << curr->data << endl;
        q.pop_front();
        if (curr->left) {
            q.push_front(curr->left);
        }
        if (curr->right) {
            q.push_front(curr->right);
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

    dfs(root);

    return 0;
}