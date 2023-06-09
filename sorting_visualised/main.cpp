#include <iostream>
#include "sorting.h"
#include "../move_cursor/move_cursor.h"
#include "../random/random.h"
using namespace std;


// Main loop function.
int main() {
	unsigned number;
	char answer[21];
	unsigned size = 20;
	unsigned minValue = 1;
	unsigned maxValue = 40;
	bool mustRefresh = true;

	// Initialise array.
	unsigned* array = randUintArray(size, minValue, maxValue);

	// Main loop.
	while (answer[0] != 'Q') {

		// Selectively clear the screen.
		if (mustRefresh) {
			clearScreen();
		}

		// Display the array.
		Sorting::displayArray(array, size);

		// Show the options.
		cout << "========================================" << endl;
		cout << "Array contents ~ Z["<<minValue<<", "<<maxValue<<"]" << endl;
		cout << "Array size = " << size << endl;
		cout << "Vertical scale = " << Sorting::getVerticalScale() << endl;
		cout << "Bar width = " << Sorting::getBarWidth() << endl;
		cout << "Time delay = " << Sorting::getDelay() << "ms\n";
		cout << "Sort ";
		cout << (Sorting::sortAscending ? "Ascending" : "Descending");
		cout << " Order" << endl;
		cout << "========================================" << endl;
		cout << "(0)  Restore Default Settings" << endl;
		cout << "(1)  Alter Array" << endl;
		cout << "(2)  Update Array Range" << endl;
		cout << "(3)  Toggle Bar Width" << endl;
		cout << "(4)  Change Step Delay" << endl;
		cout << "(5)  Toggle Ascending/Descending" << endl;
		cout << "(6)  Change Vertical Scale" << endl;
		cout << "(7)  Sort Array" << endl;
		cout << "(Q)  << QUIT PROGRAM >>" << endl;
		cout << "========================================" << endl;
		cout << "> ";
		cin.getline(answer, 20);

		// Format the answer.
		answer[0] = toupper(answer[0]);
		mustRefresh = (answer[0] != '7');

		// Safety for number higher than 7.
		if (isdigit(answer[0]) && atoi(answer) > 7) {
			continue;
		}


		// Perform the user specified action.
		switch (answer[0]) {


		// Restore sorting settings back to default.
		case '0':
			Sorting::restoreDefault();
			maxValue = 40;
			minValue = 1;
			size = 20;
			delete [] array;
			array  = randUintArray(size, minValue, maxValue);
			break;


		// Alter the array.
		case '1':
			cout << "========================================" << endl;
			cout << "(1)  Change Array Size" << endl;
			cout << "(2)  Reverse Array Order" << endl;
			cout << "(3)  Create Sorted Ascending Array" << endl;
			cout << "(4)  Create Sorted Descending Array" << endl;
			cout << "(5)  Shuffle Current Array" << endl;
			cout << "(6)  Randomise Array" << endl;
			cout << "========================================" << endl;
			cout << "> ";
			cin.getline(answer, 20);

			// Perform the requested array alteration.
			switch (answer[0]) {

			// Change array size.
			case '1':
				cout << "new size = ";
				unsigned newSize;
				cin >> newSize;

				// Shrink array.
				if (newSize < size) {
					unsigned* newArray = new unsigned[newSize];
					for (unsigned i = 0; i < newSize; i++) {
						newArray[i] = array[i];
					}
					delete [] array;
					array = newArray;
					size = newSize;
				}

				// Grow array.
				else if (newSize > size) {
					unsigned* newArray = new unsigned[newSize];
					for (unsigned i = 0; i < size; i++) {
						newArray[i] = array[i];
					}
					for (unsigned i = size; i < newSize; i++) {
						newArray[i] = randUint(minValue, maxValue);
					}
					delete [] array;
					array = newArray;
					size = newSize;
				}
				break;

			// Reverse the array order.
			case '2':
				for (unsigned i = 0, j = size-1; i < j; i++, j--) {
					swap(array[i], array[j]);
				}
				break;

			// Array with ascending elements.
			case '3':
				size = maxValue - minValue + 1;
				delete [] array;
				array = new unsigned[size];
				for (unsigned i = 0, n = minValue; i < size; i++, n++) {
					array[i] = n;
				}
				break;

			// Array with descending elements.
			case '4':
				size = maxValue - minValue + 1;
				delete [] array;
				array = new unsigned[size];
				for (unsigned i = 0, n = maxValue; i < size; i++, n--) {
					array[i] = n;
				}
				break;

			// Shuffle the current array.
			case '5':
				shuffle(array, size);
				break;

			// Randomise the array.
			case '6':
				delete [] array;
				array = randUintArray(size, minValue, maxValue);
				break;

			}
			break;


		// Update the minimum and maximum values.
		case '2':
			cout << "minimum value = ";
			cin >> minValue;
			cout << "maximum value = ";
			cin >> maxValue;

			// Ensure maxValue >= minValue.
			if (minValue > maxValue) {
				swap(minValue, maxValue);
			}

			// Modify the array to meet this criteria.
			for (unsigned i = 0; i < size; i++) {
				array[i] = max(minValue, array[i]);
				array[i] = min(maxValue, array[i]);
			}

			// Update bar height and width.
			Sorting::setBarHeight(maxValue);
			Sorting::setBarWidth(maxValue);

			break;


		// Toggle the width of the vertical bars.
		case '3':
			Sorting::toggleWideBar();
			break;


		// Change the milliseconds delay when sorting.
		case '4':
			cout << "new delay = ";
			unsigned ms;
			cin >> ms;
			Sorting::setDelay(ms);
			break;


		// Toggle sorting in ascending/descending order.
		case '5':
			Sorting::sortAscending = !Sorting::sortAscending;
			break;


		// Change the value to vertical bar scale.
		case '6':
			cout << "new vertical scale = ";
			unsigned scale;
			cin >> scale;
			Sorting::setVerticalScale(scale);
			break;


		// Run one of the sorting algorithms..
		case '7':
			cout << "==============================" << endl;
			cout << " (1)  Bubble Sort" << endl;
			cout << " (2)  Selection Sort" << endl;
			cout << " (3)  Insertion Sort" << endl;
			cout << " (4)  Cocktail Shaker Sort" << endl;
			cout << " (5)  Gnome Sort" << endl;
			cout << " (6)  QuickSort" << endl;
			cout << " (7)  QuickSort V2" << endl;
			cout << " (8)  Shell Sort" << endl;
			cout << " (9)  Merge Sort" << endl;
			cout << "(10)  Comb Sort" << endl;
			cout << "(11)  Radix Sort (base 10)" << endl;
			cout << "(12)  Radix Sort (custom base)" << endl;
			cout << "(13)  Heap Sort" << endl;
			cout << "(14)  Bucket Sort" << endl;
			cout << "(15)  Bitonic Sort" << endl;
			cout << "==============================" << endl;
			cout << "> ";
			cin.getline(answer, 20);

			// Continue if not a number.
			if (!isdigit(answer[0])) {
				clearScreen();
				continue;
			}

			// Run the requested sorting algorithm.
			number = atoi(answer);
			switch (number) {
			case 1:
				Sorting::bubbleSort(array, size);
				break;
			case 2:
				Sorting::selectionSort(array, size);
				break;
			case 3:
				Sorting::insertionSort(array, size);
				break;
			case 4:
				Sorting::cocktailShakerSort(array, size);
				break;
			case 5:
				Sorting::gnomeSort(array, size);
				break;
			case 6:
				Sorting::quickSort(array, size);
				break;
			case 7:
				Sorting::quickSortV2(array, size);
				break;
			case 8:
				Sorting::shellSort(array, size);
				break;
			case 9:
				Sorting::mergeSort(array, size);
				break;
			case 10:
				Sorting::combSort(array, size);
				break;
			case 11:
				Sorting::radixSort(array, size);
				break;
			case 12:
				cout << "base = ";
				unsigned base;
				cin >> base;
				Sorting::radixSort(array, size, base);
				break;
			case 13:
				Sorting::heapSort(array, size);
				break;
			case 14:
				Sorting::bucketSort(array, size);
				break;
			case 15:
				Sorting::bitonicSort(array, size);
				break;
			default:
				clearScreen();
			}
		}
	}

	return 0;
}
