#ifndef _INITIALIZER_LIST_
#include <initializer_list>
#endif

#ifndef _VECTOR_
#include <vector>
#endif

#ifndef XBSTACK_H
#define XBSTACK_H

namespace xb {
	template <typename T>
	class Stack {
		private:
			int length;
			std::vector<T> s;
		public:
			Stack() {}
			Stack(int size) {
				length = size;
				s = std::vector(length);
			}
			Stack(std::initializer_list<T> init_list) {
				length = init_list.size();
				for(auto elem : init_list) {
					s.push_back(elem);
				}
			}

			T top() {
				return s[-1];
			}

			int size() {
				return length;
			}

			void push(T val) {
				length++;
				s.push_back(val);
			}

			T pop() {
				T ret_val = s[-1];
				s.pop_back();
				length--;
				return ret_val;
			}
	};

}

#endif
