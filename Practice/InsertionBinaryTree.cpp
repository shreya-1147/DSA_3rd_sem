#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

node* insertNode(node* root, int key) {
    if (root == NULL) {
        root = new node(key);
        return root;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* curr = q.front();
        q.pop();

        // If left child is empty, insert here
        if (curr->left == NULL) {
            curr->left = new node(key);
            return root;
        }
        else {
            q.push(curr->left);
        }

        // If right child is empty, insert here
        if (curr->right == NULL) {
            curr->right = new node(key);
            return root;
        }
        else {
            q.push(curr->right);
        }
    }

    return root;
}

// Print tree in level order
void levelOrder(node* root) {
    if (root == NULL)
        return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left != NULL)
            q.push(curr->left);

        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int main() {

    node* root = new node(20);

    root->left = new node(11);
    root->right = new node(9);

    root->left->left = new node(16);
    root->left->right = new node(5);

    root->right->left = new node(7);
    root->right->right = new node(3);

    // Insert a new node
    root = insertNode(root, 10);

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}