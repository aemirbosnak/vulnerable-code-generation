//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// List of Morse code characters
char morse_code[][6] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "---.", ".-.-", "--.-",
    ".-.", "-..-", "--.-", ".-.-", "-....", "--...", ".-.-.-", ".----",
    "..---", "...--", "....-", ".....", "-....-", "-...-", "-.--.", "-.--.-",
    ".----.", "..--.."
};

// List of corresponding English characters
char english_characters[] = "abcdefghijklmnopqrstuvwxyz0123456789";

// Function to convert a character to Morse code
char* char_to_morse(char c) {
    int index = strchr(english_characters, c) - english_characters;
    if (index >= 0 && index < 36) {
        return morse_code[index];
    }
    return "";
}

// Function to convert a string to Morse code
char* string_to_morse(char* str) {
    int len = strlen(str);
    char* morse_code_str = malloc(len * 5 + 1);  // Each character can be up to 5 Morse code characters + 1 for the null-terminator
    int pos = 0;
    for (int i = 0; i < len; i++) {
        char* morse_code = char_to_morse(str[i]);
        strcat(morse_code_str + pos, morse_code);
        pos += strlen(morse_code);
        strcat(morse_code_str + pos, " ");
        pos++;
    }
    morse_code_str[pos] = '\0';
    return morse_code_str;
}

// Function to convert a Morse code string to English
char* morse_to_char(char* morse_code) {
    int len = strlen(morse_code);
    char* english_char = malloc(len / 5 + 1);  // Each Morse code character is up to 5 characters
    int pos = 0;
    for (int i = 0; i < len; i++) {
        char* morse_code_char = malloc(6);
        int j = 0;
        while (morse_code[i] != ' ' && i < len) {
            morse_code_char[j++] = morse_code[i++];
        }
        morse_code_char[j] = '\0';
        int index = -1;
        for (int k = 0; k < 36; k++) {
            if (strcmp(morse_code_char, morse_code[k]) == 0) {
                index = k;
                break;
            }
        }
        if (index >= 0) {
            english_char[pos++] = english_characters[index];
        }
        i++;  // Skip the space
    }
    english_char[pos] = '\0';
    return english_char;
}

// Function to play the Morse code using beeps
void play_morse_code(char* morse_code) {
    int len = strlen(morse_code);
    for (int i = 0; i < len; i++) {
        if (morse_code[i] == '.') {
            printf("Beep ");
        } else if (morse_code[i] == '-') {
            printf("Beep Beep Beep ");
        } else if (morse_code[i] == ' ') {
            printf(" ");
        }
    }
    printf("\n");
}

// Main function
int main() {
    // Get the input string from the user
    char* input_str;
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", input_str);

    // Convert the string to Morse code
    char* morse_code_str = string_to_morse(input_str);

    // Print the Morse code string
    printf("Morse code: %s\n", morse_code_str);

    // Convert the Morse code string back to English
    char* english_str = morse_to_char(morse_code_str);

    // Print the English string
    printf("English: %s\n", english_str);

    // Play the Morse code using beeps
    play_morse_code(morse_code_str);

    return 0;
}