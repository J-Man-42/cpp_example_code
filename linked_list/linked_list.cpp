#include <iostream>
#include <sstream>
#include "linked_list.h"
using namespace std;


// The constructor.
template<class T>
LinkedList<T>::LinkedList() {
	head = tail = current = nullptr;
	length = 0;
}


// The copy constructor.
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {

	// If the same lists has been provided, do nothing.
	if (this == &other) {
		return;
	}

	// Set the initial parameters.
	this->length = other.length;
	this->head = nullptr;
	this->tail = nullptr;
	this->current = nullptr;

	// Copy other.head if not null.
	if (other.head) {
		this->head = new ListNode<T>(other.head->data);
		this->tail = this->head;
		this->current = this->head;

		// Copy all remaining elements.
		ListNode<T>* otherPtr = other.head->next;
		while (otherPtr) {
			this->tail->next = new ListNode<T>(otherPtr->data);
			this->tail->next->prev = this->tail;
			this->tail = this->tail->next;
			otherPtr = otherPtr->next;
		}
	}
}


// Construct a LinkedList from the given array.
template<class T>
LinkedList<T>::LinkedList(const T array[], const unsigned SIZE) {
	this->head = nullptr;
	this->tail = nullptr;
	this->length = 0;
	for (unsigned i = 0; i < SIZE; i++) {
		this->append(array[i]);
	}
	this->current = head;
}


// The destructor.
template<class T>
LinkedList<T>::~LinkedList() {
	clear();
}



// Output stream the list to string.
template<class T>
ostream& operator<<(ostream& out, LinkedList<T>& list) {
	out << list.toString();
	return out;
}



// Overload the assignment operator.
template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {

	// Only make changes if this and other are different lists.
	if (this != &other) {
		this->clear();
		this->length = other.length;

		// Copy other.head if not null.
		if (other.head) {
			this->head = new ListNode<T>(other.head->data);
			this->tail = this->head;
			this->current = this->head;

			// Copy all remaining elements.
			ListNode<T>* otherPtr = other.head->next;
			while (otherPtr) {
				this->tail->next = new ListNode<T>(otherPtr->data);
				this->tail->next->prev = this->tail;
				this->tail = this->tail->next;
				otherPtr = otherPtr->next;
			}
		}
	}

	return *this;
}



// Overload the subscript operator.
template<class T>
T& LinkedList<T>::operator[](const int index) {
	return findIndex(handleNegativeIndex(index))->data;
}



// Returns a copied list with element added to the end.
template<class T>
LinkedList<T> LinkedList<T>::operator+(const T element) {
	LinkedList<T> list = this->clone();
	list.append(element);
	return list;
}



// Returns a copied list with the other list added to the end.
template<class T>
LinkedList<T> LinkedList<T>::operator+(const LinkedList<T>& other) {
	LinkedList<T> list = this->clone();
	ListNode<T>* nodePtr = other.head;
	while (nodePtr) {
		list.append(nodePtr->data);
		nodePtr = nodePtr->next;
	}
	return list;
}



// Add the element to the end of this list.
template<class T>
LinkedList<T>& LinkedList<T>::operator+=(const T element) {
	this->append(element);
	return *this;
}



// Add the list of elements to the end of this list.
template<class T>
LinkedList<T>& LinkedList<T>::operator+=(const LinkedList<T>& other) {
	ListNode<T>* nodePtr = other.head;
	while (nodePtr) {
		this->append(nodePtr->data);
		nodePtr = nodePtr->next;
	}
	return *this;
}



// Add an element to the end of the list.
template<class T>
void LinkedList<T>::append(const T element) {
	length++;

	// See if it's the first element.
	if (isEmpty()) {
		head = tail = current = new ListNode<T>(element);
	}

	// Otherwise, add to the end.
	else {
		tail->next = new ListNode<T>(element);
		tail->next->prev = tail;
		tail = tail->next;
	}
}



