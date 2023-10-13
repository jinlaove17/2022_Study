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
void BubbleSort(vector<int>& v, function<bool(int, int)> callable = Less());

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[버블 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);
	BubbleSort(v); // BubbleSort(v, Greater());
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

void BubbleSort(vector<int>& v, function<bool(int, int)> callable)
{
	int n = static_cast<int>(v.size());

	for (int i = n - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (callable(v[j + 1], v[j]))
			{
				swap(v[j], v[j + 1]);
			}
		}
	}
}
