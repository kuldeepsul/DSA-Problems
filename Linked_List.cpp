#include "Linked_List.h"

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if (list1 == nullptr)
    {
        list1 = list2;
        return list1;
    }
    if (list2 == nullptr)
    {
        return list1;
    }
    ListNode* prev_01 = nullptr;
    if (list1->val > list2->val)
    {
        prev_01 = list2;
    }
    else
    {
        prev_01 = list1;
    }
    ListNode* newhead = prev_01;
    ListNode* cur_01 = list1;
    ListNode* cur_02 = list2;
    ListNode* next_02 = cur_02->next;

    while (cur_01)
    {
        if (cur_01->val <= cur_02->val)
        {
            prev_01 = cur_01;
            cur_01 = cur_01->next;
        }
        else
        {
            prev_01->next = cur_02;
            cur_02->next = cur_01;
            prev_01 = cur_02;
            cur_02 = next_02;
            if (cur_02 != nullptr)
            {
                next_02 = cur_02->next;
            }
            else
            {
                list2 = nullptr;
                break;
            }
        }
    }
    if (cur_01 == nullptr)
    {
        prev_01->next = cur_02;
        list2 = nullptr;
    }
    return newhead;
}

ListNode* reverseList(ListNode* head)
{
    ListNode* temp = head;
    ListNode* back = nullptr;
    ListNode* front = temp;

    while (temp != nullptr)
    {
        front = temp->next;
        temp->next = back;
        back = temp;
        temp = front;
    }
    return back;
}

ListNode* mergeList(ListNode* list1, ListNode* list2)
{
    ListNode* cur_01 = list1;
    ListNode* cur_02 = list2;
    ListNode* prev = cur_01;
    ListNode* next = cur_02;

    while (cur_02 != nullptr)
    {
        cur_01 = cur_01->next;
        prev->next = cur_02;
        prev = cur_01;
        next = cur_02->next;
        cur_02->next = cur_01;
        cur_02 = next;
        
 
    }
    return list1;


}

void reorderList(ListNode* head)
{
    if (head->next == nullptr)
    {
        return;
    }
    if (head->next->next == nullptr)
    {
        return;
    }

    ListNode* left = head;
    ListNode* right = head;

    while (right != nullptr)
    {
        if (right->next != nullptr)
        {
            left = left->next;
            right = right->next->next;
        }
        else
        {
            break;
        }
    }
    ListNode* temp = left->next;
    left->next = nullptr;
    temp = reverseList(temp);

    head = mergeList(head, temp);

}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if (head == nullptr)
    {
        return head;
    }
    else if (head->next == nullptr && n == 1)
    {
        head = nullptr;
        return head;
    }

    int k = n;
    ListNode* forward = head;
    ListNode* backward = head;

    while (k > 0)
    {
        forward = forward->next;
        k--;
    }
    if (forward == nullptr)
    {
        ListNode* temp = head;
        head = head->next;
        temp->next = nullptr;
        return head;
    }

    while (forward->next != nullptr)
    {
        forward = forward->next;
        backward = backward->next;
    }
    ListNode* temp = backward;
    temp = temp->next;
    backward->next = temp->next;
    temp->next = nullptr;
    return head;
}

ListNode* copyListwithRandomMap(ListNode* head, std::map <int, int>& map_01, std::map <int, ListNode* >& map_02)
{

    if (head->random != nullptr)
    {
        map_01[head->val] = head->random->val;
    }
    else
    {
        map_01[head->val] = 9999;
    }

    if (head->next == nullptr)
    {
        ListNode* newhead = new ListNode(head->val);
        map_02[newhead->val] = newhead;
        return newhead;
    }

    ListNode* temp = copyListwithRandomMap(head->next, map_01, map_02);
    ListNode* newhead = new ListNode(head->val);
    newhead->next = temp;
    map_02[newhead->val] = newhead;
    return newhead;
}

ListNode* copyRandomList(ListNode* head)
{
    if (head == nullptr)
    {
        return head;
    }

    std::map <int, int> r_map;
    std::map <int, ListNode*> a_map;

    ListNode* newhead = copyListwithRandomMap(head, r_map, a_map);
    ListNode* temp = newhead;

    while (temp != nullptr)
    {
        if (r_map[temp->val] == 9999)
        {
            temp->random = nullptr;
            temp = temp->next;
        }
        else
        {
            temp->random = a_map[r_map[temp->val]];
            temp = temp->next;
        }
    }
    return newhead;
}


ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode* fast_p = head;
    ListNode* slow_p = head;
    ListNode* temp_old = nullptr;
    ListNode* temp = nullptr;
    int n = 1;
    int count = 0;

    while (fast_p != nullptr)
    {
        fast_p = fast_p->next;
        n++;
        if (n == k)
        {
            // temp pointer states the partition of the list .

            temp = fast_p;
            fast_p = fast_p->next;
            n++;

            // breaking the list form real list and reversing th
            temp->next = nullptr;               // breaking current link
            temp = slow_p;                      // moving temp to start of list.
            slow_p = reverseList(temp);
            temp->next = fast_p;
            

            count++;
            n = 1;
            if (count == 1)
            {
                
                head = slow_p;
            }
            else
            {
                temp_old->next = slow_p;
            }
            temp_old = temp;
            slow_p = fast_p;

        }

    }
    return head;
}