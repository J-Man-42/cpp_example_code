#include <cctype>
#include "colour_text.h"
using namespace std;


// Returns the text provided in the given colour.
// If no colour is provided, return text as is.
string colourText(string text, char colour) {
	string gamma = islower(colour) ? "1" : "0";
	colour = toupper(colour);

	// Switch statement for each colour.
	switch (colour) {

	// Grey.
	case 'X':
		return "\033["+gamma+";30m"+text+"\033[0m";

	// Red.
	case 'R':
		return "\033["+gamma+";31m"+text+"\033[0m";

	// Green.
	case 'G':
		return "\033["+gamma+";32m"+text+"\033[0m";

	// Yellow.
	case 'Y':
		return "\033["+gamma+";33m"+text+"\033[0m";

	// Blue.
	case 'B':
		return "\033["+gamma+";34m"+text+"\033[0m";

	// Magenta.
	case 'M':
		return "\033["+gamma+";35m"+text+"\033[0m";

	// Cyan.
	case 'C':
		return "\033["+gamma+";36m"+text+"\033[0m";

	// White.
	case 'W':
		return "\033["+gamma+";37m"+text+"\033[0m";

	// No colour.
	default:
		return text;
	}
}


// Prints the specified colour going forward.
void startColour(char colour) {
	string gamma = islower(colour) ? "1" : "0";
	colour = toupper(colour);

	// Switch statement for each colour.
	switch (colour) {

	// Grey.
	case 'X':
		cout << "\033["<<gamma<<";30m";
		break;

	// Red.
	case 'R':
		cout << "\033["<<gamma<<";31m";
		break;

	// Green.
	case 'G':
		cout << "\033["<<gamma<<";32m";
		break;

	// Yellow.
	case 'Y':
		cout << "\033["<<gamma<<";33m";
		break;

	// Blue.
	case 'B':
		cout << "\033["<<gamma<<";34m";
		break;

	// Magenta.
	case 'M':
		cout << "\033["<<gamma<<";35m";
		break;

	// Cyan.
	case 'C':
		cout << "\033["<<gamma<<";36m";
		break;

	// White.
	case 'W':
		cout << "\033["<<gamma<<";37m";
		break;
	}
}


// Print normal text again.
void endColour() {
	cout << "\033[0m";
}
