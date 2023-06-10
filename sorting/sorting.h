#ifndef SORTING_H
#define SORTING_H

// All function prototypes.
uint randint(uint minvalue, uint maxValue);
void displayArray(
	uint array[], const uint SIZE,
	uint* highlight = nullptr, const uint COUNT = 0
);
void bubbleSort(uint array[], const uint SIZE);

#endif