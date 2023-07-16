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

Node* findLCA(Node* n, Node* m, Node* root) {
    if (!root || root->data == n->data || root->data == m->data) {
        return root;
    }

    Node* left = findLCA(n, m, root->left);
    Node* right = findLCA(n, m, root->right);

    if (left == nullptr) {
        return right;
    }
    else if (right == nullptr) {
        return left;
    } else {
        return root;
    }

    return nullptr;

}

void childSum(Node* &root) {
    if (!root) return;
    int child = 0;
    if (root->left) {
        child += root->left->data;
    } 
    if (root->right) {
        child += root->right->data;
    }
    if (child >= root->data) {
        root->data = child;
    } else {
        if (root->left) {
            root->left->data = child;
        } 
        if (root->right) {
            root->right->data = child;
        }
    }
    childSum(root->left);
    childSum(root->right);
    int total = 0;
    if (root->left) {
        total += root->left->data;
    }
    if (root->right) {
        total += root->right->data;
    }
    if (root->left || root->right) {
        root->data = total;
    }
    return;
}

int main () {

    Node* root = new Node(2);
    root->left = new Node(35);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(2);

    childSum(root);
    cout << "root = " << root->data << endl;
    cout << root->left->data << endl;
    cout << root->right->data << endl;
    cout << root->left->left->data << endl;
    cout << root->left->right->data << endl;
    cout << root->right->left->data << endl;
    cout << root->right->right->data << endl;

    return 0;
}