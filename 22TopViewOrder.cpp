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

void topViewOrder(Node* root) {
    if (!root) return;
    queue<pair<Node*, int>> q;
    // Queue contains Nodes & VERTICAL LEVEL
    map<int, int> nodes;
    q.push({root, 0});
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        if (nodes.find(curr.second) == nodes.end()) {
            nodes[curr.second] = curr.first->data;
        }
        if (curr.first->left) {
            q.push({curr.first->left, curr.second-1});
        }
        if (curr.first->right) {
            q.push({curr.first->right, curr.second+1});
        }
    }
    vector<int> ans;
    for (auto node : nodes) {
        ans.push_back(node.second);
    }
    for (int x : ans) {
        cout << x << "  ";
    }
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

    topViewOrder(root);

    

    return 0;
}