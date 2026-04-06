#include <iostream>
#include <vector>
#include "Array.h"
#include "Linked_List.h"
#include "Tree.h"

int main()
{


	TreeNode* n1 = new TreeNode(5);
	TreeNode* n2 = new TreeNode(3);
	TreeNode* n3 = new TreeNode(8);
	TreeNode* n4 = new TreeNode(1);
	TreeNode* n5 = new TreeNode(4);
	TreeNode* n6 = new TreeNode(7);
	TreeNode* n7 = new TreeNode(9);
	TreeNode* n8 = new TreeNode(2);


	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	n4->right = n8;
	

	std::vector <std::vector <int>> result = n1->levelOrder(n1);

	return 0;
}