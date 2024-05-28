#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tempRes = &dummy;
    ListNode* temp = l1;
    int remain = 0, sum = 0;
    
    // Pass all l1 node to sum linked list
    while (temp != nullptr)
    {
        ListNode* newNode = new ListNode(temp->val);
        tempRes->next = newNode;
        tempRes = newNode;
        temp = temp->next;
    }

    // Deal with the second one
    tempRes = &dummy;
    temp = l2;
    while (temp != nullptr || tempRes->next != nullptr || remain)
    {
        if (temp != nullptr && tempRes->next != nullptr) // normal case l1, l2: still
            sum = temp->val + tempRes->next->val + remain;
        else if (!temp && tempRes->next != nullptr) // l2: over; l1: still
            sum = tempRes->next->val + remain;
        else if (temp != nullptr && !tempRes->next) // l1: over; l2: still
            sum = temp->val + remain;
        else if (remain) // remain: still; l1, l2: over
            sum = remain;
        else 
            break;

        remain = sum / 10;
        sum %= 10;

        if (!tempRes->next)
        {
            ListNode* newNode = new ListNode(sum);
            tempRes->next = newNode;
        }
        else
            tempRes->next->val = sum;

        if (temp != nullptr) temp = temp->next;
        if (tempRes != nullptr) tempRes = tempRes->next;
    }

    return dummy.next;
}

int main()
{
    int nums1[] = {2, 4, 3};
    int nums2[] = {5, 6, 4};
    ListNode dummy1(0);
    ListNode dummy2(0);
    ListNode* temp1 = &dummy1;
    ListNode* temp2 = &dummy2;
    for (int i = 0; i < 3; i++)
    {
        ListNode* newNode1 = new ListNode(nums1[i]);
        temp1->next = newNode1;
        temp1 = newNode1;
    }

    for (int i = 0; i < 3; i++)
    {
        ListNode* newNode2 = new ListNode(nums2[i]);
        temp2->next = newNode2;
        temp2 = newNode2;
    }

    // temp1 = dummy1.next;
    // while (temp1 != nullptr)
    // {
    //     cout << temp1->val << " | ";
    //     temp1 = temp1->next;
    // }

    // cout << endl;

    // temp2 = dummy2.next;
    // while (temp2 != nullptr)
    // {
    //     cout << temp2->val << " | ";
    //     temp2 = temp2->next;
    // }
    
    ListNode* result = addTwoNumbers(dummy1.next, dummy2.next);
    temp1 = result;
    while (temp1 != nullptr)
    {
        cout << temp1->val << " | ";
        temp1 = temp1->next;
    }

    return 0;
}