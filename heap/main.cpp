#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cmath>
#include "heap.h"
#include "../move_cursor/move_cursor.h"
#include "../random/random.h"
using namespace std;
using namespace std::this_thread;	// sleep_for, sleep_until
using namespace std::chrono;		// nanoseconds, system_clock, seconds.


// Main function.
int main() {
	char answer[3];
	unsigned number;
	unsigned element;

	// Create the heap.
	Heap<unsigned> heap;
	Heap<unsigned> temp;

	// Loop until Q has been entered.
	while (answer[0] != 'Q') {

		// Clear the screen
		clearScreen();

		// Traverse the heap.
		cout << "DFT:";
		heap.dft();
		cout << "BFT:";
		heap.bft();

		// Print the heap height and size.
		cout << "Height:  " << heap.height() << endl;
		cout << "Size:    " << heap.size() << endl;

		// Display the heap.
		heap.display();

		// Print majority of available functions.
		cout << "\n==============================" << endl;
		cout << " (1)  clear()" << endl;
		// cout << " (3)  clone()" << endl;
		// cout << " (4)  contains(element)" << endl;
		// cout << " (5)  insert(element)" << endl;
		// cout << " (6)  isEmpty() / isNotEmpty()" << endl;
		// cout << " (7)  remove(element)" << endl;
		// cout << " (8)  operator=" << endl;
		// cout << " (9)  operator+(element)" << endl;
		// cout << "(10)  operator+=(element)" << endl;
		// cout << "(11)  operator-(element)" << endl;
		// cout << "(12)  operator-=(element)" << endl;
		cout << " (2)  push(element)" << endl;
		cout << " (3)  pop()" << endl;
		cout << " (Q)  << QUIT PROGRAM >>" << endl;
		cout << "==============================" << endl;
		cout << "> ";
		cin.getline(answer, 3);
		answer[0] = toupper(answer[0]);


		// Any other character continues the loop.
		if (!isdigit(answer[0])) {
			continue;
		}


		// Switch statement for answer.
		number = atoi(answer);
		switch (number) {


		// Clear all elements in the heap.
		case 1:
			cout << "clear()" << endl;
			heap.clear();
			break;


		// // Clone the heap.
		// case 3:
		// 	cout << "clone()" << endl;
		// 	temp = heap.clone();
		// 	cout << "> cloned heap:" << endl;
		// 	heap.display();
		// 	sleep_for(seconds(5));
		// 	break;


		// // Test if element in the heap.
		// case 4:
		// 	cout << "contains(element)" << endl;
		// 	cout << "> element = ";
		// 	cin >> element;
		// 	cout << "> Tree contains " << element << ":  ";
		// 	if (heap.contains(element)) {
		// 		cout << "true" << endl;
		// 	} else {
		// 		cout << "false" << endl;
		// 	}
		// 	sleep_for(seconds(2));
		// 	break;


		// // Insert an element in the heap.
		// case 5:
		// 	cout << "insert(element)" << endl;
		// 	cout << "> element = ";
		// 	cin >> element;
		// 	heap.insert(element);
		// 	break;


		// // Check if empty / not empty.
		// case 6:
		// 	cout << "isEmpty() / isNotEmpty()" << endl;
		// 	cout << "> Tree IS empty:      ";
		// 	cout << (heap.isEmpty() ? "true\n" : "false\n");
		// 	cout << "> Tree is NOT empty:  ";
		// 	cout << (heap.isNotEmpty() ? "true\n" : "false\n");
		// 	sleep_for(seconds(3));
		// 	break;


		// // Remove an element from the heap.
		// case 7:
		// 	cout << "remove(element)" << endl;
		// 	cout << "> element = ";
		// 	cin >> element;
		// 	try {
		// 		heap.remove(element);
		// 	} catch (string e) {
		// 		cout << e << endl;
		// 		sleep_for(seconds(2));
		// 	}
		// 	break;


		// // Work with the assignment operator.
		// case 8:
		// 	cout << "operator=" << endl;
		// 	cout << "> number of elements = ";
		// 	cin >> number;
		// 	temp.clear();
		// 	for (unsigned i = 0; i < number; i++) {
		// 		temp.insert(randUint(0, 999));
		// 	}
		// 	heap = temp;
		// 	break;


		// // Work with heap + element.
		// case 9:
		// 	cout << "operator+(element)" << endl;
		// 	cout << "> element = ";
		// 	cin >> element;
		// 	temp = heap + element;
		// 	cout << "> returned heap:" << endl;
		// 	temp.display();
		// 	sleep_for(seconds(5));
		// 	break;


		// // Work with heap += element.
		// case 10:
		// 	cout << "operator+=(element)" << endl;
		// 	cout << "> element = ";
		// 	cin >> element;
		// 	heap += element;
		// 	break;


		// // Work with heap - element.
		// case 11:
		// 	cout << "operator-(element)" << endl;
		// 	cout << "> element = ";
		// 	cin >> element;
		// 	try {
		// 		temp = heap - element;
		// 		cout << "> returned heap:" << endl;
		// 		temp.display();
		// 		sleep_for(seconds(5));
		// 	} catch (string e) {
		// 		cout << e << endl;
		// 		sleep_for(seconds(2));
		// 	}
		// 	break;


		// // Work with heap -= element.
		// case 12:
		// 	cout << "operator-=(element)" << endl;
		// 	cout << "> element = ";
		// 	cin >> element;
		// 	try {
		// 		heap -= element;
		// 	} catch (string e) {
		// 		cout << e << endl;
		// 		sleep_for(seconds(2));
		// 	}
		// 	break;


		// Push element onto the heap.
		case 2:
			cout << "push(element)" << endl;
			cout << "> element = ";
			cin >> element;
			heap.push(element);
			break;

		// Pop from the heap.
		case 3:
			cout << "pop()" << endl;
			break;
		}
	}

	return 0;
}
