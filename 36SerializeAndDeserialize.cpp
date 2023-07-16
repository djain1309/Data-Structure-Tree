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

string serialization (Node* root) {
    if (!root) return "#";

    string ans = "";
    deque <Node *> q;
    q.push_back(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop_front();
        if (!curr) ans.append("#,");
        else {
            ans.append(to_string(curr->data) + ',');
        }
        if (curr) {
            q.push_back(curr->left);
            q.push_back(curr->right);
        }
    }
    cout << ans << endl;
    return ans;
}

Node* deserialization (string& data) {
    if (data.size() == 0) return nullptr;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    deque <Node*> q;
    Node* root = new Node(stoi(str));
    q.push_back(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop_front();

        getline(s, str, ',');
        if (str == "#") {
            curr->left = nullptr;
        } else {
            Node* leftNode = new Node(stoi(str));
            curr->left = leftNode;
            q.push_back(leftNode);
        }

        getline(s, str, ',');
        if (str == "#") {
            curr->right = nullptr;
        } else {
            Node* rightNode = new Node(stoi(str));
            curr->right = rightNode;
            q.push_back(rightNode);
        }
    }
    return root;
}

int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    string serialized = serialization(root);

    Node *root1 = deserialization(serialized);
    cout << root1->data << endl;
    cout << root1->left->data << endl;
    cout << root1->right->data << endl;
    cout << root1->right->left->data << endl;
    cout << root1->right->right->data << endl;

    return 0;
}