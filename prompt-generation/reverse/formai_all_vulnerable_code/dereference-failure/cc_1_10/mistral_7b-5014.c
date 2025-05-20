//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

char morseCode[26][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.", "...", "--", "---.", ".--.", "--.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...-", "-...-", "..--", "-..-.", "--.."};

void printMorseCode(char str[], int start, int end);

void textToMorse(char str[], int start, int end) {
    if (start <= end) {
        if (str[start] == '\0') {
            printMorseCode(str, start, end);
            printf("\n");
        } else {
            char currentChar = str[start];
            int index = currentChar - 'A' + 26;
            if (isalpha(currentChar)) {
                printf("%s ", morseCode[index]);
                textToMorse(str, start + 1, end);
            } else if (isalnum(currentChar)) {
                printf("%s ", morseCode[index - 26]);
                int nextIndex = currentChar - '0' + 22;
                textToMorse(str, start + 1, end);
                printf(" %s", morseCode[nextIndex]);
            } else if (currentChar == ' ') {
                printf("/");
                textToMorse(str, start + 1, end);
            }
        }
    }
}

void printMorseCode(char str[], int start, int end) {
    int i;
    for (i = start; i <= end; i++) {
        printf("%c", str[i]);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char inputText[MAX_LEN];
    strcpy(inputText, argv[1]);

    textToMorse(inputText, 0, strlen(inputText) - 1);

    return 0;
}