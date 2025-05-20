//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: future-proof
#include <stdio.h>
#include <string.h>

// Function to print ASCII art
void printArt(char* text) {
    int len = strlen(text);
    int i, j, k;

    for (i = 0; i < len; i++) {
        // Print upper border
        for (j = 0; j < 5; j++) {
            printf("%c%c%c%c", 32, 95, 95, 95);
        }
        printf("%c\n", 32);

        // Print side border and text
        printf("%c", 124);
        for (j = 0; j < 3; j++) {
            printf("%c", 32);
        }
        printf("%c", 32);
        for (j = 0; j < len; j++) {
            printf("%c%c%c", 32, 32, text[j]);
        }
        for (j = len; j < 17; j++) {
            printf("%c%c%c", 32, 32, 32);
        }
        printf("%c", 124);

        // Print lower border
        printf("\n");
        for (j = 0; j < 5; j++) {
            printf("%c%c%c%c", 32, 45, 45, 45);
        }
        printf("%c\n", 32);

        // Shift text to left
        char temp = text[0];
        for (k = 0; k < len - 1; k++) {
            text[k] = text[k + 1];
        }
        text[len - 1] = temp;
    }
}

int main() {
    char* text = "ASCII ART";
    printArt(text);
    return 0;
}