// Graph ADT: Adjacency List Structure
// Link: Goodrich, Tamassia & Goldwasser - Data Structures & Algorithms in Python, Ch 14.2
// Pattern: Vertex -> Incident Edge List per Vertex (Shared Edge Objects)
// Time: degree O(1), incident O(deg v), getEdge O(min(deg u, deg v))   Space: O(V+E)
#include <iostream>
#include <list>
#include <iterator>
#include <unordered_map>
using namespace std;
struct Edge;

struct Vertex{
    int data;
    list<Vertex>::iterator position;
    Vertex(int x){data = x;}
};

struct Edge{
    int label;
    Vertex * origin, *destination;
    list<Edge>::iterator position;
    Edge(Vertex * o, Vertex* d,int l){
        label=l;
        origin=o;
        destination = d;
    }
};

class AdjacencyList{
    private:
        list<Vertex> V;
        list<Edge> E;
        bool directed;

        unordered_map<Vertex*, list<Edge*>>  outgoing;
        unordered_map<Vertex*, list<Edge*>>  incoming;
    public:
        AdjacencyList(bool is_Directed){
            directed = is_Directed;
        }
        int vertexCount();
        int edgeCount();
        list<Vertex*> vertices();
        list<Edge *> edges();
        Vertex * insertVertex(int x);
        Edge * insertEdge(Vertex * u, Vertex * v, int label);
        bool removeVertex(Vertex * v);
        bool removeEdge(Edge * e);
        list<Edge*> getEdges(Vertex * u, Vertex * v);
        list<Edge*> incidentEdges(Vertex* v, bool out);
        int degree(Vertex* v,bool out);
};

int AdjacencyList::vertexCount(){return V.size();}
int AdjacencyList::edgeCount(){return E.size();}
list<Vertex*> AdjacencyList::vertices(){
    list<Vertex*> result;
    for(Vertex& v: V){result.push_back(&v);}
    return result;
}
list<Edge *> AdjacencyList::edges(){
    list<Edge*> result;
    for(Edge& e: E){result.push_back(&e);}
    return result;
}
Vertex * AdjacencyList::insertVertex(int x){
    V.push_back(Vertex(x));
    Vertex * v = &V.back();
    v->position=--V.end();
    outgoing[v] = list<Edge*>();
    if(directed){incoming[v] = list<Edge*>();}
    return v;
}        
Edge * AdjacencyList::insertEdge(Vertex * u, Vertex * v, int label){
    E.push_back(Edge(u,v,label));
    Edge * e = &E.back();
    e->position =--E.end();
    outgoing[u].push_back(e);
    if(directed){
        incoming[v].push_back(e);
    }else{
        outgoing[v].push_back(e);
    }
    return e;
}

bool AdjacencyList::removeEdge(Edge * e){
    if(e==nullptr)return false;
    outgoing[e->origin].remove(e);
    if(directed){
        incoming[e->destination].remove(e);
    }else{
        outgoing[e->destination].remove(e);
    }
    E.erase(e->position);
    return true;
}

bool AdjacencyList::removeVertex(Vertex * v){
    if(v==nullptr)return false;
    list<Edge*> toRemove = outgoing[v];
    if(directed){toRemove.insert(toRemove.end(),incoming[v].begin(),incoming[v].end());}
    toRemove.sort();
    toRemove.unique();
    for(Edge* e: toRemove){removeEdge(e);}
    V.erase(v->position);
    outgoing.erase(v);
    if(directed) {
        incoming.erase(v);
    }

    return true;
}

list<Edge*> AdjacencyList::getEdges(Vertex * u, Vertex * v){
    list<Edge*> result;
    for(Edge* e: outgoing[u]){
        if(e->destination==v|| (!directed && e->origin == v)){
            result.push_back(e);
        }
    }
    return result;
}

list<Edge*> AdjacencyList::incidentEdges(Vertex* v, bool out){
    list<Edge *> result;
    if(!directed){
        for(Edge* e:outgoing[v]){
            if(e->origin==v || e->destination==v){
                result.push_back(e);
            }
        }
    }else if(out){
        for(Edge* e:outgoing[v]){
            result.push_back(e);
        }
    }else{
        for(Edge* e:incoming[v]){
            result.push_back(e);
        }
    }
    return result;
}

int AdjacencyList::degree(Vertex* v, bool out) {
    if (!directed) {
        return outgoing[v].size(); 
    }
    return out ? outgoing[v].size() : incoming[v].size();
}

int main(){
    cout<<"---Adjacency List---"<<endl;
    AdjacencyList al(true);
    Vertex * v1 = al.insertVertex(10);
    Vertex * v2 = al.insertVertex(20);
    Vertex * v3 = al.insertVertex(40);
    Vertex * v4 = al.insertVertex(60);
    cout<<"Vertex count: "<<al.vertexCount()<<endl;
    Edge * e1 = al.insertEdge(v1,v2,1);
    Edge * e2 = al.insertEdge(v2,v3,2);
    Edge * e3 = al.insertEdge(v3,v4,3);
    cout<<"Edge Count: "<<al.edgeCount()<<endl;
    cout<<"Vertex information: "<<endl;
    for(Vertex * v: al.vertices()){
        cout<<"Vertex data: "<<v->data<<endl;
    }
    cout<<"Edge information: "<<endl;
    for(Edge * e: al.edges()){
        cout<<"Edge data: "<<e->label<<endl;
        cout<<"Edge origin: "<<e->origin->data<<endl;
        cout<<"Edge destination: "<<e->destination->data<<endl;
    }
    cout<<"Degree(Out) of vertex(40): "<<al.degree(v3,true)<<endl;
    cout<<"Incident edges(outgoing) on vertex 20"<<endl;
    for(Edge * e: al.incidentEdges(v2,true)){
        cout<<"Edge data: "<<e->label<<endl;
        cout<<"Edge origin: "<<e->origin->data<<endl;
        cout<<"Edge destination: "<<e->destination->data<<endl;
    }
    cout<<"Edges between v1 and v2"<<endl;
    for(Edge * e: al.getEdges(v1,v2)){
        cout<<"Edge data: "<<e->label<<endl;
        cout<<"Edge origin: "<<e->origin->data<<endl;
        cout<<"Edge destination: "<<e->destination->data<<endl;
    }
    cout<<"Deleting v1"<<endl;
    al.removeVertex(v1);
    cout<<"Deleting e2"<<endl;
    al.removeEdge(e2);
    cout<<"Final Vertex count: "<<al.vertexCount()<<endl;
    cout<<"Final Edge Count: "<<al.edgeCount()<<endl;
    return 0;
}




