//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000 // Maximum input length

char morse_codes[36][6] = { // Morse codes for 0-9 and A-Z
    "-----",
    ".----",
    "..---",
    "...--",
    "....-",
    ".....",
    "-....",
    "--...",
    "---..",
    "----.",
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--.."
};

char *convert_to_morse(char *input) {
    char *output = malloc(strlen(input) * 5 + 1); // Allocate memory for output string
    output[0] = '\0'; // Initialize string with null character
    int index = 0;
    
    // Loop through input string, convert each character to Morse code and append to output string
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            int digit = input[i] - '0';
            strcat(output, morse_codes[digit]);
            strcat(output, " ");
        } else if (isalpha(input[i])) {
            char letter = toupper(input[i]);
            int letter_index = letter - 'A' + 10;
            strcat(output, morse_codes[letter_index]);
            strcat(output, " ");
        } else if (isspace(input[i])) {
            strcat(output, "/ ");
        }
    }
    
    output[strlen(output) - 1] = '\0'; // Remove trailing space
    return output;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter text to convert to Morse code: ");
    fgets(input, MAX_LENGTH, stdin); // Read input from user
    
    char *output = convert_to_morse(input); // Convert input to Morse code
    printf("Morse code: %s\n", output); // Print Morse code
    
    free(output); // Free memory allocated for output string
    return 0;
}