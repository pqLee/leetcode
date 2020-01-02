## 堆
1.首先我们需要找到最后一个结点的父结点如图(a),我们找到的结点是16,然后找出该结点的最大子节点与自己比较,若该子节点比自身大,则将两个结点交换.
图(a)中,16是最大的结点,不需要交换.  
2.我们移动到第下一个父结点3,如图(b)所示.同理做第一步的操作,交换了3和14,结果如图(c)所示.  
3.移动结点到下一个父结点13,如图(d)所示,发现不需要做任何操作,  
4.移动到下个父结点1,如图(e)所示,然后交换1和16,如图(f)所示,此时我们发现交换后,1的子节点并不是最大的,我们接着在交换(如图g)所示  
5.移动到父结点到5,一次重复上述步骤,交换5和16,在交换14和5,在交换5和6  
所有节点交换完毕,最大堆构建完成
![两数之和](https://github.com/pqLee/leetcode/blob/master/images/heap.png)
## 应用
C++中priority_queue是堆模板，priority_queue底层就是堆实现
## 代码实现(C++)
```
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
```


