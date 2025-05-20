//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MORSE_CODE_MAX_LEN 1024

typedef struct {
    char *text;
    char *morse_code;
} text_to_morse_code_entry;

text_to_morse_code_entry text_to_morse_code_table[] = {
    { "A", ".-" },
    { "B", "-..." },
    { "C", "-.-." },
    { "D", "-.." },
    { "E", "." },
    { "F", "..-." },
    { "G", "--." },
    { "H", "...." },
    { "I", ".." },
    { "J", ".---" },
    { "K", "-.-" },
    { "L", ".-.." },
    { "M", "--" },
    { "N", "-." },
    { "O", "---" },
    { "P", ".--." },
    { "Q", "--.-" },
    { "R", ".-." },
    { "S", "..." },
    { "T", "-" },
    { "U", "..-." },
    { "V", "...-" },
    { "W", ".--" },
    { "X", "-..-." },
    { "Y", "-.--" },
    { "Z", "--.." },
    { "0", "-----" },
    { "1", ".----" },
    { "2", "..---" },
    { "3", "...--" },
    { "4", "....-" },
    { "5", "....." },
    { "6", "-...." },
    { "7", "--..." },
    { "8", "---.." },
    { "9", "----." },
    { " ", " " },
    { NULL, NULL }
};

char *text_to_morse_code(char *text) {
    char *morse_code = malloc(MORSE_CODE_MAX_LEN);
    if (morse_code == NULL) {
        return NULL;
    }

    int i = 0;
    int j = 0;
    while (text[i] != '\0') {
        for (j = 0; text_to_morse_code_table[j].text != NULL; j++) {
            if (text[i] == text_to_morse_code_table[j].text[0]) {
                strcat(morse_code, text_to_morse_code_table[j].morse_code);
                break;
            }
        }
        i++;
    }

    return morse_code;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *text = argv[1];
    char *morse_code = text_to_morse_code(text);
    if (morse_code == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        return EXIT_FAILURE;
    }

    printf("%s\n", morse_code);

    free(morse_code);

    return EXIT_SUCCESS;
}