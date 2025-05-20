//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
static char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
    ".--", "-..-", "-.--", "--..", "..--", "-....", "--...", "---..", "----", ".-.-.-",
    "--..--", ".-.-.", "---...", ".-..-...", ".----.", "-....-", "..--..",
    "---...----", "--..--.--"
};

// Convert a character to Morse code
static char *to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 'a';
    } else if (c >= 'A' && c <= 'Z') {
        c -= 'A';
    } else {
        return NULL;  // Invalid character
    }

    return morse_table[c];
}

// Convert a string to Morse code
static char *to_morse_str(char *str) {
    char *result = malloc(strlen(str) * 5);  // Allocate enough space for the result
    char *ptr = result;

    for (int i = 0; str[i] != '\0'; i++) {
        char *morse = to_morse(str[i]);
        if (morse != NULL) {
            strcpy(ptr, morse);
            ptr += strlen(morse);
            *ptr++ = ' ';  // Add a space between characters
        }
    }

    *ptr = '\0';  // Null-terminate the result

    return result;
}

// Main function
int main(int argc, char **argv) {
    // Check if a string was specified
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert the string to Morse code
    char *morse = to_morse_str(argv[1]);

    // Print the result
    printf("%s\n", morse);

    // Free the allocated memory
    free(morse);

    return EXIT_SUCCESS;
}