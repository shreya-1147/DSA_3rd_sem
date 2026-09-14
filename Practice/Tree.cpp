#include <iostream>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;

    node(int data) {
        val = data;
        left = right = NULL;
    }
};

//COUNT NUMBER OF NODES-

int countnodes(node* root) {
    if (root == NULL)
        return 0;

    return 1 + countnodes(root->left) + countnodes(root->right);
}

//HEIGHT OF TREE-
int height(node* root) {
    if (root == NULL)
        return 0;

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return max(leftheight, rightheight) + 1;
}

//COUNT LEAF NODES-
int countleafnodes(node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countleafnodes(root->left) + countleafnodes(root->right);
}


int main() {
    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->right = new node(6);
    root->right->right->left = new node(7);

    cout << "The no. of nodes : " << countnodes(root);

    cout << "\nThe height of the tree : " << height(root);

    cout << "\nThe no. of leaf nodes : " << countleafnodes(root);

    return 0;
}