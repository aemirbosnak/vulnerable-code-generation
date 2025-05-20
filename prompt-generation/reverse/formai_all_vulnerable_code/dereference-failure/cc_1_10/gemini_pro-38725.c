//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

struct MorseCode {
    char character;
    char* code;
};

struct MorseCode morseCodes[] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {' ', " "}
};

int main() {
    char buffer[MAX_BUFFER_SIZE];
    printf("Enter a text: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    char* encodedBuffer = malloc(strlen(buffer) * 5);
    int encodedBufferIndex = 0;

    for (int i = 0; i < strlen(buffer); i++) {
        for (int j = 0; j < sizeof(morseCodes) / sizeof(struct MorseCode); j++) {
            if (morseCodes[j].character == buffer[i]) {
                strcat(encodedBuffer, morseCodes[j].code);
                strcat(encodedBuffer, " ");
                encodedBufferIndex += strlen(morseCodes[j].code) + 1;
                break;
            }
        }
    }

    printf("Morse code: %s\n", encodedBuffer);

    free(encodedBuffer);

    return 0;
}