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

int findLeftHeight (Node *root) {
    if (!root) return 0;
    int height = 0;
    while (root) {
        height++;
        root = (root->left);
    }
    return height;

}

int findRightHeight (Node *root) {
    if (!root) return 0;
    int height = 0;
    while (root) {
        height++;
        root = (root->right);
    }
    return height;
}


int countNodes (Node* root) {
    if (!root) return 0;

    // Formula is 2^h - 1;

    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    if (lh == rh) {
        return (1 << lh) - 1;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    return 0;
}


int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    root->left->left->left= new Node(8);
    root->left->left->right= new Node(9);
    root->left->right->left= new Node(10);
    root->left->right->right= new Node(11);
    
    int counts = countNodes(root);
    cout << "Total Nodes = " << counts << endl;

    return 0;
}