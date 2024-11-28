#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE 1
#include <iostream>
#include "_VECTOR.hpp"
#include "_COMPARE.hpp"


template<class A, class cmp = Less<A>>
class Priority_Queue {
	private:
		Vector<A> heap;
		cmp _cmp;

		void push_elem(int index) {
			while (index > 0 && _cmp(heap[index], heap[(index - 1 ) / 2] )) {
				heap.swap(index, (index-1)/2);
				index = (index - 1) / 2;
			}
		}

		void pop_elem(int index) {
			int left = index * 2 + 1;
			int right = index * 2 + 2;
			int min = index;

			if (left < heap.size() && _cmp(heap[left], heap[min])) {
				min = left;
			}

			if (right < heap.size() && _cmp(heap[right], heap[min])) {
				min = right;
			}

			if(min != index) {
				heap.swap(min, index);
				pop_elem(min);
			}
		}
	public:
		int size () {return heap.size();}

		bool empty() {return heap.empty();}

		A& top () {return heap[0];}
		A& back () {return heap[heap.size() - 1];}

		void push (A value) {
			heap.push_back(value);
			push_elem(heap.size() - 1);
		}

		void pop () {
			if (!heap.empty()) {
				heap[0] = heap[heap.size()-1];
				heap.pop_back();
				pop_elem(0);
			}
			else std::cout << "Hang doi rong.\n";
		}
		
		A& operator[](int index) {return heap[index];}
};

#endif
