#include <iostream>
#include <iomanip>
#include <vector>
#include <list>

using namespace std;

class CVertex
{
public:
	static const int INF = 9999;

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

void Floyd(int vertexCount, vector<vector<int>>& v);

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

	cout << "[플로이드 최단 경로]" << endl;

	// 계산의 편의성을 위하여 주어진 인접리스트를 이용하여 인접행렬을 만든다.
	vector<vector<int>> adjMat(v.size(), vector<int>(v.size(), CVertex::INF));

	for (int i = 0; i < vertexCount; ++i)
	{
		adjMat[i][i] = 0;

		for (auto& vertex : v[i])
		{
			int number = vertex.GetNumber();
			int weight = vertex.GetWeight();

			adjMat[i][number] = weight;
			adjMat[number][i] = weight;
		}
	}

	Floyd(vertexCount, adjMat);
}

void Floyd(int vertexCount, vector<vector<int>>& v)
{
	for (int k = 0; k < vertexCount; ++k)
	{
		for (int i = 0; i < vertexCount; ++i)
		{
			for (int j = 0; j < vertexCount; ++j)
			{
				if (v[i][k] + v[k][j] < v[i][j])
				{
					v[i][j] = v[i][k] + v[k][j];
				}
			}
		}
	}

	for (int i = 0; i < vertexCount; ++i)
	{
		for (int j = 0; j < vertexCount; ++j)
		{
			cout << setw(2) << v[i][j] << " ";
		}

		cout << endl;
	}
}
