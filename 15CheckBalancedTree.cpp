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

int check(Node* root) {
    if (!root) return 0;

    int lh = check(root->left);
    if (lh == -1) return -1;
    
    int rh = check(root->right);
    if (rh == -1) return -1;

    if (abs(lh - rh) > 1) {
        return -1;
    }
    return 1 + max(lh, rh);

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

    int h = check(root);
    if (h == -1) cout << "NOT A BALANCED TREE";
    else cout << "BALANCED TREE";

    return 0;
}