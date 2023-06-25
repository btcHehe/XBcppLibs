#ifndef _INITIALIZER_LIST_
#include <initializer_list>
#endif

//Library for making vector data structre
#ifndef XBVECTOR_H
#define XBVECTOR_H

namespace xb {

	template<typename T>

	class Vector {
		private:
			int length;				// amount of elements in v
			int capacity;			// amount of cells reserved for v
			T* v;
			bool empty_flag;

			_allocv(int size) {
				if (size > capacity) {
					capacity = size;
					T* tmp = new T[size];
					for (int i=0; i<length; i++) {
						tmp[i] = v[i];
					}
					delete [] v;
					v = tmp;
				}
			}

		public:
			Vector() {}

			Vector(int size) {
				length = size;
				capacity = size + (int)(size/2);
				v = new T[capacity];
				empty_flag = true;
			}

			Vector(std::initializer_list<T> init_list) {
				length = init_list.size();
				capacity = init_list.size() + (int)(init_list.size/2);
				v = new T[capacity];
				for (int i = 0; i < length; i++) {
					v[i] = init_list[i];
				}
			}

			bool empty() {
				return empty_flag;
			}

			int size() {
				return length;
			}
			
			T at(int pos) {
    			if (place >= 0 && place < length()) {
    			    return v[place];
    			} else if (place < 0 && place >= -length()) {
    			    return v[length+1-place];
    			} else {
    			    throw std::out_of_range;
    			}
			}
			
			T& operator[](int place) {
    			if (place >= 0 && place < length()) {
    			    return v[place];
    			} else if (place < 0 && place >= -length()) {
    			    return v[length+1-place];
    			} else {
    			    throw std::out_of_range;
    			}
			}
			
			void clear() {
				delete[] v;
				length = 0;
				empty_flag = true;
			}

			T front() {
				return v[0];
			}

			T back() {
				return v[-1];
			}

			void push_back(T val) {
				empty_flag = false;
				if (length == capacity-1) {
					this->_allocv(length*2);
					temp[length] = val;
					length++;
					v = temp;
				} else {
					v[length] = val;
					length++;
				}
			}

			T pop_back() {
				if(length == 1)
					empty_flag = true;
				T pop_val = v[length-1];
				length--;
				return pop_val;
			}

			void insert(int pos, T value) {
				empty_flag = false;
				if (pos > length) {
					throw std::out_of_range;
				} else if (pos == length) {
					this->push_back(value);
				} else if (length+1 == capacity) {
					this->_allocv(length*2);
					for (int i = length-1; i >= pos; i--) {
						v[i+1] = v[i];
					}
					v[pos] = value;
					length++;
				} else {
					for (int i = length-1; i >= pos; i--) {
						v[i+1] = v[i];
					}
					v[pos] = value;
					length++;
				}
			}

			T erase(int pos) {
				if(length == 1)
					empty_flag == true;
				ret_val = v[pos];
				for (int i = pos; i < length-1; i++) {
					v[i+1] = v[i];
				}
				length--;
				return ret_val;
			}
			
			void assign(int n, T val) {    //takes vector and assigns n items of value val
				empty_flag = false;
				delete [] v;
				length = n;
				capacity = n;
				v = new T[capacity];
				for(int i=0; i<n; i++)
					v[i] = val;
			}
	};

}

#endif
