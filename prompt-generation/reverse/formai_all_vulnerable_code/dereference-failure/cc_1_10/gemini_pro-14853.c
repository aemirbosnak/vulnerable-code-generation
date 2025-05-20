//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Romeo and Juliet style Text to Morse code conversion

// Declare the Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----.", "-----", "|"
};

// Declare the alphabet table
char alphabet[] = "abcdefghijklmnopqrstuvwxyz1234567890";

// Function to convert a character to Morse code
char *to_morse(char c) {
    int i;

    // Find the character in the alphabet table
    for (i = 0; i < strlen(alphabet); i++) {
        if (c == alphabet[i]) {
            return morse_table[i];
        }
    }

    // If the character is not found, return an empty string
    return "";
}

// Function to convert a string to Morse code
char *to_morse_string(char *str) {
    char *morse_code;
    int i, len;

    // Allocate memory for the Morse code string
    len = strlen(str);
    morse_code = malloc(len * 5 + 1);

    // Convert each character in the string to Morse code
    for (i = 0; i < len; i++) {
        strcat(morse_code, to_morse(str[i]));
    }

    // Add a null terminator to the Morse code string
    morse_code[len * 5] = '\0';

    // Return the Morse code string
    return morse_code;
}

// Main function
int main() {
    char *text, *morse_code;

    // Get the text from the user
    printf("Enter the text to convert to Morse code: ");
    text = malloc(100);
    fgets(text, 100, stdin);

    // Convert the text to Morse code
    morse_code = to_morse_string(text);

    // Print the Morse code
    printf("The Morse code is: %s\n", morse_code);

    // Free the memory allocated for the text and Morse code strings
    free(text);
    free(morse_code);

    return 0;
}