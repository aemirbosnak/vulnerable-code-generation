//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CHARS 1000
#define MAX_MORSE_CODE_LENGTH 10
#define DELIMITER "   "

// Morse code dictionary
char *morse_dict[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--..", "-----"
};

int main() {
    char input_text[MAX_CHARS];
    char *morse_code_output = malloc(MAX_CHARS * MAX_MORSE_CODE_LENGTH);
    int input_length = 0;
    int morse_code_length = 0;

    // Prompt user for input
    printf("Enter the text to convert to Morse code: ");
    fgets(input_text, MAX_CHARS, stdin);

    // Remove newline character from input
    input_text[strcspn(input_text, "\n")] = '\0';

    // Convert input text to uppercase
    for (int i = 0; input_text[i]!= '\0'; i++) {
        input_text[i] = toupper(input_text[i]);
    }

    // Convert input text to Morse code
    for (int i = 0; input_text[i]!= '\0'; i++) {
        if (isalpha(input_text[i])) {
            char *morse_code = morse_dict[input_text[i] - 'A'];
            strcat(morse_code_output, morse_code);
            morse_code_length += strlen(morse_code);
        } else {
            strcat(morse_code_output, " ");
            morse_code_length += 1;
        }
    }

    // Print Morse code output
    printf("Morse code output:\n");
    for (int i = 0; i < morse_code_length; i++) {
        if (i % MAX_MORSE_CODE_LENGTH == 0) {
            printf("%s", DELIMITER);
        }
        printf("%c", morse_code_output[i]);
    }
    printf("\n");

    // Free memory
    free(morse_code_output);

    return 0;
}