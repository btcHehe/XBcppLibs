#ifndef XBSTACK_H
#define XBSTACK_H

namespace xb {
	template <typename T>
	class stack {
		private:
			int length;
		public:
			T* s;
			stack(int size=0) {
				length = size;
				s = new T[length];
			}

			T top() {
				return s[-1];
			}

			int size() {
				return length;
			}

			void push(T val) {
				if(length == 0) {
					length++;
					s = new T[length];
					s[-1] = val;
				}
				else {
					T* temp = new T[length];
					length++;
					temp = s;
					s = new T[length];
					s = temp;
					s[length-1] = val;
				}
			}

			T pop() {
				length--;
				T* temp = new T[length];
				T ret_val = s[length];
				temp = s;
				s = new T[length];
				s = temp;
				return ret_val;
			}
	};

}

#endif
