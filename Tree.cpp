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

TreeNode* TreeNode::searchLCA(TreeNode* root, TreeNode* p ,TreeNode* q)
{
    if (!root)
    {
        return root;
    }
    if (root->val < p->val && root->val < q->val)
    {
        return searchLCA(root->right,p,q);
    }
    else if (root->val > p->val && root->val > q->val)
    {
        return searchLCA(root->left,p,q);
    }
    else
    {
        return root;
    }
}

TreeNode* TreeNode::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    return searchLCA(root,p,q);
}

std::vector<std::vector<int>> TreeNode::levelOrder(TreeNode* root)
{
    std::vector <std::vector <int>> result;
    std::vector <int> level;
    std::deque <TreeNode*> q1;
    std::deque <TreeNode*> q2;

    q1.push_back(root);


    bool done = false;

    while (!done)
    {

        if (!q1.size() && !q2.size())
        {
            done = true;
        }

        while (q1.size())
        {
            if (q1.front()->left)
            {
                q2.push_back(q1.front()->left);
            }

            if (q1.front()->right)
            {
                q2.push_back(q1.front()->right);
            }

            level.push_back(q1.front()->val);
            q1.pop_front();

        }
        if (level.size())
        {
            result.push_back(level);
            level.clear();
        }


        while (q2.size())
        {
            if (q2.front()->left)
            {
                q1.push_back(q2.front()->left);
            }
            if (q2.front()->right)
            {
                q1.push_back(q2.front()->right);
            }

            level.push_back(q2.front()->val);
            q2.pop_front();

        }

        if (level.size())
        {
            result.push_back(level);
            level.clear();
        }
    }

    return result;
}

TreeNode* TreeNode::findLowest(TreeNode* root)
{
    if (root->left)
    {
        return findLowest(root->left);
    }
    else
    {
        return root;
    }
}
TreeNode* TreeNode::findHighest(TreeNode* root)
{
    if (root->right)
    {
        return findHighest(root->right);
    }
    else
    {
        return root;
    }
}

bool TreeNode::isValidBST(TreeNode* root)
{
    if (!root)
    {
        return true;
    }

    if (root->left)
    {
        if (findHighest(root->left)->val >= root->val)
        {
            return false;
        }
    }
    if (root->right)
    {
        if (findLowest(root->right)->val <= root->val)
        {
            return false;
        }
    }
    else if (!root->left && !root->right)
    {
        return true;
    }

    if (isValidBST(root->left) && isValidBST(root->right))
    {
        return true;
    }

    return false;
}

void TreeNode::DFSTraversal(TreeNode* root, std::vector <int>& list)
{
    if (!root)
    {
        return;
    }
    else
    {
        DFSTraversal(root->left, list);
        list.push_back(root->val);
        DFSTraversal(root->right, list);

    }
}

bool TreeNode::isValidBST2(TreeNode* root)
{
    std::vector <int> list;
    DFSTraversal(root, list);

    int i = 1;
    int max = list[0];
    bool done = false;

    while (true)
    {
        if (i == list.size())
        {
            break;
        }

        if (list[i - 1] < list[i])
        {
            i++;
        }
        else
        {
            return false;
        }

    }
    return true;
}

int TreeNode::noOfGoodNodes(TreeNode* root,int cur_max)
{
    int left = 0;
    int right = 0;
    int cur = 0;

    if (!root)
    {
        return 0;
    }

    if (root->val >= cur_max)
    {
        cur_max = root->val;
        cur = 1;

    }

    if (root->left)
    {
        left = noOfGoodNodes(root->left, cur_max);
    }

    if (root->right)
    {
        right = noOfGoodNodes(root->right, cur_max);
    }

    return cur + left + right;

}
int TreeNode::goodNodes(TreeNode* root)
{
    return noOfGoodNodes(root,root->val);
}

