#include <iostream>
#include <vector>

using namespace std;

void PrintArray(const string& tag, const vector<int>& v);
void SelectionSort(vector<int>& v);

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[선택 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);
	SelectionSort(v);
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

void SelectionSort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; ++i)
	{
		int minIndex = i;

		for (int j = i + 1; j < v.size(); ++j)
		{
			if (v[j] < v[minIndex])
			{
				minIndex = j;
			}
		}

		swap(v[i], v[minIndex]);
	}
}
