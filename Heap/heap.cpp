#include <iostream>
#include <vector>

void initHeap(std::vector<int>& arr, int size)
{
    // 寻找最后一个节点的父节点
    for (int pIndex = size/2; pIndex > 0; pIndex--)
    {
        int tmp = pIndex - 1;
        while((tmp*2) <= size - 1)   // 表示该节点有孩子节点——>如果该节点为叶子节点，循环结束
        {
            // 寻找这个节点的最大子节点
            int maxChildIndex = 0; 
            if ((tmp*2) + 1 > size - 1) // 该节点没有右孩子，则左孩子是最大节点
            {
                maxChildIndex = tmp*2;
            }
            else
            {
                maxChildIndex = arr[tmp*2]>arr[tmp*2+1] ? tmp*2 : tmp*2+1; 
            }

            // 比较最大子节点和当前父节点，如果父节点的值小于最大子节点，交换两个节点
            if (arr[tmp] < arr[maxChildIndex])
            {
                int a = arr[tmp];
                arr[tmp] = arr[maxChildIndex];
                arr[maxChildIndex] = a;
                tmp = maxChildIndex;
            }
            else
            {
                // 当该节点不再需要交换时，结束向下查找(退出while循环)
                break;
            } // 故结束这个while循环有两个方式：到达子节点和该节点不需要交换

        }
    }
}

int main()
{
    // std::vector<int> nums = {5, 1, 13, 3, 16, 7, 10, 14, 6, 9};
    std::vector<int> nums = {91, 83, 87, 79, 72, 43, 38};
    initHeap(nums, nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " " ;
    }
        std::cout << std::endl;

    return 0;
}

