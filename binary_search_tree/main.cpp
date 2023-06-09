#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cmath>
#include "binary_search_tree.h"
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

	// Create the binary search tree.
	BinarySearchTree<unsigned> tree;
	BinarySearchTree<unsigned> temp;

	// Loop until Q has been entered.
	while (answer[0] != 'Q') {

		// Clear the screen
		clearScreen();

		// Traverse the tree.
		cout << "DFT:";
		tree.dft();
		cout << "BFT:";
		tree.bft();

		// Print the tree height.
		cout << "Height:  " << tree.height() << endl;

		// Display the tree.
		tree.display();

		// Print majority of available functions.
		cout << "\n==============================" << endl;
		cout << " (1)  balanceTree()" << endl;
		cout << " (2)  clear()" << endl;
		cout << " (3)  clone()" << endl;
		cout << " (4)  contains(element)" << endl;
		cout << " (5)  insert(element)" << endl;
		cout << " (6)  isEmpty() / isNotEmpty()" << endl;
		cout << " (7)  remove(element)" << endl;
		cout << " (8)  operator=" << endl;
		cout << " (9)  operator+(element)" << endl;
		cout << "(10)  operator+=(element)" << endl;
		cout << "(11)  operator-(element)" << endl;
		cout << "(12)  operator-=(element)" << endl;
		cout << " (Q)  << QUIT PROGRAM >>" << endl;
		cout << "==============================" << endl;
		cout << "> ";
		cin.getline(answer, 3);
		answer[0] = toupper(answer[0]);


		// Any other character continues the loop.
		if (isalpha(answer[0])) {
			continue;
		}


		// Switch statement for answer.
		number = atoi(answer);
		switch (number) {


		// Balance the tree.
		case 1:
			cout << "balanceTree()" << endl;
			tree.balanceTree();
			break;


		// Clear all elements in the tree.
		case 2:
			cout << "clear()" << endl;
			tree.clear();
			break;


		// Clone the tree.
		case 3:
			cout << "clone()" << endl;
			temp = tree.clone();
			cout << "> cloned tree:" << endl;
			tree.display();
			sleep_for(seconds(5));
			break;


		// Test if element in the tree.
		case 4:
			cout << "contains(element)" << endl;
			cout << "> element = ";
			cin >> element;
			cout << "> Tree contains " << element << ":  ";
			if (tree.contains(element)) {
				cout << "true" << endl;
			} else {
				cout << "false" << endl;
			}
			sleep_for(seconds(2));
			break;


		// Insert an element in the tree.
		case 5:
			cout << "insert(element)" << endl;
			cout << "> element = ";
			cin >> element;
			tree.insert(element);
			break;


		// Check if empty / not empty.
		case 6:
			cout << "isEmpty() / isNotEmpty()" << endl;
			cout << "> Tree IS empty:      ";
			cout << (tree.isEmpty() ? "true\n" : "false\n");
			cout << "> Tree is NOT empty:  ";
			cout << (tree.isNotEmpty() ? "true\n" : "false\n");
			sleep_for(seconds(3));
			break;


		// Remove an element from the tree.
		case 7:
			cout << "remove(element)" << endl;
			cout << "> element = ";
			cin >> element;
			try {
				tree.remove(element);
			} catch (string e) {
				cout << e << endl;
				sleep_for(seconds(2));
			}
			break;


		// Work with the assignment operator.
		case 8:
			cout << "operator=" << endl;
			cout << "> number of elements = ";
			cin >> number;
			temp.clear();
			for (unsigned i = 0; i < number; i++) {
				temp.insert(randUint(1, 999));
			}
			tree = temp;
			break;


		// Work with tree + element.
		case 9:
			cout << "operator+(element)" << endl;
			cout << "> element = ";
			cin >> element;
			temp = tree + element;
			cout << "> returned tree:" << endl;
			temp.display();
			sleep_for(seconds(5));
			break;


		// Work with tree += element.
		case 10:
			cout << "operator+=(element)" << endl;
			cout << "> element = ";
			cin >> element;
			tree += element;
			break;


		// Work with tree - element.
		case 11:
			cout << "operator-(element)" << endl;
			cout << "> element = ";
			cin >> element;
			try {
				temp = tree - element;
				cout << "> returned tree:" << endl;
				temp.display();
				sleep_for(seconds(5));
			} catch (string e) {
				cout << e << endl;
				sleep_for(seconds(2));
			}
			break;


		// Work with tree -= element.
		case 12:
			cout << "operator-=(element)" << endl;
			cout << "> element = ";
			cin >> element;
			try {
				tree -= element;
			} catch (string e) {
				cout << e << endl;
				sleep_for(seconds(2));
			}
			break;
		}
	}

	return 0;
}
