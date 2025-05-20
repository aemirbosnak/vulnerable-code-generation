//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code dictionary
char* morse_codes[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----",
    "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-", "--..--",
    "...---...", ".-.-.-.", "-....-", "-.-.--", "-..-.", "-.--.-", ".-...", "---...", "-.-.-.-", "-....-",
    "..--..", "-.--.--", "-.-.--.-", "-....--", "-...-", "-.--."
};

// Function to convert a character to Morse code
char* char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }

    int index = c - 'A';
    if (index >= 0 && index < 26) {
        return morse_codes[index];
    } else if (c == ' ') {
        return " ";
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char* string_to_morse(char* str) {
    int len = strlen(str);
    char* morse_code = malloc(len * 5 + 1);  // Allocate enough space for the Morse code

    int index = 0;
    for (int i = 0; i < len; i++) {
        char* code = char_to_morse(str[i]);
        if (code != NULL) {
            strcat(morse_code, code);
            strcat(morse_code, " ");  // Add a space between each character
            index += strlen(code) + 1;
        }
    }

    morse_code[index] = '\0';  // Null-terminate the string

    return morse_code;
}

// Function to print Morse code
void print_morse_code(char* morse_code) {
    int len = strlen(morse_code);
    for (int i = 0; i < len; i++) {
        if (morse_code[i] == '.') {
            printf(".-");
        } else if (morse_code[i] == '-') {
            printf("-...");
        } else if (morse_code[i] == ' ') {
            printf(" ");
        }
    }

    printf("\n");
}

int main() {
    // Get the input string
    char* str = malloc(100);
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char* morse_code = string_to_morse(str);

    // Print the Morse code
    printf("Morse code: ");
    print_morse_code(morse_code);

    free(morse_code);
    free(str);

    return 0;
}