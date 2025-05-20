//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse Code table
char* morse_code_table[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                            "....", "..", ".---", "-.-", ".-..", "--", "-.",
                            "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                            "...-", ".--", "-..-", "-.--", "--.."};

// Convert a letter to Morse Code
char* letter_to_morse(char letter) {
    int ascii = (int)letter;
    // Check for space character
    if (ascii == 32) {
        return "/";  // Separate words with a slash
    } else if (ascii >= 65 && ascii <= 90) {
        return morse_code_table[ascii - 65];
    } else if (ascii >= 97 && ascii <= 122) {
        return morse_code_table[ascii - 97];
    } else {
        return "";  // Return empty string for non-alphabetic characters
    }
}

// Convert a string to Morse Code
char* string_to_morse(char* input_string) {
    int length = strlen(input_string);
    // Allocate enough memory to hold the converted Morse Code string
    char* output_string = (char*) malloc(length * 5 + 1);
    output_string[0] = '\0';  // Initialize the string to an empty string

    for (int i = 0; i < length; i++) {
        char* letter_morse = letter_to_morse(input_string[i]);
        strcat(output_string, letter_morse);
    }

    return output_string;
}

int main() {
    char input_string[100];
    printf("Enter a string: ");
    fgets(input_string, 100, stdin);
    // Remove the newline character at the end of the input
    input_string[strlen(input_string) - 1] = '\0';
    char* morse_string = string_to_morse(input_string);
    printf("Morse Code: %s\n", morse_string);
    free(morse_string);
    return 0;
}