//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: puzzling
#include <stdio.h>
#include <string.h>

// Morse code table
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--..", "...", "....", "..",
    ".---", "-.-.-", "-.--", "--.-", ".-.", "---", ".--.", "....-", "..--", "...--",
    "-....", "--...", "---..", "----.", "-----", ".----", "..---", "...--", "....-", ".....",
    "-....-", "--...", "---..", "----.", "-----",
};

// Lookup table for characters to morse code
char *char_to_morse_code[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", "0", "1", "2", "3",
    "4", "5", "6", "7", "8", "9",
};

// Convert a character to morse code
char *char_to_morse(char c) {
    int index = c - 'a';
    if (index < 0 || index >= 26) {
        return "";
    }
    return morse_code[index];
}

// Convert a string to morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code_str = malloc(len * 5 + 1);
    int i;
    for (i = 0; i < len; i++) {
        strcat(morse_code_str, char_to_morse(str[i]));
        strcat(morse_code_str, " ");
    }
    morse_code_str[len * 5] = '\0';
    return morse_code_str;
}

// Print the morse code for a string
void print_morse_code(char *str) {
    printf("%s", str);
}

// Main function
int main() {
    char str[] = "hello world";
    char *morse_code_str = string_to_morse(str);
    print_morse_code(morse_code_str);
    free(morse_code_str);
    return 0;
}