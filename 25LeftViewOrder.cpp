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

void LeftView (Node* root) {
    if (!root) return;

    deque <pair<Node *, int>> q;
    map <int, Node*> nodes;

    q.push_back({root, 0});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop_front();
        int level = curr.second;
        nodes[level] = curr.first;
        if (curr.first->right) {
            q.push_back({curr.first->right, level+1});
        }
        if (curr.first->left) {
            q.push_back({curr.first->left, level+1});
        }
    }
    for (auto node : nodes) {
        cout << node.second->data << "  ";
    }

}


int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left= new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    LeftView(root);

    return 0;
}