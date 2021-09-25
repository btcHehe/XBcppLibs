//Library for making two way lists
#ifndef XBList_H
#define XBList_H

namespace xb
{

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
	 public:
		int length = 0;
  		list(int size = 0)
		{
		  length = size;
		  if(size == 0)
		  {
			 element first;
			 first.next = 0;
			 first.prev = 0;
		  }
		  else
		  {
		    element* maker;
		    static element* last;               //memory remember previous object of the list
		    for(int i = 0 ; i < size ; i++)
		    {
		      maker = new element;
	 		 	if(i == 0)
			 	{
				  maker->prev = 0;
			 	  maker->next = 0;
			 	  firstItem = maker;
				  last = maker;
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
			 //-------------------------------------------------------------------------
		  }
		}
		void pushBack(T newValue)
		{
		  element* maker = new element;
		  maker->value = newValue;
		  maker->next = 0;
		  maker->prev = lastItem;
		  lastItem = maker;
		  length++;
		}

		void pushFront(T newValue)
		{
		  element* maker = new element;
		  maker->value = newValue;
		  maker->next = firstItem;
		  maker->prev = 0;
		  firstItem = maker;
		  length++;
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
		  //if(index >= (length/2))
		  //{
		  //  watcher = lastItem;
		  //  for(int i = 0; i < (length - index - 1); i++)
		  //  {
		  // 	  watcher = watcher->prev;
		  //  }
		  //}
		  //else
		  //{
		  //  watcher = firstItem;
		  //  watcher = watcher->next;
		  //  for(int i = 0; i < index ; i++)
		  //  {
		  // 	watcher = watcher->next;
		  //  }
		  //}
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
