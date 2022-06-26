// One-directional graph with values on vertices
// Every vertex can have multiple edges that are
// placed in the public vector called "edges"
#pragma once
#ifndef _VECTOR_
#include <vector>
#endif

#ifndef _INITIALIZER_LIST_
#include <initializer_list>
#endif

#ifndef DGRAPH_H
#define DGRAPH_H

namespace xb {

template <typename V>
class DEdge;
template <typename V>
class DVertex {
public:
    DVertex(V val);
    V value;
    std::vector<DEdge<V>> edges;
    void add_edge(DVertex<V>& dst);
    void set_value(V val);
};

template <typename V>
class DEdge {
public:
    DEdge(DVertex<V>& ver);
    DVertex<V>* vertex = nullptr;
};

template <typename V>
class DGraph {
public:
    DGraph() {};
    DGraph(std::initializer_list<V> vals);
    DGraph(std::initializer_list<DVertex<V>> verts);
    ~DGraph();
    std::vector<DVertex<V>> vertices;
    void add_vertex(V val);
    void add_vertex(DVertex<V> v);
};

template <typename V>
using DHead = DVertex<V>*;

// ---------------------- DEFINITIONS -----------------------

template <typename V>
DVertex<V>::DVertex(V val) {
    value = val;
}

template <typename V>
void DVertex<V>::add_edge(DVertex<V>& dst) {
    DEdge<V> e(dst);
    edges.push_back(e);
}

template <typename V>
void DVertex<V>::set_value(V val) {
    value = val;
}

template <typename V>
DEdge<V>::DEdge(DVertex<V>& ver) {
    vertex = &ver;
}

template <typename V>
DGraph<V>::DGraph(std::initializer_list<V> vals) {
    for (auto v : vals) {
        vertices.push_back(DVertex<V>(v));
    }
}

template <typename V>
DGraph<V>::DGraph(std::initializer_list<DVertex<V>> verts) {
    for (auto v : verts) {
        vertices.push_back(v);
    }
}

template <typename V>
DGraph<V>::~DGraph() {
}

template <typename V>
void DGraph<V>::add_vertex(V val) {
    DVertex<V>* tmp = new DVertex<V>(val);
    vertices.push_back(*tmp);
}

template <typename V>
void DGraph<V>::add_vertex(DVertex<V> v) {
    vertices.push_back(v);
}

}
#endif