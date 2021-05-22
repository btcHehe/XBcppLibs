#ifndef XBQueue_H
#define XBQueue_H

namespace xb
{
	template<typename T>

	class queue
	{
		private:
			int length;
			T* q;
		public:
			queue(int size=0)
			{
				length = size;
				q = new T[length];
			}

			int size()
			{
				return length;
			}

			T front()
			{
				return q[0];
			}

			T back()
			{
				return q[-1];
			}

			void push(T val)
			{
				T* temp = new T[length];
				length++;
				temp = q;
				q = new T[length];
				q = temp;
				q[length-1] = val;
			}

			T pop()
			{
				T retVal = q[0];
				length--;
				T* temp = new T[length];
				temp = &q[1];
				q = new T[length];
				q = temp;
				return retVal;
			}

	};

}

#endif
