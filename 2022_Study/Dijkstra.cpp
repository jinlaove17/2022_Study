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

void Dijkstra(int vertexCount, vector<list<CVertex>>& v, int start);
int GetMinVertex(int vertexCount, const vector<bool>& isVisited, const vector<int>& distances);

int main()
{
	int vertexCount = 7;
	vector<list<CVertex>> v(vertexCount);

	v[0].push_back(CVertex(1, 7));
	v[0].push_back(CVertex(4, 3));
	v[0].push_back(CVertex(5, 10));

	v[1].push_back(CVertex(0, 7));
	v[1].push_back(CVertex(2, 4));
	v[1].push_back(CVertex(3, 10));
	v[1].push_back(CVertex(4, 2));
	v[1].push_back(CVertex(5, 6));

	v[2].push_back(CVertex(1, 4));
	v[2].push_back(CVertex(3, 2));

	v[3].push_back(CVertex(1, 10));
	v[3].push_back(CVertex(2, 2));
	v[3].push_back(CVertex(4, 11));
	v[3].push_back(CVertex(5, 9));
	v[3].push_back(CVertex(6, 4));

	v[4].push_back(CVertex(0, 3));
	v[4].push_back(CVertex(1, 2));
	v[4].push_back(CVertex(3, 11));
	v[4].push_back(CVertex(6, 5));

	v[5].push_back(CVertex(0, 10));
	v[5].push_back(CVertex(1, 6));
	v[5].push_back(CVertex(3, 9));

	v[6].push_back(CVertex(3, 4));
	v[6].push_back(CVertex(4, 5));

	cout << "[다익스트라 최단 경로]" << endl;

	Dijkstra(vertexCount, v, 0);
}

void Dijkstra(int vertexCount, vector<list<CVertex>>& v, int start)
{
	vector<bool> isVisited(vertexCount);
	vector<int> distances(vertexCount, INT_MAX);

	distances[start] = 0;

	for (int i = 0; i < vertexCount - 1; ++i)
	{
		int minVertex = GetMinVertex(vertexCount, isVisited, distances);

		if (minVertex == -1)
		{
			break;
		}

		isVisited[minVertex] = true;

		for (auto& nearVertex : v[minVertex])
		{
			int number = nearVertex.GetNumber();
			int weight = nearVertex.GetWeight();

			if (!isVisited[number] && distances[minVertex] + weight < distances[number])
			{
				distances[number] = distances[minVertex] + weight;
			}
		}
	}

	for (int i = 0; i < vertexCount; ++i)
	{
		cout << "정점 " << start << "에서 정점 " << i << "까지의 거리: " << distances[i] << endl;
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
