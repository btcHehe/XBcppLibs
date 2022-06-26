#ifndef _INITIALIZER_LIST_
#include <initializer_list>
#endif

#ifndef _VECTOR_
#include <vector>
#endif

#ifndef XBQUEUE_H
#define XBQUEUE_H

namespace xb {
	template<typename T>
	class Queue {
		private:
			int length;
			std::vector<T> q;
		public:
			Queue() {}
			Queue(int size) {
				length = size;
				q = std::vector<T>(length);
			}
			Queue(std::initializer_list<T> init_list) {
				length = init_list.size();
				q = std::vector<T>(length);
				for(int i = 0; i < length; i++) {
					q[i] = init_list[i];
				}
			}

			int size() {
				return length;
			}

			T front() {
				return q[0];
			}

			T back() {
				return q[-1];
			}

			void push(T val) {
				q.push_back(val);
				length++;
			}

			T pop() {
				T ret_val = q.front();
				q.erase(q.begin());
				return ret_val;
			}

	};

}

#endif
