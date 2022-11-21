#include <iostream>
#include <vector>

using namespace std;

void PrintArray(const string& tag, const vector<int>& v);
void QuickSort(vector<int>& v, int begin, int end);

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[퀵 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);
	QuickSort(v, 0, v.size() - 1);
	PrintArray("▶ 정렬 후", v);
}

void PrintArray(const string& tag, const vector<int>& v)
{
	cout << tag << endl;

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}

	cout << endl << endl;
}

void QuickSort(vector<int>& v, int begin, int end)
{
	if (begin < end)
	{
		int pivot = begin;
		int left = begin + 1;
		int right = end;

		while (left <= right)
		{
			while (left <= end && v[left] < v[pivot])
			{
				++left;
			}

			while (right >= begin && v[right] > v[pivot])
			{
				--right;
			}

			if (left <= right)
			{
				swap(v[left], v[right]);
			}
		}

		swap(v[pivot], v[right]);

		QuickSort(v, begin, right);
		QuickSort(v, left, end);
	}
}
