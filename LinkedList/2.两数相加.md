## 题目地址
https://leetcode-cn.com/problems/add-two-numbers/

## 题目描述
```
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```
## 思路
用一个标志位标识进位即可，以下几种情况需要特别注意  
l1=[0,1]，l2=[0,1,2]	当一个列表比另一个列表长时  
l1=[]，l2=[0,1]	当一个列表为空时，即出现空列表  
l1=[9,9]，l2=[1]	求和运算最后可能出现额外的进位，这一点很容易被遗忘

## 代码
* 语言支持：C++，python3
> C++代码
```c++
class Solution()
{
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
};
```
> python代码
```
class Solution:
    def addTwoNumbers(self, l1, l2):
        res = ListNode(0)
        head = res
        carry = 0
        p = l1
        q = l2
        while (p != None or q != None):
            x = p.val if (p != None) else 0 
            y = q.val if (q != None) else 0            
            sum = x + y + carry
            carry = sum // 10
            # print("p val : ", p.val, "q val : ", q.val)
            # print("carry : ", carry)
            # print("sum : ", sum)
            head.next = ListNode(sum % 10)
            if p != None:
                p = p.next
            if q != None:
                q = q.next
            # print("head val : ", head.val)
            head = head.next
        if carry > 0:
            head.next = ListNode(carry)
        res = res.next
        return res
```
