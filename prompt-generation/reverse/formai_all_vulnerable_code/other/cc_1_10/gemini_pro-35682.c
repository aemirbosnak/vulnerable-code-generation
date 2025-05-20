//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#define MAX_CODE_LEN 1024

char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--..", "...", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...-",
    "-....", "--...", "---..", "----.", "-----", "|", "....-", "..--.-", "-.--", "-.--.", "-..-"
};

char *text_to_morse(char *text) {
    int i, j, k;
    char *morse = malloc(MAX_CODE_LEN);
    assert(morse != NULL);

    for (i = 0, k = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            for (j = 0; j < 26; j++) {
                if (tolower(text[i]) == 'a' + j) {
                    strcpy(morse + k, morse_code[j]);
                    k += strlen(morse_code[j]);
                    break;
                }
            }
        } else if (isdigit(text[i])) {
            for (j = 0; j < 10; j++) {
                if (text[i] == '0' + j) {
                    strcpy(morse + k, morse_code[26 + j]);
                    k += strlen(morse_code[26 + j]);
                    break;
                }
            }
        } else if (text[i] == ' ') {
            strcpy(morse + k, "|");
            k += strlen("|");
        }
    }

    morse[k] = '\0';
    return morse;
}

int main() {
    char text[] = "Hello World!";
    char *morse;

    morse = text_to_morse(text);
    printf("Text: %s\nMorse: %s\n", text, morse);

    free(morse);
    return 0;
}