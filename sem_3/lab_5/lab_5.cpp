#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& arr)
{
	for (size_t j = 1; j < arr.size(); j++)
	{
		int key = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i--;
		}

		arr[i + 1] = key;
	}
}

int main()
{
	std::vector<int> arr = { 15, 8, 4, 42, 23, 16 };

	insertion_sort(arr);

	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ' ';
	}
}