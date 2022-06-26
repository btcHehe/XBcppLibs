//Library for making two way lists
#ifndef XBLIST_H
#define XBLIST_H

namespace xb {
	//TODO:
	//[x] front
	//[x] back
	//[x] empty
	//[x] size
	//[x] clear
	//[] insert
	//[] erase
	//[x] push_back
	//[x] pop_back
	//[x] push_front
	//[x] pop_front
	//[] resize
	//[] swap
	//[] reverse

  template <typename T>
  class list {
	struct element {
	  	T value;
		element* next;
		element* prev;
	};
	element* last_item;
	element* first_item;
	bool empty_flag;
	int length = 0;
	public:
  	list(int size = 0) {
		  length = size;
		  if(size == 0) {
				empty_flag = true;
				element first;
				first.next = 0;
				first.prev = 0;
		  } else {
				empty_flag = false;
				element* maker;
		   		static element* last;               //memory remember previous last object of the list
				for(int i = 0 ; i < size ; i++) {
					maker = new element;
	 		 		if(i == 0) {
					  	maker->prev = 0;
					  	maker->next = 0;
					  	last = maker;
			 		  	firstItem = last;
			 		} else if(i == size - 1) {
					  	last->next = maker;
			 		  	maker->prev = last;
			 		  	maker->next = 0;
			 		  	lastItem = maker;
			 		} else {
					  	last->next = maker;
					  	maker->prev = last;
		      		 	maker->next = 0;
		      		}
					last = maker;
		    	}
		 		for(int i = 0 ; i < size ; i++) {
					element* ptr;
					if(i == 0) {
					  ptr = first_item;
					  last = ptr;
					} else {
					  ptr = ptr->next;
					}
					last = ptr;
			 	}
			}
		}
		//-------------------------------------------------------------------------
		
		element front() {
			return *first_item;
		}

		element back() {
			return *last_item;
		}

		bool empty() {
			return empty_flag;
		}

		int size() {
			return length;
		}

		void clear() {
			first_item->next = 0;
			last_item->prev = 0;
			length = 0;
			empty_flag = true;
		}

		void erase(int index) {
			if(length == 1)
				empty_flag = true;
			element* ptr = first_item;
			int i = 0;
			while(i != index) {
				ptr = ptr->next;
				i++;
			}
			ptr->value = 0;
		}

		void push_back(T new_value) {
			if(length == 0) {
				empty_flag = false;
				first_item = new element;
				first_item->value = new_value;
				last_item = first_item;
				length++;
			} else {
				element* maker = new element;
		   		maker->value = new_value;
		   		maker->next = 0;
		   		maker->prev = last_item;
				last_item->next = maker;
		   		last_item = maker;
		   		length++;
			}
		}

		T pop_back() {
			if(length == 1)
				empty_flag = true;
			T ret_val = last_item->value;
			element* tmp = last_item->prev;
			delete last_item;
			length--;
			last_item = tmp;
			return ret_val;
		}

		void push_front(T new_value) {
			if(length == 0) {
				empty_flag = false;
				first_item = new element;
				first_item->value = new_value;
				last_item = first_item;
				length++;
			} else {
		   		element* maker = new element;
		   		maker->value = new_value;
		   		maker->next = first_item;
		   		maker->prev = 0;
		   		first_item = maker;
		   		length++;
			}
		}

		T pop_front() {
			if(length == 1)
				empty_flag = true;
			T ret_val = first_item->value;
			first_item = first_item->next;
			first_item->prev = 0;
			length--;
			return ret_val;
		}

		void insert(int index, T val) {		// BROKEN
			length++;
			element* ptr = first_item;
			int i = 0;
			while(i != index) {
				ptr = ptr->next;
				i++;
			}
			element* tmp = ptr->prev;
			element* new_elem = new element;
			new_elem->value = val;
			new_elem->prev = tmp;
			tmp->next = new_elem;
			ptr->prev = new_elem;
			new_elem->next = ptr;
		}

		void change_value(int index ,T new_value) {           //we start indexing from 0
			element* ptr = 0;
			if(index >= (length/2)) {
				ptr = last_item;
				for(int i = 0; i < (length - index - 1); i++) {
				     ptr = ptr->prev;
				}
			} else {
				ptr = first_item;
				for(int i = 0; i < index ; i++)
				{
				   ptr = ptr->next;
				}
		  	}
		  	ptr->value = new_value;
		}



		//-----------------for development purpose only-------------------------------//

		T seek_value(int index) {
			element* watcher;
			int i = 0;
			watcher = first_item;
			while(i != index) {
			  	watcher = watcher->next;
			  	i++;
			}
			return watcher->value;
		}


		element* seek_next(int index) {
			element* watcher;
			if(index >= (length/2)) {
			   watcher = last_item;
			   for(int i = 0; i < (length - index - 1); i++) {
			  	  watcher = watcher->prev;
			   }
			} else {
			   watcher = first_item;
			   for(int i = 0; i < index ; i++) {
			  	watcher = watcher->next;
			   }
			}
			return watcher->next;
		}

		element* seek_prev(int index) {
			element* watcher;
			if(index >= (length/2)) {
			   watcher = last_item;
			   for(int i = 0; i < (length - index - 1); i++) {
			  	  watcher = watcher->prev;
			   }
			} else {
			   watcher = firstItem;
			   for(int i = 0; i < index ; i++) {
			  	watcher = watcher->next;
			   }
			}
			return watcher->prev;
		}


  };

}

#endif
