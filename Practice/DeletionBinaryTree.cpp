#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void deleteDeep(node* root, node* dnode)
{
    queue<node*> q;
    q.push(root);

    node*temp;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->left != NULL)
        {
            if (temp->left == dnode)
            {
                temp->left = NULL;
                delete dnode;
                return;
            }
            else
            {
                q.push(temp->left);
            }
        }
        if (temp->right != NULL)
        {
            if (temp->right == dnode)
            {
                temp->right = NULL;
                delete dnode;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }
}
node* deletion(node* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
        {
            delete root;
            return NULL;
        }
        else
        {
            return root;
        }
    }
    queue<node*> q;
    q.push(root);
    node* temp;
    node* keynode = NULL;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == key)
        {
            keynode = temp;
        }

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }

        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    if (keynode != NULL)
    {
        int x = temp->data;
        keynode->data = x;

        deleteDeep(root, temp);
    }

    return root;
}
void inorder(node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << "Before deletion: ";
    inorder(root);

    root = deletion(root, 3);

    cout << endl;

    cout << "After deletion: ";
    inorder(root);

    return 0;
}