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

int timeToBurn (Node* root, Node* toBurn) {
    if (!root) return 0;

    // Perform BFS to find the parents of all Elements

    unordered_map <Node*, Node*> parent_track;
    deque <Node*> q;
    q.push_back(root);
    parent_track[root] = nullptr;

    while (!q.empty()) {

        Node *curr = q.front();
        q.pop_front();

        if (curr->left) {
            q.push_back(curr->left);
            parent_track[curr->left] = curr;
        }
        if (curr->right) {
            q.push_back(curr->right);
            parent_track[curr->right] = curr;
        }
    }
    // for (auto x : parent_track) {
    //     x.second->data && cout << "child " << x.first->data << " & Parent = " << x.second->data << endl;
    // }

    // Find the time to burn the BT
    // And it goes Radially

    int time = 0;
    unordered_map <Node*, bool> visited;
    q.push_back(toBurn);
    visited[toBurn] = true;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop_front();
            
            if (curr->left && !visited[curr->left]) {
                q.push_back(curr->left);
                visited[curr->left] = true;
            }
            if (curr->right && !visited[curr->right]) {
                q.push_back(curr->right);
                visited[curr->right] = true;
            }
            if (parent_track.find(curr) != parent_track.end() && !visited[parent_track[curr]] && 
                !visited[parent_track[curr]->left] && !visited[parent_track[curr]->right])
                 {
                q.push_back(parent_track[curr]);
                visited[parent_track[curr]] = true;
            }
        }
        time++;
        
    }
    return time;
}

int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    Node* toBurn = root->left->left;
    int time = 0;

    time = timeToBurn(root, toBurn);
    cout << "Time to burn the BT = " << time << endl;

    return 0;
}