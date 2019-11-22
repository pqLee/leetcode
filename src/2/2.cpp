#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* res = new ListNode(0);;
	ListNode* head_res = res;
	int carry = 0;
	while (l1 != NULL || l2 != NULL)
	{
	    int x = (l1 != NULL) ? l1->val : 0;
	    int y = (l2 != NULL) ? l2->val : 0;
	    int sum = x + y + carry;
	    carry = sum / 10;
	    head_res->next = new ListNode(sum % 10);
	    head_res = head_res->next;
	    if (l1 != NULL)
		l1 = l1->next;
	    if (l2 != NULL)
		l2 = l2->next;
	}

	if (carry > 0)
	    head_res->next = new ListNode(carry);

	res = res->next;

	return res;
    }
};


int main()
{
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    l2->next->next->next = new ListNode(1);
    
    Solution sln;

    ListNode* res = sln.addTwoNumbers(l1, l2);

    while (res != NULL)
    {
	std::cout << res->val << std::endl;
	res = res->next;
    }

    return 0;
}


/*

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* res = new ListNode(l1->val + l2->val);

	ListNode* cur = res;
	
	int imp = 0;

	while (l1->next != NULL || l2->next != NULL)
	{
	    if (l1->next == NULL)
	    {
		while (l2->next != NULL)
		{
		    cur->next = l2->next;
		    l2 = l2->next;
		    cur = cur->next;
		}
		return res;
	    }
	    else if (l2->next == NULL)
	    {
		while (l1->next != NULL)
		{
		    cur->next = l1->next;
		    l1 = l1->next;
		    cur = cur->next;
		}
		return res;
	    }

	    l1 = l1->next;
	    l2 = l2->next;

	    if (l1->val+l2->val+imp > 9)
	    {
		cur->next = new ListNode((l1->val+l2->val+imp)%10);
		cur = cur->next;
		imp = 1;
	    }
	    else
	    {
	        cur->next = new ListNode(l1->val + l2->val + imp);
	        cur = cur->next;
		imp = 0;
	    }
	}

	return res;

    }
};
*/
