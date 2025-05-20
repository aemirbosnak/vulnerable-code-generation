//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 256

// Morse code representation for alphabet and digits
const char *morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...",
    "-", "..-", "...-", ".--", "-..-", "-.--", "--..", // A-Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
    "---..", "----." // 0-9
};

// Function to get the Morse code for a character
const char* getMorse(char ch) {
    if ('A' <= ch && ch <= 'Z') {
        return morseCode[ch - 'A'];
    } else if ('0' <= ch && ch <= '9') {
        return morseCode[ch - '0' + 26];
    } else {
        return " "; // Space for unsupported characters
    }
}

// Function to convert a string to Morse code
void convertToMorse(const char *message) {
    char *morseMessage = (char *)malloc(MAX_MESSAGE_LENGTH * 6); // Approx max size
    if (!morseMessage) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    morseMessage[0] = '\0'; // Initialize empty string

    for (size_t i = 0; i < strlen(message); i++) {
        if (message[i] == ' ') {
            strcat(morseMessage, " / ");
        } else {
            char upperChar = (message[i] >= 'a' && message[i] <= 'z') ? message[i] - 32 : message[i];
            const char *morse = getMorse(upperChar);
            strcat(morseMessage, morse);
            strcat(morseMessage, " "); // Add space between characters
        }
    }

    printf("Morse Code: %s\n", morseMessage);
    free(morseMessage);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return 1;
    }

    char message[MAX_MESSAGE_LENGTH];
    strncpy(message, argv[1], MAX_MESSAGE_LENGTH - 1);
    message[MAX_MESSAGE_LENGTH - 1] = '\0'; // Ensure null termination

    convertToMorse(message);

    return 0;
}