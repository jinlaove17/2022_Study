#include <iostream>
#include <vector>
#include <functional>

using namespace std;

struct Less
{
	bool operator()(int a, int b)
	{
		return a <= b;
	}
};

struct Greater
{
	bool operator()(int a, int b)
	{
		return a >= b;
	}
};

void PrintArray(const string& tag, const vector<int>& v);
void QuickSort(vector<int>& v, int begin, int end, function<bool(int, int)> callable = Less());

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[퀵 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);
	QuickSort(v, 0, v.size() - 1); // QuickSort(v, 0, v.size() - 1, Greater());
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

void QuickSort(vector<int>& v, int begin, int end, function<bool(int, int)> callable)
{
	if (begin < end)
	{
		int pivot = begin;
		int left = begin + 1;
		int right = end;

		while (left <= right)
		{
			while ((left <= end) && (callable(v[left], v[pivot])))
			{
				++left;
			}

			while ((right > begin) && (callable(v[pivot], v[right])))
			{
				--right;
			}

			if (left < right)
			{
				swap(v[left], v[right]);
			}
		}

		swap(v[pivot], v[right]);
		QuickSort(v, begin, right - 1, callable);
		QuickSort(v, right + 1, end, callable);
	}
}
