//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
static const char *morse_table[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--..", // Z
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
};

// Convert a character to Morse code
static char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }

    int index = c - 'A';
    if (index < 0 || index >= sizeof(morse_table) / sizeof(char *)) {
        return NULL;
    }

    return strdup(morse_table[index]);
}

// Convert a string to Morse code
static char *string_to_morse(const char *str) {
    size_t len = strlen(str);
    char *morse_code = malloc(len * 5 + 1);
    if (!morse_code) {
        return NULL;
    }

    char *ptr = morse_code;
    for (size_t i = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        if (!morse) {
            free(morse_code);
            return NULL;
        }

        strcpy(ptr, morse);
        ptr += strlen(morse);
        *ptr++ = ' ';
    }

    *ptr = '\0';
    return morse_code;
}

// Print Morse code
static void print_morse_code(const char *morse_code) {
    printf("%s\n", morse_code);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *string = argv[1];
    char *morse_code = string_to_morse(string);
    if (!morse_code) {
        perror("string_to_morse");
        return EXIT_FAILURE;
    }

    print_morse_code(morse_code);
    free(morse_code);

    return EXIT_SUCCESS;
}