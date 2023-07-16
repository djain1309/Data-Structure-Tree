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

Node* constructBTFromInAndPost(vector<int>& inOrder, int inStart, int inEnd, map<int, int>& inMap,
                                vector<int>& postOrder, int postStart, int postEnd) {

    if (inStart > inEnd || postStart > postEnd) return nullptr;

    Node* root = new Node(postOrder[postEnd]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;
    root->left = constructBTFromInAndPost(inOrder, inStart, inRoot-1, inMap,
                                        postOrder, postStart, postStart+numsLeft-1);
    
    root->right = constructBTFromInAndPost(inOrder, inRoot+1, inEnd, inMap,
                                        postOrder, postStart+numsLeft, postEnd-1);
    
    return root;

}

int main () {

    vector<int> inOrder = {40, 20, 50, 10, 60, 30};
    vector<int> postOrder = {40, 50, 20, 60, 30, 10};

    map <int, int> inMap;
    for (int i{0}; i < inOrder.size(); i++) {
        inMap[inOrder[i]] = i;
    }

    Node* root = constructBTFromInAndPost(inOrder, 0, inOrder.size()-1, inMap,
                                            postOrder, 0, postOrder.size()-1);

    cout << root->data << endl; 
    cout << root->left->data << endl; 
    cout << root->right->data << endl; 
    cout << root->left->left->data << endl; 
    cout << root->left->right->data << endl; 
    cout << root->right->left->data << endl; 

    return 0;
}