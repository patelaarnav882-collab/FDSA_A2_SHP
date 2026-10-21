#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    string name;
    Node *left;
    Node *right;

    Node(string n)
    {
        name = n;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->name << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->name << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->name << " ";
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << temp->name << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main()
{
    Node *root = new Node("CEO");
    root->left = new Node("Manager1");
    root->right = new Node("Manager2");
    root->left->left = new Node("Employee1");
    root->left->right = new Node("Employee2");
    root->right->left = new Node("Employee3");
    root->right->right = new Node("Employee4");

    cout << "Preorder: ";
    preorder(root);
    cout<<endl;

    cout << "\nInorder: ";
    inorder(root);
    cout<<endl;

    cout << "\nPostorder: ";
    postorder(root);
    cout<<endl;

    cout << "\nLevel Order: ";
    levelOrder(root);
    cout<<endl;

    return 0;
}