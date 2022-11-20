#include <iostream>
#include <vector>

using namespace std;

void PrintArray(const string& tag, const vector<int>& v);
void InsertionSort(vector<int>& v);

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[삽입 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);
	InsertionSort(v);
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

void InsertionSort(vector<int>& v)
{
	for (int i = 1, j = 0; i < v.size(); ++i)
	{
		int key = v[i];

		for (j = i - 1; j >= 0 && key < v[j]; --j)
		{
			v[j + 1] = v[j];
		}

		v[j + 1] = key;
	}
}
