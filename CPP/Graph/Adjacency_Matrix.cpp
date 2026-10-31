// Graph ADT: Adjacency Matrix Structure
// Link: Goodrich, Tamassia & Goldwasser - Data Structures & Algorithms in Python, Ch 14.2
// Pattern: Vertex Index -> V x V Table of Edge Pointers (Null = No Edge)
// Time: getEdge/insertEdge/removeEdge O(1), degree/incident O(V), removeVertex O(V^2)   Space: O(V^2)

#include <iostream>
#include <list>
#include <iterator>
#include <vector>
using namespace std;

struct Edge;

struct Vertex{
    int data;
    list<Vertex>::iterator position;
    int matrixIndex;
    Vertex(int x){
        data = x;
        matrixIndex = -1;
    }
};

struct Edge{
    int label;
    Vertex * origin,* destination;
    list<Edge>::iterator position;
    Edge(Vertex* o,Vertex* d,int l){
        label = l;
        origin = o;
        destination = d;
    }
};

class AdjacencyMatrix{
    private:
        list<Vertex> V;
        list<Edge> E;
        bool directed;

        vector<vector<Edge*>> matrix;
    public:
        AdjacencyMatrix(bool is_directed){directed = is_directed;}
        int vertexCount(){return V.size();}
        int edgeCount(){return E.size();}
        list<Edge*> edges();
        list<Vertex*> vertices();
        Vertex* insertVertex(int x);
        Edge* insertEdge(Vertex* u, Vertex* v,int label);
        bool removeVertex(Vertex* v);
        bool removeEdge(Edge* e);
        int degree(Vertex * v,bool out);
        list<Edge*> getEdges(Vertex* u,Vertex * v);
        list<Edge*> incidentEdges(Vertex* v,bool out);
};

list<Edge*> AdjacencyMatrix::edges(){
    list<Edge*> result;
    for(Edge &e: E){
        result.push_back(&e);
    }
    return result;
}

list<Vertex*> AdjacencyMatrix::vertices(){
    list<Vertex*> result;
    for(Vertex& v: V){
        result.push_back(&v);
    }
    return result;
}

Vertex* AdjacencyMatrix::insertVertex(int x){
    V.push_back(Vertex(x));
    Vertex * v = &V.back();
    v->position = --V.end();

    v->matrixIndex = V.size()-1;

    matrix.resize(V.size());
    for(int i = 0;i<V.size();i++){
        matrix[i].resize(V.size(),nullptr);
    }
    return v;
}

Edge* AdjacencyMatrix::insertEdge(Vertex* u, Vertex* v,int label){
    E.push_back(Edge(u,v,label));
    Edge * e = &E.back();
    e->position = --E.end();

    matrix[u->matrixIndex][v->matrixIndex] = e;
    if(!directed){
        matrix[v->matrixIndex][u->matrixIndex] = e;
    }

    return e;
}

bool AdjacencyMatrix::removeVertex(Vertex* v){
    if(v==nullptr)return false;
    int k = v->matrixIndex;
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[k][i] != nullptr) removeEdge(matrix[k][i]);
        if (matrix[i][k] != nullptr) removeEdge(matrix[i][k]);
    }
    for(int i = 0;i<matrix.size();i++){
        matrix[i].erase(matrix[i].begin() + v->matrixIndex);
    }
    matrix.erase(matrix.begin()+v->matrixIndex);
    for(Vertex& u:V){
        if(u->matrixIndex>v->matrixIndex){u->matrixIndex--;}
    }
    V.erase(v->position);
    return true;
}

bool AdjacencyMatrix::removeEdge(Edge* e){
    if(e==nullptr)return false;
    int row = e->origin->matrixIndex;
    int col = e->destination->matrixIndex;
    matrix[row][col] = nullptr;
    if(!directed){
        matrix[col][row] = nullptr;
    }
    E.erase(e->position);
    return true;
}

