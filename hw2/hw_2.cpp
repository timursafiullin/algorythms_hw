#include <iostream>


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
        {
            if (list1 == nullptr)
                return list2;
            if (list2 == nullptr)
                return list1;

            if (list1->val < list2->val)
            {
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            }
            else
            {
                list2->next = mergeTwoLists(list1, list2->next);
                return list2;
            }
        }
};


int main()
{
    Solution solution;

    ListNode* list1 = new ListNode(1, new ListNode(1, new ListNode(3)));
    ListNode* list2 = new ListNode(1, new ListNode(2, new ListNode(4)));

    ListNode* result = solution.mergeTwoLists(list1, list2);
    while(result != nullptr)
    {
        std::cout << result->val << " ";
        result = result->next;
    }
}