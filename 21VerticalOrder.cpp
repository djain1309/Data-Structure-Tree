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
    deque <pair<Node*, pair<int, int>>> q;
    //          node,  vertical, level
    map<int, map<int, multiset<int>>> nodes;
    //  vertical, level,      nodes

    vector<vector<int>> ans;

    q.push_back({root, {0, 0}});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop_front();
        int y = curr.second.first;
        int x = curr.second.second;
        nodes[y][x].insert(curr.first->data);
        if (curr.first->left) {
            q.push_back({curr.first->left, {y-1, x+1}});
        }
        if (curr.first->right) {
            q.push_back({curr.first->right, {y+1, x+1}});
        }
    }
    for (auto node : nodes) {
        vector<int> col;
        for (auto x : node.second) {
            col.insert(col.end(), x.second.begin(), x.second.end());
        }
        ans.push_back(col);
    }
    for(int i{0}; i<ans.size(); i++) {
        for (int j{0}; j<ans[i].size(); j++) {
            cout << ans[i][j] <<"  ";
        }
        cout << endl;
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

    verticalOrderTraversal(root);

    return 0;
}