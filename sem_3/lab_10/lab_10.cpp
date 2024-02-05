#include <iostream>
#include <vector>

void merge_sort(std::vector<int>& arr)
{
	size_t BlockSizeIterator;
	size_t BlockIterator;
	size_t LeftBlockIterator;
	size_t RightBlockIterator;
	size_t MergeIterator;

	size_t LeftBorder;
	size_t MidBorder;
	size_t RightBorder;

	for (BlockSizeIterator = 1; BlockSizeIterator < arr.size(); BlockSizeIterator *= 2)
	{
		for (BlockIterator = 0; BlockIterator < arr.size() - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
		{
			LeftBlockIterator = 0;
			RightBlockIterator = 0;
			LeftBorder = BlockIterator;
			MidBorder = BlockIterator + BlockSizeIterator;
			RightBorder = BlockIterator + 2 * BlockSizeIterator;
			RightBorder = (RightBorder < arr.size()) ? RightBorder : arr.size();
			int* SortedBlock = new int[RightBorder - LeftBorder];

			while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
			{
				if (arr[LeftBorder + LeftBlockIterator] < arr[MidBorder + RightBlockIterator])
				{
					SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator];
					LeftBlockIterator += 1;
				}
				else
				{
					SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator];
					RightBlockIterator += 1;
				}
			}

			while (LeftBorder + LeftBlockIterator < MidBorder)
			{
				SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator];
				LeftBlockIterator += 1;
			}
			while (MidBorder + RightBlockIterator < RightBorder)
			{
				SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator];
				RightBlockIterator += 1;
			}

			for (MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
			{
				arr[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
			}
			delete SortedBlock;
		}
	}
}

int main()
{
    std::vector<int> arr = { 15, 8, 4, 42, 23, 16 };

    merge_sort(arr, 0, arr.size() - 1);

    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << ' ';
    }
}