#ifndef _VECTOR_
#define _VECTOR_ 1

template<class A>
class Vector {
	private:
		A *arr;
		int _capacity, _size;

	public:
		Vector() {arr = 0; _capacity = _size = 0;}
		Vector(int n) {arr = new A[n]; _capacity = n; _size = 0;}
		Vector(int n, A value) {
			arr = new A[n];
			_capacity = _size = n;
			for (int i = 0; i < n; i++) {
				arr[i] = value;
			}
		}

		int capacity() {return _capacity;}
		int size() {return _size;}
		bool empty() {return _size == 0;}

		void pop_back() {if (_size > 0) _size--;}

		void expand(int new_cap) {
			_capacity = new_cap;

			A *new_arr = new A[_capacity];
			for (int i = 0; i < _size; i++) new_arr[i] = arr[i];

			if(arr) delete[]arr;
			arr = new_arr;
		}

		void push_back(A new_val) {
			if (_size == _capacity) expand(_capacity * 2 + 5);
			arr[_size] = new_val;
			_size++;
		}

		A& back () {return arr[_size-1];}

		A& operator[](int i) {return arr[i];}

		void swap (int index1, int index2) {
			A temp = arr[index1];
			arr[index1] = arr[index2];
			arr[index2] = temp;
		}
};

#endif
