//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code representation
const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", " "};

// Function to convert a given character to Morse code
const char* char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_code[c - 'a'];
    } else if (c == ' ') {
        return morse_code[26]; // 26th index is space
    }
    return ""; // Return empty string for unrecognized characters
}

// Function to convert the entire input string to Morse code
char* text_to_morse(const char *text) {
    int length = strlen(text);
    char *morse_output = malloc(length * 5 * sizeof(char)); // Maximum 5 symbols for each character
    if (morse_output == NULL) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    morse_output[0] = '\0'; // Initialize the output string
    for (int i = 0; i < length; i++) {
        const char* morse_char = char_to_morse(text[i]);
        strcat(morse_output, morse_char);
        strcat(morse_output, " "); // Adding space after each letter
    }

    return morse_output;
}

// Example of use
int main() {
    char input[256];
    printf("Enter text to convert to Morse code: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character if present at the end of input
    input[strcspn(input, "\n")] = 0;

    char *morse_result = text_to_morse(input);
    printf("Morse Code: %s\n", morse_result);

    // Clean up
    free(morse_result);
    return 0;
}