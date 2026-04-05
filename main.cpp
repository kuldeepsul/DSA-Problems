#include <iostream>
#include <vector>
#include "Array.h"
#include "Linked_List.h"
#include "Tree.h"

int main()
{
	//TreeNode* n1 = new TreeNode(1);
	//TreeNode* n2 = new TreeNode(2);
	//TreeNode* n3 = new TreeNode(3);
	//TreeNode* n4 = new TreeNode(4);
	//TreeNode* n5 = new TreeNode(5);
	////TreeNode* n6 = new TreeNode(6);
	//

	//n1->left = n2;
	//n1->right = n3;
	//n2->left = n4;
	//n2->right = n5;
	////n4->left = n6;
	//

	//TreeNode* p1 = new TreeNode(2);
	//TreeNode* p2 = new TreeNode(4);
	//TreeNode* p3 = new TreeNode(5);

	//p1->left = p2;
	//p1->right = p3;

	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(1);
	TreeNode* n3 = new TreeNode(1);
	TreeNode* n4 = new TreeNode(1);
	TreeNode* n5 = new TreeNode(1);
	TreeNode* n6 = new TreeNode(1);
	TreeNode* n7 = new TreeNode(1);
	TreeNode* n8 = new TreeNode(1);
	TreeNode* n9 = new TreeNode(1);
	TreeNode* n10 = new TreeNode(1);
	TreeNode* n11 = new TreeNode(1);
	TreeNode* n12 = new TreeNode(2);

	n1->right = n2;
	n2->right = n3;
	n3->right = n4;
	n5->right = n6;
	n6->right = n7;
	n7->right = n8;
	n8->right = n9;
	n9->right = n10;
	n10->right = n11;
	n11->right = n12;



	TreeNode* p1 = new TreeNode(1);
	TreeNode* p2 = new TreeNode(1);
	TreeNode* p3 = new TreeNode(1);
	TreeNode* p4 = new TreeNode(1);
	TreeNode* p5 = new TreeNode(1);
	TreeNode* p6 = new TreeNode(1);
	TreeNode* p7 = new TreeNode(2);

	p1->right = p2;
	p2->right = p3;
	p3->right = p4;
	p4->right = p5;
	p5->right = p6;
	p6->right = p7;


	bool result = n1->isSubtree(n1,p1);


	return 0;
}