#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

void DFS(const vector<vector<int>>& adjMat, vector<bool>& isVisited, int current);
void DFS(const vector<list<int>>& adjList, vector<bool>& isVisited, int current);

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

	cout << "[깊이 우선 탐색(DFS): 인접 행렬]" << endl;

	DFS(adjMat, isVisited1, 0);

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

	cout << "[깊이 우선 탐색(DFS): 인접 리스트]" << endl;

	DFS(adjList, isVisited2, 0);

	cout << endl << endl;
}

void DFS(const vector<vector<int>>& adjMat, vector<bool>& isVisited, int current)
{
	// 1. 재귀호출 사용
	isVisited[current] = true;

	cout << current + 1 << " → ";

	for (int i = 0; i < adjMat.size(); ++i)
	{
		if (adjMat[current][i] && !isVisited[i])
		{
			DFS(adjMat, isVisited, i);
		}
	}

	// 2. 스택 사용
	//stack<int> s;

	//s.push(current);

	//while (!s.empty())
	//{
	//	current = s.top();
	//	s.pop();

	//	isVisited[current] = true;

	//	cout << current + 1 << " → ";

	//	for (int i = 0; i < adjMat.size(); ++i)
	//	{
	//		if (adjMat[current][i] && !isVisited[i])
	//		{
	//			s.push(i);
	//		}
	//	}
	//}
}

void DFS(const vector<list<int>>& adjList, vector<bool>& isVisited, int current)
{
	// 1. 재귀호출 사용
	isVisited[current] = true;

	cout << current + 1 << " → ";

	for (auto iter = adjList[current].begin(); iter != adjList[current].end(); ++iter)
	{
		if (!isVisited[*iter])
		{
			DFS(adjList, isVisited, *iter);
		}
	}

	// 2. 스택 사용
	//stack<int> s;
	//
	//s.push(current);
	//
	//while (!s.empty())
	//{
	//	current = s.top();
	//	s.pop();
	//
	//	isVisited[current] = true;
	//
	//	cout << current + 1 << " → ";
	//
	//	for (auto iter = adjList[current].begin(); iter != adjList[current].end(); ++iter)
	//	{
	//		if (!isVisited[*iter])
	//		{
	//			s.push(*iter);
	//		}
	//	}
	//}
}
