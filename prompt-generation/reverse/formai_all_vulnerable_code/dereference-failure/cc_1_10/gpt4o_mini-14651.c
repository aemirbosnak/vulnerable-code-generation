//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// Define the Morse code representation for each alphanumeric character
const char *morseCode[] = {
    ".-", "-...", "-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",  // A-Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."  // 0-9
};

// Function to convert a single character to Morse code
const char* charToMorse(char c) {
    if (isalpha(c)) {
        return morseCode[toupper(c) - 'A']; // Map A-Z to 0-25
    } else if (isdigit(c)) {
        return morseCode[c - '0' + 26]; // Map 0-9 to 26-35
    }
    return ""; // Return empty if not supported
}

// Function to convert a string to Morse code
void textToMorse(const char *text, char *output, int maxOutputLen) {
    output[0] = '\0'; // Initialize output string
    char morseChar[8]; // Temporary storage for Morse code characters

    for (int i = 0; text[i] != '\0'; i++) {
        const char *morseEquiv = charToMorse(text[i]);
        snprintf(morseChar, sizeof(morseChar), "%s ", morseEquiv); // Append Morse code for character
        strncat(output, morseChar, maxOutputLen - strlen(output) - 1); // Add to output
    }
}

// Main function
int main() {
    char input[MAX_LEN];
    char output[MAX_LEN * 6]; // To ensure we have enough space for Morse code

    printf("Welcome to the visionary Morse Code Converter!\n");
    printf("Enter your text (max %d characters): ", MAX_LEN - 1);
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove trailing newline from the input
        input[strcspn(input, "\n")] = '\0';

        // Convert to Morse code
        textToMorse(input, output, sizeof(output));

        printf("Morse Code Representation:\n");
        printf("%s\n", output);
    } else {
        printf("Error reading input. Please try again.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}