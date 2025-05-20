//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a single English letter to Morse code
const char* letter_to_morse(char letter) {
    static const char* morse[] = {
        ".-",   "..",   ".--.",  "--.",
        "---.", "--",  ".--",   "--.-.",
        ".---", ".--.", "--.",   "---",
        "...",  "..--", "...-",  "....",
        "..---", "...--", ".---.", "--...",
        "---..", "----.", "--..",  "-----"
    };

    int index = isalpha(letter) ? letter - 'A' : (isdigit(letter) ? letter - '0' : -1);
    return index >= 0 ? morse[index] : "";
}

// Function to print Morse code for a single letter or number
void print_morse(const char* morse_code) {
    int length = strlen(morse_code);
    for (int i = 0; i < length; ++i) {
        switch (morse_code[i]) {
            case '.': printf("._"); break;
            case '-': printf("|_"); break;
            case ' ': printf("   "); break;
        }
        if (i != length - 1) printf(" ");
    }
    printf("\n");
}

// Main function to convert text to Morse code
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s text\n", argv[0]);
        return 1;
    }

    const char* text = argv[1];
    for (const char* p = text; *p != '\0'; ++p) {
        if (isalnum(*p)) {
            const char* morse_code = letter_to_morse(*p);
            print_morse(morse_code);
        } else {
            putchar(*p);
            putchar(' ');
        }
    }

    return 0;
}