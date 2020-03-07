#pragma once
template <class Type>
class MergeSort {
private:
	void Merge(Type result[], int from, int middle, int to);
public:
	void Sort(Type origin[], Type result[], int from, int to);

};

/**
 ** 合并result数组中两个子序列
 ** 两个子序列下标分别为
 ** 1： from ~ middle
 ** 2： middle + 1 ~ to
 ** 合并后的结果仍然存放在result中
*/
template<class Type>
void MergeSort<Type>::Merge(Type result[], int from, int middle, int to)
{

    int size = to - from + 1; // 待合并元素总数
    int* temp = new int[size]; // 申请临时空间存储合并结果

    int  i = from, j = middle + 1, k = 0;
    // i: 第一个子序列的下标
    // j: 第二个子序列的下标
    // k: 临时空间temp的下标

    // 循环，每次迭代选取一个最小元存放到temp中
    while (true) {

        if (result[i] <= result[j])
            temp[k++] = result[i++];
        else
            temp[k++] = result[j++];

        if (i > middle) // 只剩下 第二个子序列了
        {
            // 剩余元素的起始下标rFrom
            // 剩余元素的字节数rByteSize
            int rFrom = j, rByteSize = (to - j + 1) * sizeof(Type);
            memcpy(&(temp[k]), &(result[rFrom]), rByteSize);
            break;
        }
        else if (j > to) // 只剩下 第一个子序列了
        {
            // 剩余元素的起始下标rFrom
            // 剩余元素的字节数rByteSize
            int rFrom = i, rByteSize = (middle - i + 1) * sizeof(Type);
            memcpy(&(temp[k]), &(result[rFrom]), rByteSize);
            break;
        }

        // 如果两个子序列都有元素，则继续迭代

    } // while结束

    // 将temp中所有（已排好序）元素拷贝回result
    memcpy(&(result[from]), temp, size * sizeof(Type));

    delete[] temp; // 释放临时空间
}

/**
 ** 二分归并排序
 **  origin： 原数组
 **  result： 排序后有序数组
 **  from : 待排起始元素下标
 **    to : 待排结束元素下标
*/
template<class Type>
void MergeSort<Type>::Sort(Type origin[], Type result[], int from, int to)
{
    if (from == to)
        result[from] = origin[from];    //只有一个元素，直接赋值
    else {
        int m;
        m = (from + to) / 2;
        Sort(origin, result, from, m);    //归并排序前半个子序列
        Sort(origin, result, m + 1, to);   //归并排序后半个子序列
        Merge(result, from, m, to);      //合并两个已排序的子序列
    }

}
