#include <iostream>
#include <vector>

void selection_sort(std::vector<int>& arr)
{
	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		int min_index = i;

		for (size_t j = i + 1; j < arr.size(); j++)
		{
			if (arr[j] < arr[min_index])
				min_index = j;
		}

		if (min_index != i)
			std::swap(arr[i], arr[min_index]);
	}
}

int main()
{
	std::vector<int> arr = { 15, 8, 4, 42, 23, 16 };

	selection_sort(arr);

	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ' ';
	}
}