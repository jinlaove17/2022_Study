#include <iostream>
#include <vector>
#include <functional>

using namespace std;

struct Less
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

struct Greater
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

void PrintArray(const string& tag, const vector<int>& v);
void SelectionSort(vector<int>& v, function<bool(int, int)> callable = Less());

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[선택 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);
	SelectionSort(v); // SelectionSort(v, Greater());
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

void SelectionSort(vector<int>& v, function<bool(int, int)> callable)
{
	int n = static_cast<int>(v.size());

	for (int i = 0; i < n - 1; ++i)
	{
		int cur = i;

		for (int j = i + 1; j < n; ++j)
		{
			if (callable(v[j], v[cur]))
			{
				cur = j;
			}
		}

		swap(v[i], v[cur]);
	}
}
