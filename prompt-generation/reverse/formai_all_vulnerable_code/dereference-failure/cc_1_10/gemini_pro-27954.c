//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code dictionary
const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-", "--..--", "-....-",
    "--...--", "...-..-", "....--", ".....", "-....", "..---", "-.-.--", ".-.-.",
    "-....-", "-.-.-.", ".-..-.", ".--.-.", "...--.-", ".-.--.-", "-.-.--.-",
    "--..--.-", ".-.--.--", "-..-.--", "-.-.--.-"
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32; // Convert to uppercase
    }
    int index = c - 'A';
    if (index >= 0 && index < 26) {
        return strdup(morse_code[index]);
    }
    return NULL;
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc((len * 5 + 1) * sizeof(char)); // Allocate enough space for the Morse code
    int index = 0;
    for (int i = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        if (morse != NULL) {
            strcpy(&morse_code[index], morse);
            index += strlen(morse);
            morse_code[index++] = ' '; // Add a space between characters
        }
    }
    morse_code[index] = '\0'; // Null-terminate the string
    return morse_code;
}

int main() {
    char str[] = "HELLO";
    char *morse_code = string_to_morse(str);
    printf("Morse code for \"%s\": %s\n", str, morse_code);
    free(morse_code);
    return 0;
}