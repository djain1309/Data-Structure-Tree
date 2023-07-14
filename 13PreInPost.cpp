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


void allOrder(Node* root) {

    stack<pair<Node*, int>> st;

    st.push({root, 1});

    vector<int> pre, in, post;

    while (st.empty() == false) {
        auto curr = st.top();
        st.pop();
        if (curr.second == 1) {
            // PRE
            pre.push_back(curr.first->data);
            curr.second++;
            st.push(curr);
            // Push the LEFT of curr
            if (curr.first->left) {
                st.push({curr.first->left, 1});
            }
        } else if (curr.second == 2) {
            // INORDER
            in.push_back(curr.first->data);
            curr.second++;
            st.push(curr);
            // PUSH RIGHT 
            if (curr.first->right) {
                st.push({curr.first->right, 1});
            }
        } else {
            // POST
            post.push_back(curr.first->data);
        }

    }
    cout << "INORDER : ";
    for (int x : in) {
        cout << x << "  ";
    }
    cout << endl << "PREORDE : ";
    for (int x : pre) {
        cout << x << "  ";
    }
    cout << endl << "POSTORD : ";
    for (int x : post) {
        cout << x << "  ";
    }

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

    allOrder(root);

    return 0;
}