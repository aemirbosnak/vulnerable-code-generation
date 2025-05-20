//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Morse code table
char *morse_code_table[] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--..",  // Z
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
    " "      // Space
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_code_table[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morse_code_table[c - 'a' + 26];
    } else if (c >= '0' && c <= '9') {
        return morse_code_table[c - '0' + 52];
    } else if (c == ' ') {
        return morse_code_table[62];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse(char *s) {
    char *morse_code = malloc(strlen(s) * 5);
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        char *morse_char = char_to_morse(s[i]);
        if (morse_char == NULL) {
            free(morse_code);
            return NULL;
        }
        strcat(morse_code, morse_char);
        strcat(morse_code, " ");
    }
    return morse_code;
}

// Print a string in Morse code
void print_morse_code(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '.') {
            printf("·");
        } else if (s[i] == '-') {
            printf("- ");
        } else if (s[i] == ' ') {
            printf("   ");
        }
    }
    printf("\n");
}

int main(void) {
    char line[MAX_LINE_LENGTH];
    char *morse_code;

    printf("Enter a string to convert to Morse code: ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    morse_code = string_to_morse(line);
    if (morse_code == NULL) {
        printf("Error: Invalid character in string.\n");
        return 1;
    }

    printf("Morse code: ");
    print_morse_code(morse_code);

    free(morse_code);

    return 0;
}