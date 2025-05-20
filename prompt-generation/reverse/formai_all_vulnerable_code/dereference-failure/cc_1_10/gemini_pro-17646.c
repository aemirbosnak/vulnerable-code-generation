//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the Morse code table
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----", " ",
    "/ (slash)", "-.-.- (dash-dot-dash-dot)"
};

// Define the alphabet table
char *alphabet = "abcdefghijklmnopqrstuvwxyz/ ";

// Function to convert a character to Morse code
char *to_morse(char c) {
    for (int i = 0; i < 27; i++) {
        if (tolower(c) == alphabet[i]) {
            return morse_code[i];
        }
    }
    return NULL;
}

// Function to convert a string to Morse code
char *to_morse_string(char *str) {
    char *morse_string = malloc(100);
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        char *morse = to_morse(str[i]);
        for (j = 0; j < strlen(morse); j++) {
            morse_string[j + i * 4] = morse[j];
        }
        morse_string[i * 4 + j] = ' ';
        i++;
    }
    morse_string[i * 4 + j - 1] = '\0';
    return morse_string;
}

// Main function
int main() {
    // Get the input text
    char *text = malloc(100);
    printf("Enter the text to convert to Morse code: ");
    scanf("%s", text);

    // Convert the text to Morse code
    char *morse_string = to_morse_string(text);

    // Print the Morse code
    printf("Morse code: %s\n", morse_string);

    // Free the allocated memory
    free(text);
    free(morse_string);

    return 0;
}