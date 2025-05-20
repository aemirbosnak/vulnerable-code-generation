//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_MESSAGE_LENGTH 256
#define MAX_MORSE_LENGTH 6

// Morse Code representation
const char *morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", 
    "--.", "....", "..", ".---", "-.-", ".-..", 
    "--", "-.", "---", ".--.", "--.-", ".-.", 
    "...", "-", "..-", "...-", ".--", "-..-", 
    "-.--", "--.."
};

const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function to convert a character to Morse code
void *charToMorse(void *arg) {
    char ch = *(char *)arg;
    static char morse[MAX_MORSE_LENGTH];
    int index;
    
    if (ch >= 'A' && ch <= 'Z') {
        index = ch - 'A';
        strncpy(morse, morseCode[index], MAX_MORSE_LENGTH);
        printf("%c: %s\n", ch, morse);
    }
    else {
        strcpy(morse, " ");
        printf("%c: (space)\n", ch);
    }
    
    return NULL;
}

// Function to convert a string to Morse code
void convertToMorse(char *message) {
    pthread_t threads[MAX_MESSAGE_LENGTH];
    int threadCount = 0;

    for (int i = 0; i < strlen(message); i++) {
        char upperChar = toupper(message[i]); // Convert to uppercase
        pthread_create(&threads[threadCount], NULL, charToMorse, &upperChar);
        threadCount++;
        usleep(100000); // Small delay for thread management
    }
    
    for (int i = 0; i < threadCount; i++) {
        pthread_join(threads[i], NULL);
    }
}

// Function to get user input and handle Morse conversion
void getUserInput() {
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter message to convert to Morse code (uppercase letters only):\n");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    
    // Remove newline character if present
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }

    convertToMorse(message);
}

int main() {
    printf("=== Morse Code Converter ===\n");
    getUserInput();
    printf("Conversion complete.\n");
    return 0;
}