
#define MAXVEX 15
#define _INFINITY 65535
typedef char VertexType;
typedef int EdgeType;

// �ڽӾ���
typedef struct {
	VertexType vertex[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertex, numEdge;		// ��ǰͼ�ж���ͱ���
}MGraph;

// �ڽӱ�
typedef struct EdgeNode		// �߱�ڵ�
{
	int vertexIndex;			// �洢�Ķ����
	EdgeType info;			// ����Ϣ
	struct EdgeNode* next;
}EdgeNode;

typedef struct {		// �����
	VertexType data;	// ������Ϣ
	EdgeNode* head;					// �ö��� �� ��
}VertexNode, AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numNodes, numEdges;
}GraphAdjList;

class Graph {
public:
	//basic opera
	void CreateMGraph(MGraph& G);
	void CreateAdjList(GraphAdjList& G);
	void DFSTraverse(GraphAdjList G);
	void BFSTraverse(GraphAdjList G);
	//funtional opera
	bool LianTongGraph(GraphAdjList G);
	bool ExistCircle(GraphAdjList G);
	bool IsTree(GraphAdjList G);
private:
	void DFS(GraphAdjList G,int v);
	void BFS(GraphAdjList G, int v);
	void DFSEdgeNum(GraphAdjList G,int v);
	bool visited[MAXVEX];
	int EdgeNum;
	int VerNum;
};

