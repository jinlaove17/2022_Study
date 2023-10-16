#include <iostream>
#include <vector>
#include <functional>
#include <cassert>

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

// STL�� priority_queueó�� Default�� Less�� ����ϴ� �ִ����̰�, Greater�� ����Ͽ� �ּ������� ���� �� �ֵ��� �����Ͽ���.
// m_elemenets�� �ε����� 0���� �����Ѵ�.
template<typename T, typename Callable = Less>
class CHeap
{
private:
	vector<T> m_elements;

public:
	void Insert(const T& val)
	{
		m_elements.push_back(val);

		int cur = static_cast<int>(m_elements.size()) - 1;
		int parent = (cur - 1) / 2;

		while ((parent >= 0) && Callable()(m_elements[parent], m_elements[cur]))
		{
			swap(m_elements[cur], m_elements[parent]);
			cur = parent;
			parent = (cur - 1) / 2;
		}
	}

	T Delete()
	{
		assert(m_elements.size() > 0);

		T root = move(m_elements.front());
		T last = move(m_elements.back());

		m_elements.pop_back();

		if (!m_elements.empty())
		{
			int parent = 0;
			int child = 1;

			while (child < m_elements.size())
			{
				if ((child < m_elements.size() - 1) && Callable()(m_elements[child], m_elements[child + 1]))
				{
					++child;
				}

				if (Callable()(m_elements[child], last))
				{
					break;
				}

				m_elements[parent] = m_elements[child];
				parent = child;
				child = 2 * parent + 1;
			}

			m_elements[parent] = last;
		}

		return root;
	}
};

void PrintArray(const string& tag, const vector<int>& v);

int main()
{
	vector<int> v = { 5, 1, 7, 9, 6, 2, 10, 8, 3, 4 };

	cout << "[�� ����]" << endl << endl;

	PrintArray("�� ���� ��", v);

	CHeap<int> maxHeap; // CHeap<int, Greater> minHeap;

	for (int i = 0; i < v.size(); ++i)
	{
		maxHeap.Insert(v[i]);
	}

	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = maxHeap.Delete();
	}

	PrintArray("�� ���� ��", v);
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
