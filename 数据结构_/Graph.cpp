#include "Graph.h"
#include<iostream>
#include<queue>

using namespace std;

#pragma region basic opera

/// <summary>
/// Create non-direction Graph
/// </summary>
void Graph::CreateMGraph(MGraph& G)
{
	cout << "�����붥������������";
	cin >> G.numVertex >> G.numEdge;
	cout << "�����붥����Ϣ��";
	for (int i = 0; i < G.numVertex; i++)
	{
		cin >> G.vertex[i];
	}
	// init edge
	for (int i = 0; i < G.numVertex; i++)
	{
		for (int j = 0; j < G.numVertex; j++)
		{
			G.arc[i][j] = _INFINITY;
		}
	}
	// in arc
	int i, j;
	for (int t = 0; t < G.numEdge; t++)
	{
		cout << "�����������ӵı�(vi, vj)�ϵ� �±�";
		cin >> i >> j;
		G.arc[i][j] = 1;
		G.arc[j][i] = 1;
	}
}
/// <summary>
/// non-Directional Graph
/// </summary>
/// <param name="G"></param>
void Graph::CreateAdjList(GraphAdjList& G)
{
	int i, j, k;
	EdgeNode* e;
	cout << "���붥�����ͱ���: ";
	cin >> G.numNodes >> G.numEdges;
	for (i = 0; i < G.numNodes; i++)
	{
		cin >> G.adjList[i].data;
		G.adjList[i].head = NULL;
	}


	// �����߱�
	for (k = 0; k < G.numEdges; k++)
	{
		cout << "�����(vi,vj)�ϵĶ����±꣺";
		cin >> i >> j;
		e = new EdgeNode;
		e->vertexIndex = j;
		e->next = G.adjList[i].head;	// ͷ�巨
		G.adjList[i].head = e;

		// ����ͼ ��ȱ�� ��Ҫ������ 
		e = new EdgeNode;
		e->vertexIndex = i;
		e->next = G.adjList[j].head;	// ͷ�巨
		G.adjList[j].head = e;
	}
}

void Graph::DFSTraverse(GraphAdjList G)
{
	for (int i = 0; i < G.numNodes; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < G.numNodes; i++)
	{
		if (!visited[i])
		{
			DFS(G, i);
		}
	}
}

void Graph::BFSTraverse(GraphAdjList G)
{
	for (int i = 0; i < G.numNodes; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < G.numEdges; i++)
	{
		if (!visited[i])
		{
			BFS(G, 0);
		}
	}
}

void Graph::DFS(GraphAdjList G, int v) {
	cout << G.adjList[v].data << " ";

	EdgeNode* tem;
	visited[v] = true;
	tem = G.adjList[v].head;
	while (tem)
	{
		if (!visited[tem->vertexIndex])
			DFS(G, tem->vertexIndex);
		tem = tem->next;
	}
}

void Graph::BFS(GraphAdjList G, int v)
{
	cout << G.adjList[v].data << " ";
	visited[v] = true;

	queue<VertexNode> que;
	que.push(G.adjList[v]);
	EdgeNode* e;
	while (!que.empty())
	{
		VertexNode temNode = que.front();
		que.pop();
		e = temNode.head;
		while (e)
		{
			if (!visited[e->vertexIndex])
			{
				cout << G.adjList[e->vertexIndex].data << " ";
				visited[e->vertexIndex] = true;
				que.push(G.adjList[e->vertexIndex]);
			}
			e = e->next;
		}
	}

}

#pragma endregion

#pragma region funtional opera

bool Graph::LianTongGraph(GraphAdjList G)
{
	for (int i = 0; i < G.numNodes; i++)
	{
		visited[i] = false;
	}
	DFS(G, 0);

	for (int i = 0; i < G.numNodes; i++)
	{
		if (!visited[i])
			return false;
	}

	return true;;
}

bool Graph::ExistCircle(GraphAdjList G)
{
	EdgeNum = 0;
	for (int i = 0; i < G.numNodes; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < G.numNodes; i++)
	{
		if (!visited[i])
		{
			DFSEdgeNum(G, i);
		}
	}
	if (EdgeNum > 2 * (G.numNodes - 1))
		return true;
	return false;
}

bool Graph::IsTree(GraphAdjList G)
{
	EdgeNum = 0;
	VerNum = 0;
	for (int i = 0; i < G.numNodes; i++)
	{
		visited[i] = false;
	}
	DFSEdgeNum(G, 0);

	if (VerNum == G.numNodes && EdgeNum == 2 * (G.numNodes - 1))
	{
		return true;
	}
	return false;
}

void Graph::DFSEdgeNum(GraphAdjList G, int v)		//�ڽӱ��DFS
{
	VerNum++;

	visited[v] = true;
	cout << G.adjList[v].data << " ";

	EdgeNode* tem = G.adjList[v].head;
	while (tem)
	{
		EdgeNum++;							//  �˴�Ϊ�ؼ���Ҳ����ĳ��ֻҪ ���������������Ӵ˴��ͼ�һ
		if (!visited[tem->vertexIndex])
			DFSEdgeNum(G, tem->vertexIndex);
		tem = tem->next;
	}
}

#pragma endregion