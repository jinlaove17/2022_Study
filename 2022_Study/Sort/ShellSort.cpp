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
void ShellSort(vector<int>& v, function<bool(int, int)> callable = Less());
void InsertionSort(vector<int>& v, const function<bool(int, int)>& callable, int begin, int end, int gap);

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[셸 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);
	ShellSort(v); // ShellSort(v, Greater());
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

void ShellSort(vector<int>& v, function<bool(int, int)> callable)
{
	int n = static_cast<int>(v.size());

	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		if (gap % 2 == 0)
		{
			++gap;
		}

		for (int i = 0; i < gap; ++i)
		{
			InsertionSort(v, callable, i, n - 1, gap);
		}
	}
}

void InsertionSort(vector<int>& v, const function<bool(int, int)>& callable, int begin, int end, int gap)
{
	int n = static_cast<int>(v.size());

	for (int i = begin + gap, j = 0; i <= end; i += gap)
	{
		int tmp = v[i];

		for (j = i - gap; j >= begin; j -= gap)
		{
			if (callable(tmp, v[j]))
			{
				v[j + gap] = v[j];
			}
			else
			{
				break;
			}
		}

		v[j + gap] = tmp;
	}
}
