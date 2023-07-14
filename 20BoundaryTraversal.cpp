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

void printLeftExceptLeaf(Node* root, vector<int>& ans) {
    if ( !root ) return;
    if (root && root->left == nullptr && root->right == nullptr) return;
    ans.push_back(root->data);
    printLeftExceptLeaf(root->left, ans);
    printLeftExceptLeaf(root->right, ans);
    return;
}
void printLeaf(Node* root, vector<int>& ans) {
    if (!root) return;
    printLeaf(root->left, ans);
    if (!root->left && !root->right) {
        ans.push_back(root->data);
    }
    printLeaf(root->right, ans);
    return;
}

void printRightExceptLeafInReverse(Node *root, stack<int>& st) {
    if (!root) return;
    if (root && !root->left && !root->right) return;
    st.push(root->data);
    printRightExceptLeafInReverse(root->left, st);
    printRightExceptLeafInReverse(root->right, st);
    return;
}

/**
 * 
 * Below is the POST ORDER that works perfect
 * 
 * 
void printRightExceptLeafInReverse(Node *root, vector<int>& ans) {
    if (!root) return;
    if (root && !root->left && !root->right) return;
    printRightExceptLeafInReverse(root->left, ans);
    printRightExceptLeafInReverse(root->right, ans);
    ans.push_back(root->data);
    return;
}

************** First we applied : PREORDER
                Then : INORDER
                Then : POSTORDER
*/


void printBoundary(Node *root) {
    if (!root) return;
    vector<int> ans;

    // PUSHED ROOT ONLY
    ans.push_back(root->data);

    // 
    printLeftExceptLeaf(root->left, ans);


    printLeaf(root, ans);


    stack<int> st;
    printRightExceptLeafInReverse(root->right, st);

    
    while (st.empty() == false) {
        ans.push_back(st.top());
        st.pop();
    }
    for (int x : ans) {
        cout << x << "  ";
    }
    return;

}


int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);
    printBoundary(root);
    return 0;
}