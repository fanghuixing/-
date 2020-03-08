#include <iostream>
using namespace std;
//===============================================
//函数名称：binarySearch2
//函数功能：在有序序列a[left]~a[right]中进行查找元素v 
//函数参数说明： a[]:要查找的序列，left和right分别为该序列的最小下标和最大下标，v为待查的元素
//函数返回值：int
//===============================================
int binarySearch(int* a, int left, int right, int v)    //半开区间[left,right)  
{
    if (right - left == 1)     //递归边界处理  
    {
        if (v == a[left]) return left + 1;
        else return -1;    //所找元素不存在  
    }
    else    //尚未达到边界，继续划分  
    {
        int m = left + (right - left) / 2;
        if (v == a[m]) return m + 1;
        else if (v < a[m])   //在左边查找  
            return binarySearch(a, left, m, v);
        else   //在右边查找  
            return binarySearch(a, m + 1, right, v);
    }
}

//===============================================
//函数名称：main
//函数功能：在具体的升序序列a[0]~a[n-1]中查找元素x
//函数参数说明： 
//函数返回值：int
//===============================================
int main()
{
    int n, x, y;
    int a[100];
    cout << "请输入数组的规模n：";
    cin >> n;
    cout << "\n请输入要查找的数:";
    cin >> x;
    cout << "\n请输入按升序排列的" << n << "个的元素：";
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);  //输入数据  
    cout << endl;
    y = binarySearch(a, 0, n - 1, x);
    if (y != -1)
        cout << "找到数" << x << "位于数组中的第" << y << "元素\n" << endl;
    else
        cout << "没找到！\n" << endl;
    return 0;
}
