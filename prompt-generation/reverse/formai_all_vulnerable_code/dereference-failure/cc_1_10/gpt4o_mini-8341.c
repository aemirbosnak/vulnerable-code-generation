//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_MESSAGE_LENGTH 1024

// Morse Code representation of characters
const char* morseCode[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--.."  // Z
};

const char* morseCodeDigits[] = {
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----."  // 9
};

void printMorseCode(char *message) {
    printf("Morse Code for: %s\n", message);
    for(int i = 0; message[i] != '\0'; i++) {
        char ch = toupper(message[i]); // Convert to uppercase
        
        if (ch >= 'A' && ch <= 'Z') {
            printf("%s ", morseCode[ch - 'A']);
        } else if (ch >= '0' && ch <= '9') {
            printf("%s ", morseCodeDigits[ch - '0']);
        } else if (ch == ' ') {
            printf("/ "); // Using '/' as a separator for words
        } else {
            printf("? "); // Unknown characters
        }
    }
    printf("\n");
}

void getInputMessage(char *message) {
    printf("Enter your message (max %d characters): ", MAX_MESSAGE_LENGTH - 1);
    if (fgets(message, MAX_MESSAGE_LENGTH, stdin) != NULL) {
        // Remove the newline character if present
        size_t len = strlen(message);
        if (message[len - 1] == '\n') {
            message[len - 1] = '\0';
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];

    printf("Welcome to the Morse Code Converter!\n");
    getInputMessage(message);
    
    printMorseCode(message);

    return 0;
}