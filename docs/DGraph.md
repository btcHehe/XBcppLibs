# DGraph.h

## Description
Library contains 3 template classes: DGraph<T>, DVertex<T>, DEdge<T> for creating directional graphs. Graph has a field called vertices which is a vector containing DVertex<T> type objects, every vertex has a field called edges which is a vector containing all DEdge<T> type objects connected to this vertex. Adding edge to the vertex doesnt add this edge to the vertex on the other side because it's one-way edge. For moving around in the graph there is a helper type **DHead**. The example of usage:
```
xb::DGraph<vertex_t> my_graph = { 1, 2, 5, 10, 56, 12 };
DHead<vertex_t> reader = my_graph.vertices[0].edges[0].vertex;      // reader points to the first neighbour of the first vertex in a graph
std::cout << reader->value << std::endl;
reader = reader->edges[0].vertex;        // reader points to the first neighbour of vertex it was pointing to previously
std::cout << reader->value << std::endl;
```

## Constructors
- DGraph()
- DGraph(std::initializer_list<V> vals);
- DGraph(std::initializer_list<DVertex<V>> verts);
- DEdge(DVertex<V>& ver);
- DVertex(V val);

## Methods

Method name | Arguments         | Return type   | Class         | Description
------------|-------------------|---------------|---------------|-------------
add_vertex  | V val             | void          | DGraph        | Adds new vertex with value **val** to the graph
add_vertex  | DVertex<V> v      | void          | DGraph        | Adds new vertex to the graph
add_edge    | DVertex<V>& dst   | void          | DVertex       | Adds new edge to the vertex passed as argument
set_value   | V val             | void          | DVertex       | Sets value for vertex
