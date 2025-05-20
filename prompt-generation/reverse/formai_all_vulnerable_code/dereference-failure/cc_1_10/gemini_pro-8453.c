//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// Morse code character map
char* morse_codes[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-.--", "-...", "-.-.-",
    ".-..-", "---...", "----", "..-", "-----", ".----", "..---", "---..",
    "----.", "-----", ".----.", "-....-", "--...--", "-..---", "-.--.--", "--..--",
    "....-", "-----.", "----.."
};

// Convert a character to Morse code
char* char_to_morse(char character) {
    if (character >= 'a' && character <= 'z') {
        character -= 32; // Convert to uppercase
    }
    if (character >= 'A' && character <= 'Z') {
        return morse_codes[character - 'A'];
    } else {
        return " "; // Return a space for non-alphabetic characters
    }
}

// Convert a string to Morse code
char* str_to_morse(char* string) {
    char* morse_string = malloc(strlen(string) * 5); // Allocate enough space for the converted string
    int i, j, k;
    for (i = 0, j = 0; i < strlen(string); i++) {
        char* morse_code = char_to_morse(string[i]);
        for (k = 0; k < strlen(morse_code); k++) {
            morse_string[j++] = morse_code[k];
            morse_string[j++] = ' '; // Separate Morse code characters with a space
        }
    }
    morse_string[j - 1] = '\0'; // Add a null-terminator to the end of the string
    return morse_string;
}

int main() {
    char text[] = "Hello World!";

    char* morse_code = str_to_morse(text);

    printf("Original Text: %s\n", text);
    printf("Morse Code: %s\n", morse_code);

    return 0;
}