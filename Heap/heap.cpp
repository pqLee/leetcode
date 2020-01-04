#include <iostream>
#include <vector>
#include <queue>

template <typename T>
void heapify(std::vector<T>& arr, int i, int len)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int largest_node = i;  // 记录父节点、左节点、右节点中最大值位置

    if (left < len && arr[largest_node] < arr[left])
    {
        largest_node = left;
    }

    if (right < len && arr[largest_node] < arr[right])
    {
        largest_node = right;
    }

    // 如果最大值不是父节点
    if (largest_node != i)
    {
        auto temp = arr[i];
        arr[i] = arr[largest_node];
        arr[largest_node] = temp;
        
        // 一直向下递归调用，直到该节点满足：父节点大于等于左右两个子节点
        heapify(arr, largest_node, len);
    }
}

// 建堆时从底向上调整
template <typename T>
void buildHeap(std::vector<T>& arr, int len)
{
    for (int i = len / 2; i >= 0; i--)
    {
        heapify(arr, i, len);
    }
}

template <typename T>
void heapSort(std::vector<T>& arr)
{
    int len = arr.size();
    buildHeap(arr, len);

    for (int i = len - 1; i > 0; i--)
    {
        auto temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        len--;
        heapify(arr, 0, len);
    }
}

int main()
{
    // std::vector<int> nums = {5, 1, 13, 3, 16, 7, 10, 14, 6, 9};
    std::vector<int> nums = {91, 83, 87, 79, 72, 43, 38, 38, 9, 87};
    std::vector<float> nums_float = {5.1, 4.3, 8.7, 3.4, 6.9};
    
    // buildHeap(nums, nums.size());
    // heapSort<int>(nums);
    heapSort<float>(nums_float);

    for (int i = 0; i < nums_float.size(); i++)
    {
        std::cout << nums_float[i] << " " ;
    }
    std::cout << std::endl;

    return 0;
}


