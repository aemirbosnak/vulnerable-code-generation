//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void text_to_morse(char *text);
char *morse_lookup(char character);

char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    "/", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

int main(void) {
    char *str = malloc(256 * sizeof(char));
    printf("Enter text to convert to Morse code: ");
    fgets(str, 256, stdin);
    text_to_morse(str);
    free(str);
    return 0;
}

void text_to_morse(char *text) {
    char *morse = malloc(strlen(text) * 4 * sizeof(char));
    int i, j;
    for (i = 0, j = 0; i < strlen(text); i++) {
        if (text[i] == '\n') break;
        char *code = morse_lookup(text[i]);
        if (code != NULL) {
            while (*code) {
                morse[j++] = *code++;
            }
            morse[j++] = ' ';
        }
        else {
            printf("Invalid character %c\n", text[i]);
        }
    }
    printf("Morse code: %s\n", morse);
    free(morse);
}

char *morse_lookup(char character) {
    if (character >= 'a' && character <= 'z') {
        return morse_table[character - 'a'];
    }
    else if (character >= 'A' && character <= 'Z') {
        return morse_table[character - 'A'];
    }
    else if (character >= '0' && character <= '9') {
        return morse_table[26 + (character - '0')];
    }
    else if (character == ' ') {
        return morse_table[36];
    }
    else {
        return NULL;
    }
}