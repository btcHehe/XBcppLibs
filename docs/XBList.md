# XBVector.h

## Description
Template class for creating double linked list.

## Constructors
- Node(const T& value)
- XBList()


## Methods
Method name 	| 	Arguments 	 	| 	Return type   	| 	Description
------------	|	-----------	 	|	-----------	|	-------------
push_front  	| const T& value 		| void     		| Adds element to the front of the list
push_back   	| const T& value 		| void     		| Adds element to the back of the list
check_exist 	| const T& value 		| bool     		| Returns true if given element exists in the list and false if it doesn't
print_forward   | -       	 		| void        	        | Displays whole list in console from head to tail
print_backward  | -       	 		| void       	        | Displays whole list in console from tail to head
rm_elem     	| const T& value 		| T         		| Removes elements given in argument if element exists
rm_first    	| -         	 		| void         	 	| Removes element pointed by head
rm_last     	| -         	 		| void          	| Removes element pointed by tail
clear       	| -         	 		| void          	| Removes all elements in list
reverse     	| -         	 		| void          	| Reverses the order of the list (head is tail and tail is head)
modify_at   	| const int pos, const T& value | void			| Modifies object in list at given position with value
length     	| - 				| int          		| Return the length of the list
empty		| -				| bool			| Returns true if list empty false if not
at		| int pos			| T			| Returns element at given position