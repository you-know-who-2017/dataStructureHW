enum GraphType{
    undigraph,
    digraph,
    undinetwork,
    dinetwork
};

template<class T>
struct EdgeType
{
    T head, tail;
    int cost;
    EdgeType(T h, T t, int c){
        head = h;
        tail = t;
        cost = c;
    }
};

template<class T>
class MGraph
{
    private:
        int vexnum, edgenum;
        GraphType kind;
        vector<vector <int>> edges;
        vector<T> vexs;
        void DFS(int v, bool * visited);
    public:
        MGraph(GraphType t, T v[], int n, int e);
        ~MGraph(){};
        int VexterNum();
        int EdgeNum();
        T GetVexValue(int i);
        int GetVexValueNum(T v);
        int GetEdgeValue(int i, int j);\
        void InsertVex(T v);
        void RemoveVex(T v);
        void InsertEdge(EdgeType e);
        void DeleteEdge(EdgeType e);
        void DFSTraverse();
        void BFSTraverse();
        void PrintEdges();
        void PrintVexs();
        void Prim(int v);
        void Kruskal(vector<EdgeType> &Tree);
        void Dijkstra(int v, int path[], int dist[]);
        void Floyd(int path[][MAXV],int D[][MAXV]);
};