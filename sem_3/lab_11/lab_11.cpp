#include <iostream>
#include <vector>

void quick_sort(std::vector<int>& arr, unsigned int left, unsigned int right)
{
    if (left >= right)
        return;

    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

int main()
{
    std::vector<int> arr = { 15, 8, 4, 42, 23, 16 };

    quick_sort(arr, 0, arr.size() - 1);

    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << ' ';
    }
}