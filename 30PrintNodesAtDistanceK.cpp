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

void PrintNodesAtDistanceK(Node* root, Node* toFind, int k) {
    if (!root) return;
    deque <Node*> q;
    unordered_map <Node*, Node*> parent_track;

    // RUN BFS to keep track of the parents;
    q.push_back(root);
    parent_track[root] = nullptr;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop_front();

        if (curr->left) {
            parent_track[curr->left] = curr;
            q.push_back(curr->left);
        }
        if (curr->right) {
            parent_track[curr->right] = curr;
            q.push_back(curr->right);
        }
    }

    // Now go RADIALLy & mark VISITED
    unordered_map <Node*, bool> visited;
    int distance = 0;
    q.push_back(toFind);
    visited[toFind] = true;

    while (!q.empty()) {

        int size = q.size();

        // Printing when distance reaches to k
        if (distance == k) {
            cout << "NODES AT distance " << k << " : ";
            while (size--) {
                cout << q.front()->data << " ";
                q.pop_front();
            }
            cout << endl;
            break;
        }

        while (size--) {
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
            Node *parent = parent_track[curr];
            if (parent && !visited[parent]) {
                q.push_back(parent);
                visited[parent] = true;
            }
        }
        distance++;
    }
}

int main () {

    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    Node* toFind = root->left;
    int distance = 3;
    PrintNodesAtDistanceK(root, toFind, distance);

    return 0;
}
