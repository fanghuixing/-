#include <iostream>
using namespace std;
//===============================================
//函数名称：partition
//函数功能：实现对序列a[x]~a[y]进行划分
//函数参数说明： a[]:要排序的序列，x和y分别为该序列的最小下标和最大下标
//函数返回值：int
//===============================================
int partition(int* a, int left, int right)
{
    int i = left, j = right + 1;
    do
    {
        do i++; while (a[i] < a[left] && i < right);
        do j--; while (a[j] > a[left]);
        if (i < j) { int t = a[i]; a[i] = a[j]; a[j] = t; }
    } while (i < j);
    int t = a[left]; a[left] = a[j]; a[j] = t;
    return j;
}
//===============================================
//函数名称：quickSort
//函数功能：对序列a[x]~a[y]快速排序
//函数参数说明： a[]:要排序的序列，x和y分别为该序列的最小下标和最大下标
//函数返回值：void
//===============================================
//快速排序，区间为[x,y]  
void quickSort(int* a, int x, int y) {
    if (x < y)//如果只有一个元素，不用排序  
    {
        //划分成左右两个部分（尽量等长）
        // m是主元（应该在）的位置  
        int m = partition(a, x, y);
        //递归解决左右两边的排序  
        quickSort(a, x, m - 1);
        quickSort(a, m + 1, y);
        //不用合并，此时已经有序  
    }
}
//===============================================
//函数名称：main
//函数功能：对具体序列a[0]~a[n-1]快速排序
//函数参数说明： 
//函数返回值：int
//===============================================
int main()
{
    int n, i;
    int a[100];
    cout << "请输入数组的规模n：";
    cin >> n;
    cout << "\n请输入按要排序的" << n << "个元素：";
    for (i = 0; i < n; i++) scanf("%d", &a[i]);  //输入数据  
    cout << "\n输出排序前的" << n << "个元素：";
    for (i = 0; i < n; i++) printf("%d ", a[i]);  //输入数据  
    cout << endl;
    quickSort(a, 0, n - 1);
    cout << "\n输出排序后的" << n << "个元素：";
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n\n\n");
    return 0;
}
