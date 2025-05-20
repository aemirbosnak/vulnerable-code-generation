//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char* morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "---.", "----", ".-.-.-",
    "--..--", "..--.."
};

// Convert a character to Morse code
char* char_to_morse(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        ch -= 'A';
    } else if (ch >= 'a' && ch <= 'z') {
        ch -= 'a';
    } else if (ch >= '0' && ch <= '9') {
        ch += 4;
    } else if (ch == ' ') {
        return " ";
    } else {
        return "";
    }

    return strdup(morse_table[ch]);
}

// Convert a string to Morse code
char* string_to_morse(const char* str) {
    int len = strlen(str);
    char* morse_code = malloc(len * 5 + 1);
    int index = 0;

    for (int i = 0; i < len; i++) {
        char* char_morse = char_to_morse(str[i]);
        strcat(morse_code, char_morse);
        index += strlen(char_morse);
        free(char_morse);

        if (i < len - 1) {
            morse_code[index++] = ' ';
        }
    }

    morse_code[index] = '\0';
    return morse_code;
}

int main() {
    // Your text, ready to be transformed!
    char* text = "Hello World!";

    // Summon the power of Morse!
    char* morse_code = string_to_morse(text);

    // Dance, Morse code, dance!
    printf("Text: %s\n", text);
    printf("Morse Code: %s\n", morse_code);

    // Free the memory, like a Morse code magician
    free(morse_code);

    return 0;
}