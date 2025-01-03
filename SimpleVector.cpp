#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>

class SimpleVector
{
	T* arr;
	int capacity;
	int length;
public:
	SimpleVector() 
	{
		arr = new T[10];
		capacity = 10;
		length = 0;
	}
	SimpleVector(int num) 
	{
		arr = new T[num];
		capacity = num;
		length = 0;
	}
	~SimpleVector() {
		delete[] arr;
	}
	void push_back(T a) {
		if (capacity <= length) {
			capacity += 5;
			T* temp = new T[capacity];
			for (int i = 0; i < length; i++) {
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
		}
		arr[length++] = a;
	}
	void pop_back() {
		length = length > 0 ? length - 1 : 0;
	}
	void resize(int num) {
		if (num > length) {
			capacity = num;
			T* temp = new T[capacity];
			for (int i = 0; i < length; i++) {
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
		}
	}
	void sortData() {
		sort(arr, arr + length);
	}
	int Size() {
		return length;
	}
	int Capacity() {
		return capacity;
	}

	T operator[](int i) { return arr[i]; }

};

int main() {
	SimpleVector<int> sv(30);
	sv.push_back(5);
	sv.push_back(10);
	sv.push_back(4);
	sv.push_back(2);

	int i = sv[2];

	cout << sv.Size()<<endl;
	cout << sv.Capacity()<<endl;
	cout << sv[2]<<endl;
	sv.pop_back();
	cout << sv.Size();

	return 0;
}