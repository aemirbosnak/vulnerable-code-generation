//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 256
#define MAX_MORSE_LENGTH (MAX_MESSAGE_LENGTH * 5)

// Morse code map for alphanumeric characters and a space
const char* morseCodeMap[36] = {
    "00000", // ' ' (space)
    ".-",    // 'A'
    "-...",  // 'B'
    "-.-.",  // 'C'
    "-..",   // 'D'
    ".",     // 'E'
    "..-.",  // 'F'
    "--.",   // 'G'
    "....",  // 'H'
    "..",    // 'I'
    ".---",  // 'J'
    "-.-",   // 'K'
    ".-..",  // 'L'
    "--",    // 'M'
    "-.",    // 'N'
    "---",   // 'O'
    ".--.",  // 'P'
    "--.-",  // 'Q'
    ".-.",   // 'R'
    "...",   // 'S'
    "-",     // 'T'
    "..-",   // 'U'
    "...-",  // 'V'
    ".--",   // 'W'
    "-..-",  // 'X'
    "-.--",  // 'Y'
    "--..",  // 'Z'
    "-----",  // '0'
    ".----", // '1'
    "..---", // '2'
    "...--", // '3'
    "....-", // '4'
    ".....", // '5'
    "-....", // '6'
    "--...", // '7'
    "---..", // '8'
    "----."  // '9'
};

void initialize_post_apocalypse() {
    printf("\n=== Welcome to the Morse Codex Converter ===\n");
    printf("In these fragmented times, we must connect through the whispers of the past.\n");
    printf("Input a message, and the echoes will guide it through the static.\n\n");
}

void translate_to_morse(const char *input, char *output) {
    char *ptr = output;
    while (*input) {
        if (*input >= 'A' && *input <= 'Z') {
            strcpy(ptr, morseCodeMap[*input - 'A' + 1]);
        } 
        else if (*input >= 'a' && *input <= 'z') {
            strcpy(ptr, morseCodeMap[*input - 'a' + 1]);
        }
        else if (*input >= '0' && *input <= '9') {
            strcpy(ptr, morseCodeMap[*input - '0' + 27]);
        } 
        else if (*input == ' ') {
            strcpy(ptr, morseCodeMap[0]);
        }
        else {
            input++;  // Ignore any unsupported characters
            continue;
        }
        
        ptr += strlen(ptr);        
        *ptr++ = ' '; // Add a space between Morse code characters
        input++;
    }
    *(ptr - 1) = '\0'; // Replace last space with null terminator
}

int main() {
    char inputMessage[MAX_MESSAGE_LENGTH];
    char morseOutput[MAX_MORSE_LENGTH];

    initialize_post_apocalypse();

    printf("Enter your message: ");
    if (fgets(inputMessage, sizeof(inputMessage), stdin) == NULL) {
        fprintf(stderr, "Failed to read input message.\n");
        return EXIT_FAILURE;
    }
    
    // Strip the newline character that fgets might leave
    size_t len = strlen(inputMessage);
    if (len > 0 && inputMessage[len - 1] == '\n') {
        inputMessage[len - 1] = '\0';
    }

    translate_to_morse(inputMessage, morseOutput);
    printf("\nYour message in Morse code is:\n%s\n", morseOutput);
    
    printf("\nUse this knowledge wisely, traveler. The echoes may save you in your journey.\n");

    return EXIT_SUCCESS;
}