//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "---.", "----", ".-.-",
    "--..--", ".-.-.-", ".-..-.", "-....-", "-.-.--", "-.--.-", ".-.-.-",
    "....-", "---..", "----."
};

// Main function
int main() {
    // Get the input text from the user

    printf("Text: ");
    char *input_text = (char *)malloc(1024);
    fgets(input_text, 1024, stdin);

    // Convert the input text to Morse code

    char *morse_code = (char *)malloc(1024);
    memset(morse_code, 0, 1024);

    int i, j, k;
    char *p, *q;

    for (i = 0, p = input_text; *p != '\0'; i++, p++) {
        for (j = 0; j < 26; j++) {
            if (*p == 'a' + j || *p == 'A' + j) {
                strcat(morse_code, morse_table[j]);
                strcat(morse_code, " ");
                break;
            }
        }
    }

    for (i = 0, p = input_text; *p != '\0'; i++, p++) {
        if (*p == ' ') {
            strcat(morse_code, " ");
        }
    }

    // Print the Morse code

    printf("Morse code: %s\n", morse_code);

    // Free the allocated memory

    free(input_text);
    free(morse_code);

    return 0;
}