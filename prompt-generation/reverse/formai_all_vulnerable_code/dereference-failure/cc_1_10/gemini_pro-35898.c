//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Romeo and Juliet style Morse code conversion

// Declare Romeo's and Juliet's love letters
char *romeo = "But soft! what light through yonder window breaks? It is the east, and Juliet is the sun.";
char *juliet = "O Romeo, Romeo! Wherefore art thou Romeo? Deny thy father and refuse thy name;";

// Morse code conversion table
char *morse[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Convert a character to Morse code
char *toMorse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morse[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse[c - '0' + 26];
    } else {
        return "";
    }
}

// Convert a string to Morse code
char *toMorseString(char *s) {
    char *result = malloc(strlen(s) * 5);
    int i;
    int j;
    for (i = 0; i < strlen(s); i++) {
        char *morseCode = toMorse(s[i]);
        for (j = 0; j < strlen(morseCode); j++) {
            result[i * 5 + j] = morseCode[j];
        }
        result[i * 5 + j] = ' ';
    }
    return result;
}

// Main function
int main() {
    // Convert Romeo's and Juliet's love letters to Morse code
    char *romeoMorse = toMorseString(romeo);
    char *julietMorse = toMorseString(juliet);

    // Print Romeo's and Juliet's love letters in Morse code
    printf("Romeo: %s\n", romeoMorse);
    printf("Juliet: %s\n", julietMorse);

    // Free the allocated memory
    free(romeoMorse);
    free(julietMorse);

    return 0;
}