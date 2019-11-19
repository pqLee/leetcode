class Solution:
    def twoSum(self, nums, target):
        hashmap = {}
        for index, value in enumerate(nums):
            print(index, " : ", value)
            if hashmap.get(target - value) is not None:
                return [index, hashmap.get(target - value)]
            hashmap[value] = index


if __name__ == '__main__':
    sln = Solution()
    nums = [2, 7, 11, 13]
    target = 9

    res = sln.twoSum(nums, target)
    print(res)
