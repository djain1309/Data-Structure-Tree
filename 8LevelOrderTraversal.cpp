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

vector<vector<int>> levelOrderTraversal (Node *root, vector<vector<int>>& ans) {
    if (!root) return ans;

    deque <Node*> q;
    
    q.push_back(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> temp;
        for (int i{0}; i < size; i++) {
            Node *curr = q.front();
            q.pop_front();
            temp.push_back(curr->data);
            if (curr->left) {
                q.push_back(curr->left);
            }
            if (curr->right) {
                q.push_back(curr->right);
            }
        }
        ans.push_back(temp);
    }
    return ans;
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
    vector<vector<int>> ans;
    levelOrderTraversal (root, ans);
    for (int i{0}; i<ans.size(); i++) {
        for (int j{0}; j<ans[i].size(); j++) {
            cout << ans[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}