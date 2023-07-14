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

void topView (Node* root) {
    if (!root) return;
    deque <pair<Node*, int>> q;
    map <int, Node*> nodes;
    q.push_back({root, 0});
    while (!q.empty()) {
        pair<Node *, int> curr = q.front();
        q.pop_front();
        if (nodes.find(curr.second) == nodes.end()) {
            nodes[curr.second] = curr.first;
        }
        int vertical = curr.second;
        if (curr.first->left) {
            q.push_back({curr.first->left, vertical-1});
        }
        if (curr.first->right) {
            q.push_back({curr.first->right, vertical+1});
        }
    }
    for (auto node : nodes) {
        cout << node.second->data << "  ";
    }
    return;
}


int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(10);

    topView(root);

    return 0;
}