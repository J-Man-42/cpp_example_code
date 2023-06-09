#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include "../../display_structure/display_structure.h"


// The heap class.
template<class T>
class Heap
{
public:
	Heap(const bool maxHeap = true, const unsigned maxCapacity = 100);
	Heap(const Heap<T>& other);
	Heap(const T array[], const unsigned SIZE, const bool maxHeap = true);
	~Heap();

	Heap<T>& operator=(const Heap<T>& other);
	Heap<T> operator+(const T element);
	Heap<T>& operator+=(const T element);
	Heap<T>& operator--();
	Heap<T> operator--(int);

	void bft();
	void clear();
	unsigned capacity() const;
	Heap<T> clone();
	bool contains(const T element) const;
	void dft();
	void display();
	unsigned height() const;
	bool isEmpty() const;
	bool isMaxHeap() const;
	bool isMinHeap() const;
	bool isNotEmpty() const;
	void push(const T element);
	T pop();
	unsigned size() const;
	T* toDynamicArray();
	T* toDynamicArray(const unsigned SIZE);
	void toggleMaxMin();

private:
	bool compare(const T left, const T right) const;
	bool contains(const unsigned index, const T& element) const;
	void dft(const unsigned index);
	void heapify(unsigned index);

	unsigned numElements;
	unsigned maxCapacity;
	bool maxHeap;
	T* array;
};


#include "heap.cpp"

#endif
