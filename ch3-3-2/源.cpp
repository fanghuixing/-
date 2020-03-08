/** 选择序列的第k小元素
 ** Select
*/

#include <iostream>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <stdlib.h>
#include "源.h"


using std::sort;
using std::cout;
using std::endl;

/** 返回序列S中的中位数
 ** n为序列长度 (n <= 5)
*/
int middle(int* S, int n) {
    // 如果序列中只有一个元素，就直接返回
    if ( n == 1 )  return S[0];

    // 先排序
    sort(S, S + n);

    if (n % 2 == 0 ) // 如果n是偶数，返回下中位数
    {
        return S[n/2 - 1]; 
    }

    return S[n/2]; //  n为奇数，则返回正中位数
}

int partition(int* a, int left, int right)
{
    int i = left, j = right + 1;
    do
    {
        do i++; while (a[i] < a[left] && i < right);
        do j--; while (a[j] > a[left] && j>0);
        if (i < j) { int t = a[i]; a[i] = a[j]; a[j] = t; }
    } while (i < j);
    int t = a[left]; a[left] = a[j]; a[j] = t;
    return j;
}

// 返回p在当前数组S中的位置
int findCurrentPos(int* S, int p) {
    for ( int i = 0;  ; i++)
        if (S[i] == p)  return i;    
}

// S 有n个元素
// 返回S中第k小元素
int Select(int* S, int n, int k) {

    if (n <= 5) { sort(S, S + n);  return S[k-1]; }
    // 每5个元素1组
    int arrayNum = ceil(n / 5.0); 
    // 存放所有组的中位数
    int* MiddleValues = new int[arrayNum]; 
    
    for (int i = 0, j = 0; i < n; i = i + 5) {
        if( i <= n - 5 )
            MiddleValues[j++] = middle(S + i, 5);
        else if ( i <= n - 1 )
            MiddleValues[j++] = middle(S + i, n - i);                
    }
    //S 的中位数    
    int p = Select(MiddleValues, arrayNum, ceil(arrayNum / 2.0));

    // 找到标准数的下标
    int curPos = findCurrentPos(S, p);

    // 把标准数放在首位
    S[curPos] = S[0]; S[0] = p; curPos = 0;

    // 划分，返回标准数应该在的位置
    int midPos = partition(S, curPos, n - 1);

    // 设置左右两部分子序列信息
    int *S1 = S;
    int i1 = midPos;
    int *S2 = S + midPos + 1;
    int i2 = n - i1 - 1;
      
    // 如果是标准数就是要找的数，就直接返回
    if (k == i1 + 1) return p;
    if (k <= i1) // 如果在左边
        return Select(S1, i1, k);
    else // 如果在右边
        return Select(S2, i2, k - i1 - 1);
}


int main() {
    srand(time(0));
    int N = 99999; // 数组长度
    int* a = new int[N];
    while (true) {
        for (int i = 0; i < N; i++) {
            a[i] = rand();            
        }
                
        //cout << "随机数生成完毕" << endl;

        int k = rand() % N + 1;

        cout << "检查第"<< k <<"个," ;

        int res = Select(a, N, k);

        sort(a, a + N);
        if (a[k - 1] != res) {
            cout << "不匹配" << endl;
            for (int i = 0; i < N; i++) {
                cout << a[i] << "\t";
                return EXIT_FAILURE;
            }
        }
        else 
            cout << "匹配" << endl;
    }
   
    return 0;
}