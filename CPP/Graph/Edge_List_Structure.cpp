// Graph ADT: Edge List Structure
// Link: Goodrich, Tamassia & Goldwasser - Data Structures & Algorithms in Python, Ch 14.2
// Pattern: Flat Vertex List + Flat Edge List -> Linear Scan for Adjacency Queries
// Time: getEdge/degree/incident O(E), insert O(1), removeVertex O(E)   Space: O(V+E)

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

struct Vertex{
    int data;
    list<Vertex>::iterator position;
    Vertex(int x){data=x;}
};

struct Edge{
    int label;
    Vertex* origin;
    Vertex * destination;
    list<Edge>::iterator position;
    Edge(Vertex * o,Vertex * d,int l){
        label = l;
        origin = o;
        destination = d;
    }
};

class EdgeListGraph{
    private:
        list<Vertex> V;
        list<Edge> E;
        bool directed;
    public:
        EdgeListGraph(bool is_directed);
        int vertexCount();
        int edgeCount();
        list<Vertex *> vertices();
        list<Edge*> edges();
        list<Edge*> getEdge(Vertex* u,Vertex* v);
        int degree(Vertex* v,bool out);
        list<Edge*> incidentEdges(Vertex*  v, bool out);
        Vertex* insertVertex(int x);
        Edge* insertEdge(Vertex* u,Vertex* v,int x);
        bool removeEdge(Edge* e);
        bool removeVertex(Vertex* v);
};

EdgeListGraph::EdgeListGraph(bool is_directed){
    directed = is_directed;
}

int EdgeListGraph::vertexCount(){
    return V.size();
}

int EdgeListGraph::edgeCount(){
    return E.size();
}

list<Vertex*> EdgeListGraph::vertices(){
    list<Vertex*> result;
    //Add address of each vertex to result
    for(Vertex& v:V){
        result.push_back(&v);
    }
    return result;
}

list<Edge*> EdgeListGraph::edges(){
    list<Edge*> result;
    //Add address of each vertex to result
    for(Edge& e:E){
        result.push_back(&e);
    }
    return result;
}

list<Edge*> EdgeListGraph::getEdge(Vertex* u,Vertex* v){
    list<Edge*> result;
    for(Edge& e:E){
        if(e.origin==u && e.destination==v){
            result.push_back(&e);
        }else if(!directed && e.origin==v && e.destination==u){
            result.push_back(&e);
        }
    }
    return result;
}

int EdgeListGraph::degree(Vertex* v,bool out){
    int degree = 0;
    if(!directed){
        for(Edge& e:E){
            if(e.origin==v||e.destination==v)degree++;
        }
        return degree;
    }
    if(out){
        for(Edge& e:E){
            if(e.origin==v)degree++;
        }
    }else{
        for(Edge& e:E){
            if(e.destination==v)degree++;
        }
    }
    return degree;
}

list<Edge*> EdgeListGraph::incidentEdges(Vertex*  v, bool out){
    list<Edge*> result;
    if(!directed){
        for(Edge& e: E){
            if(e.origin==v || e.destination==v) result.push_back(&e);
        }
        return result;
    }
    if(out){
        for(Edge& e:E){
            if(e.origin==v)result.push_back(&e);
        }
    }else{
        for(Edge& e:E){
            if(e.destination==v)result.push_back(&e);
        }
    }
    return result;
}

Vertex* EdgeListGraph::insertVertex(int x){
    V.push_back(Vertex(x));
    Vertex* v = &V.back();
    v->position = --V.end();
    return v;
}

Edge* EdgeListGraph::insertEdge(Vertex* u,Vertex* v,int x){
    E.push_back(Edge(u,v,x));
    Edge * e = &E.back();
    e->position = --E.end();
    return e;
}

bool EdgeListGraph::removeEdge(Edge* e) {
    if (e == nullptr) return false;
    E.erase(e->position);
    return true;
}

bool EdgeListGraph::removeVertex(Vertex* v){
    if (v == nullptr) return false;   
    auto it = E.begin();
    while (it != E.end()) {
        if (it->origin == v || it->destination == v) {
            it = E.erase(it); 
        } else {
            ++it; 
        }
    }
    V.erase(v->position);
    return true;
}



int main(){
    cout<<"---Creating undirected graph---"<<endl;
    EdgeListGraph graph(false);
    Vertex * v1 = graph.insertVertex(10);
    Vertex* v2 = graph.insertVertex(20);
    Vertex* v3 = graph.insertVertex(30);
    cout<<"Inserted 3 vertices. Total Count: "<<graph.vertexCount()<<endl;
    Edge* e1  = graph.insertEdge(v1,v2,101);
    Edge* e2 = graph.insertEdge(v2,v3,102);
    cout<<"Inserted 2 edges. Total Count: "<<graph.edgeCount()<<endl;
    cout<<"Vertices currently in the graph"<<endl;
    list<Vertex *> all_V = graph.vertices();
    for(Vertex* v:all_V){
        cout<<v->data<<" "; 
    }
    cout<<endl;
    cout<<"Degree of vertex(20): "<<graph.degree(v2,true)<<endl;
    cout<<"Incident Edges on vertex(20)"<<endl;
    list<Edge*> incident_e = graph.incidentEdges(v2,true);
    for(Edge* e:incident_e){
        cout<<"[Label: "<<e->label<<" connecting "<<e->origin->data<<" and "<<e->destination->data<<" ] "<<endl;
    }
    cout<<"Checking edge between vertex(10) and vertex(20)"<<endl;
    list<Edge*> btw = graph.getEdge(v1,v2);
    if(!btw.empty()){
        cout<<"Match Found"<<endl;
        for(Edge* e:btw){
            cout<<"[Label: "<<e->label<<" connecting "<<e->origin->data<<" and "<<e->destination->data<<" ] "<<endl;
        }
    }else{
        cout<<"Match not found"<<endl;
    }
    cout<<"Deleting edge e1(label:101)"<<endl;
    graph.removeEdge(e1);
    cout<<"Changed degree of vertex(20): "<< graph.degree(v2,true)<<endl;
    cout<<"Deleting vertex v3"<<endl;
    graph.removeVertex(v3);
    cout<<"Final vertex count: "<<graph.vertexCount()<<endl;
    cout<<"Final edge count: "<<graph.edgeCount()<<endl;
    return 0;
}