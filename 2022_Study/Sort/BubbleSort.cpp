#include <iostream>
#include <vector>

using namespace std;

void PrintArray(const string& tag, const vector<int>& v);
void BubbleSort(vector<int>& v);

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[버블 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);
	BubbleSort(v);
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

void BubbleSort(vector<int>& v)
{
	for (int i = v.size() - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
			}
		}
	}
}
