#include <iostream>
#include <vector>

using namespace std;

void PrintArray(const string& tag, const vector<int>& v);
void MergeSort(vector<int>& v, int begin, int end);
void Merge(vector<int>& v, int begin, int mid, int end);

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[합병 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);
	MergeSort(v, 0, v.size() - 1);
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

void MergeSort(vector<int>& v, int begin, int end)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;

		MergeSort(v, begin, mid);
		MergeSort(v, mid + 1, end);
		Merge(v, begin, mid, end);
	}
}

void Merge(vector<int>& v, int begin, int mid, int end)
{
	vector<int> sorted(v.size());
	int i = begin;
	int j = mid + 1;
	int k = i;

	while (i <= mid && j <= end)
	{
		if (v[i] <= v[j])
		{
			sorted[k++] = v[i++];
		}
		else
		{
			sorted[k++] = v[j++];
		}
	}

	if (i <= mid)
	{
		for (; i <= mid; ++i)
		{
			sorted[k++] = v[i];
		}
	}
	else
	{
		for (; j <= end; ++j)
		{
			sorted[k++] = v[j];
		}
	}

	for (int l = begin; l <= end; ++l)
	{
		v[l] = sorted[l];
	}
}
