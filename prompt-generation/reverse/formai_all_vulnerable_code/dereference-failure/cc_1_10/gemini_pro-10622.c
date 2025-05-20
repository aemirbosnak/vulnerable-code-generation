//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
    "-----", "  ", "     "};

// Text to Morse code conversion function
char *text_to_morse(char *text) {
    int i, j, len = strlen(text);
    char *morse_code = malloc(len * 5); // Allocate memory for the morse code string

    for (i = 0; i < len; i++) {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') c -= 'A'; // Convert uppercase letters to their index
        else if (c >= 'a' && c <= 'z') c -= 'a'; // Convert lowercase letters to their index

        for (j = 0; j < 36; j++) {
            if (c == j) { // Find the morse code for the character
                strcat(morse_code, morse_table[j]); // Append the morse code to the morse code string
                break;
            }
        }

        if (c == ' ') strcat(morse_code, " "); // Append a space to the morse code string for spaces in the text
    }

    return morse_code; // Return the morse code string
}

// Morse code to text conversion function
char *morse_to_text(char *morse_code) {
    int i, j, len = strlen(morse_code);
    char *text = malloc(len); // Allocate memory for the text string

    for (i = 0; i < len; i++) {
        char c = morse_code[i];
        for (j = 0; j < 36; j++) {
            if (strcmp(morse_table[j], &c) == 0) { // Find the character for the morse code
                text[i] = j + 'a'; // Convert the index to the character
                break;
            }
        }

        if (c == ' ') text[i] = ' '; // Convert spaces in the morse code string to spaces in the text string
    }

    return text; // Return the text string
}

// Main function
int main() {
    char text[] = "HELLO WORLD";
    char *morse_code = text_to_morse(text);

    printf("Text: %s\n", text);
    printf("Morse code: %s\n", morse_code);

    char *decoded_text = morse_to_text(morse_code);

    printf("Decoded text: %s\n", decoded_text);

    return 0;
}