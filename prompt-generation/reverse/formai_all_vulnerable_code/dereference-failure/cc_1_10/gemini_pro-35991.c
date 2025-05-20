//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: recursive
#include <stdio.h>
#include <string.h>

// Morse code table
const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----",
    "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-", "--..--",
    "..--..", "...---...", "....--", ".....-.", ".-.-.-.", "-...-.-", "-....-", "--...--", "---..-.",
    "----.-..", "-.-.-."
};

// Recursively convert a character to Morse code
void char_to_morse(char c, int depth) {
    // Base case: if we've reached the end of the string, print a newline
    if (depth == strlen(c)) {
        printf("\n");
        return;
    }

    // Check if the character is an uppercase letter
    if (c >= 'A' && c <= 'Z') {
        // Convert the character to lowercase
        c += 32;
    }

    // Get the Morse code for the character
    const char *morse = morse_table[c - 'a'];

    // Print the Morse code for the character
    printf("%s", morse);

    // Recursively convert the next character in the string
    char_to_morse(c + 1, depth + 1);
}

// Convert a string to Morse code
void string_to_morse(const char *s) {
    // Recursively convert the first character in the string
    char_to_morse(s[0], 0);
}

// Main function
int main() {
    // Get the input string from the user
    char s[101];
    printf("Enter a string: ");
    scanf("%s", s);

    // Convert the string to Morse code
    string_to_morse(s);

    return 0;
}