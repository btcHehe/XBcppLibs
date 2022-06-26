# XBVector.h

## Description
Template class for producing dynamic vectors comparable to std::vector<T>. Vector is indexed starting from 0.

## Constructors
- Vector()
- Vector(int size)
- Vector(std::initializer_list<T> init_list)

## Methods
Method name | Arguments | Return type   | Description
------------|-----------|---------------|-------------
empty       | -         | bool          | Returns the status of emptiness of the vector object
size        | -         | int           | Returns number of the elements in the vector
at          | int pos   | T             | Returns value of the element stored in the vector at the **pos** position
operator [] | int place | T*            | Returns element stored in the vector at the **pos** position
clear       | -         |   void        |  Clears the whole vector and sets it's **length** to 0
front       | -         | T             | Returns first element of the vector
back        | -         | T             | Returns last element of the vector
push_back   | T val     | void          | Adds new object to the end of the vector
pop_back    | -         | T             | Removes last object in the vector and returns it's copy
insert      | int pos, T val | void     | Puts new object in the specified position **pos** in the vector
erase       | int pos   | T             | Removes object from chosen position **pos** in the vector and returns it
assign      | int n, T val | void       | Fills vector with **n** objects of value **val**; the operation is destructive
