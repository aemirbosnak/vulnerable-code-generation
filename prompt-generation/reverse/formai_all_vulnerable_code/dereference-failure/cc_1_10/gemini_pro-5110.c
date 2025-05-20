//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code dictionary
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.-", "---.", ".-.-", ".-", "--", "-.", "...", "|", ".-", "---", ".-..", "-..", "..", "-", "..-", ".-.", "....", "...", "-.", "-...", "--", "-..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    int index = c - 'A';
    if (index < 0 || index >= 26) {
        return NULL;
    }
    return morse_table[index];
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5 + 1);  // Each character can be represented by up to 5 Morse code units
    int index = 0;
    for (int i = 0; i < len; i++) {
        char *morse_unit = char_to_morse(str[i]);
        if (morse_unit != NULL) {
            strcpy(morse_code + index, morse_unit);
            index += strlen(morse_unit);
            morse_code[index++] = ' ';  // Add a space between Morse code units
        }
    }
    morse_code[index] = '\0';
    return morse_code;
}

// Print Morse code
void print_morse_code(char *morse_code) {
    printf("%s\n", morse_code);
}

// Get input from the user
char *get_input() {
    char *str = malloc(101);
    printf("Enter a string: ");
    scanf("%100s", str);
    return str;
}

// Main function
int main() {
    char *str = get_input();
    char *morse_code = string_to_morse(str);
    print_morse_code(morse_code);
    free(str);
    free(morse_code);
    return 0;
}