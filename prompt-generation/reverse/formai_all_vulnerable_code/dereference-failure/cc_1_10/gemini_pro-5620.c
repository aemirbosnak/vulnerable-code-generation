//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
static const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
    "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Convert a character to Morse code
static char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        c -= 'A';
    } else if (c >= 'a' && c <= 'z') {
        c -= 'a';
    } else if (c >= '0' && c <= '9') {
        c += 4;
    } else {
        return NULL;
    }

    return strdup(morse_table[c]);
}

// Convert a string to Morse code
static char *string_to_morse(const char *str) {
    char *morse_code = malloc(1);
    *morse_code = '\0';

    for (int i = 0; i < strlen(str); i++) {
        char *char_morse = char_to_morse(str[i]);
        if (char_morse) {
            morse_code = realloc(morse_code, strlen(morse_code) + strlen(char_morse) + 2);
            strcat(morse_code, char_morse);
            free(char_morse);
            strcat(morse_code, " ");
        }
    }

    return morse_code;
}

// Print Morse code
static void print_morse(const char *morse_code) {
    for (int i = 0; i < strlen(morse_code); i++) {
        if (morse_code[i] == ' ') {
            printf(" ");
        } else if (morse_code[i] == '.') {
            printf("·");
        } else if (morse_code[i] == '-') {
            printf("- ");
        }
    }

    printf("\n");
}

int main() {
    // Get the input string
    char *str = malloc(1024);
    printf("Enter a string to convert to Morse code: ");
    fgets(str, 1024, stdin);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code
    printf("Morse code: ");
    print_morse(morse_code);

    // Free the allocated memory
    free(str);
    free(morse_code);

    return 0;
}