#include <iostream>
#include <vector>
#include <queue>

//// 堆化操作，针对i节点调整，实现堆化
void heapify(std::vector<int>& arr, int i, int len)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;   // 记录父节点、左节点、右节点中最大值位置
    if (left < len && arr[left] > arr[largest])
    {
        largest = left;
    }
    
    if (right < len && arr[right] > arr[largest])
    {
        largest = right;
    }

    // 如果最大值不是父节点
    if (largest != i)  
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // 一直向下递归调用，直到该节点满足：父节点大于等于左右两个子节点
        heapify(arr, largest, len);
    }
}

// 建堆时从底向上调整
void buildHeap(std::vector<int>& arr, int len)
{
    for (int i = len/2; i >= 0; i--)
    {
        heapify(arr, i, len);
    }
}

void heapSort(std::vector<int>& arr)
{
    int len = arr.size();

    buildHeap(arr, len);

    for (int i = len - 1; i > 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        len--;
        heapify(arr, 0, len);
    }
}


int main()
{
    std::vector<int> nums = {91, 83, 87, 79, 72, 43, 38, 38, 9, 87};

    heapSort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " " ;
    }
    std::cout << std::endl;
    return 0;
}
