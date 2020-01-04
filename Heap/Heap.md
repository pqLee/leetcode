## 堆
1.首先我们需要找到最后一个结点的父结点如图(a),我们找到的结点是16,然后找出该结点的最大子节点与自己比较,若该子节点比自身大,则将两个结点交换.
图(a)中,16是最大的结点,不需要交换.  
2.我们移动到第下一个父结点3,如图(b)所示.同理做第一步的操作,交换了3和14,结果如图(c)所示.  
3.移动结点到下一个父结点13,如图(d)所示,发现不需要做任何操作,  
4.移动到下个父结点1,如图(e)所示,然后交换1和16,如图(f)所示,此时我们发现交换后,1的子节点并不是最大的,我们接着在交换(如图g)所示  
5.移动到父结点到5,一次重复上述步骤,交换5和16,在交换14和5,在交换5和6  
所有节点交换完毕,最大堆构建完成
![建堆](https://github.com/pqLee/leetcode/blob/master/images/heap.png)
## 应用
C++中priority_queue是堆模板，priority_queue底层就是堆实现  
堆排序：  
· 将数组建堆  
· 将堆顶与最后一个元素交换，这样最后一个元素就是最大值了(针对大顶堆),然后再将交换后的堆调整为大顶堆(heapify操作)  
· 逐次执行上一步操作，就从大到小逐次取出数据，数组最终就是有序数组
![堆排序](https://github.com/pqLee/leetcode/blob/master/images/heap_sort.gif)
## 代码实现(C++)
```
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
/* 堆排序（Heapsort）是指利用堆这种数据结构（所设计的一种排序算法。堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。堆排序可以说是一种利用堆的概念来排序的选择排序。分为两种方法：  
        大顶堆：每个节点的值都大于或等于其子节点的值，在堆排序算法中用于升序排列；  
        小顶堆：每个节点的值都小于或等于其子节点的值，在堆排序算法中用于降序排列；  
        堆排序的平均时间复杂度为 Ο(nlogn)
   算法步骤：  
        创建一个堆 H[0……n-1]；
        把堆首（最大值）和堆尾互换；
        把堆的尺寸缩小 1，并调用 shift_down(0)，目的是把新的数组顶端数据调整到相应位置；
        重复步骤 2，直到堆的尺寸为 1
*/
```


