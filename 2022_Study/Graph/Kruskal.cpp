#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CEdge
{
private:
	int m_begin;
	int m_end;

	int m_weight;

public:
	CEdge(int begin, int end, int weight) :
		m_begin(begin),
		m_end(end),
		m_weight(weight)
	{
	}
	~CEdge() = default;

	int GetBegin()
	{
		return m_begin;
	}

	int GetEnd()
	{
		return m_end;
	}

	int GetWeight()
	{
		return m_weight;
	}

	bool operator <(const CEdge& rhs)
	{
		return m_weight < rhs.m_weight;
	}
};

void Kruskal(int vertexCount, vector<CEdge>& v);
int GetRoot(const vector<int>& parents, int current);
void SetUnion(vector<int>& parents, int root1, int root2);

int main()
{
	int vertexCount = 7;
	vector<CEdge> v;

	v.emplace_back(0, 1, 29);
	v.emplace_back(1, 2, 16);
	v.emplace_back(2, 3, 12);
	v.emplace_back(3, 4, 22);
	v.emplace_back(4, 5, 27);
	v.emplace_back(5, 0, 10);
	v.emplace_back(6, 1, 15);
	v.emplace_back(6, 3, 18);
	v.emplace_back(6, 4, 25);

	cout << "[ũ�罺Į �ּ� ���� Ʈ��]" << endl;

	Kruskal(vertexCount, v);
}

void Kruskal(int vertexCount, vector<CEdge>& v)
{
	// ����ġ�� �������� ������ ������������ �����Ѵ�.
	sort(v.begin(), v.end());

	// �� ����� �θ� ����ϱ� ���� ����
	vector<int> parents(vertexCount);

	// �ʱ� �θ� �ڱ� �ڽ��� �ε����� �����Ѵ�.
	for (int i = 0; i < vertexCount; ++i)
	{
		parents[i] = i;
	}

	int totalWeight = 0;

	// ������ ������ ��(i)�� ������ �� - 1�� �� ������ �ݺ��Ѵ�.
	for (int i = 0, j = 0; i < vertexCount - 1; ++j)
	{
		int root1 = GetRoot(parents, v[j].GetBegin());
		int root2 = GetRoot(parents, v[j].GetEnd());

		// root1�� root2�� �ٸ��ٴ� ���� �ٸ� ���տ� ���ϴ� ���̹Ƿ� ����Ŭ�� �������� �ʴ� �����̶�� ���� ���Ѵ�.
		if (root1 != root2)
		{
			cout << "���� (" << v[j].GetBegin() << ", " << v[j].GetEnd() << ")[" << v[j].GetWeight() << "] ����" << endl;

			SetUnion(parents, root1, root2);

			totalWeight += v[j].GetWeight();
			++i;
		}
	}

	cout << endl << "�� ����ġ: " << totalWeight << endl;
}

int GetRoot(const vector<int>& parents, int current)
{
	while (parents[current] != current)
	{
		current = parents[current];
	}

	return current;
}

void SetUnion(vector<int>& parents, int root1, int root2)
{
	if (root1 < root2)
	{
		parents[root2] = root1;
	}
	else
	{
		parents[root1] = root2;
	}
}
