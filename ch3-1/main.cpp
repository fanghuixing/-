#include <iostream>
#include "MergeSort.h"
using std::cout;
using std::endl;

int main() {
    // ��������
    double origin[8] = { 60.4, 20.9, 31.1, 5.5, 44.3, 55.8, 65.1, 0.2 };
    double result[8];

    MergeSort<double> ms;

    ms.Sort(origin, result, 0, 7);

    // ��ӡ���
    for (double val : result)
    {
        cout << val << "\t";
    }

    cout << endl;
}