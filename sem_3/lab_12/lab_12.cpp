#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void merge_sort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    vector<int> temp(right - left + 1);

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int i = left; i <= right; i++)
        arr[i] = temp[i - left];
}

int main()
{
    std::ifstream inA("A.txt", std::ios::in);
    std::ifstream inB("B.txt", std::ios::in);
    std::ofstream out;

    vector<int> arrA;
    vector<int> arrB;
    vector<int> arrC;

    if (inA.is_open())
    {
        int x;
        while (inA >> x)
            arrA.push_back(x);
    }

    merge_sort(arrA, 0, arrA.size() - 1);

    if (inA.is_open())
    {
        int x;
        while (inB >> x)
            arrB.push_back(x);
    }

    for (size_t i = 0; i < arrA.size(); i++)
    {
        arrC.push_back(arrA[i]);
    }

    for (size_t i = 0; i < arrB.size(); i++)
    {
        arrC.push_back(arrB[i]);
    }

    merge_sort(arrC, 0, arrC.size() - 1);

    out.open("C.txt");

    for (size_t i = 0; i < arrC.size(); i++)
        out << arrC[i] << " ";

    out.close();

    return 0;
}