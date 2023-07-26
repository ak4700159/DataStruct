#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "logger.h"

using namespace std;

template <class T>
class MyVector{
	private:
		T * arr;
		int capacity;
		int len;
	public:
		MyVector();
		void push_back(T data);
		T at(int idx);
		int size();
//		friend ostream& operator<<(ostream &os, const MyVector &vector);
		T operator[](int idx);
};

template <class T>
MyVector<T>::MyVector(){
	this->len = -1;
	this->capacity = 1;
	arr = (T*)malloc(sizeof(T) * capacity);
}

template <class T>
int MyVector<T>::size(){
	return len+1;
}

template <class T>
void MyVector<T>::push_back(T data){
	len++;
	if(len > capacity){
		
		LOG("재할당전LEN:%d, CAP=%d ", len,capacity); 

		for(int i = 0 ; i < 10 ; i++)
			LOG("HELLO");

		capacity *= 2;
		arr = (T*)realloc(arr, sizeof(T) * capacity);

		LOG("재할당후LEN:%d, CAP=%d ", len,capacity); 
	}
	arr[len] = data;
}

template <class T>
T MyVector<T>::at(int idx){
	if(idx < 0 || idx > len){
		cout <<"범위 초과 오류입니다." << endl;
		exit(1);
	}

	return arr[idx];
}

template <class T>
T MyVector<T>::operator[](int idx){
	if(idx < 0 || idx > len){
		cout <<"범위 초과 오류입니다." << endl;
		exit(1);
	}

	return arr[idx];
}
/*
ostream& operator<<(ostream &os, const MyVector &vector){
	for(int i = 0; i < vector.len; i++){
		os << "arr[" << i << "] : [ " << vector.arr[i] << " ]" << endl;
	}
	return os;
}
*/

int main(void){
	MyVector<double> vector;
	for(int i = 0; i < 10; i++){
		vector.push_back(1.1);
	}
//	cout << vector << endl;
	cout << "idx(4) : " << vector.at(4) << endl;
	cout << "idx[4] : " << vector[4] << endl;

	return 0;
}
