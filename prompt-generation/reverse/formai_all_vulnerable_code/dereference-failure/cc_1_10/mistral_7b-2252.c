//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LENGTH 100
#define MORSE_LEN 26

char morseCode[MORSE_LEN][MAX_LENGTH] = {
    ".-", "--.", "-...", "-.-.", "-..", ".", "..-.", "--", "....", "..", ".---", "-.-", ".-..", "--.", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

void morse(char text[], int start, int end, int *codeLength) {
    int len = end - start;
    char ch = text[start];

    if (len > 0) {
        if (ch >= 'A' && ch <= 'Z') {
            printf("%s", morseCode[ch - 'A']);
            codeLength += strlen(morseCode[ch - 'A']);
        } else if (ch >= 'a' && ch <= 'z') {
            printf("%s", morseCode[ch - 'a']);
            codeLength += strlen(morseCode[ch - 'a']);
        } else if (ch == ' ') {
            printf("/");
            *codeLength += 1;
        } else {
            printf("Invalid character: %c", ch);
            *codeLength += 3;
        }

        if (len > 1) {
            int spaces = 1;
            for (int i = start + 1; i <= end; i++) {
                if (text[i] == ' ') {
                    spaces++;
                } else if (text[i] != text[i - 1]) {
                    morse(text, i, i + 1, codeLength);
                    break;
                }
            }

            for (int i = 0; i < spaces; i++) {
                printf("/");
                *codeLength += 1;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>", argv[0]);
        return 1;
    }

    int codeLength = 0;
    morse(argv[1], 0, strlen(argv[1]), &codeLength);

    printf("\nMorse Code Length: %d\n", codeLength);
    return 0;
}