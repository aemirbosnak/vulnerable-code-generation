//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code character map
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-.", ".-.-.-", "--..--",
    "---...", "...--...","....--..", ".....--...", "-....--...", "--...--...",
    "---..--...", "----....--...", "-----....---...", "------....----...",
    ".......--.....", "-....--...", "..--..", ".-..-.", ".-.-.-.", ".-...-.", ".-.--.", "-....-",
    "..-...", "-.-.-.", "---...", "-.--.-", "-.-.--", "-.--.-", ".-....", ".-.-.-", "-.--..",
    "-.--.-", "-.--.-", "-..-.", "-..-.", "-.--.-", "-..--.", "-.-.-.", "-.-.-.",
    "----.", "---.", "----.", "----.", "----.", "----.", "----.", "----.",
    "----.", "----.", "----.", "----.", "----.", "----.", "----.", "----.",
    "----.", "----.", "----.", "----.", "----.", "----.", "----.", "----.",
    "----.", "----.", "----.", "----."
};

// Function to convert character to Morse code
char *char_to_morse(char character) {
    int index = character - 'A';
    if (index >= 0 && index < 26) {
        return morse_code[index];
    } else {
        return NULL;
    }
}

// Function to convert string to Morse code
char *string_to_morse(char *string) {
    // Calculate the length of the Morse code representation
    int morse_length = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        char *morse = char_to_morse(string[i]);
        morse_length += strlen(morse) + 1;
    }

    // Allocate memory for the Morse code representation
    char *morse_code = malloc(morse_length + 1);

    // Convert each character to Morse code and concatenate them
    int index = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        char *morse = char_to_morse(string[i]);
        strcpy(morse_code + index, morse);
        index += strlen(morse);
        morse_code[index++] = ' ';
    }

    // Null-terminate the string
    morse_code[morse_length] = '\0';

    // Return the Morse code representation
    return morse_code;
}

// Main function
int main() {
    // Prompt the user to enter a string
    printf("Enter a string to convert to Morse code: ");
    char string[100];
    scanf("%s", string);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(string);

    // Display the Morse code representation
    printf("Morse code representation: %s\n", morse_code);

    // Free the allocated memory
    free(morse_code);

    return 0;
}