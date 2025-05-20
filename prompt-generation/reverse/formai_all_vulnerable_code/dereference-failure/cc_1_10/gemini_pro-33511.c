//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
char *to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
    if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else {
        return "";
    }
}

// Convert a string to Morse code
char *to_morse_string(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5 + 1);
    int i;
    for (i = 0; i < len; i++) {
        strcat(morse_code, to_morse(str[i]));
        strcat(morse_code, " ");
    }
    morse_code[len * 5] = '\0';
    return morse_code;
}

// Print the Morse code for a string
void print_morse(char *str) {
    char *morse_code = to_morse_string(str);
    printf("%s\n", morse_code);
    free(morse_code);
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);
    print_morse(str);
    return 0;
}