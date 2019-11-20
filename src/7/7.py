
class Solution:
    def reverse1(self, x):
        res = 0
        while x!= 0:
            num = x%10
            x = x//10

    def reverse(self, x):
        res = 0
        flag = 1 if x > 0 else -1
        abs_x = abs(x)
        x_str = str(abs_x)
        reverse_x_str = x_str[::-1]
        reverse_x_int = int(reverse_x_str) * flag
        if -2**31 <= reverse_x_int <= 2**31-1:
            return reverse_x_int
        else:
            return 0


if __name__ == '__main__':
    sln = Solution()
    print(sln.reverse(-321))


