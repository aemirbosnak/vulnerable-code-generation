//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char morse_code[26][5] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Function to convert a character to Morse code
char *to_morse_code(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_code[c - 'a'];
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char *to_morse_code_str(char *str) {
    int len = strlen(str);
    char *morse_code_str = malloc(len * 5 + 1); // 5 characters per character, plus 1 for the null terminator
    int index = 0;
    for (int i = 0; i < len; i++) {
        char *morse_code_char = to_morse_code(str[i]);
        if (morse_code_char != NULL) {
            strcpy(morse_code_str + index, morse_code_char);
            index += strlen(morse_code_char);
            morse_code_str[index++] = ' '; // Add a space between characters
        }
    }
    morse_code_str[index] = '\0'; // Add the null terminator
    return morse_code_str;
}

// Main function
int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code_str = to_morse_code_str(str);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code_str);

    // Free the allocated memory
    free(morse_code_str);

    return 0;
}