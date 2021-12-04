#include <bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
//Es u nuemro equivalnete al infinito.
typedef pair <int,int>baseWeightingNode;
// node,weight( distancia ) es una abreviatura
class Graph{
  int V;
  list <baseWeightingNode> *graph;
  public:
  Graph(int V){
    this->V=V;
    this->graph=new list<baseWeightingNode>[V];
    //El constructor genera el grafo
  };
     void addUnderectedNode(int u, int v, int w){
       this->graph[u].push_back(make_pair(v,w));
       this->graph[v].push_back(make_pair(u,w));
     }
     //La funcion agrega un nodo, esto representa
     //una lista de adjacencia.
     void shortestPath(int s,int p){
       priority_queue< baseWeightingNode, vector <baseWeightingNode> , greater<baseWeightingNode> > pq;
       //Es una cola (estrucutura de datos) que ordena los elementos de manor a mayor.
       vector <int>dist(V,INF);
       //Inicializa la distancia en infinito a todos los vertices
       vector<int> father(V);
       pq.push(make_pair(s,0));
      dist[s]=0;
       while(!pq.empty()){
         int node=pq.top().first;
         pq.pop();
         list<baseWeightingNode>::iterator i;
         for(i=graph[node].begin();i!=graph[node].end();i++){
           int nodoAdj=(*i).first;
           int weight=(*i).second;
           if(dist[nodoAdj]> dist[node]+weight){
             dist[nodoAdj]=dist[node]+weight;
             father[nodoAdj]=node;
             pq.push(make_pair(nodoAdj,dist[nodoAdj]));
           }
         }

       }
       int aux=p;
       cout<<"Camino mas corto"<<endl;
       cout<<"Paths: "<<p<<" ";
       while(aux!=s){
         cout<<father[aux]<<" ";
         aux=father[aux];
       }
       cout<<endl;
       cout<<"Tamnio: "<<dist[p]<<endl;
     }
};
int main()
{
    int V = 10;
    Graph g(V);
  
    //Agrega los nodos ayacentes con sus respectivos
    //pesos
    g.addUnderectedNode(0, 1, 7);
    g.addUnderectedNode(0, 2, 7);
    g.addUnderectedNode(0, 3, 6);
    g.addUnderectedNode(1, 4, 3);
    g.addUnderectedNode(1, 2, 1);
    g.addUnderectedNode(2, 4, 4);
    g.addUnderectedNode(2, 5, 3);
    g.addUnderectedNode(2, 3, 2);
    g.addUnderectedNode(3, 5, 4);
    g.addUnderectedNode(4, 5, 3);
    g.addUnderectedNode(4, 6, 5);
    g.addUnderectedNode(4, 8, 9);
    g.addUnderectedNode(5, 8, 6);
    g.addUnderectedNode(5, 7, 4);
    g.addUnderectedNode(6,9,6);
    g.addUnderectedNode(6,8,2);
    g.addUnderectedNode(8,9,7);
    g.addUnderectedNode(8,7,1);
    g.addUnderectedNode(7,9,6);
  
    //Parte desde el nodo 0
    g.shortestPath(0,9);
  
    return 0;
}
