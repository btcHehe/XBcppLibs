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
			bool emptyFlag;
		public:
			vector(int size=0)
			{
				length = size;
				v = new T[length];
				emptyFlag = true;
			}

			bool empty()
			{
				return emptyFlag;
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
				emptyFlag = true;
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
				emptyFlag = false;
				T* temp = new T[length];
				temp = v;
				temp[length] = val;
				length++;
				v = new T[length];
				v = temp;
			}

			T popBack()
			{
				if(length == 1)
					emptyFlag = true;
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
				emptyFlag = false;
				T* frstHalf = new T[pos];
				T* scndHalf = new T[length-pos];
				length++;
				frstHalf = v;
				T temp = v[pos];
				scndHalf = &v[pos];
				v = new T[length];
				v = frstHalf;
				v[pos] = value;
				T temp2;
				for(int i=pos+1; i<length; i++)
				{
					temp2 = v[i];
					v[i] = temp;
					temp = temp2;
				}
					// idk may be theres more efficient way
			}

			T erase(int pos)
			{
				if(length == 1)
					emptyFlag == true;
				T* frstHalf = new T[pos];
				T* scndHalf = new T[length-pos];
				T retVal = v[pos];
				frstHalf = v;
				//scndHalf = &v[pos+1];
				length--;
				v = new T[length];
				v = frstHalf;
				for(int i=pos+1; i<length+1; i++)
				{
					v[i-1] = v[i];
				}
				//idk may be theres more efficient way
				return retVal;
			}
			
			void assign(int n, T val)    //takes vector and assigns n items of value val
			{
				emptyFlag = false;
				length = n;
				v = new T[n];
				for(int i=0; i<n; i++)
					v[i] = val;
			}

	};

}

#endif
