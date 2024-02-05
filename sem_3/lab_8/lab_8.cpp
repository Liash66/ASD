#include <iostream>
#include <vector>
#include <algorithm>

void radix_sort(std::vector<int>& arr)
{
	int max = *max_element(arr.begin(), arr.end());

	for (size_t exp = 1; max / exp > 0; exp *= 10)
	{
		std::vector<int> buckets[10];

		for (int num : arr)
		{
			int digit = (num / exp) % 10;
			buckets[digit].push_back(num);
		}
		
		int index = 0;
		for (size_t i = 0; i < 10; i++)
		{
			for (int num : buckets[i])
			{
				arr[index++] = num;
			}
		}
	}
}

int main()
{
	std::vector<int> arr = { 15, 8, 4, 42, 23, 16 };

	radix_sort(arr);

	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ' ';
	}
}