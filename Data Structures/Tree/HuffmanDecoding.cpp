// https://www.hackerrank.com/challenges/tree-huffman-decoding/problem
#include <string>
#include <iostream>

struct node
{
    int freq;
    char data;
    node* left;
    node* right;
};

static bool is_leaf(node* n)
{
    return n->left == nullptr and n->right == nullptr;
}

void decode_huff(node* root, std::string s)
{
    std::string out;
    auto current = root;
    for (auto it = s.cbegin(); it != s.cend(); it++)
    {
        if (*it == '1')
            current = current->right;
        else
            current = current->left;
        if (is_leaf(current))
        {
            out += current->data;
            current = root;
        }
    }
    std::cout << out;
}