import os 

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        dummy = ListNode(0)
        dummy.next = head

        count = 0
        l = head
        while l != None:
            count += 1
            l = l.next
        pos = count - n
        
        count = 0
        cur = dummy
        while pos > 0:
            pos -= 1
            cur = cur.next

        cur.next = cur.next.next

        return dummy.next


if __name__ == '__main__':
    sln = Solution()

    head = ListNode(1)
    # head.next = ListNode(2)
    # head.next.next = ListNode(3)
    # head.next.next.next = ListNode(4)
    # head.next.next.next.next = ListNode(5)

    res = sln.removeNthFromEnd(head, 1)

    while res != None:
        print(res.val)
        res = res.next

    print('hello')
