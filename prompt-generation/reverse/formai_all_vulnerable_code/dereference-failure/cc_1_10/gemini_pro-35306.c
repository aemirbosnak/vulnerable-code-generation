//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our trusty Morse code table, keeping us on track through the cosmos
char *morseCodeTable[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----",
    "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----",
};

// Function that shoots our text into the Morse code galaxy
char *textToMorse(char *text) {
    int textLength = strlen(text);
    char *morseCode = (char *)malloc((textLength * 5) + 1); // Ample space for our secret messages

    // Teleporting through the characters of our text
    for (int i = 0; i < textLength; i++) {
        char character = text[i];
        int characterIndex = character - 'a'; // Translating characters to their index in the table

        // Decoding each character into its Morse code equivalent
        if (characterIndex >= 0 && characterIndex < 26) {
            strcat(morseCode, morseCodeTable[characterIndex]);
        } else if (character == ' ') { // A little break in the transmission
            strcat(morseCode, " ");
        }
    }

    return morseCode; // Our shiny new Morse code message, ready for transmission
}

// Let's decode those messages! We're like space detectives
char *morseToText(char *morseCode) {
    int morseLength = strlen(morseCode);
    char *text = (char *)malloc((morseLength / 5) + 1); // Enough space for our decoded text
    char currentCode[6]; // To hold the current Morse code sequence we're working on

    // Looping through the Morse code message
    for (int i = 0, j = 0; i < morseLength; i++, j++) {
        currentCode[j] = morseCode[i];

        // Time to find the character that matches this code
        if (i == morseLength - 1 || morseCode[i + 1] == ' ') {
            currentCode[j + 1] = '\0'; // Capping off the sequence
            for (int k = 0; k < 26; k++) { // Exploring the Morse code table
                if (!strcmp(currentCode, morseCodeTable[k])) {
                    text[j] = 'a' + k; // Bingo! Decoded character found
                    break;
                }
            }

            if (morseCode[i + 1] == ' ') { // Space signals a new word
                text[j + 1] = ' ';
                j++;
            }

            j = -1; // Resetting our counter for the next character
            memset(currentCode, 0, sizeof(currentCode)); // Clearing the code sequence
        }
    }

    return text; // Our decoded text, ready for translation
}

int main() {
    // Let's rock 'n' roll with some text and Morse code conversions!

    // Text to Morse code: Engage!
    char *text = "Hello World";
    printf("Beam me up, Scotty! Let's turn '%s' into Morse code...\n", text);
    char *morseCode = textToMorse(text);
    printf("Transmission received: %s\n\n", morseCode);

    // Morse code to text: Decrypt the message!
    morseCode = ".... . .-.. .-.. --- --..--";
    printf("Incoming transmission! Decoding '%s' into text...\n", morseCode);
    char *decodedText = morseToText(morseCode);
    printf("Mission accomplished: %s\n", decodedText);

    return 0; // Mission accomplished!
}