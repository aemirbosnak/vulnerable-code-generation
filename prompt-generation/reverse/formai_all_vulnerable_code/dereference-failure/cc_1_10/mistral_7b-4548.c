//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 26
#define DASH_LENGTH 3
#define DOT_LENGTH 1
#define GAP_LENGTH 1

char morse[][LENGTH] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

void printMorseCode(char morseCode[]) {
    int i = 0;

    printf("%s", morseCode);
    printf(": ");

    for (i = 0; morseCode[i] != '\0'; i++) {
        if (morseCode[i] == '.') {
            printf("Happy ");
            if (i != strlen(morseCode) - 1 && morseCode[i + 1] != ' ') {
                printf("-");
                i++;
            }
        } else if (morseCode[i] == '-') {
            printf("Sad ");
        }

        if (morseCode[i] == ' ') {
            printf("Space");
        }

        if (i != strlen(morseCode) - 1 && morseCode[i + 1] != ' ') {
            printf(".");
        }
    }

    printf("\n");
}

int main() {
    char text[100];
    char *token;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    token = strtok(text, " ");

    while (token != NULL) {
        char morseCode[strlen(token) + 1];
        int i = 0;

        strcpy(morseCode, morse[token[0] - 'A']);

        for (i = 1; token[i] != '\0'; i++) {
            if (token[i] != morse[token[0] - 'A'][i]) {
                strcat(morseCode, morse[token[i] - 'A']);
                token[i - 1] = '\0';
                break;
            }
        }

        if (strlen(morseCode) > 0) {
            printMorseCode(morseCode);
        }

        token = strtok(NULL, " ");
    }

    return 0;
}