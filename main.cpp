#include "Graph.hpp"

using namespace std;

int main() {
  Graph G(10); //se creó un grafo con 10 vertices 
  G.addEdge(0,9); //crea una arista de 0 a 9
  G.addEdge(4, 2);
  G.addEdge(1, 4);
  G.addEdge(7, 4);
  G.addEdge(5, 4);

   G.print();


  int totalAristas = G.numEdges(); //cantidad total de aristas en el grafo
  cout << totalAristas << endl;

  int aristasVertice = G.inDegree(4); //cantidad total de aristas que apuntan un vertice particular
  cout << aristasVertice << endl;

  bool Max = G.isInfluencer(4); //Es 4 el vertice como más aristas?
  cout << Max << endl;

}
 
