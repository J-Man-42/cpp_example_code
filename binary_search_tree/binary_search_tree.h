#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>


// The node class.
template<class T>
class Node
{
public:
	Node(const T data) {
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
	~Node() {
		this->left = nullptr;
		this->right = nullptr;
	}
	T data;
	Node<T>* left;
	Node<T>* right;
};


// The binary search tree class.
template<class T>
class BinarySearchTree
{
public:
	BinarySearchTree();
	// BinarySearchTree(const BinarySearchTree<T>& other);
	// BinarySearchTree(const T array[], const uint SIZE);
	// ~BinarySearchTree();

	void bft();
	void dft();

// 	template<class U>
// 	friend std::ostream& operator<<(
// 		std::ostream& out, BinarySearchTree<U>& list);

// 	BinarySearchTree<T>& operator=(const BinarySearchTree<T>& other);
// 	T& operator[](const int index);
// 	BinarySearchTree<T> operator+(const T element);
// 	BinarySearchTree<T> operator+(const BinarySearchTree<T>& other);
// 	BinarySearchTree<T>& operator+=(const T element);
// 	BinarySearchTree<T>& operator+=(const BinarySearchTree<T>& other);
// 	void append(const T element);
// 	void clear();
// 	BinarySearchTree<T> clone();
// 	bool contains(const T element) const;
// 	T& get(const int index);
// 	T& getFirst();
// 	T& getLast();
// 	T& getNext();
// 	int indexOf(const T element);
	void insert(const T element);
// 	void insertAt(const int signedIndex, const T element);
// 	bool isEmpty() const;
// 	void remove(const T element);
// 	T removeAt(const int signedIndex);
// 	T removeFirst();
// 	T removeLast();
// 	void resetNext();
// 	void reverse();
// 	BinarySearchTree<T> reversed();
// 	void set(const int signedIndex, const T element);
// 	void setFirst(const T element);
// 	void setLast(const T element);
// 	uint size() const;
// 	BinarySearchTree<T>* subList(const uint start, const uint end);
// 	T* toDynamicArray();
// 	T* toDynamicArray(const uint SIZE);
// 	std::string toString();

private:
	void bft(Node<T>* node);
	void dft(Node<T>* node);
	void insert(Node<T>* node, const T& element);
	Node<T>* root;
};


#include "binary_search_tree.cpp"

#endif