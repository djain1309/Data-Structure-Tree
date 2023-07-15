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

int maxWidth(Node* root) {
    if (!root) return 0;
    deque <pair<Node*, int>> q;
    q.push_back({root, 0});
    int ans = 0;
    while (!q.empty()) {
        int size = q.size();
        cout << "SIZE = " << size << endl;
        int mini = q.front().second;
        cout << "MINi = " << mini << endl;

        int first, last;

        for (int i{0}; i < size; i++) {
            int curr_id = q.front().second - mini;
            Node* node = q.front().first;
            q.pop_front();
            if (i == 0) {
                first = curr_id;
            } 
            if (i == size - 1) {
                last = curr_id;
            }
            if (node->left) {
                q.push_back({node->left, 2 * curr_id + 1});
            }
            if (node->right) {
                q.push_back({node->right, 2 * curr_id + 2});
            }
            ans = max(ans, last - first + 1);
        }
    }
    return ans;
}

int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->right->right = new Node(4);

    int maxWidthOfBinaryTree = maxWidth(root);
    cout << "Max Width Of Binary Tree = " << maxWidthOfBinaryTree << endl;

    return 0;
}