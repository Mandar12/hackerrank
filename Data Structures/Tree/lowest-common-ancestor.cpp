// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem
/* Approach 1: Find paths of both nodes from root. Compare paths for common ancestor.
   Approach 2: Assume v1 and v2 are present in the tree. Find LCA recursively in left and right subtree
*/
struct node
{
    int data;
    node* left;
    node* right;
};

// Approach 2: Assume v1 and v2 are present in the tree.
node* lca(node* root, int v1, int v2)
{
    // Base case
    if (root == nullptr)
        return nullptr;
    // If either v1 or v2 matches with root's data, report the presence by returning root
    // Note that if a data is ancestor of other, then the ancestor data becomes LCA
    if (root->data == v1 || root->data == v2)
        return root;
    // Look for datas in left and right subtrees
    auto left_lca = lca(root->left, v1, v2);
    auto right_lca = lca(root->right, v1, v2);

    // If both of the above calls return Non-NULL (due to assumption break),
    // then one data is present in one subtree and other is present in other, so this node is the LCA
    if (left_lca && right_lca)
        return root;

    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != nullptr) ? left_lca : right_lca;
}