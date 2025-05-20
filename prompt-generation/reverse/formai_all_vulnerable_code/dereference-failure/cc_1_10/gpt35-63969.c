//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code mapping table as a structure
typedef struct MorseCodeMapping {
    char letter;
    char* morseCode;
} MorseCodeMapping;

// Define the Morse code mapping table as an array of structures
MorseCodeMapping morseCodeTable[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, 
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, 
    {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, 
    {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, 
    {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"}, 
    {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, 
    {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, 
    {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, 
    {'7', "--..."}, {'8', "---.."}, {'9', "----."}
};

// Function to get the Morse code for a given character
char* getMorseCode(char c) {
    // Loop through the Morse code mapping table to find the matching character
    for (int i = 0; i < 36; i++) {
        if (morseCodeTable[i].letter == c) {
            return morseCodeTable[i].morseCode; // Return the Morse code
        }
    }
    return ""; // If no matching character found, return an empty string
}

// Function to convert a given string to Morse code
char* convertToMorseCode(char* inputString) {
    char* outputString = (char*) malloc(strlen(inputString) * 5); // Allocate an array for the output string
    strcpy(outputString, ""); // Initialize the output string to an empty string
    
    // Loop through the characters in the input string
    for (int i = 0; i < strlen(inputString); i++) {
        char c = toupper(inputString[i]); // Convert the character to upper case
        if (c == ' ') {
            strcat(outputString, "/"); // Add a Morse code slash to represent spaces
        } else {
            char* morseCode = getMorseCode(c); // Get the Morse code for the character
            strcat(outputString, morseCode); // Add the Morse code to the output string
            strcat(outputString, " "); // Add a space between each Morse code character
        }
    }
    return outputString;
}

int main() {
    // Get the input string from the user
    char inputString[100];
    printf("Enter a string to convert to Morse code: ");
    gets(inputString);
    
    // Convert the input string to Morse code
    char* outputString = convertToMorseCode(inputString);
    
    // Print the output string
    printf("Morse code: %s\n", outputString);
    
    // Free the memory allocated for the output string
    free(outputString);
    
    return 0; // Exit the program
}