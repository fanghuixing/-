#include <iostream>
#include "源.h"
using std::cout;

void MergeSort(int origin[], int result[], int from, int to)
{
    if (from == to) 
        result[from] = origin[from];    //只有一个元素，直接赋值
    else {
        int m;
        m = (from + to) / 2;
        MergeSort(origin, result, from, m);    //归并排序前半个子序列
        MergeSort(origin, result, m + 1, to);   //归并排序后半个子序列
        Merge(result, from, m, to);      //合并两个已排序的子序列
    }
}

void Merge(int result[], int from, int middle, int to)
{
    int size = to - from + 1; // 待合并元素总数
    int* temp = new int[size]; // 申请临时空间存储合并结果
    
    int  i = from, j = middle + 1, k = 0;
    // i: 第一个子序列的下标
    // j: 第二个子序列的下标
    // k: 临时空间temp的下标


    while (true) {

        if (result[i] <= result[j])     
            temp[k++] = result[i++];                  
        else        
            temp[k++] = result[j++];      
        
        if (i > middle) // 只剩下 第二个子序列了
        {
            // 剩余元素的起始下标rFrom
            // 剩余元素的字节数rByteSize
            int rFrom = j, rByteSize = (to - j + 1) * sizeof(int);
            memcpy(&(temp[k]), &(result[rFrom]), rByteSize);
            break;
        }
        else if (j > to) // 只剩下 第一个子序列了
        {
            // 剩余元素的起始下标rFrom
            // 剩余元素的字节数rByteSize
            int rFrom = i, rByteSize = (middle - i + 1) * sizeof(int);
            memcpy(&(temp[k]), &(result[rFrom]), rByteSize);
            break;
        }
    }

    // 将temp中所有（已排好序）元素拷贝回result
    memcpy(&(result[from]), temp, size * sizeof(int));  

    delete[] temp; // 释放临时空间
}

int main() {
    int origin[8] = {60, 20, 31, 5, 44, 55, 65, 0};
    int result[8];
    MergeSort(origin, result, 0, 7);

    for(int val : result)
    {
        cout << val << "\t";
    }
}