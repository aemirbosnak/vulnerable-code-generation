//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_table[] = {
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
    " ",     // Space
};

// Convert a character to Morse code
char *to_morse(char c) {
    int index = c - 'A';
    if (index < 0 || index >= sizeof(morse_table) / sizeof(char *)) {
        return NULL;
    }
    return strdup(morse_table[index]);
}

// Convert a string to Morse code
char *to_morse_string(char *str) {
    size_t len = strlen(str);
    char *result = malloc(len * 4 + 1);  // Each character can be up to 4 Morse code characters plus a space
    result[0] = '\0';
    for (size_t i = 0; i < len; i++) {
        char *morse = to_morse(str[i]);
        if (morse) {
            strcat(result, morse);
            strcat(result, " ");
        }
    }
    return result;
}

// Print usage information
void usage(char *program_name) {
    printf("Usage: %s <text>\n", program_name);
    printf("Converts the given text to Morse code.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *text = argv[1];
    char *morse_code = to_morse_string(text);

    printf("Morse code: %s\n", morse_code);

    free(morse_code);

    return EXIT_SUCCESS;
}