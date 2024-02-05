#include <iostream>
#include <vector>

void shell_sort(std::vector<int>& arr)
{
	int step, tmp, j;
	 
	for (size_t step = arr.size() / 2; step > 0; step /= 2)
	{
		for (size_t i = step; i < arr.size(); i++)
		{
			tmp = arr[i];

			for (j = i; j >= step; j -= step)
			{
				if (tmp < arr[j - step])
					arr[j] = arr[j - step];
				else
					break;
			}

			arr[j] = tmp;
		}
	}
}

int main()
{
	std::vector<int> arr = { 15, 8, 4, 42, 23, 16 };

	shell_sort(arr);

	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ' ';
	}
}