//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the Morse code table
const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "---.",
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----",
    "-....-", "--...--", "---...--", "-.-.-.-", "..--..", ".-..-.", "-.-.--", "-....-", ".-.-.-", "--...--",
    "....-.", "....-.", "-..-.--", "---....", "--..--", "-....-", "-....-", "--...--", "-....-", "-....-",
    "-....-", ".-.-.-.", ".-.-.-.", "-....-", "-....-", "-....-", "-....-", "-....-", "-....-", "-.-.-.",
    "-.-.-.", "-.-.-.", "-.-.-.", "-.-.-.", "-.-.-.", ".-.---", ".-.-.-.", "-.-.-.---", "-.-.-.", "-.-.-.",
    "-.-.-."
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c = toupper(c);
    }
    if (c >= 'A' && c <= 'Z') {
        return (char *)morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return (char *)morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return "";
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5 + 1);
    int i;
    for (i = 0; i < len; i++) {
        strcat(morse_code, char_to_morse(str[i]));
        strcat(morse_code, " ");
    }
    morse_code[len * 5] = '\0';
    return morse_code;
}

// Print the Morse code representation of a string
void print_morse_code(char *morse_code) {
    printf("%s\n", morse_code);
}

// Main function
int main() {
    char *str = "Hello World!";
    char *morse_code = string_to_morse(str);
    print_morse_code(morse_code);
    free(morse_code);
    return 0;
}