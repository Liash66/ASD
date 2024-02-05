#include <iostream>
#include <vector>

void comb_sort(std::vector<int>& arr)
{
	double factor = 1.2473309;
	int step = arr.size() - 1;

	while (step >= 1)
	{
		for (size_t i = 0; i + step < arr.size(); i++)
		{
			if (arr[i] > arr[i + step])
				std::swap(arr[i], arr[i + step]);
		}

		step /= factor;
	}
}

int main()
{
	std::vector<int> arr = { 15, 8, 4, 42, 23, 16 };

	comb_sort(arr);

	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ' ';
	}
}