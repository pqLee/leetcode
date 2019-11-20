#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>

class Solution
{
public:
    int reverse(int x)
    {
	int temp = x;
	int res = 0;

	while (temp != 0)
	{
	    int num = temp % 10;
	    temp = temp/10;

	    if (res > INT_MAX/10 || res == INT_MAX/10 && num > 7)
		return 0;
	
	    if (res < INT_MIN/10 || res == INT_MAX/10 && num < -8)
		return 0;

	    res = res * 10 + num;
	}

	return res;
    }
};


int main()
{
    Solution sln;
    int res = sln.reverse(-3215);
    std::cout << "res : " << res << std::endl;

    return 0;
}
