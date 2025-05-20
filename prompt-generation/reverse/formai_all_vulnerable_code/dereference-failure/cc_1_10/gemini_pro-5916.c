//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: detailed
#include <stdio.h>
#include <string.h>

// Morse code character map
const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----",
    " ", "|", ".-"
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        c += 32;  // Convert to lowercase
    }

    int index = c - 'a';
    if (index >= 0 && index < 26) {
        return morse_code[index];
    } else if (c == ' ') {
        return morse_code[36];
    } else if (c == '|') {
        return morse_code[37];
    } else if (c == '.') {
        return morse_code[38];
    } else {
        return NULL;  // Invalid character
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code_str = malloc(len * 5 + 1);  // Allocate enough space for the Morse code string
    int index = 0;

    for (int i = 0; i < len; i++) {
        char *morse_code_char = char_to_morse(str[i]);
        if (morse_code_char != NULL) {
            strcat(morse_code_str, morse_code_char);
            index += strlen(morse_code_char);
            morse_code_str[index++] = ' ';  // Add a space between each character
        }
    }

    morse_code_str[index] = '\0';  // Null-terminate the string
    return morse_code_str;
}

int main() {
    char *str = "Hello World!";

    char *morse_code_str = string_to_morse(str);

    printf("Original string: %s\n", str);
    printf("Morse code: %s\n", morse_code_str);

    free(morse_code_str);  // Free the allocated memory

    return 0;
}