#include <iostream>
#include <queue>

struct node
{
    int data;
    node* left;
    node* right;
};

/*
Depth First Traversals:
(a) Inorder (Left, Root, Right)
(b) Preorder (Root, Left, Right)
(c) Postorder (Left, Right, Root)
position of root - name of traversal
*/
void inOrder(node* root)
{
    if (root == nullptr)
        return;
    if (root->left)
        inOrder(root->left);
    std::cout << root->data << " ";
    if (root->right)
        inOrder(root->right);
}

void preOrder(node* root)
{
    if (root == nullptr)
        return;
    std::cout << root->data << " ";
    if (root->left)
        preOrder(root->left);
    if (root->right)
        preOrder(root->right);
}

void postOrder(node* root)
{
    if (root == nullptr)
        return;
    if (root->left)
        postOrder(root->left);
    if (root->right)
        postOrder(root->right);
    std::cout << root->data << " ";
}

void levelOrder(node* root)
{
    if (root == nullptr)
        return;
    std::queue<node*> q;
    q.push(root);

    while (not q.empty())
    {
        auto n = q.front();
        q.pop();
        std::cout << n->data << " ";
        if (n->left)
            q.push(n->left);
        if (n->right)
            q.push(n->right);
    }
}