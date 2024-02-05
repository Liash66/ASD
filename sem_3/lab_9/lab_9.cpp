#include <iostream>
#include <vector>

void heap_sort(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int j = i;
        while (j > 0 && arr[j] > arr[(j - 1) / 2])
        {
            std::swap(arr[j], arr[(j - 1) / 2]);
            j = (j - 1) / 2;
        }
    }

    for (int i = arr.size() - 1; i >= 1; i--)
    {
        std::swap(arr[0], arr[i]);
        int j = 0;

        while (2 * j + 1 < i)
        {
            int k = 2 * j + 1;
            
            if (k + 1 < i && arr[k + 1] > arr[k])
                k++;

            if (arr[k] > arr[j])
            {
                std::swap(arr[j], arr[k]);
                j = k;
            }
            else
                break;
        }
    }
}

int main()
{
	std::vector<int> arr = { 15, 8, 4, 42, 23, 16 };

	heap_sort(arr);

	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ' ';
	}
}