// Delete all entries in the list.
template<class T>
void LinkedList<T>::clear() {
	length = 0;

	// Check if head is not null.
	if (!isEmpty()) {

		// Delete all nodes except the last.
		while (head != tail) {
			head = head->next;
			delete head->prev;
		}

		// Delete the final node.
		delete head;
		head = tail = current = nullptr;
	}
}



// Returns a hard copy of this list.
template<class T>
LinkedList<T> LinkedList<T>::clone() {
	return LinkedList<T>(*this);
}



// Returns true if element is in the list.
template<class T>
bool LinkedList<T>::contains(const T element) const {
	ListNode<T>* headPtr = head;
	ListNode<T>* tailPtr = tail;

	// Loop while both headPtr and tailPtr are not null.
	while (headPtr && tailPtr) {

		// Check if element at either headPtr or tailPtr.
		if (headPtr->data == element || tailPtr->data == element) {
			return true;
		}

		// Update pointers and ensure overlap has not occurred.
		headPtr = headPtr->next;
		if (!headPtr || headPtr == tailPtr || tailPtr->next == headPtr)
			return false;
		tailPtr = tailPtr->prev;
	}

	// The element was not found.
	return false;
}



// Returns the element at the given index.
template<class T>
T& LinkedList<T>::get(const int index) {
	return (*this)[index];
}



// Returns the first element in the list.
template<class T>
T& LinkedList<T>::getFirst() {

	// Throw an error if the list is empty.
	if (isEmpty()) {
		throw "Error! No elements in the list";
	}

	// Returns the element at head.
	return head->data;
}



// Returns the last element in the list.
template<class T>
T& LinkedList<T>::getLast() {

	// Throw an error if the list is empty.
	if (isEmpty()) {
		throw "Error! No elements in the list";
	}

	// Returns the element at head.
	return tail->data;
}



// Get the next element in the list.
template<class T>
T& LinkedList<T>::getNext() {

	// Throw an error if the list is empty.
	if (isEmpty()) {
		throw "Error! No elements in the list";
	}

	// If only one element.
	if (head == tail) {
		return head->data;
	}

	// If last element in the list.
	if (!current->next) {
		current = head;
		return tail->data;
	}

	// Otherwise, at least 2 in the list.
	current = current->next;
	return current->prev->data;
}



// Returns the list index of the given element.
template<class T>
int LinkedList<T>::indexOf(const T element) {
	ListNode<T>* nodePtr = head;
	int index = 0;

	// Iterate until null or element found.
	while (nodePtr) {
		if (nodePtr->data == element)
			return index;
		nodePtr = nodePtr->next;
		index++;
	}

	// If not found, return -1.
	return -1;
}



// Insert element at head.
template<class T>
void LinkedList<T>::insert(const T element) {
	length++;

	// See if it's the first element.
	if (isEmpty()) {
		head = tail = current = new ListNode<T>(element);
	}

	// Otherwise, insert at the beginning.
	else {
		head->prev = new ListNode<T>(element);
		head->prev->next = head;
		head = head->prev;
	}
}



// Insert element at the specified index.
template<class T>
void LinkedList<T>::insertAt(const int signedIndex, const T element) {
	ListNode<T>* newListNode = new ListNode<T>(element);

	// Accommodate negative indices.
	unsigned index = handleNegativeIndex(signedIndex);

	// If empty list, assign as head and tail.
	if (isEmpty()) {
		head = tail = current = newListNode;
	}

	// See if element is simply appended to the end.
	else if (index >= length) {
		tail->next = newListNode;
		newListNode->prev = tail;
		tail = newListNode;
	}

	// See if element should be added to the front.
	else if (index == 0) {
		head->prev = newListNode;
		newListNode->next = head;
		head = newListNode;
	}

	// It is somewhere in the middle.
	else {
		ListNode<T>* nodePtr = findIndex(index);
		newListNode->next = nodePtr;
		newListNode->prev = nodePtr->prev;
		newListNode->next->prev = newListNode;
		newListNode->prev->next = newListNode;
	}

	// Increment the length.
	length++;
}



// Returns true if head is null.
template<class T>
bool LinkedList<T>::isEmpty() const {
	return head == nullptr;
}


