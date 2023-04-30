
#define MAXVEX 15
#define _INFINITY 65535
typedef char VertexType;
typedef int EdgeType;

// 邻接矩阵
typedef struct {
	VertexType vertex[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertex, numEdge;		// 当前图中顶点和边数
}MGraph;

// 邻接表
typedef struct EdgeNode		// 边表节点
{
	int vertexIndex;			// 存储的顶点号
	EdgeType info;			// 边信息
	struct EdgeNode* next;
}EdgeNode;

typedef struct {		// 顶点表
	VertexType data;	// 顶点信息
	EdgeNode* head;					// 该顶点 的 表
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

