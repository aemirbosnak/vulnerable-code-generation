//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code table
const char* morse_code_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----.", "-----", ".----.", "..---.", "...--.", "....-.", ".....-", "-....-", "--...--", "---..--",
    "----..--", "-----.--", ".--.-.", "-....-", "..--..", "...--..", "....--..", ".....--..", "-....---", "--...---", "---..---",
    "----..---", "-----...-"
};

// Convert a character to Morse code
char* char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_code_table[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_code_table[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_code_table[c - '0' + 26];
    } else {
        return ".";
    }
}

// Convert a string to Morse code
char* string_to_morse(char* str) {
    char* morse_code = malloc(strlen(str) * 5 + 1);
    int i;
    int j = 0;
    for (i = 0; i < strlen(str); i++) {
        char* morse_char = char_to_morse(str[i]);
        for (j = 0; j < strlen(morse_char); j++) {
            morse_code[j + i * 5] = morse_char[j];
        }
        morse_code[j + i * 5] = ' ';
    }
    morse_code[strlen(str) * 5] = '\0';
    return morse_code;
}

// Print the Morse code for a string
void print_morse_code(char* morse_code) {
    printf("%s\n", morse_code);
}

// Main function
int main() {
    char* str = "Hello World!";
    char* morse_code = string_to_morse(str);
    print_morse_code(morse_code);
    return 0;
}