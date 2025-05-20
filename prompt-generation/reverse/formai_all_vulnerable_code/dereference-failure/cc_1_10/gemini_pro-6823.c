//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code table
const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "---.", ".-.-.-", "..--..", "-....-", "-...-", "-.--.", "-.--.-", ".-...", "-.-.-.","-...", ".----", "..---", "...--", "....-", ".....", "-....", "-.-..", "-.--", "-..-.", ".-.-.", "--..--", "...-..-", "---...", "..--.-", ".-..-.", "-.-.--", ".-....", "--...-", ".-.-.", "-....-", ".-.--", "-..-.", ".-.-.-", "..--..", "-....-", "-...-", "-.--.", "-.--.-"
};

// Define the character-to-Morse code mapping
const char *char_to_morse[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", " ", ".", ",", "?", "/", "!", "'", ":", ";", "=", "+", "-", "_", "\"", "$", "&", "@", "(", ")", "=", "+", "-", "_", "=", "+", "-"
};

char *to_morse(char *text) {
    // Allocate memory for the Morse code string
    char *morse = malloc(strlen(text) * 5 + 1);

    // Convert each character to Morse code
    int i, j;
    for (i = 0, j = 0; text[i] != '\0'; i++) {
        // Find the character in the mapping table
        int index = -1;
        for (int k = 0; k < strlen(char_to_morse); k++) {
            if (text[i] == char_to_morse[k][0]) {
                index = k;
                break;
            }
        }

        // Convert the character to Morse code
        if (index != -1) {
            strcat(morse, morse_table[index]);
            strcat(morse, " ");
        }
    }

    // Return the Morse code string
    return morse;
}

int main() {
    // Get the text to convert from the user
    char text[1024];
    printf("Enter the text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin);

    // Convert the text to Morse code
    char *morse = to_morse(text);

    // Print the Morse code
    printf("The Morse code is: %s\n", morse);

    // Free the memory allocated for the Morse code string
    free(morse);

    return 0;
}