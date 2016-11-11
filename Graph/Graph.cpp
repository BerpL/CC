#include "Graph.h"
#include <stdexcept>
#include <map>
#include <vector>
using namespace std;

Graph::Graph(const vector<int> &inicio, const vector<int> &fin)
{
    if(inicio.size() != fin.size())
        throw invalid_argument("el punto inicio no tiene el mismo tamaño con el punto final");
    for(int i=0; i<inicio.size();i++)
    {
        int ini= inicio[i];
        int fi= fin[i];
        salida[ini].push_back(fi);
        salida[fi];
    }
}

int Graph::numOutgoing(const int ID) const
{
    return ady(ID).size();
}

const vector<int> &Graph::ady(const int ID) const
{
    map<int, vector<int> >::iterator i= salida.find(ID);
    if(i == salida.end())
        throw invalid_argument("Nodo invalido");
    return i->next;
}