int AdjacencyMatrix::degree(Vertex * v,bool out){
    int degree_count=0;
    int idx = v->matrixIndex;
     if (!directed) {
        for (Edge* e : matrix[idx]) {
            if (e != nullptr) {
                if (e->origin->matrixIndex == e->destination->matrixIndex) {
                    degree_count += 2;
                } else {
                    degree_count++;
                }
            }
        }
        return degree_count;
    }
    if (out) {
        for (int col = 0; col < matrix.size(); ++col) {
            if (matrix[idx][col] != nullptr) {
                degree_count++;
            }
        }
    }else {
        for (int row = 0; row < matrix.size(); ++row) {
            if (matrix[row][idx] != nullptr) {
                degree_count++;
            }
        }
    }   
    return degree_count;
}

list<Edge*> AdjacencyMatrix::getEdges(Vertex* u,Vertex * v){
    list<Edge*> result;
    int row = u->matrixIndex;
    int col = v->matrixIndex;
    if (!directed) {
        if (matrix[row][col] != nullptr) {
            result.push_back(matrix[row][col]);
        }
        return result;
    }
    if (matrix[row][col] != nullptr) {
        result.push_back(matrix[row][col]);
    }
    if (matrix[col][row] != nullptr) {
        result.push_back(matrix[col][row]);
    }
    return result;
}

list<Edge*> AdjacencyMatrix::incidentEdges(Vertex* v,bool out){
    list<Edge*> result;
    int idx = v->matrixIndex;
    if (!directed) {
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[idx][i] != nullptr) {
                result.push_back(matrix[idx][i]);
            }
        }
        return result;
    }
    for (int i = 0; i < matrix.size(); i++) {
        if (out && matrix[idx][i] != nullptr) {
            result.push_back(matrix[idx][i]);
        }
        if (!out && matrix[i][idx] != nullptr) {
            result.push_back(matrix[i][idx]);
        }
    }
    return result;
}

int main(){
    cout << "---Adjacency Matrix---" << endl;
    AdjacencyMatrix am(true); 
    
    Vertex * v1 = am.insertVertex(10);
    Vertex * v2 = am.insertVertex(20);
    Vertex * v3 = am.insertVertex(40);
    Vertex * v4 = am.insertVertex(60);
    cout << "Vertex count: " << am.vertexCount() << endl;
    
    Edge * e1 = am.insertEdge(v1, v2, 1);
    Edge * e2 = am.insertEdge(v2, v3, 2);
    Edge * e3 = am.insertEdge(v3, v4, 3);
    cout << "Edge Count: " << am.edgeCount() << endl;
    
    cout << "\nVertex information: " << endl;
    for(Vertex * v : am.vertices()){
        cout << "Vertex data: " << v->data << " (Matrix Index: " << v->matrixIndex << ")" << endl;
    }
    
    cout << "\nEdge information: " << endl;
    for(Edge * e : am.edges()){
        cout << "Edge data: " << e->label << endl;
        cout << "Edge origin: " << e->origin->data << endl;
        cout << "Edge destination: " << e->destination->data << endl;
    }
    
    cout << "\nDegree(Out) of vertex(40): " << am.degree(v3, true) << endl;
    
    cout << "\nIncident edges(outgoing) on vertex 20" << endl;
    for(Edge * e : am.incidentEdges(v2, true)){
        cout << "Edge data: " << e->label << endl;
        cout << "Edge origin: " << e->origin->data << endl;
        cout << "Edge destination: " << e->destination->data << endl;
    }
    
    cout << "\nEdges between v1 and v2" << endl;
    for(Edge * e : am.getEdges(v1, v2)){
        cout << "Edge data: " << e->label << endl;
        cout << "Edge origin: " << e->origin->data << endl;
        cout << "Edge destination: " << e->destination->data << endl;
    }
    
    cout << "\nDeleting v1..." << endl;
    am.removeVertex(v1); // This automatically sweeps out edge e1!
    
    cout << "Deleting e2..." << endl;
    am.removeEdge(e2);
    
    cout << "\nFinal Vertex count: " << am.vertexCount() << endl;
    cout << "Final Edge Count (Should be 1 - only e3 remains): " << am.edgeCount() << endl;
    
    cout << "\nUpdated Vertex Matrix Indices after contraction:" << endl;
    for(Vertex * v : am.vertices()){
        cout << "Vertex data: " << v->data << " is now tracking at Matrix Index: " << v->matrixIndex << endl;
    }
    
    return 0;
}
