#include <iostream>
#include <vector>

using namespace std;

void PrintArray(const string& tag, const vector<int>& v);
void ShellSort(vector<int>& v);
void InsertionSort(vector<int>& v, int begin, int end, int gap);

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[셸 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);
	ShellSort(v);
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

void ShellSort(vector<int>& v)
{
	for (int gap = v.size() / 2; gap > 0; gap /= 2)
	{
		if (gap % 2 == 0)
		{
			++gap;
		}

		for (int i = 0; i < gap; ++i)
		{
			InsertionSort(v, i, v.size() - 1, gap);
		}
	}
}

void InsertionSort(vector<int>& v, int begin, int end, int gap)
{
	for (int i = begin + gap, j = 0; i <= end; i += gap)
	{
		int key = v[i];

		for (j = i - gap; j >= begin && key < v[j]; j -= gap)
		{
			v[j + gap] = v[j];
		}

		v[j + gap] = key;
	}
}
