#pragma once
#include <map>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode* random;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

	
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
ListNode* reverseList(ListNode* head);
ListNode* mergeList(ListNode* list1, ListNode* list2);
void reorderList(ListNode* head);
ListNode* removeNthFromEnd(ListNode* head, int n);
ListNode* copyListwithRandomMap(ListNode* head, std::map <int, int>& map_01, std::map <int, ListNode* >& map_02);
ListNode* copyRandomList(ListNode* head);
ListNode* reverseKGroup(ListNode* head, int k);