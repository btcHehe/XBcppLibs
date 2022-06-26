# XBQueue.h
Template class for producing dynamic queues/FIFO buffers.

## Constructors
- Queue()
- Queue(int size)
- Queue(std::initializer_list<T> init_list)

## Methods
Method name | Arguments | Return type   | Description
------------|-----------|---------------|-------------
size        | -         | int           | Returns number of the elements in the vector
front       | -         | T             | Returns value of first element in the queue
back        | -         | T             | Returns value of the last element in the queue
push        | T val     | void          | Puts new object at the end of the queue
pop         | -         | T             | Removes first object of the queue and returns its copy