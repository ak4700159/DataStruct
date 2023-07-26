#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "logger.h"
using namespace std;


class MyVector{
	private:
		int * arr;
		int capacity;
		int len;
	public:
		MyVector();
		void push_back(int data);
		int at(int idx);
		int size();
		friend ostream& operator<<(ostream &os, const MyVector &vector);
		int operator[](int idx);
};

MyVector::MyVector(){
	LOG("I'm a constructor!");

	this->len = -1;
	this->capacity = 1;
	arr = (int*)malloc(sizeof(int) * capacity);
}

int MyVector::size(){
	return len+1;
}

void MyVector::push_back(int data){
	len++;
	if(len > capacity){
		cout << "재할당 전 LEN : " << len << " CAPACITY : " << capacity << endl;
		capacity *= 2;
		arr = (int*)realloc(arr, sizeof(int) * capacity);
		cout << "재할당 후 LEN : " << len << " CAPACITY : " << capacity << endl;
	}
	arr[len] = data;
}

int MyVector::at(int idx){
	if(idx < 0 || idx > len){
		cout <<"범위 초과 오류입니다." << endl;
		exit(1);
	}

	return arr[idx];
}

int MyVector::operator[](int idx){
	if(idx < 0 || idx > len){
		cout <<"범위 초과 오류입니다." << endl;
		exit(1);
	}

	return arr[idx];
}

ostream& operator<<(ostream &os, const MyVector &vector){
	for(int i = 0; i < vector.len; i++){
		os << "arr[" << i << "] : [ " << vector.arr[i] << " ]" << endl;
	}
	return os;
}

int main(void){
	MyVector vector;
	for(int i = 0; i < 10; i++){
		vector.push_back(i);
	}
	cout << vector << endl;
	cout << "idx(4) : " << vector.at(4) << endl;
	cout << "idx[4] : " << vector[4] << endl;

	return 0;
}
