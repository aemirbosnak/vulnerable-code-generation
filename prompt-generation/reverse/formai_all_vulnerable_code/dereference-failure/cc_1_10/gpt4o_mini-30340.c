//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Morse code representation of each letter and digit
const char *morseCodeTable[] = {
    "A", ".-",  "B", "-...", "C", "-.-.", "D", "-..",  "E", ".",
    "F", "..-.", "G", "--.",  "H", "....", "I", "..",   "J", ".---",
    "K", "-.-",  "L", ".-..", "M", "--",   "N", "-.",   "O", "---",
    "P", ".--.", "Q", "--.-", "R", ".-.",  "S", "...",  "T", "-",
    "U", "..-",  "V", "...-", "W", ".--",  "X", "-..-", "Y", "-.--",
    "Z", "--..", "0", "-----", "1", ".----", "2", "..---", "3", "...--",
    "4", "....-", "5", ".....", "6", "-....", "7", "--...", "8", "---..",
    "9", "----."
};

// Function to convert text to Morse code
void textToMorse(const char *input) {
    char *upperInput = strdup(input);  // Duplicate input to preserve original
    for (int i = 0; upperInput[i]; i++) {
        if (upperInput[i] >= 'a' && upperInput[i] <= 'z') {
            upperInput[i] -= 32;  // Convert to uppercase
        }
    }

    printf("Morse Code: ");
    for (int i = 0; upperInput[i]; i++) {
        if (upperInput[i] == ' ') {
            printf("   ");  // Space between words
        } else {
            for (int j = 0; j < 36; j++) {
                if (upperInput[i] == morseCodeTable[j][0]) {
                    printf("%s ", morseCodeTable[j][1]);  // Print Morse code
                    break;
                }
            }
        }
    }
    printf("\n");
    free(upperInput);  // Free dynamically allocated memory
}

// Function to read and sanitize input
char* sanitizeInput() {
    char *buffer = (char*) malloc(255 * sizeof(char));
    if (!buffer) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    printf("Enter the text to convert to Morse code (max 254 characters): ");
    fgets(buffer, 255, stdin);
    
    // Remove trailing newline character
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    return buffer;
}

int main() {
    printf("Welcome to the Text to Morse Code Converter!\n");
    char *userInput = sanitizeInput();
    
    textToMorse(userInput);
    
    free(userInput);  // Free the input buffer
    return 0;
}