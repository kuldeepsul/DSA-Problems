#include <iostream>
#include <vector>
#include "Array.h"
#include "Linked_List.h"
#include "Tree.h"

int main()
{


	TreeNode* n1 = new TreeNode(3);
	TreeNode* n2 = new TreeNode(3);
	TreeNode* n3 = new TreeNode(4);
	TreeNode* n4 = new TreeNode(2);

	//TreeNode* n6 = new TreeNode(1);
	//TreeNode* n7 = new TreeNode(5);
	//TreeNode* n8 = new TreeNode(8);


	n1->left = n2;
	n2->left = n3;
	n2->right = n4;
	

	int result = 0;
	result = n1->goodNodes(n1);

	return 0;
}