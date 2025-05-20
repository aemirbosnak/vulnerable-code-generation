//FormAI DATASET v1.0 Category: QR code reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generateCode(char* code) {
    srand(time(NULL));
    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int codeLength = 25;

    for (int i = 0; i < codeLength; i++) {
        int randomIndex = rand() % sizeof(charset);
        code[i] = charset[randomIndex];
    }
}

int main() {
    char* code = malloc(sizeof(char) * 26);
    memset(code, 0, sizeof(char) * 26);

    generateCode(code);
    printf("Code generated: %s\n", code);

    printf("Make sure to scan the QR code below to verify!\n");

    // Now let's create a QR code that shapeshifts
    for (int i = 0; i < strlen(code); i++) {
        if (code[i] >= '0' && code[i] <= '9') {
            // draw a square QR code block
            printf("\u2588");
        } else if (code[i] >= 'A' && code[i] <= 'Z') {
            // draw a circle QR code block
            printf("\u25CF");
        } else if (code[i] >= 'a' && code[i] <= 'z') {
            // draw a triangle QR code block
            printf("\u25B3");
        } else {
            // draw a space character for any other character
            printf(" ");
        }

        if ((i + 1) % 5 == 0) {
            // end of QR code row, print a newline character
            printf("\n");
        }
    }

    free(code);
    return 0;
}