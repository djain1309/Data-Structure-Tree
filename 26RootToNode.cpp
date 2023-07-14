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



bool printRootToNodePath(Node* root, Node* toFind, vector<int>& path ) {
    if (!root) return false;
    path.push_back(root->data);
    if (root->data == toFind->data) {
        return true;
    }

    bool left = printRootToNodePath(root->left, toFind, path);
    bool right = printRootToNodePath(root->right, toFind, path);
    if (!left && !right) {
        path.pop_back();
    }
    return left || right;
};

int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    Node* toFind = new Node(3);
    vector<int> path;
    printRootToNodePath(root, toFind, path);
    for (int x : path) {
        cout << x << "  ";
    }

    return 0;
}