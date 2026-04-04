#include <iostream>
#include <vector>
#include "Array.h"
#include "Linked_List.h"
#include "Tree.h"

int main()
{
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	

	n1->left = n2;
	n1->right = n3;
	

	TreeNode* p1 = new TreeNode(1);
	TreeNode* p2 = new TreeNode(2);
	TreeNode* p3 = new TreeNode(3);

	p1->left = p2;
	p1->right = p3;



	bool result = n1->isSameTree(n1,p1);


	return 0;
}