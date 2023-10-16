#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void PrintArray(const string& tag, const vector<int>& v);
void RadixSort(vector<int>& v, bool isAscending = true);
int GetMSD(int num);

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[기수 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);
	RadixSort(v); // RadixSort(v, false);
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

void RadixSort(vector<int>& v, bool isAscending)
{
	int maxValue = 0;

	// 최댓값을 구한다.
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] > maxValue)
		{
			maxValue = v[i];
		}
	}

	// 최댓값의 자리수를 구한다.
	int msd = GetMSD(maxValue);

	// 각 자리수(0 ~ 9)를 저장하기 위한 버킷
	queue<int> bucket[10];
	int digit = 1;

	for (int i = 0; i < msd; ++i)
	{
		for (int j = 0; j < v.size(); ++j)
		{
			bucket[(v[j] / digit) % 10].push(v[j]);
		}

		if (isAscending)
		{
			for (int k = 0, l = 0; k < 10; ++k)
			{
				while (!bucket[k].empty())
				{
					v[l++] = bucket[k].front();
					bucket[k].pop();
				}
			}
		}
		else
		{
			for (int k = 9, l = 0; k >= 0; --k)
			{
				while (!bucket[k].empty())
				{
					v[l++] = bucket[k].front();
					bucket[k].pop();
				}
			}
		}

		digit *= 10;
	}
}

int GetMSD(int num)
{
	int digit = 0;

	while (num > 0)
	{
		++digit;
		num /= 10;
	}

	return digit;
}
