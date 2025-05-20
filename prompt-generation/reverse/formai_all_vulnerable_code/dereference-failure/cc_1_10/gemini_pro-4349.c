//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-",
    "...-", "...-", ".-..", "..-.", ".-", ".-", ".-.", "-..", "-..-", "-.-.", "--", "..", "-.", "..-",
    "--.-", "..--", "---", ".-.-.-", "--..--", ".-.-.", "---.", ".-...", "-.--.", "-.--.-", "--..--",
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
char *to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *to_morse_string(char *s) {
    int len = strlen(s);
    char *morse = malloc(len * 5 + 1);
    for (int i = 0; i < len; i++) {
        char *c = to_morse(s[i]);
        if (c == NULL) {
            free(morse);
            return NULL;
        }
        strcat(morse, c);
        strcat(morse, " ");
    }
    return morse;
}

// Print Morse code
void print_morse(char *morse) {
    printf("%s\n", morse);
}

// Main function
int main() {
    char *s = "Hello World!";
    char *morse = to_morse_string(s);
    print_morse(morse);
    free(morse);
    return 0;
}