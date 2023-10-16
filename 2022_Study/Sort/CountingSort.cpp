#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100'001;

int freq[MAX];

void PrintArray(const string& tag, const vector<int>& v);
void CountingSort(vector<int>& v, bool isAscending = true);

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[계수 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);
	CountingSort(v);
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

void CountingSort(vector<int>& v, bool isAscending)
{
	for (int i = 0; i < v.size(); ++i)
	{
		++freq[v[i]];
	}

	int idx = 0;

	if (isAscending)
	{
		for (int i = 0; i < MAX; ++i)
		{
			for (int j = 0; j < freq[i]; ++j)
			{
				v[idx++] = i;
			}
		}
	}
	else
	{
		for (int i = MAX - 1; i >= 0; --i)
		{
			for (int j = 0; j < freq[i]; ++j)
			{
				v[idx++] = i;
			}
		}
	}
}
