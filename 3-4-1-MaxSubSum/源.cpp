#include <iostream>
#include <algorithm>
#include "源.h"
using std::max;
using std::cout;
using std::endl;
// 向左连续求和标记
#define LEFT 0    
// 向右连续求和标记
#define RIGHT 1

/** 求序列最大子段和问题 
 **
*/
int MaxSubSum(int *A, int left, int right) {
	// 如果只有一个元素
	if ( left == right )  return max(0, A[left]);
	
	int center = (left + right) / 2;     // 中点下标
    // 左子序列最大子段和
	int LeftSum = MaxSubSum( A, left, center );
	// 右子序列最大子段和
	int	RightSum = MaxSubSum( A, left + 1, right );
	// 中序列最大子段和
	// 向左连续延伸最大值 + 向右连续延伸最大值
	int	CenterSum = MaxSum(A, LEFT, left, center) + 
		            MaxSum(A, RIGHT, center + 1, right);    
	return  max(max(LeftSum, CenterSum), RightSum);
}

int MaxSum(int* A, int flag, int left, int right)
{
	int Sum = 0;
	int max = 0;
	if ( flag == LEFT )
	{		
		int i = right;
		while (i >= left) {			
			Sum = Sum + A[i];
			if (Sum > max) max = Sum;
			i--;
		}

	}
	else
	{
		int i = left;
		while (i <= right) {
			Sum = Sum + A[i];
			if (Sum > max) max = Sum;
			i++;
		}
	}
	return max;
}

int main() {
	int A[] = {-20,-11,-400,-130,-5,-2};
	int size = sizeof(A) / sizeof(int);
	
	for (int i=0; i<size; i++)
	{
		cout << A[i] << "\t";
	}
	
	cout << endl;
	
	cout<< MaxSubSum(A, 0, size - 1) << endl;
}