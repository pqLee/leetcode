#include <iostream>
#include <vector>
#include <map>

class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
	std::vector<int> res;

	int sum = 0;
	for (int i = 0; i < nums.size()-1; i++)
	{
	    for (int j = i+1; j < nums.size(); j++)
	    {
		if (nums[i]+nums[j] == target)
		{
		    res.push_back(i);
		    res.push_back(j);
		    return res;
		}
	    }
	}

	return res;
    }
    
    std::vector<int> optimized_twoSum(std::vector<int>& nums, int target)
    {
	std::map<int, int> record;

	for (int i = 0; i < nums.size(); i++)
	{
	    int complement = target - nums[i];
	    if (record.find(complement) != record.end())
	    {
		return std::vector<int>{record[complement], i};
	    }

	    record[nums[i]] = i;
	}
    }
};


int main()
{
    Solution sln;

    std::vector<int> nums = {2, 7, 11, 15};

    std::vector<int> res = sln.twoSum(nums, 9);
    std::vector<int> res1 = sln.optimized_twoSum(nums, 9);


    for (int i = 0; i < res.size(); i++)
    {
	std::cout << res[i] << std::endl;
    }

    std::cout << "---------------------------------------" << std::endl;

    for (int i = 0; i < res1.size(); i++)
    {
	std::cout << res1[i] << std::endl;
    }

    return 0;
}
