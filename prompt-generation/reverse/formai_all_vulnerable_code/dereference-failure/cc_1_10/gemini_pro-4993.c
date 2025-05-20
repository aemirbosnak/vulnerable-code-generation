//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: imaginative
// Dance with the dots and dashes: A Text to Morse Code Odyssey

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The rhythmic alphabet: Morse Code mappings
char morseCode[26][5] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
    ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// The conductor's baton: Function to convert a character to Morse code
char* charToMorse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morseCode[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morseCode[c - 'a'];
    } else {
        return " ";
    }
}

// The telegraph's orchestra: Function to convert a string to Morse code
char* strToMorse(char* str) {
    int len = strlen(str);
    char* morse = malloc((len * 5) + 1); // Generous space for dashes and dots
    int i, j = 0;
    
    // Echo the characters' Morse code melodies
    for (i = 0; i < len; i++) {
        strcat(morse, charToMorse(str[i]));
        strcat(morse, " "); // Separate each character's Morse code with a space
    }
    
    morse[len * 5] = '\0'; // Terminate the string to keep the harmony
    return morse;
}

// The grand finale: Main function where the text-to-Morse symphony unfolds
int main() {
    // Overture: Request the message from the user
    printf("Enter a message to transform into Morse code: ");
    char str[100];
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character from the input
    
    // The maestro's command: Convert the message to Morse code
    char* morse = strToMorse(str);
    
    // The symphony's performance: Display the Morse code message
    printf("Morse Code Symphony: %s\n", morse);
    
    // Curtain call: Free the memory allocated for the Morse code string
    free(morse);
    
    return 0;
}