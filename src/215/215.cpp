#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    int findKthLargest(std::vector<int>& nums, int k)
    {
        int res = 0;

        sort(nums.begin(), nums.end());

        res = nums[k-1];

        return res;
    }
};

int main()
{
    std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};

    Solution* sln = new Solution();
    int res = sln->findKthLargest(nums, 4);
    delete sln;

    std::cout << "res : " << res << std::endl;

    return 0;
}

