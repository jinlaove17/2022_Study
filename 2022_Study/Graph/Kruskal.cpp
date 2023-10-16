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

	cout << "[크루스칼 최소 신장 트리]" << endl;

	Kruskal(vertexCount, v);
}

void Kruskal(int vertexCount, vector<CEdge>& v)
{
	// 가중치를 기준으로 간선을 오름차순으로 정렬한다.
	sort(v.begin(), v.end());

	// 각 노드의 부모를 기록하기 위한 벡터
	vector<int> parents(vertexCount);

	// 초기 부모를 자기 자신의 인덱스로 설정한다.
	for (int i = 0; i < vertexCount; ++i)
	{
		parents[i] = i;
	}

	int totalWeight = 0;

	// 선택한 간선의 수(i)가 정점의 수 - 1이 될 때까지 반복한다.
	for (int i = 0, j = 0; i < vertexCount - 1; ++j)
	{
		int root1 = GetRoot(parents, v[j].GetBegin());
		int root2 = GetRoot(parents, v[j].GetEnd());

		// root1과 root2가 다르다는 것은 다른 집합에 속하는 것이므로 사이클을 형성하지 않는 간선이라는 것을 뜻한다.
		if (root1 != root2)
		{
			cout << "간선 (" << v[j].GetBegin() << ", " << v[j].GetEnd() << ")[" << v[j].GetWeight() << "] 선택" << endl;

			SetUnion(parents, root1, root2);

			totalWeight += v[j].GetWeight();
			++i;
		}
	}

	cout << endl << "총 가중치: " << totalWeight << endl;
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
