//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-....", "--...", "---..", "----.", "-----"
};

// Character to Morse code conversion function
char *text_to_morse(char *text) {
    // Allocate memory for the Morse code string
    char *morse_code = malloc(strlen(text) * 5);

    // Loop through each character in the text
    for (int i = 0; i < strlen(text); i++) {
        // Get the Morse code for the character
        char *code = morse_table[text[i] - 'A'];

        // Append the Morse code to the Morse code string
        strcat(morse_code, code);

        // Add a space between the characters
        strcat(morse_code, " ");
    }

    // Return the Morse code string
    return morse_code;
}

// Morse code to character conversion function
char *morse_to_text(char *morse_code) {
    // Allocate memory for the character string
    char *text = malloc(strlen(morse_code) / 5);

    // Loop through each Morse code character
    int i = 0;
    int j = 0;
    while (i < strlen(morse_code)) {
        // Get the Morse code for the character
        char code[5];
        strncpy(code, morse_code + i, 4);
        code[4] = '\0';

        // Find the character in the Morse code table
        int index = -1;
        for (int k = 0; k < 26; k++) {
            if (strcmp(code, morse_table[k]) == 0) {
                index = k;
                break;
            }
        }

        // Add the character to the text string
        text[j++] = index + 'A';

        // Move to the next Morse code character
        i += 5;
    }

    // Return the text string
    return text;
}

// Main function
int main() {
    // Get the text from the user
    char text[100];
    printf("Enter the text to convert: ");
    scanf("%s", text);

    // Convert the text to Morse code
    char *morse_code = text_to_morse(text);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    // Convert the Morse code to text
    char *text_back = morse_to_text(morse_code);

    // Print the converted text
    printf("Converted text: %s\n", text_back);

    // Free the memory
    free(morse_code);
    free(text_back);

    return 0;
}