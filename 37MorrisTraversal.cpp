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


void morrisTraversalInOrder (Node* root) {
    if (!root) return;
    vector<int> inOrder;
    Node* curr = root;

    while (curr != nullptr) {

        // If left doesn't exist then simply move right
        if (!curr->left) {
            inOrder.push_back(curr->data);
            curr = curr->right;
        } else {
            // If left EXISTS, then point the left's RightMost node to current node 
            // then move left
            Node* prev = curr->left;
            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }

            // After the while command there are 2 possibilities:
            // 1 ) It can go back to curr due to previous thread connection if already exists
            //     In that case, its the root and needs to be pushed
            //     And move current to Right
            // 2 ) It can reach to nullptr, means no more right exists.
            //     In that case, make a threaded connection from prev->right = curr
            //     And move curr to curr->left
            if (prev->right == curr) {
                inOrder.push_back(curr->data);
                prev->right = nullptr; 
                curr = curr->right;
            } else if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            }
        }
    }
    for (int x : inOrder) {
        cout << x << "  ";
    }
}



void morrisTraversalPREOrder (Node* root) {
    if (!root) return;
    vector<int> preOrder;
    Node* curr = root;

    while (curr != nullptr) {

        // If left doesn't exist then simply move right
        if (!curr->left) {
            preOrder.push_back(curr->data);
            curr = curr->right;
        } else {
            // If left EXISTS, then point the left's RightMost node to current node 
            // then move left
            Node* prev = curr->left;
            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }

            // After the while command there are 2 possibilities:
            // 1 ) It can go back to curr due to previous thread connection if already exists
            //     In that case, its the root and needs to be pushed
            //     And move current to Right
            // 2 ) It can reach to nullptr, means no more right exists.
            //     In that case, make a threaded connection from prev->right = curr
            //     And move curr to curr->left
            if (prev->right == curr) {
                prev->right = nullptr; 
                curr = curr->right;
            } else if (prev->right == nullptr) {
                prev->right = curr;
                preOrder.push_back(curr->data);
                curr = curr->left;
            }
        }
    }
    cout << endl;
    for (int x : preOrder) {
        cout << x << "  ";
    }
}


int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    morrisTraversalInOrder(root);
    morrisTraversalPREOrder(root);

    return 0;
}