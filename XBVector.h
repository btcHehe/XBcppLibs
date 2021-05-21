//Library for making vector data structre
#ifndef XBVector_H
#define XBVector_H

namespace xb
{

	template<typename T>

	class vector
	{
		private:
			int length;
			T* v;
		public:
			vector(int size=0)
			{
				length = size;
				if(length != 0)
					v = new T[length];
				else
				{
					T temp[0];
					v = temp;
				}
			}

			int size()
			{
				return length;
			}

			void pushBack(T val)
			{
				if(length == 0)
				{
					length++;
					v = new T[length];
					v[0] = val;
				}
				else
				{
					T* temp = new T[length];
					for(int i=0; i<length; i++)
						temp[i] = v[i];
					length++;
					v = new T[length];
					for(int i=0; i<length; i++)
						v[i] = temp[i];
					v[length-1] = val;
					delete [] temp;
				}
			}
			
			T popBack()
			{
				length--;
				T* temp = new T[length];
				T popVal = v[-1];
				for(int i=0; i<length; i++)
					temp[i] = v[i];
				v = new T[length];
				for(int i=0; i<length; i++)
					v[i] = temp[i];
				delete[] temp;
				return popVal;
			}

			T at(int pos)
			{
				if(pos > length-1)
					throw nullptr;
				return v[pos];
			}
			
			void clear()
			{
				delete[] v;
				length = 0;
			}

			T front()
			{
				return v[0];
			}

			T back()
			{
				return v[-1];
			}

			void insert(int pos, T value)
			{
				length++;
				T* temp = new T[length-1];
				for(int i=0; i<length-1; i++)
					temp[i] = v[i];
				v = new T[length];
				for(int i=0; i<pos; i++)
					v[i] = temp[i];
				v[pos] = value;
				for(int i=pos+1; i<length; i++)
					v[i] = temp[i-1];
			}

			T erase(int pos)
			{
				T removeVal = v[pos];
				T* temp = new T[length];
				for(int i=0; i<length; i++)
					temp[i] = v[i];
				length--;
				v = new T[length];
				for(int i=0; i<pos; i++)
					v[i] = temp[i];
				for(int i=pos+1; i<length+1; i++)
					v[i-1] = temp[i];
				return removeVal;
			}

	};

}

#endif
