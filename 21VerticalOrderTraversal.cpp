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


void verticalOrderTraversal(Node* root) {
    if (!root) return;
    queue<pair<Node*, pair<int, int>>> q;
    map<int, map<int, multiset<int>>> nodes;

    q.push({root, {0, 0}});

    while (q.empty() == false) {
        auto curr = q.front();
        q.pop();

        Node* node = curr.first;
        int x = curr.second.first;
        int y = curr.second.second;

        nodes[x][y].insert(node->data);

        if (node->left) {
            q.push({node->left, {x-1, y+1}});
        }
        if (node->right) {
            q.push({node->right, {x+1, y+1}});
        }
    }
    vector<vector<int>> ans;
    for (auto node : nodes) {
        vector<int> col;
        for (auto x : node.second) {
            col.insert(col.end(), x.second.begin(), x.second.end());
        }
        ans.push_back(col);
    }
    for (int i{0}; i < ans.size(); i++) {
        for (int j{0}; j < ans[i].size(); j++) {
            cout << ans[i][j] << "  ";
        }
        cout << endl;
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

    verticalOrderTraversal(root);

    

    return 0;
}