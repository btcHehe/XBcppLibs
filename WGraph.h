// Weighted graph with two-way edges. Every vertex and edge have values.
// Every vertex can have more than one edge. Edges are stored in public vector
// called "edges". Every Edge object has pointer to Vertex<V>.
#pragma once
#ifndef _VECTOR_
#include <vector>
#endif

#ifndef _INITIALIZER_LIST_
#include <initializer_list>
#endif

#ifndef WGRAPH_H
#define WGRAPH_H

template <typename V, typename E>
class WEdge;
template <typename V, typename E>
class WVertex {
public:
    WVertex(V val);
    V value;
    std::vector<WEdge<V, E>> edges;
    void add_edge(WVertex<V, E>& dst);
    void add_edge(WVertex<V, E>& dst, E val);
    void set_value(V val);
};

template <typename V, typename E>
class WEdge {
public:
    WEdge(WVertex<V, E>& ver);
    WEdge(E val, WVertex<V, E>& ver);
    ~WEdge();
    void set_value(E val);
    E value;
    WVertex<V, E>* vertex = nullptr;
};

template <typename V, typename E>
class WGraph {
public:
    WGraph() {};
    WGraph(std::initializer_list<V> vals);
    WGraph(std::initializer_list<WVertex<V, E>> verts);
    ~WGraph();
    std::vector<WVertex<V, E>> vertices;
    void add_vertex(V val);
    void add_vertex(WVertex<V, E>& v);
};

template <typename V, typename E>
using WHead = WVertex<V, E>*;
// ---------------------- DEFINITIONS -------------------------

template <typename V, typename E>
WVertex<V, E>::WVertex(V val) {
    value = val;
}

template <typename V, typename E>
void WVertex<V, E>::add_edge(WVertex<V, E>& dst) {
    WEdge<V, E> e(dst);
    WEdge<V, E> e2(*this);
    dst.edges.push_back(e2);
    this->edges.push_back(e);
}

template <typename V, typename E>
void WVertex<V, E>::add_edge(WVertex<V, E>& dst, E val) {
    WEdge<V, E> e(dst, val);
    WEdge<V, E> e2(*this, val);
    dst.edges.push_back(e2);
    this->edges.push_back(e);
}

template <typename V, typename E>
void WVertex<V, E>::set_value(V val) {
    value = val;
}

template <typename V, typename E>
WEdge<V, E>::WEdge(WVertex<V, E>& ver) {
    vertex = &ver;
}

template <typename V, typename E>
WEdge<V, E>::WEdge(E val, WVertex<V, E>& ver) {
    value = val;
    vertex = &ver;
}

template <typename V, typename E>
WEdge<V, E>::~WEdge() {
}

template <typename V, typename E>
void WEdge<V, E>::set_value(E val) {
    value = val;
}

template <typename V, typename E>
WGraph<V, E>::WGraph(std::initializer_list<V> vals) {
    for (auto v : vals) {
        vertices.push_back(WVertex<V, E>(v));
    }
}

template <typename V, typename E>
WGraph<V, E>::WGraph(std::initializer_list<WVertex<V, E>> verts) {
    for (auto v : verts) {
        vertices.push_back(v);
    }
}

template <typename V, typename E>
WGraph<V, E>::~WGraph() {
}

template <typename V, typename E>
void WGraph<V, E>::add_vertex(V val) {
    WVertex<V, E>* tmp = new WVertex<V, E>(val);
    vertices.push_back(*tmp);
}

template <typename V, typename E>
void WGraph<V, E>::add_vertex(WVertex<V, E>& v) {
    vertices.push_back(v);
}
#endif