// Returns true if head is not null.
template<class T>
bool LinkedList<T>::isNotEmpty() const {
	return head != nullptr;
}



// Removes the first instance of the given element.
template<class T>
void LinkedList<T>::remove(const T element) {
	bool found = false;
	ListNode<T>* nodePtr = head;

	// Iterate until null or element found.
	while (nodePtr) {
		if (nodePtr->data == element) {
			found = true;
			break;
		}
		nodePtr = nodePtr->next;
	}

	// If not found, throw error.
	if (!found) {
		throw "Error! Element '"+to_string(element)+"' not found";
	}

	// The only element.
	if (head == tail) {
		delete head;
		head = tail = current = nullptr;
	}

	// The element is the first element.
	else if (head == nodePtr) {
		if (current == head) {
			current = current->next;
		}
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}

	// The element is the last element.
	else if (tail == nodePtr) {
		if (current == tail) {
			current = head;
		}
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}

	// Otherwise, it is somewhere in the middle.
	else {
		if (nodePtr == current) {
			current = current->next;
		}
		nodePtr->prev->next = nodePtr->next;
		nodePtr->next->prev = nodePtr->prev;
		delete nodePtr;
	}

	// Decrement the length.
	length--;
}



// Removes the element at the given index.
template<class T>
T LinkedList<T>::removeAt(const int signedIndex) {

	// Accommodate negative indices.
	unsigned index = handleNegativeIndex(signedIndex);

	// Throw error if index out of bounds.
	if (index >= length) {
		throw "Error! Index out of bounds";
	}

	// Find correct node and get the element.
	ListNode<T>* nodePtr = findIndex(index);
	T element = nodePtr->data;

	// The only element.
	if (head == tail) {
		delete head;
		head = tail = current = nullptr;
	}

	// The element is the first element.
	else if (head == nodePtr) {
		if (current == head) {
			current = current->next;
		}
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}

	// The element is the last element.
	else if (tail == nodePtr) {
		if (current == tail) {
			current = head;
		}
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}

	// Otherwise, it is somewhere in the middle.
	else {
		if (nodePtr == current) {
			current = current->next;
		}
		nodePtr->prev->next = nodePtr->next;
		nodePtr->next->prev = nodePtr->prev;
		delete nodePtr;
	}

	// Return the element.
	length--;
	return element;
}



// Remove the element at head.
template<class T>
T LinkedList<T>::removeFirst() {

	// Throw an error if the list is empty.
	if (isEmpty()) {
		throw "Error! No elements in the list";
	}

	// Update length and extract the element.
	T element = head->data;
	length--;

	// Only one element in the list.
	if (head == tail) {
		delete head;
		head = tail = current = nullptr;
	}

	// Otherwise, at least two elements in the list.
	else {
		if (current == head) {
			current = current->next;
		}
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}

	// Return the element.
	return element;
}



// Remove the element at tail.
template<class T>
T LinkedList<T>::removeLast() {

	// Throw an error if the list is empty.
	if (isEmpty()) {
		throw "Error! No elements in the list";
	}

	// Update length and extract the element.
	T element = tail->data;
	length--;

	// Only one element in the list.
	if (head == tail) {
		delete head;
		head = tail = current = nullptr;
	}

	// Otherwise, at least two elements in the list.
	else {
		if (current == tail) {
			current = head;
		}
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}

	// Return the element.
	return element;
}



// Reset the current pointer to head.
template<class T>
void LinkedList<T>::resetNext() {
	current = head;
}



// Reverse this linked list.
template<class T>
void LinkedList<T>::reverse() {
	ListNode<T>* nodePtr = head;
	ListNode<T>* prevPtr = nullptr;

	// Swap head and tail.
	swap(head, tail);

	// Loop through all elements and swap next and prev.
	while (nodePtr) {
		prevPtr = nodePtr;
		nodePtr = nodePtr->next;
		swap(prevPtr->next, prevPtr->prev);
	}
}



