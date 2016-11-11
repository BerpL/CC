#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <vector>

using namespace std;
class Graph
{
protected:
    map<int, vector<int> > salida;
public:
    Graph(const vector<int> &inicio, const vector <int> &fin);
    int numOutgoing(const int ID) const;
    const vector<int> &ady(const int ID) const;
};

#endif // GRAPH_H
