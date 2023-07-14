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

int Diameter(Node* root, int& dia) {
    if (!root) return 0;
    int left = Diameter(root->left, dia);
    int right = Diameter(root->right, dia);
    dia = max(left + right, dia);
    return 1 + max(left, right);
}


int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left->left = new Node(5);
    root->right->left->left->left = new Node(9);
    root->right->right->right = new Node(7);
    root->right->right->right->right = new Node(8);
    int dia = 0;
    Diameter(root, dia); 
    cout << "Diameter TREE = " << dia;

    return 0;
}