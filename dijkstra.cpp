#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>

#include "Edge.hpp"
#include "FibHeap.hpp"
#include "Graph.hpp"
#include "Node.hpp"

using namespace std;

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;
using namespace std;

int main(int argc, char* argv[]) {
    /**/
    if (argc < 3) return -1;

    stringstream ss(argv[1]);
    int N = 0;
    ss >> N;
    int E = 2 * N;

    Graph* g = new Graph();
    Node** nodes = new Node*[N];
    for (int i = 0; i < N; i++) {
        nodes[i] = g->insertNode(i);
    }
    for (int i = 0; i < E; i++) {
        g->insertEdges(nodes[rand() % N], nodes[rand() % N], rand() % N);
    }
    ofstream f(argv[2], ios::app);

    auto start =
        duration_cast<milliseconds>(system_clock::now().time_since_epoch())
            .count();
    g->Dijkstra(g->start);
    auto end =
        duration_cast<milliseconds>(system_clock::now().time_since_epoch())
            .count();
    // g->print();
    f << "Graph sa : " << N << " cvorova\n"
      << "I sa : " << E << " grana\n"
      << "Vreme za Dijkstrin Algoritam :" << end - start << "ms\n"
      << "-----------------------------------------\n";
    f.close();
    return 1;
}