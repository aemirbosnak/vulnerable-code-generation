//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHAR 256
#define MORSE_LENGTH 32

const char morse[][MORSE_LENGTH] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

void printMorse(const char* text) {
    bool dotPrinted = false;
    const char* p = text;
    while (*p) {
        if (isalpha(*p)) {
            char c = tolower(*p);
            int index = c - 'a';
            if (index < 0 || index >= 26) {
                printf("Invalid character %c\n", *p);
                return;
            }
            printf("%s ", morse[index]);
        } else if (*p == ' ') {
            printf("%s ", morse[26]);
            putchar(' ');
            putchar(' ');
            putchar('\n');
            putchar(' ');
            putchar('\n');
            putchar(' ');
            putchar('\n');
            p++;
            continue;
        }

        if (!dotPrinted) {
            putchar('.');
            dotPrinted = true;
        } else {
            putchar(' ');
            dotPrinted = false;
        }
        p++;
    }

    putchar('\n');
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    size_t len = strlen(argv[1]);
    char* text = malloc(len + 1);
    strcpy(text, argv[1]);

    printMorse(text);
    free(text);

    return 0;
}