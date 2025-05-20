//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----",
    "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "|",
};

// Convert a character to its Morse code representation
char *char_to_morse(const char c) {
    // Check if the character is a letter
    if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    }
    // Check if the character is a number
    else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    }
    // Check if the character is a special character
    else if (c == ' ') {
        return "|";
    }
    // Otherwise, return an empty string
    else {
        return "";
    }
}

// Convert a string to its Morse code representation
char *string_to_morse(const char *str) {
    // Allocate memory for the Morse code representation
    char *morse = malloc((strlen(str) + 1) * 5);
    if (!morse) {
        return NULL;
    }

    // Convert each character in the string to its Morse code representation
    int i;
    for (i = 0; i < strlen(str); i++) {
        strcat(morse, char_to_morse(str[i]));
        strcat(morse, " ");
    }

    // Return the Morse code representation
    return morse;
}

// Print the Morse code representation of a string
void print_morse(const char *morse) {
    int i;

    for (i = 0; i < strlen(morse); i++) {
        printf("%c", morse[i]);
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert the string to Morse code
    char *morse = string_to_morse(argv[1]);
    if (!morse) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Print the Morse code representation
    print_morse(morse);

    // Free the memory allocated for the Morse code representation
    free(morse);

    return EXIT_SUCCESS;
}