#include <iostream>
using namespace std;

struct node
{
    node *left;
    int data;
    node *right;
};

node *createTree()
{

    int input, data;

    cout << "Enter 1 for insert data 0 for not :: " << endl;
    cin >> input;

    if (input == 0)
    {
        return nullptr;
    }

    else
    {

        node *newnode = new node; //? Memory Allocation for a new node dynamically

        cout << "Enter the data " << endl;
        cin >> data;

        newnode->data = data; //?Pushed the data

        cout << "Enter the data for left child of " << data << endl;
        newnode->left = createTree();
        cout << "Enter the data for right child of " << data << endl;
        newnode->right = createTree();

        return newnode; // Returning the newnode address
    }
}

void deleteTree(node *root)
{

    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;

    root = nullptr;
}

int main()
{

    node *root = createTree();

    if (root != nullptr)
    {
        cout << "The Root data : " << root->data << endl;

        if (root->left != nullptr)
        {
            cout << "The left child of the root is " << root->left->data << endl;
        }

        else
            cout << "The Left child is NULL " << endl;

        if (root->right != nullptr)
        {
            cout << "The right child of root is " << root->right->data << endl;
        }

        else
            cout << "There is no right child " << endl;

        if (root->left != nullptr && root->left->left != nullptr)
        {
            cout << "The left childs of left child " << root->left->left->data << endl;
        }

        if (root->left != nullptr && root->left->right != nullptr)
        {
            cout << "The left childs of right child " << root->left->right->data << endl;
        }

        if (root->right != nullptr && root->right->left != nullptr)
        {
            cout << "The right childs of left child " << root->right->left->data << endl;
        }

        if (root->right != nullptr && root->right->right != nullptr)
        {
            cout << "The left childs of left child " << root->right->right->data << endl;
        }
    }

    deleteTree(root);

    return 0;
}