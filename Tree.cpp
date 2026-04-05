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

int TreeNode::lengthofBinaryTree(TreeNode* root)
{
    int l = 0;
    int r = 0;

    if (root->left != nullptr && root->right != nullptr)
    {
        l = 1 + lengthofBinaryTree(root->left);
        r = 1 + lengthofBinaryTree(root->right);
    }
    else if (root->left == nullptr && root->right == nullptr)
    {
        l = 0;
        r = 0;
    }
    else if (root->left == nullptr)
    {
        r = 1 + lengthofBinaryTree(root->right);
    }
    else if (root->right == nullptr)
    {
        l = 1 + lengthofBinaryTree(root->left);
    }

    return std::max(l, r);
}

int TreeNode::diameterOfBinaryTree(TreeNode* root)
{
    int left = 0;
    int right = 0;
    int diaright = 0;
    int dialeft = 0;

    if (root->left == nullptr && root->right == nullptr)
    {
        return 0;
    }
    else if (root->left == nullptr)
    {
        right = 1 + lengthofBinaryTree(root->right);
        diaright = diameterOfBinaryTree(root->right);
    }
    else if (root->right == nullptr)
    {
        left = 1 + lengthofBinaryTree(root->left);
        dialeft = diameterOfBinaryTree(root->left);
    }
    else
    {
        left = 1 + lengthofBinaryTree(root->left);
        right = 1 + lengthofBinaryTree(root->right);
        diaright = diameterOfBinaryTree(root->right);
        dialeft = diameterOfBinaryTree(root->left);

    }



    int child = std::max(dialeft, diaright);
    int parent = left + right;

    return std::max(child, parent);
}

int TreeNode::checkHeight(TreeNode* root)
{
    if (!root)
    {
        return 0;
    }
    int l = checkHeight(root->left);
    if (l == -1)
    {
        return -1;
    }
    int r = checkHeight(root->right);
    if (r == -1)
    {
        return -1;
    }
    if (std::abs(l - r) > 1)
    {
        return -1;
    }

    return 1 + std::max(l, r);
}

bool TreeNode::isBalanced(TreeNode* root)
{
    return checkHeight(root) != -1;
}

bool TreeNode::checknode(TreeNode* p, TreeNode* q)
{
    if (!p && !q)
    {
        return true;
    }
    else if (p && q)
    {
        if (p->val == q->val)
        {
            if (checknode(p->left, q->left))
            {
                if (checknode(p->right, q->right))
                {
                    return true;
                }
            }
        }
    }



    return false;

}

bool TreeNode::isSameTree(TreeNode* p, TreeNode* q)
{
    return checknode(p, q);
}

bool TreeNode::isSubtree(TreeNode* root, TreeNode* subRoot)
{
    if (!root && !subRoot)
    {
        return true;
    }

    if (checknode(root, subRoot))
    {
        return true;
    }
    else
    {
        if (root->left)
        {
            if (isSubtree(root->left, subRoot))
            {
                return true;
            }
        }
        else if (root->right)
        {
            if (isSubtree(root->right, subRoot))
            {
                return true;
            }
        }

    }



    return false;
}

