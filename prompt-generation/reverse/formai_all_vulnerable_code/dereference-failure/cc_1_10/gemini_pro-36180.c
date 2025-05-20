//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

// Morse code table
char *morse_table[26] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-.."  // L
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5 + 1); // Allocate enough space for the Morse code
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        if (morse) {
            strcpy(&morse_code[j], morse);
            j += strlen(morse);
            morse_code[j++] = ' '; // Add a space between characters
        }
    }
    morse_code[j] = '\0'; // Add a null terminator

    return morse_code;
}

int main() {
    char line[MAX_LINE_LEN];

    while (1) {
        printf("Enter a string to convert to Morse code (or q to quit): ");
        if (fgets(line, MAX_LINE_LEN, stdin) == NULL) {
            break;
        }

        // Check if the user wants to quit
        if (strcmp(line, "q\n") == 0) {
            break;
        }

        // Convert the string to Morse code
        char *morse_code = string_to_morse(line);

        // Print the Morse code
        printf("Morse code: %s\n", morse_code);

        // Free the memory allocated for the Morse code
        free(morse_code);
    }

    return 0;
}