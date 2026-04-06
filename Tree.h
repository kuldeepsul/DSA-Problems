#pragma once
#include <iostream>
#include <vector>
#include <deque>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

public:
	TreeNode* invertTree(TreeNode* root);
	int maxDepth(TreeNode* root);
	int lengthofBinaryTree(TreeNode* root);
	int diameterOfBinaryTree(TreeNode* root);
	int checkHeight(TreeNode* root);
	bool isBalanced(TreeNode* root);
	bool isSameTree(TreeNode* p, TreeNode* q);
	bool checknode(TreeNode* p, TreeNode* q);
	bool isSubtree(TreeNode* root, TreeNode* subRoot);
	TreeNode* searchLCA(TreeNode* root, TreeNode* p, TreeNode* q);
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
	std::vector<std::vector<int>> levelOrder(TreeNode* root);



};