#include <iostream>
#include <vector>
#include <stdexcept>

class Graph {
private:
    int numVertices;  //nodos
    std::vector<std::vector<int>> adjMatrix; //arreglo dinamico de enteros

public:
    // Crea un vector de 2D n x n
    Graph(int n) : numVertices(n), adjMatrix(n, std::vector<int>(n, 0)) {}

    // Add a vertex from node u to node v
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 1;
        } else {
            std::out_of_range("Vertice fuera de rango");
        }
    }

    // Imprime la matriz de adyacencias
    void print() const {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Implementar!! 
    // Devuelve la cantidad total de aristas
    //para matriz dinamica se necesita usar un for anidado para filas y columnas pero es n x n, es un cuadrado 
    int numEdges() const {
        int contador = 0;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (adjMatrix[i][j] == 1){
                    contador++; 
                }
            }
        }
        return contador;
    }
        
    

    // Completa esta función
    // Devuelve el in-degree de un vertice (cantidad total de artistas que apunta a un vertice en particular)
    int inDegree(int u) const {
        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");
        else {
            int count = 0;
            for (int i = 0; i < numVertices; ++i) { // como estamos buscando un nodo de destino en particular ya no necesitamos recorrer todas las columnas sino que solo una en particular
                if (adjMatrix[i][u]==1){ // las columnas son las q representan el nodo de destino osea a los q se apuntan 
                    count++; //si encuentra 1 significa que se le apunta y el contador aumenta            
                }
            }
            return count;
        }
        
    }
    

    // Completa esta función
    // Devuelve cierto si u es el nodo con mayor inDegree.
    // En caso de que haya varios nodos que tengan el mayor inDegree,
    // devuelve true si u es uno de ellos
    bool isInfluencer(int u) const  {
        int countMax = 0;
        for (int v = 0; v < numVertices; ++v){ //ahora recorremos vertice por vertice (nodo)
            int aristas = inDegree(v);  // almacenamos la cantidad de aristas que apunta un vertice particular en la variable aristas
            if (aristas > countMax){ //si la cantidad almacenada en aristas es mayor q a la de countMax (comparando vertice con vertice en cada iteración)
                countMax = aristas; //almacenar mayor en countmax
            }
        }
         if (inDegree(u)==countMax){ //si el vertice o nodo añadido como parametro tiene la cantidad aristas max 
            return true;               //devuelve true
            }else{
                return false;
            }
    }
};

