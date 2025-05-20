//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: post-apocalyptic
// Post-apocalyptic Text to Morse Code Conversion program
// Developed by [your name here] in the year 2156

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse Code lookup table
const char* morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                           ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
                           ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// Function to convert a character to its Morse Code equivalent
char* charToMorse(char c) {
    // Check if character is alphabetic
    if (isalpha(c)) {
        // Convert to uppercase
        c = toupper(c);
        // Lookup corresponding Morse Code
        return morseCode[c - 'A'];
    }
    // Check if character is a digit
    else if (isdigit(c)) {
        // Lookup corresponding Morse Code
        return morseCode[c - '0' + 24];
    }
    // Check for other characters
    else {
        switch(c) {
            case ' ':
                return "/";
            case '.':
                return morseCode[36];
            case ',':
                return morseCode[37];
            case '?':
                return morseCode[38];
            case '\'':
                return morseCode[39];
            case '!':
                return morseCode[40];
            case '/':
                return morseCode[41];
            case '(':
                return morseCode[42];
            case ')':
                return morseCode[43];
            case '&':
                return morseCode[44];
            case ':':
                return morseCode[45];
            case ';':
                return morseCode[46];
            case '=':
                return morseCode[47];
            case '+':
                return morseCode[48];
            case '-':
                return morseCode[49];
            case '_':
                return morseCode[50];
            case '\"':
                return morseCode[51];
            case '$':
                return morseCode[52];
            case '@':
                return morseCode[53];
            default:
                return "";
        }
    }
}

// Function to convert a string to its Morse Code equivalent
char* stringToMorse(char* str) {
    // Allocate memory for output string
    char* output = (char*) malloc(strlen(str) * 5);
    output[0] = '\0';
    // Loop through each character in input string
    for (int i = 0; i < strlen(str); i++) {
        // Convert character to Morse Code and append to output string
        char* morse = charToMorse(str[i]);
        strcat(output, morse);
        // Add space between characters
        strcat(output, " ");
    }
    return output;
}

int main() {
    // Get input string from user
    char input[100];
    printf("Enter text to convert to Morse Code:");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove newline character
    // Convert input string to Morse Code
    char* output = stringToMorse(input);
    // Print Morse Code to console
    printf("Morse Code: %s\n", output);
    // Free memory
    free(output);
    return 0;
}