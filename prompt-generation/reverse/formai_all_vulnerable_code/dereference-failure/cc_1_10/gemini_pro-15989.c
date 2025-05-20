//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "---.", "----", ".-.-.-",
    "--..--", "...---...", "---...", "..--..", ".-.-.-.", "-....-", "--...--",
    "-.-.--", "-..-.--", ".-..-.--", "-.--.--.", "-....---", "-.-.--.--",
    "--..--.--", "---...---..."
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    int index = (int)c - (int)'A';
    if (index >= 0 && index < 26) {
        return morse_code[index];
    } else {
        return NULL;
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse = malloc(len * 5);
    for (int i = 0; i < len; i++) {
        char *morse_char = char_to_morse(str[i]);
        if (morse_char == NULL) {
            morse_char = "";
        }
        strcat(morse, morse_char);
        if (i != len - 1) {
            strcat(morse, " ");
        }
    }
    return morse;
}

// Print the Morse code for a string
void print_morse(char *str) {
    char *morse = string_to_morse(str);
    printf("%s\n", morse);
    free(morse);
}

int main() {
    char *str = "HELLO WORLD";
    print_morse(str);
    return 0;
}