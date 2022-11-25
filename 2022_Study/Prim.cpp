#include <iostream>
#include <vector>
#include <list>

using namespace std;

class CVertex
{
private:
	int m_number;

	int m_weight;

public:
	CVertex(int number, int weight) :
		m_number(number),
		m_weight(weight)
	{
	}
	~CVertex() = default;

	int GetNumber()
	{
		return m_number;
	}

	int GetWeight()
	{
		return m_weight;
	}
};

void Prim(int vertexCount, vector<list<CVertex>>& v, int start);
int GetMinVertex(int vertexCount, const vector<bool>& isVisited, const vector<int>& distances);

int main()
{
	int vertexCount = 7;
	vector<list<CVertex>> v(vertexCount);

	v[0].push_back(CVertex(1, 29));
	v[0].push_back(CVertex(5, 10));

	v[1].push_back(CVertex(0, 29));
	v[1].push_back(CVertex(2, 16));
	v[1].push_back(CVertex(6, 15));

	v[2].push_back(CVertex(1, 16));
	v[2].push_back(CVertex(3, 12));

	v[3].push_back(CVertex(2, 12));
	v[3].push_back(CVertex(4, 22));
	v[3].push_back(CVertex(6, 18));

	v[4].push_back(CVertex(3, 22));
	v[4].push_back(CVertex(5, 27));
	v[4].push_back(CVertex(6, 25));

	v[5].push_back(CVertex(0, 10));
	v[5].push_back(CVertex(4, 27));

	v[6].push_back(CVertex(1, 15));
	v[6].push_back(CVertex(3, 18));
	v[6].push_back(CVertex(4, 25));

	cout << "[프림 최소 신장 트리]" << endl;

	Prim(vertexCount, v, 0);
}

void Prim(int vertexCount, vector<list<CVertex>>& v, int start)
{
	vector<bool> isVisited(vertexCount);
	vector<int> distances(vertexCount, INT_MAX);

	distances[start] = 0;

	for (int i = 0; i < vertexCount; ++i)
	{
		int minVertex = GetMinVertex(vertexCount, isVisited, distances);

		if (minVertex == -1)
		{
			break;
		}

		isVisited[minVertex] = true;

		cout << "정점 " << minVertex << " 선택" << endl;

		for (auto& nearVertex : v[minVertex])
		{
			int number = nearVertex.GetNumber();
			int weight = nearVertex.GetWeight();

			if (!isVisited[number] && weight < distances[number])
			{
				distances[number] = weight;
			}
		}
	}
}

int GetMinVertex(int vertexCount, const vector<bool>& isVisited, const vector<int>& distances)
{
	int minVertex = -1;
	int minDistance = INT_MAX;

	for (int i = 0; i < vertexCount; ++i)
	{
		if (!isVisited[i] && distances[i] < minDistance)
		{
			minVertex = i;
			minDistance = distances[i];
		}
	}

	return minVertex;
}