// Return a reversed version of this list.
template<class T>
LinkedList<T> LinkedList<T>::reversed() {
	LinkedList<T> list;
	ListNode<T>* nodePtr = head;
	while (nodePtr) {
		list.insert(nodePtr->data);
		nodePtr = nodePtr->next;
	}
	return list;
}



// Set the element at the given index.
template<class T>
void LinkedList<T>::set(const int signedIndex, const T element) {

	// Accommodate negative indices.
	unsigned index = handleNegativeIndex(signedIndex);

	// If index out of bounds, add to the end.
	if (index >= length) {
		append(element);
		return;
	}

	// Find the node and set the element.
	ListNode<T>* nodePtr = findIndex(index);
	nodePtr->data = element;
}



// Set the element at head.
template<class T>
void LinkedList<T>::setFirst(const T element) {

	// If empty list, simply add element.
	if (isEmpty()) {
		append(element);
		return;
	}

	// Set the element at head.
	head->data = element;
}



// Set the element at tail.
template<class T>
void LinkedList<T>::setLast(const T element) {

	// If empty list, simply add element.
	if (isEmpty()) {
		append(element);
		return;
	}

	// Set the element at head.
	tail->data = element;
}



// Get the number of elements in the list.
template<class T>
unsigned LinkedList<T>::size() const {
	return length;
}



// Returns a sub list from start to end.
template<class T>
LinkedList<T>* LinkedList<T>::subList(const unsigned start, const unsigned end) {

	// Throw error if invalid index.
	if (start >= end || start >= length || end > length) {
		throw "Error! Index out of bounds";
	}

	// Create the new list.
	LinkedList<T>* list = new LinkedList();

	// Find the starting point.
	ListNode<T>* nodePtr = findIndex(start);

	// Copy elements from start to end.
	for (unsigned i = start; i < end; i++) {
		list->append(nodePtr->data);
		nodePtr = nodePtr->next;
	}

	// Return the sublist.
	return list;
}



// Converts the list into a dynamic array.
template<class T>
T* LinkedList<T>::toDynamicArray() {

	// Throw an error if the list is empty.
	if (isEmpty()) {
		throw "Error! No elements in the list";
	}

	// Returns array of list length.
	return toDynamicArray(length);
}


// Converts the list into a dynamic array of the given size.
template<class T>
T* LinkedList<T>::toDynamicArray(const unsigned SIZE) {

	// Copy all elements to the new array.
	T* array = new T[SIZE];
	ListNode<T>* nodePtr = head;
	unsigned limit = (length > SIZE ? SIZE : length);
	for (unsigned i = 0; i < limit; i++) {
		array[i] = nodePtr->data;
		nodePtr = nodePtr->next;
	}

	// Return the final array.
	return array;
}



// Returns the string representation of the list.
template<class T>
string LinkedList<T>::toString() {

	// Return empty parenthesis if empty list.
	if (isEmpty()) {
		return "()";
	}

	// Iterate through all elements.
	ListNode<T>* nodePtr = head;
	stringstream ss;
	ss << "(";
	while (nodePtr->next) {
		ss << nodePtr->data << ")──(";
		nodePtr = nodePtr->next;
	}
	ss << nodePtr->data << ")";
	return ss.str();
}



// Find the node corresponding to the given index.
template<class T>
ListNode<T>* LinkedList<T>::findIndex(const unsigned index) {
	ListNode<T>* nodePtr;

	// Throw error if index out of bounds.
	if (index >= length) {
		throw "Error! Index out of bounds";
	}

	// See if index is closer to head.
	if (length-index >= index) {
		nodePtr = head;
		for (unsigned i = 0; i < index; i++) {
			nodePtr = nodePtr->next;
		}
	}

	// Otherwise, index is closer to tail.
	else {
		nodePtr = tail;
		for (unsigned i = length-1; i > index; i--) {
			nodePtr = nodePtr->prev;
		}
	}

	// Return the element.
	return nodePtr;
}



// Return the positive index equivalent.
template<class T>
unsigned LinkedList<T>::handleNegativeIndex(const int index) {
	if (index < 0)
		return length + index;
	return index;
}
