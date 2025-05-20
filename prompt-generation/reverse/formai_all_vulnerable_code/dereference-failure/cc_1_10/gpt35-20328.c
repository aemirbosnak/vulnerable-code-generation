//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int morse_encode(char c, char* buffer);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [string to encode]\n", argv[0]);
        return 1;
    }
    char* input = argv[1];
    char* output = malloc(sizeof(char) * strlen(input) * 6); // Max 6 morse code characters per input character
    char morse_code[6]; // Max length of a morse code character is 5
    memset(output, 0, strlen(input) * 6);

    for (int i = 0; i < strlen(input); i++) {
        if (morse_encode(input[i], morse_code)) {
            strcat(output, morse_code);
            strcat(output, " "); // Add space between morse code characters
        } else {
            printf("Could not encode character %c\n", input[i]);
            return 1;
        }
    }

    printf("%s\n", output);
    free(output);
    return 0;
}

int morse_encode(char c, char* buffer) {
    const char* codes[] = {
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
        "--.."  // Z
    };
    int offset = 0;
    if (c >= 'a' && c <= 'z') {
        c -= 'a' - 'A'; // Convert lower case to upper case
    }
    if (c >= 'A' && c <= 'Z') {
        offset = c - 'A';
        strcpy(buffer, codes[offset]);
        return 1;
    }
    return 0;

}