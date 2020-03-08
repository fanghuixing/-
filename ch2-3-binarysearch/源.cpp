#include <iostream>
using namespace std;
//===============================================
//�������ƣ�binarySearch2
//�������ܣ�����������a[left]~a[right]�н��в���Ԫ��v 
//��������˵���� a[]:Ҫ���ҵ����У�left��right�ֱ�Ϊ�����е���С�±������±꣬vΪ�����Ԫ��
//��������ֵ��int
//===============================================
int binarySearch(int* a, int left, int right, int v)    //�뿪����[left,right)  
{
    if (right - left == 1)     //�ݹ�߽紦��  
    {
        if (v == a[left]) return left + 1;
        else return -1;    //����Ԫ�ز�����  
    }
    else    //��δ�ﵽ�߽磬��������  
    {
        int m = left + (right - left) / 2;
        if (v == a[m]) return m + 1;
        else if (v < a[m])   //����߲���  
            return binarySearch(a, left, m, v);
        else   //���ұ߲���  
            return binarySearch(a, m + 1, right, v);
    }
}

//===============================================
//�������ƣ�main
//�������ܣ��ھ������������a[0]~a[n-1]�в���Ԫ��x
//��������˵���� 
//��������ֵ��int
//===============================================
int main()
{
    int n, x, y;
    int a[100];
    cout << "����������Ĺ�ģn��";
    cin >> n;
    cout << "\n������Ҫ���ҵ���:";
    cin >> x;
    cout << "\n�����밴�������е�" << n << "����Ԫ�أ�";
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);  //��������  
    cout << endl;
    y = binarySearch(a, 0, n - 1, x);
    if (y != -1)
        cout << "�ҵ���" << x << "λ�������еĵ�" << y << "Ԫ��\n" << endl;
    else
        cout << "û�ҵ���\n" << endl;
    return 0;
}
