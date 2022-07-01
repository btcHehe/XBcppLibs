# WGraph.h

## Description
Library contains 3 template classes: WGraph<V, E>, WVertex<V>, WEdge<E> for creating weighted graphs. Graph has a field called vertices which is a vector containing WVertex<V> type objects, every vertex has a field called edges which is a vector containing all WEdge<E> type objects connected to this vertex. Adding edge to one of the vertices automatically adds same edge to the vertex on the other side. For moving around in the graph there is a helper type **WHead**. The example of usage:
```cpp
xb::WGraph<vertex_t, edge_t> my_graph = { 1, 2, 5, 10, 56, 12 };
// reader points to the first neighbour of the first vertex in a graph
WHead<vertex_t> reader = my_graph.vertices[0].edges[0].vertex; 
std::cout << reader->value << std::endl;
// reader points to the first neighbour of vertex it was pointing to previously
reader = reader->edges[1].vertex;
std::cout << reader->value << std::endl;
```

## Constructors
- WGraph()
- WGraph(std::initializer_list<V> vals);
- WGraph(std::initializer_list<WVertex<V>> verts);
- WEdge(DVertex<V>& ver);
- WEdge(E val, WVertex<V, E>& ver);
- WVertex(V val);

## Methods

Method name | Arguments                 | Return type   | Class         | Description
------------|---------------------------|---------------|---------------|-------------
add_vertex  | V val                     | void          | WGraph        | Adds new vertex with value **val** to the graph
add_vertex  | DVertex<V> v              | void          | WGraph        | Adds new vertex to the graph
add_edge    | DVertex<V>& dst           | void          | WVertex       | Adds new edge to the vertex passed as argument
add_edge    | WVertex<V, E>& dst, E val | void          | WVertex       | Adds new edge with value **val** to vertex passed as argument
set_value   | V val                     | void          | WVertex       | Sets value for vertex
set_value   | E val                     | void          | WEdge         | Sets value for the edge
