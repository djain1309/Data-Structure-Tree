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

Node* constructBinaryTree(vector<int>& inOrder, int inStart, int inEnd, 
                            vector<int>& preOrder, int preStart, int preEnd, map <int, int>& inMap) {

    if (preStart > preEnd || inStart > inEnd) return nullptr;
    
    Node* root = new Node(preOrder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = constructBinaryTree(inOrder, inStart, inRoot-1, preOrder, 
                                        preStart+1, preStart+numsLeft, inMap);

    root->right = constructBinaryTree(inOrder, inRoot + 1, inEnd, preOrder,
                                        preStart+numsLeft+1, preEnd, inMap);
    
    return root;
}


int main () {

    vector<int> inOrder = {9, 3, 15, 20, 7};
    vector<int> preOrder = {3, 9, 20, 15, 7};

    map <int, int> inMap;
    for (int i{0}; i < inOrder.size(); i++) {
        inMap[inOrder[i]] = i;
    }

    Node* root = constructBinaryTree(inOrder, 0, inOrder.size()-1, preOrder, 0, preOrder.size()-1, inMap);
    cout << root->data << endl;
    cout << root->left->data << endl;
    return 0;
}