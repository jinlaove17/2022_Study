#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void PrintArray(const string& tag, const vector<int>& v);
void RadixSort(vector<int>& v);
int GetRadix(int n);

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[기수 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);
	RadixSort(v);
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

void RadixSort(vector<int>& v)
{
	int maxValue = 0;

	// 가장 큰 값을 구한다.
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] > maxValue)
		{
			maxValue = v[i];
		}
	}

	// 가장 큰 값의 자리수를 구한다.
	int radix = GetRadix(maxValue);

	// 각 자리수(0 ~ 9)를 저장하기 위한 버킷
	queue<int> q[10];
	int digit = 1;

	for (int i = 0; i < radix; ++i)
	{
		for (int j = 0; j < v.size(); ++j)
		{
			q[(v[j] / digit) % 10].push(v[j]);
		}

		for (int k = 0, l = 0; k < 10; ++k)
		{
			while (!q[k].empty())
			{
				v[l++] = q[k].front();
				q[k].pop();
			}
		}

		digit *= 10;
	}
}

int GetRadix(int n)
{
	int radix = 0;

	while (n > 0)
	{
		++radix;
		n /= 10;
	}

	return radix;
}
