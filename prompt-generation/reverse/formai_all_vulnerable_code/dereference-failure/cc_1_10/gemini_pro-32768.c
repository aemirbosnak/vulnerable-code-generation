//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code alphabet
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.--", "..--..", "---...",
    "-.--.-", "-.-.--", "-..--", ".", ".-", ".-.", "..--", "-...", ".-..-",
    "-.--", "--..", "-.--", "-.--.", "---.", "..--.-", "-....-", "--...-",
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..",
    "----.", "-----", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.--",
    "..--..", "---...", "-.--.-", "-.-.--", "-..--", ".", ".-", ".-.", "..--",
    "-...", ".-..-", "-.--", "--..", "-.--", "-.--.", "---.", "..--.-", "-....-",
    "--...-", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..",
    "----.", "-----"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return "";
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    char *morse_code = "";
    for (int i = 0; i < strlen(str); i++) {
        char *morse_char = char_to_morse(str[i]);
        if (strlen(morse_char) > 0) {
            strcat(morse_code, morse_char);
            strcat(morse_code, " ");
        }
    }
    return morse_code;
}

// Main function
int main() {
    // Get the input string
    char *str = malloc(100);
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code
    printf("Morse code: %s", morse_code);

    // Free the allocated memory
    free(str);
    free(morse_code);

    return 0;
}