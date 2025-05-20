//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char* morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----",
    "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "|"
};

// Function to convert a character to Morse code
char* char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_code[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char* string_to_morse(char* str) {
    int len = strlen(str);
    char* morse_code = malloc(len * 5);
    int index = 0;

    for (int i = 0; i < len; i++) {
        char* morse = char_to_morse(str[i]);
        if (morse) {
            strcpy(&morse_code[index], morse);
            index += strlen(morse);
            morse_code[index++] = ' ';
        }
    }

    return morse_code;
}

// Main function
int main() {
    char* str = "Hello World!";
    char* morse_code = string_to_morse(str);

    printf("%s = %s\n", str, morse_code);

    free(morse_code);

    return 0;
}