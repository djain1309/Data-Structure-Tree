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

int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right= new Node(7);
    root->right->left = new Node(8);
    root->right->right = new Node(9);
    Node *n1 = new Node (5);
    Node *n2 = new Node (6);

    Node* lca = findLCA(n1, n2, root);
    cout << "LCA = " << lca->data << endl;

    return 0;
}