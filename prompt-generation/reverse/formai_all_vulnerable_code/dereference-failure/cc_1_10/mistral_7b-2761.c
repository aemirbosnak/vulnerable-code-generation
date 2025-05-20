//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LETTERS 26

static const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

bool is_alphanumeric(char c) {
    return (isalpha(c) || isdigit(c) || c == ' ');
}

void print_morse_code(const char *morse) {
    int i;
    for (i = 0; i < strlen(morse); i++) {
        putchar(morse[i]);
        if (morse[i] == ' ') {
            putchar(' ');
        }
        putchar('.');
        putchar(' ');
    }
}

int main(int argc, char *argv[]) {
    int i, len;
    char text[1024];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s text\n", argv[0]);
        return 1;
    }

    strcpy(text, argv[1]);

    for (i = 0; text[i]; i++) {
        if (is_alphanumeric(text[i])) {
            int index = tolower(text[i]) - 'a';
            if (isdigit(text[i])) {
                index += 26;
                len = 1;
            } else {
                len = strlen(morse_code[index]);
            }
            print_morse_code(morse_code[index]);
            putchar(' ');
            for (int j = 1; j < len; j++) {
                putchar('.');
                putchar(' ');
            }
        }
    }

    putchar('\n');

    return 0;
}