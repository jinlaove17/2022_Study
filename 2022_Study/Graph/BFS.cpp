#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

void BFS(const vector<vector<int>>& adjMat, vector<bool>& isVisited, int current);
void BFS(const vector<list<int>>& adjList, vector<bool>& isVisited, int current);

int main()
{
	cout << "      1   " << endl;
	cout << "     / ＼ " << endl;
	cout << "    2   3 " << endl;
	cout << "  ／ ＼	   " << endl;
	cout << " 4    5   " << endl;
	cout << "    ／	   " << endl;
	cout << "   6	   " << endl << endl;

	// 1. 인접 행렬 방식
	vector<vector<int>> adjMat =
	{
		{ 0, 1, 1, 0, 0, 0 },
		{ 1, 0, 0, 1, 1, 0 },
		{ 1, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 1, 0 }
	};
	vector<bool> isVisited1(adjMat.size());

	cout << "[너비 우선 탐색(BFS): 인접 행렬]" << endl;

	BFS(adjMat, isVisited1, 0);

	cout << endl << endl;

	// 2. 인접 리스트 방식
	vector<list<int>> adjList =
	{
		{ 1, 2 },
		{ 0, 3, 4 },
		{ 0 },
		{ 1 },
		{ 1, 5 },
		{ 4 }
	};
	vector<bool> isVisited2(adjList.size());

	cout << "[너비 우선 탐색(BFS): 인접 리스트]" << endl;

	BFS(adjList, isVisited2, 0);

	cout << endl << endl;
}

void BFS(const vector<vector<int>>& adjMat, vector<bool>& isVisited, int current)
{
	isVisited[current] = true;

	cout << current + 1 << " → ";

	queue<int> q;

	q.push(current);

	while (!q.empty())
	{
		current = q.front();
		q.pop();

		for (int i = 0; i < adjMat.size(); ++i)
		{
			if (adjMat[current][i] && !isVisited[i])
			{
				isVisited[i] = true;

				cout << i + 1 << " → ";

				q.push(i);
			}
		}
	}
}

void BFS(const vector<list<int>>& adjList, vector<bool>& isVisited, int current)
{
	isVisited[current] = true;

	cout << current + 1 << " → ";

	queue<int> q;

	q.push(current);

	while (!q.empty())
	{
		current = q.front();
		q.pop();

		for (auto iter = adjList[current].begin(); iter != adjList[current].end(); ++iter)
		{
			if (!isVisited[*iter])
			{
				isVisited[*iter] = true;

				cout << *iter + 1 << " → ";

				q.push(*iter);
			}
		}
	}
}
