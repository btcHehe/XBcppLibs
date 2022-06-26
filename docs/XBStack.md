# XBStack.h
Template class for producing dynamic stacks.

## Constructors
- Stack()
- Stack(int size)
- Stack(std::initializer_list<T> init_list)

## Methods
Method name | Arguments | Return type   | Description
------------|-----------|---------------|-------------
size        | -         | int           | Returns number of the elements on the stack
top         | -         | T             | Returns value of first element on the stack
push        | T val     | void          | Puts new object at the top of the stack
pop         | -         | T             | Removes object from the top of the stack