//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code character set
char *morse_chars[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----.", "-----"
};

// Morse code character values
char morse_values[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

// Convert a character to its Morse code representation
char *char_to_morse(char c) {
    for (int i = 0; i < 26; i++) {
        if (c == morse_values[i]) {
            return morse_chars[i];
        }
    }
    return NULL;
}

// Convert a string to its Morse code representation
char *string_to_morse(char *str) {
    char *morse_str = malloc(strlen(str) * 5);
    for (int i = 0; i < strlen(str); i++) {
        char *morse_char = char_to_morse(str[i]);
        if (morse_char != NULL) {
            strcat(morse_str, morse_char);
        }
    }
    return morse_str;
}

// Print the Morse code representation of a string
void print_morse(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            printf("· ");
        } else if (str[i] == '-') {
            printf("- ");
        }
    }
    printf("\n");
}

int main() {
    // Get the input string
    char *str = malloc(1024);
    printf("Enter a string to convert to Morse code: ");
    gets(str);

    // Convert the string to Morse code
    char *morse_str = string_to_morse(str);

    // Print the Morse code representation
    printf("Morse code representation: ");
    print_morse(morse_str);

    return 0;
}