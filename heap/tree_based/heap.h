#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include "../../display_structure/display_structure.h"


// The node class.
template<class T>
class HeapNode
{
public:
	HeapNode() {
		this->data = NULL;
		this->height = 0;
		this->colour = '\0';
		this->parent = nullptr;
		this->left = nullptr;
		this->right = nullptr;
		this->next = nullptr;
		this->prev = nullptr;
	}
	HeapNode(const T data) {
		this->data = data;
		this->height = 1;
		this->colour = '\0';
		this->parent = nullptr;
		this->left = nullptr;
		this->right = nullptr;
		this->next = nullptr;
		this->prev = nullptr;
	}
	HeapNode(HeapNode* other) {
		this->data = other->data;
		this->height = other->height;
		this->colour = other->colour;
		this->parent = nullptr;
		this->left = nullptr;
		this->right = nullptr;
		this->next = nullptr;
		this->prev = nullptr;
	}
	~HeapNode() {
		this->parent = nullptr;
		this->left = nullptr;
		this->right = nullptr;
		this->next = nullptr;
		this->prev = nullptr;
	}
	T data;
	char colour;
	unsigned height;
	HeapNode<T>* parent;
	HeapNode<T>* left;
	HeapNode<T>* right;
	HeapNode<T>* next;
	HeapNode<T>* prev;
};


// The heap class.
template<class T>
class Heap
{
public:
	Heap(const bool maxHeap = true);
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
	bool contains(HeapNode<T>* node, const T& element) const;
	void clear(HeapNode<T>* node);
	void clone(HeapNode<T>* thisNode, HeapNode<T>* otherNode);
	void dft(HeapNode<T>* node);
	void heapify(HeapNode<T>* node);
	void updateHeight(HeapNode<T>* node);

	HeapNode<T>* root;
	HeapNode<T>* leftmost;
	unsigned numElements;
	bool maxHeap;
};


#include "heap.cpp"

#endif
