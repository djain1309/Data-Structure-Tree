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

bool isTrue(Node* r, Node* s) {
    if (!r || !s) return (r == s);
    return r->data == s->data 
            && isTrue(r->left, s->left) 
            && isTrue(r->right, s->right);
}

int main () {

    
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->left->right->left = new Node(6);
    root2->right->left = new Node(7);
    root2->right->right = new Node(8);
    root2->right->right->left = new Node(9);
    root2->right->right->right = new Node(10);
    root2->right->right->right->left = new Node(11);



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
    root->right->right->right->left = new Node(11);

    cout << boolalpha << isTrue(root, root2);

    return 0;
}