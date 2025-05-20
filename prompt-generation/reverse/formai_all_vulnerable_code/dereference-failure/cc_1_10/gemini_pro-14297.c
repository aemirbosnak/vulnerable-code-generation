//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
    ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----.", ".-.-.-", "..--..", "...-..-",
    "....--", ".....-", "-....-", "--...--", "---..--", "----..-"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    int i;
    for (i = 0; i < 26; i++) {
        if (c == 'a' + i || c == 'A' + i) {
            return morse_table[i];
        }
    }
    return "";
}

// Convert a string to Morse code
char *string_to_morse(char *s) {
    int i, len = strlen(s);
    char *morse = malloc(len * 5 + 1);  // 5 characters per letter plus spaces
    morse[0] = '\0';
    for (i = 0; i < len; i++) {
        strcat(morse, char_to_morse(s[i]));
        strcat(morse, " ");
    }
    return morse;
}

// Print a string in Morse code
void print_morse(char *s) {
    int i, len = strlen(s);
    for (i = 0; i < len; i++) {
        switch (s[i]) {
            case '.':
                printf("• ");
                break;
            case '-':
                printf("- ");
                break;
            case ' ':
                printf("  ");
                break;
        }
    }
    printf("\n");
}

int main() {
    char *text = "HELLO WORLD";
    char *morse = string_to_morse(text);
    printf("Text: %s\n", text);
    printf("Morse code: %s\n", morse);
    print_morse(morse);
    free(morse);
    return 0;
}