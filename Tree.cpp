#include "Tree.h"

TreeNode* TreeNode::invertTree(TreeNode* root)
{
    if (root == nullptr)
    {
        return root;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        return root;
    }
    else if (root->left != nullptr && root->right != nullptr)
    {
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
    }
    else if (root->left == nullptr)
    {
        root->left = invertTree(root->right);
        root->right = nullptr;
    }
    else if (root->right == nullptr)
    {
        root->right = invertTree(root->left);
        root->left = nullptr;
    }
    return root;

}

int TreeNode::maxDepth(TreeNode* root)
{
    static int depth = 0;

    if (root == nullptr)
    {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }
    else if (root->left != nullptr && root->right != nullptr)
    {

        int r = maxDepth(root->right);
        int l = maxDepth(root->left);

        depth = 1 + std::max(l, r);
    }
    else if (root->left == nullptr)
    {
        return  1 + maxDepth(root->right);
    }
    else if (root->right == nullptr)
    {
        return 1 + maxDepth(root->left);
    }
    return depth;

}