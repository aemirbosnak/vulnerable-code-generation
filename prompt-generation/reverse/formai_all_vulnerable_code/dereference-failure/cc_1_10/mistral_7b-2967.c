//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define LENGTH_OF_MORSE_TABLE 63

char morse_table[LENGTH_OF_MORSE_TABLE][5] = {
    ".-", "--.", "-...", "-.-.", "-..", ".", "..-.", "--", "....", "..", ".---", "-.-", ".-..", "--.",
    "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

void print_morse_code(char morse[]) {
    int i;
    for (i = 0; morse[i] != '\0'; i++) {
        if (isalpha(morse[i])) {
            printf("%s ", morse_table[toupper(morse[i]) - 'A']);
        } else if (morse[i] == ' ') {
            printf("%s ", morse_table[62]);
        }
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    int text_len = strlen(argv[1]);
    char text[text_len + 1];
    strcpy(text, argv[1]);

    printf("Text: %s\n", text);

    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalnum(text[i])) {
            if (isalpha(text[i])) {
                char morse_code[LENGTH_OF_MORSE_TABLE];
                strcpy(morse_code, morse_table[toupper(text[i]) - 'A']);
                print_morse_code(morse_code);
            } else {
                print_morse_code(morse_table[text[i] == '.' ? 0 : 61]);
            }
        } else if (text[i] == ' ') {
            print_morse_code(morse_table[62]);
        }
    }

    return 0;
}