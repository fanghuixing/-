#include <iostream>
#include "Դ.h"
using std::cout;
using std::endl;

int main() {
    // ��������
    int origin[8] = { 60, 20, 31, 5, 44, 55, 65, 0 };
    int result[8];
    MergeSort(origin, result, 0, 7);

    // ��ӡ���
    for (int val : result)
    {
        cout << val << "\t";
    }

    cout << endl;
}