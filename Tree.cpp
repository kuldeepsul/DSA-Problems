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

bool TreeNode::isBalanced(TreeNode* root)
{
    if (root == nullptr)
    {
        return true;
    }

    int l, r;
    if (root->left == nullptr && root->right == nullptr)
    {
        return true;
    }
    else if (root->left == nullptr)
    {
        if (isBalanced(root->right))
        {
            r = 1 + lengthofBinaryTree(root->right);
            if (r > 1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }

    }
    else if (root->right == nullptr)
    {
        if (isBalanced(root->left))
        {
            l = 1 + lengthofBinaryTree(root->left);
            if (l > 1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }

    }
    else
    {
        if (isBalanced(root->left) && isBalanced(root->right))
        {
            l = lengthofBinaryTree(root->left);
            r = lengthofBinaryTree(root->right);

            if (l - r > 1 || r - l > 1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            false;
        }
    }

}

bool TreeNode::checknode(TreeNode* p, TreeNode* q)
{

    if (p == nullptr)
    {   
        if (q)
        {
            return false;
        }

    }
    else if (q == nullptr)
    {
        if (p)
        {
            return false;
        }
    }
    else if ( p == nullptr && q == nullptr)
    {
        return true;
    }
    else
    {
        if (p->val != q->val)
        {
            return false;
        }
        else
        {
            if (checknode(p->left, q->left))
            {
                if (checknode(p->right, q->right))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }

        }
    }
}

bool TreeNode::isSameTree(TreeNode* p, TreeNode* q)
{
    return checknode(p, q);
}