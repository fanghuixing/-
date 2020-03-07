#include <iostream>
#include "Դ.h"
using std::cout;

void MergeSort(int origin[], int result[], int from, int to)
{
    if (from == to) 
        result[from] = origin[from];    //ֻ��һ��Ԫ�أ�ֱ�Ӹ�ֵ
    else {
        int m;
        m = (from + to) / 2;
        MergeSort(origin, result, from, m);    //�鲢����ǰ���������
        MergeSort(origin, result, m + 1, to);   //�鲢�������������
        Merge(result, from, m, to);      //�ϲ������������������
    }
}

void Merge(int result[], int from, int middle, int to)
{
    int size = to - from + 1; // ���ϲ�Ԫ������
    int* temp = new int[size]; // ������ʱ�ռ�洢�ϲ����
    
    int  i = from, j = middle + 1, k = 0;
    // i: ��һ�������е��±�
    // j: �ڶ��������е��±�
    // k: ��ʱ�ռ�temp���±�


    while (true) {

        if (result[i] <= result[j])     
            temp[k++] = result[i++];                  
        else        
            temp[k++] = result[j++];      
        
        if (i > middle) // ֻʣ�� �ڶ�����������
        {
            // ʣ��Ԫ�ص���ʼ�±�rFrom
            // ʣ��Ԫ�ص��ֽ���rByteSize
            int rFrom = j, rByteSize = (to - j + 1) * sizeof(int);
            memcpy(&(temp[k]), &(result[rFrom]), rByteSize);
            break;
        }
        else if (j > to) // ֻʣ�� ��һ����������
        {
            // ʣ��Ԫ�ص���ʼ�±�rFrom
            // ʣ��Ԫ�ص��ֽ���rByteSize
            int rFrom = i, rByteSize = (middle - i + 1) * sizeof(int);
            memcpy(&(temp[k]), &(result[rFrom]), rByteSize);
            break;
        }
    }

    // ��temp�����У����ź���Ԫ�ؿ�����result
    memcpy(&(result[from]), temp, size * sizeof(int));  

    delete[] temp; // �ͷ���ʱ�ռ�
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