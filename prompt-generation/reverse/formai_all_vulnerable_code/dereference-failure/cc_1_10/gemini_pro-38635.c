//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: optimized
#include <stdio.h>
#include <string.h>

// Morse code character mapping
const char *morse_codes[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "..--", "---..", ".-.-.-", "..--..", "-....-", ".-.-.",
    "-..-.", "--..--", "-..-.--", "...-..-", "-..---", "-....-", "..--.-", ".-....", ".-....-", "-...--", "-...---", "-.-.-.-",
    "....-", "..--..", "-.--.-", "...--..-", "-..--.-", "..--..-", "-.-.--.-", "---....", "..--.-.", "..--..--", "-.-.-.-"
};

// Convert a character to Morse code
char *to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        c -= 'A';  // Convert to 0-25 range
    } else if (c >= 'a' && c <= 'z') {
        c -= 'a';  // Convert to 0-25 range
    } else {
        return NULL;  // Invalid character
    }

    return (char *)morse_codes[c];
}

// Convert a string to Morse code
char *to_morse_str(char *str) {
    char *morse_code = malloc(strlen(str) * 4 + 1);  // Allocate memory for the Morse code string (4 characters per character + 1 for null-terminator)

    int i;
    int j = 0;
    for (i = 0; i < strlen(str); i++) {
        char *c_morse = to_morse(str[i]);
        if (c_morse == NULL) {
            continue;  // Skip invalid characters
        }

        strcpy(&morse_code[j], c_morse);
        j += strlen(c_morse);

        morse_code[j++] = ' ';  // Add a space between characters
    }

    morse_code[j] = '\0';  // Add null-terminator

    return morse_code;
}

// Print the Morse code for a string
void print_morse(char *str) {
    char *morse_code = to_morse_str(str);

    printf("Morse code: %s\n", morse_code);

    free(morse_code);  // Free the allocated memory
}

int main() {
    char *str = "Hello World";

    print_morse(str);

    return 0;
}