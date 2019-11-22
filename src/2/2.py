class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

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


if __name__ == '__main__':
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(5)

    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)
    
    sln = Solution()
    res = sln.addTwoNumbers(l1, l2)

    while res != None:
        print(res.val)
        res = res.next

