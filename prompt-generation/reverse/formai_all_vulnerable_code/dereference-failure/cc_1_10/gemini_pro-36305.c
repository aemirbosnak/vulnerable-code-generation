//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_table[] = {
    ".-",    // A
    "-...",   // B
    "-.-.",   // C
    "-..",    // D
    ".",     // E
    "..-.",   // F
    "--.",    // G
    "....",   // H
    "..",    // I
    ".---",   // J
    "-.-",    // K
    ".-..",   // L
    "--",    // M
    "-.",    // N
    "---",    // O
    ".--.",   // P
    "--.-",   // Q
    ".-.",    // R
    "...",    // S
    "-",     // T
    "..-",    // U
    "...-",   // V
    ".--",    // W
    "-..-",   // X
    "-.--",   // Y
    "--..",   // Z
    "-----",  // 0
    ".----",  // 1
    "..---",  // 2
    "...--",  // 3
    "....-",  // 4
    ".....",  // 5
    "-....",  // 6
    "--...",  // 7
    "---..",  // 8
    "----.",  // 9
    ".-.-.-", // . (period)
    "--..--", // , (comma)
    "..--..", // ? (question mark)
    ".----.", // ' (apostrophe)
    "-....-", // - (hyphen)
    "-.--.-", // / (forward slash)
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    // Convert the character to uppercase
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }

    // Check if the character is a letter or a number
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else {
        // Return an empty string for invalid characters
        return "";
    }
}

// Convert a string to Morse code
char *string_to_morse(const char *str) {
    // Allocate a buffer for the Morse code string
    size_t buf_size = strlen(str) * 5 + 1;
    char *buf = malloc(buf_size);
    if (buf == NULL) {
        return NULL;
    }

    // Convert each character in the string to Morse code
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        const char *morse_code = char_to_morse(str[i]);
        for (j = 0; morse_code[j] != '\0'; j++) {
            buf[j + (i * 5)] = morse_code[j];
        }
        buf[j + (i * 5)] = ' ';
        i++;
    }

    // Add a newline character to the end of the string
    buf[j + (i * 5) - 1] = '\n';
    buf[j + (i * 5)] = '\0';

    // Return the Morse code string
    return buf;
}

// Display the Morse code for a string
void display_morse_code(const char *str) {
    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);
    if (morse_code == NULL) {
        printf("Error converting string to Morse code\n");
        return;
    }

    // Display the Morse code
    printf("Morse code: %s", morse_code);

    // Free the allocated memory
    free(morse_code);
}

int main() {
    // Get the input string from the user
    char str[256];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Display the Morse code for the string
    display_morse_code(str);

    return 0;
}