#ifndef COLOUR_PRINT_H
#define COLOUR_PRINT_H

#include <string>
#include <iostream>

// Function prototypes.
std::string colourText(std::string text, char colour = '\0');
void startColour(char colour = '\0');
void endColour();

#endif
