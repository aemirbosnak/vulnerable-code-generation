//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
    "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else {
        return "";
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5);
    for (int i = 0; i < len; i++) {
        strcat(morse_code, char_to_morse(str[i]));
        strcat(morse_code, " ");
    }
    return morse_code;
}

// Main function
int main() {
    // Get the input string
    char *str = malloc(100);
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    // Free the allocated memory
    free(str);
    free(morse_code);

    return 0;
}