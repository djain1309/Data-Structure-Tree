#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

void printZigZag(Node *root)
{
    if (!root)
        return;
    deque<Node *> q;
    bool ltr = true; // LEFT TO RIGHT
    vector<vector<int>> ans;

    q.push_back(root);
    while (q.empty() == false)
    {
        int size = q.size();
        vector<int> row(size); 
        for (int i{0}; i < size; i++) {

            Node *curr = q.front();
            q.pop_front();
            int index = ltr ? i : size - i - 1;

            row[index] = curr->data;
            if (curr->left) {
                q.push_back(curr->left);
            }
            if (curr->right) {
                q.push_back(curr->right);
            }
        }
        ltr = !ltr;
        ans.push_back(row);
    }
    for (int i{0}; i < ans.size(); i++) {
        for (int j{0}; j < ans[i].size(); j++) {
            cout << ans[i][j] << "  ";
        }
        cout << endl;
    }
    return;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    printZigZag(root);



    return 0;
}