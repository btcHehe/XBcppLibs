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
				v = new T[length];
			}

			int size()
			{
				return length;
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

			void pushBack(T val)
			{
				T* temp = new T[length];
				length++;
				temp = v;
				temp[length-1] = val;
				v = new T[length];
				v = temp;
			}

			T popBack()
			{
				T popVal = v[length-1];
				length--;
				T* temp = new T[length];
				temp = v;
				v = new T[length];
				v = temp;
				return popVal;
			}

			void insert(int pos, T value)
			{
				T* frstHalf = new T[pos];
				T* scndHalf = new T[length-pos];
				length++;
				frstHalf = v;
				scndHalf = &v[pos];
				v = new T[length];
				// idk efficient way needed
			}

			T erase(int pos)
			{
				T* frstHalf = new T[pos];
				T* scndHalf = new T[length-pos];
				T retVal = v[pos];
				length--;
				frstHalf = v;
				scndHalf = &v[pos+1];
				v = new T[length];
				//idk efficient way needed
				return retVal;
			}

	};

}

#endif
