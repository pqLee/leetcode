#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            ListNode* dummy = new ListNode(0);
            dummy->next =  head;

            ListNode* first = dummy;
            ListNode* second  = dummy;

            for (int i = 0; i < n+1; i++)
            {
                std::cout << "i : "  << i << std::endl;
                // 注意边界条件，i=0开始出错
                first = first->next;
            }

            while (first != NULL)
            {
                first = first->next;
                second = second->next;
            }

            second->next = second->next->next;

            dummy = dummy->next;
            return dummy;
        }

};


int main()
{
    Solution sln;

    ListNode* head = new ListNode(1);
    //  head->next = new ListNode(2);
    //  head->next->next = new ListNode(3);
    //  head->next->next->next = new ListNode(4);
    //  head->next->next->next->next = new ListNode(5);

    sln.removeNthFromEnd(head, 1);

    while (head != NULL)
    {
        std::cout << head->val << std::endl;
        head = head->next;
    }

    return 0;
}
