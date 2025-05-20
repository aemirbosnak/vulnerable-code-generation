//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: real-life
#include <stdio.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
    "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        c += 32;
    }
    return morse_table[c - 'a'];
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5);
    int i;
    for (i = 0; i < len; i++) {
        strcat(morse_code, char_to_morse(str[i]));
        strcat(morse_code, " ");
    }
    return morse_code;
}

// Function to print a string in Morse code
void print_morse_code(char *morse_code) {
    int len = strlen(morse_code);
    int i;
    for (i = 0; i < len; i++) {
        if (morse_code[i] == '.') {
            printf("·");
        } else if (morse_code[i] == '-') {
            printf("—");
        } else {
            printf(" ");
        }
    }
}

int main() {
    // Get the input string
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code
    printf("Morse code: ");
    print_morse_code(morse_code);

    return 0;
}