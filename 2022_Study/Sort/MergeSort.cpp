#include <iostream>
#include <vector>
#include <functional>

using namespace std;

struct Less
{
	bool operator()(int a, int b)
	{
		// stable: <=
		return a <= b;
	}
};

struct Greater
{
	bool operator()(int a, int b)
	{
		// stable: <=
		return a >= b;
	}
};

void PrintArray(const string& tag, const vector<int>& v);
void MergeSort(vector<int>& v, int begin, int end, function<bool(int, int)> callable = Less());
void Merge(vector<int>& v, const function<bool(int, int)>& callable, int begin, int mid, int end);

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[합병 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);
	MergeSort(v, 0, v.size() - 1); // MergeSort(v, 0, v.size() - 1, Greater());
	PrintArray("▶ 정렬 후", v);
}

void PrintArray(const string& tag, const vector<int>& v)
{
	cout << tag << endl;

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << ' ';
	}

	cout << endl << endl;
}

void MergeSort(vector<int>& v, int begin, int end, function<bool(int, int)> callable)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;

		MergeSort(v, begin, mid, callable);
		MergeSort(v, mid + 1, end, callable);
		Merge(v, callable, begin, mid, end);
	}
}

void Merge(vector<int>& v, const function<bool(int, int)>& callable, int begin, int mid, int end)
{
	vector<int> tmp(v.size());
	int i = begin;
	int j = mid + 1;
	int k = begin;

	while ((i <= mid) && (j <= end))
	{
		if (callable(v[i], v[j]))
		{
			tmp[k++] = v[i++];
		}
		else
		{
			tmp[k++] = v[j++];
		}
	}

	while (i <= mid)
	{
		tmp[k++] = v[i++];
	}

	while (j <= end)
	{
		tmp[k++] = v[j++];
	}

	for (int l = begin; l <= end; ++l)
	{
		v[l] = tmp[l];
	}
}
