//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Morse code table */
char *morse_table[] = {
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
    ".-.."  // L
};

/* Convert a character to Morse code */
char *to_morse(char c) {
    int index = c - 'A';
    if (index < 0 || index > 11) {
        return NULL;
    }
    return morse_table[index];
}

/* Convert a string to Morse code */
char *to_morse_string(char *str) {
    char *morse_code = malloc(strlen(str) * 5);
    int i, j, k;
    for (i = 0, j = 0, k = 0; str[i] != '\0'; i++) {
        char *morse = to_morse(str[i]);
        if (morse == NULL) {
            morse = "";
        }
        strcpy(morse_code + j, morse);
        j += strlen(morse);
        if (str[i + 1] != '\0') {
            morse_code[j++] = ' ';
        }
        k++;
    }
    morse_code[j] = '\0';
    return morse_code;
}

/* Print a string in Morse code */
void print_morse(char *str) {
    char *morse_code = to_morse_string(str);
    printf("%s", morse_code);
    free(morse_code);
}

int main() {
    char str[] = "HELLO WORLD";
    printf("Original string: %s\n", str);
    printf("Morse code: ");
    print_morse(str);
    printf("\n");
    return 0;
}