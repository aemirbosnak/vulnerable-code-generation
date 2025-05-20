//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.-",
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-",
    "--..--", "..--.."
};

// Define the alphabet table
char *alphabet_table[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R",
    "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
};

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    int i;
    for (i = 0; i < 26; i++) {
        if (c == alphabet_table[i][0]) {
            return morse_table[i];
        }
    }
    for (i = 26; i < 36; i++) {
        if (c == alphabet_table[i][0]) {
            return morse_table[i];
        }
    }
    return " ";
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    int i, len;
    char *morse_code;

    len = strlen(str);
    morse_code = malloc(len * 5 + 1);

    for (i = 0; i < len; i++) {
        strcat(morse_code, char_to_morse(str[i]));
        strcat(morse_code, " ");
    }

    morse_code[strlen(morse_code) - 1] = '\0';
    return morse_code;
}

// Function to print the Morse code
void print_morse_code(char *morse_code) {
    int i;
    for (i = 0; i < strlen(morse_code); i++) {
        if (morse_code[i] == ' ') {
            printf(" ");
        } else if (morse_code[i] == '.') {
            printf("dit ");
        } else if (morse_code[i] == '-') {
            printf("dah ");
        }
    }
    printf("\n");
}

// Main function
int main() {
    char *str;

    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);
    if (strcmp(str, "Batman") == 0) {
        printf("The Batsignal!\n");
    }
    char *morse_code = string_to_morse(str);
    printf("The Morse code is: %s\n", morse_code);
    print_morse_code(morse_code);
    return 0;
}