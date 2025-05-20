//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
    "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Function to convert a character to Morse code
char *to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse_code[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    } else {
        return NULL;
    }
}

// Function to convert a string to Morse code
char *to_morse_string(char *str) {
    char *morse_code;
    int len = strlen(str);

    // Allocate memory for the Morse code string
    morse_code = malloc(len * 5);
    if (morse_code == NULL) {
        return NULL;
    }

    // Convert each character to Morse code and concatenate them
    for (int i = 0; i < len; i++) {
        char *code = to_morse(str[i]);
        if (code == NULL) {
            free(morse_code);
            return NULL;
        }
        strcat(morse_code, code);
    }

    // Return the Morse code string
    return morse_code;
}

// Function to print the Morse code
void print_morse(char *morse_code) {
    int len = strlen(morse_code);

    // Print each character in the Morse code string
    for (int i = 0; i < len; i++) {
        printf("%c", morse_code[i]);
    }

    // Print a newline character
    printf("\n");
}

// Main function
int main() {
    // Get the input string
    char *str;
    printf("Enter a string: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code = to_morse_string(str);
    if (morse_code == NULL) {
        printf("Error converting string to Morse code\n");
        return 1;
    }

    // Print the Morse code
    printf("Morse code: ");
    print_morse(morse_code);

    // Free the memory allocated for the Morse code string
    free(morse_code);

    return 0;
}