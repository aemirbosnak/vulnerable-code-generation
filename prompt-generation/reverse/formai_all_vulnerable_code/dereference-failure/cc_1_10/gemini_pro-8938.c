//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

// Morse code table
char *morse_table[] = {
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",  ".---",
    "-.-",  ".-..", "--",   "-.",   "...",  "-",    ".--.", "-..-", "-.--", "--..",
    "....-", "-----", "..--", "-....", "--...", "---",   ".----", "..---", "...--", "....-",
    ".....", "-....-", "--...", "-.--.", "---..", "----.", ".-.-.-", "--..--", "-.--.-", ".-.-."
};

// Main function
int main(int argc, char *argv[]) {
    // Check if a string is provided as an argument
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the input string
    char *input_string = argv[1];

    // Convert the input string to uppercase
    for (int i = 0; i < strlen(input_string); i++) {
        input_string[i] = toupper(input_string[i]);
    }

    // Convert the input string to Morse code
    char output_string[MAX_STR_LEN];
    int output_index = 0;
    for (int i = 0; i < strlen(input_string); i++) {
        // Check if the character is a letter
        if (input_string[i] >= 'A' && input_string[i] <= 'Z') {
            // Convert the letter to Morse code
            strcat(output_string, morse_table[input_string[i] - 'A']);
        }
        // Check if the character is a space
        else if (input_string[i] == ' ') {
            // Add a space to the output string
            strcat(output_string, " ");
        }
    }

    // Print the Morse code string
    printf("%s\n", output_string);

    return EXIT_SUCCESS;
}