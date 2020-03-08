#pragma once
template <class Type>
class MergeSort {
private:
	void Merge(Type result[], int from, int middle, int to);
public:
	void Sort(Type origin[], Type result[], int from, int to);

};

/**
 ** �ϲ�result����������������
 ** �����������±�ֱ�Ϊ
 ** 1�� from ~ middle
 ** 2�� middle + 1 ~ to
 ** �ϲ���Ľ����Ȼ�����result��
*/
template<class Type>
void MergeSort<Type>::Merge(Type result[], int from, int middle, int to)
{

    int size = to - from + 1; // ���ϲ�Ԫ������
    Type* temp = new Type[size]; // ������ʱ�ռ�洢�ϲ����

    int  i = from, j = middle + 1, k = 0;
    // i: ��һ�������е��±�
    // j: �ڶ��������е��±�
    // k: ��ʱ�ռ�temp���±�

    // ѭ����ÿ�ε���ѡȡһ����СԪ��ŵ�temp��
    while ( i <= middle && j <= to ) {
        if (result[i] <= result[j])
            temp[k++] = result[i++];
        else
            temp[k++] = result[j++];
    } // while����

    if (i > middle) // ֻʣ�µڶ�����������
    {
        // ʣ��Ԫ�ص���ʼ�±�rFrom
        // ʣ��Ԫ�ص��ֽ���rByteSize
        int rFrom = j, rByteSize = (to - j + 1) * sizeof(Type);
        memcpy(&(temp[k]), &(result[rFrom]), rByteSize);        
    }
    else if (j > to) // ֻʣ�� ��һ����������
    {
        // ʣ��Ԫ�ص���ʼ�±�rFrom
        // ʣ��Ԫ�ص��ֽ���rByteSize
        int rFrom = i, rByteSize = (middle - i + 1) * sizeof(Type);
        memcpy(&(temp[k]), &(result[rFrom]), rByteSize);
    }

    // ��temp�����У����ź���Ԫ�ؿ�����result
    memcpy(&(result[from]), temp, size * sizeof(Type));

    delete[] temp; // �ͷ���ʱ�ռ�
}

/**
 ** ���ֹ鲢����
 **  origin�� ԭ����
 **  result�� �������������
 **  from : ������ʼԪ���±�
 **    to : ���Ž���Ԫ���±�
*/
template<class Type>
void MergeSort<Type>::
Sort(Type origin[], Type result[], int from, int to)
{
    if (from == to) // ֻ��һ��Ԫ�أ�ֱ�Ӹ�ֵ
        result[from] = origin[from];    
    else { // ���Ԫ�أ�����
        int m;
        m = (from + to) / 2;
        Sort(origin, result, from, m);    // �鲢����ǰ���������
        Sort(origin, result, m + 1, to);  // �鲢�������������
        Merge(result, from, m, to);       // �ϲ������������������
    }
}


