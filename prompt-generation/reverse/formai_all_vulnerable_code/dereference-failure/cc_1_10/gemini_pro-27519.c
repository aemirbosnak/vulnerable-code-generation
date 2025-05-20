//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 1024

// Morse code table
char *morse_table[] = {
    ".-",    "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",  ".---",
    "-.-",   ".-..", "--",   "-.",   "...",  "-",    "..-",  "...-", ".--",  "-..-",
    "-.--",  "--..", ".-.",   "...",  "-",    ".----", "..---", "-.-.--", "--..--", ".-..-.",
    ".-..-", "-..-.", "-.--.", "-....", "--...", "-----", ".-..",  "--.",  "---",   ".----.",
    "..---.", "---..", "----.", "-----", ".-",    "--.-",  "-..-", "-.--",  "..--..",
    "-.--.-", "-.-.--", "---...", "-.--.", "-.--.", "-...-", "-...-", "-.-.-.", ".-.-.-",
    "--..--", "---...", "----",   ".-----", ".----.", ".----.", ".----.", "......", ".-.-.-"
};

// Convert a single character to Morse code
char *char_to_morse(char c) {
    c = toupper(c);
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return "";
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_str = malloc(len * 5 + 1);
    int i;
    for (i = 0; i < len; i++) {
        strcat(morse_str, char_to_morse(str[i]));
        strcat(morse_str, " ");
    }
    morse_str[len * 5] = '\0';
    return morse_str;
}

// Main function
int main() {
    char str[MAX_STR_LEN];
    char *morse_str;

    printf("Enter a string to convert to Morse code: ");
    fgets(str, MAX_STR_LEN, stdin);

    morse_str = string_to_morse(str);

    printf("Morse code: %s\n", morse_str);

    free(morse_str);

    return 0;
}