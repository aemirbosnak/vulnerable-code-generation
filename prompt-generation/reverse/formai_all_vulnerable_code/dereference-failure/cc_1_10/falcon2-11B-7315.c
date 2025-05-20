//Falcon2-11B DATASET v1.0 Category: Text to Morse code conversion ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define a function to convert a string to Morse code
void stringToMorse(char *str, char *morse) {
    // Initialize the morse code string
    memset(morse, 0, sizeof(morse));

    // Define a character to Morse code mapping
    char morses[][3] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", 
        ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", ".." };

    // Convert each character in the input string to Morse code
    for (int i = 0; i < strlen(str); i++) {
        // Convert the character to uppercase
        char c = toupper(str[i]);

        // Add the corresponding Morse code to the morse code string
        strcat(morse, morses[c - 'A']);
    }
}

// Define a function to convert a Morse code string to text
void morseToText(char *morse, char *text) {
    // Initialize the text string
    memset(text, 0, sizeof(text));

    // Define a Morse code to character mapping
    char texts[][3] = {
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", 
        "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", ", ", "-", " " };

    // Convert each character in the Morse code string to text
    for (int i = 0; i < strlen(morse); i += 2) {
        // Add the corresponding text to the text string
        strcat(text, texts[morse[i] - '.']);
    }
}

int main() {
    // Get user input
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Convert the string to Morse code
    char morse[100];
    stringToMorse(input, morse);

    // Convert the Morse code to text
    char text[100];
    morseToText(morse, text);

    // Print the result
    printf("Morse code: %s\n", morse);
    printf("Text: %s\n", text);

    return 0;
}