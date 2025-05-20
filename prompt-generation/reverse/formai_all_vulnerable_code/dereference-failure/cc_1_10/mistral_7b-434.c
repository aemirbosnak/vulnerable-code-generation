//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct MorseCode {
    char symbol;
    char* code;
} MorseCode;

MorseCode morse_codes[] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {'0', "-----"},
    {' ', "/"},
};

void print_morse_code(const MorseCode* morse_code, const char* input) {
    const char* ch = input;
    while (*ch) {
        if (isalpha(*ch) || isdigit(*ch)) {
            const MorseCode* morse = NULL;
            for (int i = 0; i < sizeof(morse_codes) / sizeof(MorseCode); ++i) {
                if (tolower(*ch) == morse_codes[i].symbol) {
                    morse = &morse_codes[i];
                    break;
                }
            }

            if (morse) {
                printf("%s", morse->code);
            }

            ch++;
        } else {
            putchar(*ch);
            ch++;
        }
    }

    putchar('\n');
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    print_morse_code(morse_codes, argv[1]);

    return 0;
}