//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", 
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

const char *alpha_numeric = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const char *space = "                   "; // 19 spaces for gap between words

char *text_to_morse(const char *input) {
    char *output = NULL;
    int i, j;
    int index;

    output = (char *)malloc(strlen(input) * 8 * sizeof(char)); // Assume 8 characters for each character in input
    if (output == NULL) {
        return NULL;
    }

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            strcat(output, space); // Add 7 spaces for gap between words
        } else {
            index = strchr(alpha_numeric, toupper(input[i])) - alpha_numeric;
            if (index < 0 || index > 35) {
                free(output);
                return NULL; // Invalid character
            }
            strcat(output, morse_code[index]);
            strcat(output, " ");
        }
    }

    // Remove trailing space
    output[strlen(output) - 1] = '\0';

    return output;
}

int main(void) {
    char input[256];
    char *output = NULL;

    printf("Enter text to convert to Morse code: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    output = text_to_morse(input);
    if (output != NULL) {
        printf("%s\n", output);
        free(output);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}