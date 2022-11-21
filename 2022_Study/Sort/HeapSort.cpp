#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class CHeap
{
private:
	vector<T> m_heap;

public:
	CHeap() = default;
	~CHeap() = default;

	void Insert(T n)
	{
		m_heap.push_back(n);

		int i = m_heap.size() - 1;
		int parent = (i - 1) / 2;

		while (i > 0 && m_heap[i] < m_heap[parent])
		{
			swap(m_heap[i], m_heap[parent]);

			i = parent;
			parent = (i - 1) / 2;
		}
	}

	T Delete()
	{
		T root = m_heap.front();
		T last = m_heap.back();

		m_heap.pop_back();

		if (!m_heap.empty())
		{
			int parent = 0;
			int child = 1;

			while (child < m_heap.size())
			{
				if (child < m_heap.size() - 1 && m_heap[child + 1] < m_heap[child])
				{
					++child;
				}

				if (last <= m_heap[child])
				{
					break;
				}

				m_heap[parent] = m_heap[child];

				parent = child;
				child = 2 * parent;
			}

			m_heap[parent] = last;
		}

		return root;
	}
};

void PrintArray(const string& tag, const vector<int>& v);

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[힙 정렬]" << endl << endl;

	PrintArray("▶ 정렬 전", v);

	CHeap<int> heap;

	for (int i = 0; i < v.size(); ++i)
	{
		heap.Insert(v[i]);
	}

	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = heap.Delete();
	}

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
