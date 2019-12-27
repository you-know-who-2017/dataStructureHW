template <class T>
MGraph<T>::MGraph(GraphType t,T v[], int n, int e){
    //t : map type
    //v : array to save map vetex
    //n : point
    //e : edge
    vexnum = n;
    edgenum = e;
    kind = t;
    vexs.resize(vexnum);    //邻接表
    edges.resize(vexnum);  //邻接矩阵
    for(i=0;i<n;i++){
        vexs[i]=v[i];   //给各个顶点赋值 邻接表
    }
    for(i=0;i<n;i++){
        edges[i].resize(vexnum); //每个元素都是数组 邻接矩阵
    }
    for(i=0;i<n;i++){
        for(i)
    }
}