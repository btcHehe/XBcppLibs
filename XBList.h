//Library for making two way lists
#ifndef XBList_H
#define XBList_H

namespace xb
{
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
  class list
  {
	  struct element
	  {
	  	T value;
		  element* next;
		  element* prev;
		};
	  element* lastItem;
		element* firstItem;
		bool emptyFlag;
		int length = 0;
		public:
  	list(int size = 0)
		{
		  length = size;
		  if(size == 0)
		  {
			  emptyFlag = true;
			  element first;
			  first.next = 0;
			  first.prev = 0;
		  }
		  else
		  {
				emptyFlag = false;
				element* maker;
		   	static element* last;               //memory remember previous last object of the list
		    for(int i = 0 ; i < size ; i++)
				{
				  	maker = new element;
	 		 	  	if(i == 0)
			 	  	{
				  	  maker->prev = 0;
				  	  maker->next = 0;
				  	  last = maker;
			 	  	  firstItem = last;
			 	  	}
			 	  	else if(i == size - 1)
			 	  	{
				  		last->next = maker;
			 	  		maker->prev = last;
			 	  		maker->next = 0;
			 	  		lastItem = maker;
			 	  	}
		   	  	else
		      	{
				  		last->next = maker;
				  		maker->prev = last;
		      	 	maker->next = 0;
		      	}
						last = maker;
		     }
		 		for(int i = 0 ; i < size ; i++)
			 	{
					element* ptr;
					if(i == 0)
					{
					  ptr = firstItem;
					  last = ptr;
					}
					else
					{
					  ptr = ptr->next;
					}
					last = ptr;
			 	}
		  }
		}
		//-------------------------------------------------------------------------
		
		element front()
		{
			return *firstItem;
		}

		element back()
		{
			return *lastItem;
		}

		bool empty()
		{
			return emptyFlag;
		}

		int size()
		{
			return length;
		}

		void clear()
		{
			firstItem->next = 0;
			lastItem->prev = 0;
			length = 0;
			emptyFlag = true;
		}

		void erase(int index)
		{
			if(length == 1)
				emptyFlag = true;
			element* ptr = firstItem;
			int i = 0;
			while(i != index)
			{
				ptr = ptr->next;
				i++;
			}
			ptr->value = 0;
		}

		void pushBack(T newValue)
		{
			if(length == 0)
			{
				emptyFlag = false;
				firstItem = new element;
				firstItem->value = newValue;
				lastItem = firstItem;
				length++;
			}
			else
			{
				element* maker = new element;
		   	maker->value = newValue;
		   	maker->next = 0;
		   	maker->prev = lastItem;
				lastItem->next = maker;
		   	lastItem = maker;
		   	length++;
			}
		}

		T popBack()
		{
			if(length == 1)
				emptyFlag = true;
			T retVal = lastItem->value;
			element* tmp = lastItem->prev;
			delete lastItem;
			length--;
			lastItem = tmp;
			return retVal;
		}

		void pushFront(T newValue)
		{
			if(length == 0)
			{
				emptyFlag = false;
				firstItem = new element;
				firstItem->value = newValue;
				lastItem = firstItem;
				length++;
			}
			else
			{
		   	element* maker = new element;
		   	maker->value = newValue;
		   	maker->next = firstItem;
		   	maker->prev = 0;
		   	firstItem = maker;
		   	length++;
			}
		}

		T popFront()
		{
			if(length == 1)
				emptyFlag = true;
			T retVal = firstItem->value;
			firstItem = firstItem->next;
			firstItem->prev = 0;
			length--;
			return retVal;
		}

		void insert(int index, T val)   //BROKEN 
		{
			length++;
			element* ptr = firstItem;
			int i = 0;
			while(i != index)
			{
				ptr = ptr->next;
				i++;
			}
			element* tmp = ptr->prev;
			element* newElem = new element;
			newElem->value = val;
			newElem->prev = tmp;
			tmp->next = newElem;
			ptr->prev = newElem;
			newElem->next = ptr;
		}

		void changeValue(int index ,T newValue)           //we start indexing from 0
		{
		  element* ptr = 0;
		  if(index >= (length/2))
		  {
			 ptr = lastItem;
			 for(int i = 0; i < (length - index - 1); i++)
			 {
				  ptr = ptr->prev;
			 }
		  }
		  else
		  {
			 ptr = firstItem;
			 for(int i = 0; i < index ; i++)
			 {
				ptr = ptr->next;
			 }
		  }
		  ptr->value = newValue;
		}



		//-----------------for development purpose only-------------------------------//

		T seekValue(int index)
		{
		  element* watcher;
		  int i = 0;
		  watcher = firstItem;
		  while(i != index)
		  {
				watcher = watcher->next;
				i++;
		  }
		  return watcher->value;
		}


		element* seekNext(int index)
		{
		  element* watcher;
		  if(index >= (length/2))
		  {
			 watcher = lastItem;
			 for(int i = 0; i < (length - index - 1); i++)
			 {
				  watcher = watcher->prev;
			 }
		  }
		  else
		  {
			 watcher = firstItem;
			 for(int i = 0; i < index ; i++)
			 {
				watcher = watcher->next;
			 }
		  }
		  return watcher->next;
		}

		element* seekPrev(int index)
		{
		  element* watcher;
		  if(index >= (length/2))
		  {
			 watcher = lastItem;
			 for(int i = 0; i < (length - index - 1); i++)
			 {
				  watcher = watcher->prev;
			 }
		  }
		  else
		  {
			 watcher = firstItem;
			 for(int i = 0; i < index ; i++)
			 {
				watcher = watcher->next;
			 }
		  }
		  return watcher->prev;
		}


  };

}

#endif
