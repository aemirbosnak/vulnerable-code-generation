//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/* Morse code table */
const char morse_table[][3] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

/* Morse code output string */
char morse_code[1024] = {0};

/* Length of user input */
int length;

/* User input string */
char input[1024] = {0};

/* Read user input from standard input */
void get_input() {
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
}

/* Print Morse code representation of a single character */
void print_morse(char c) {
    if (isalpha(c)) {
        int index = c - 'A';
        strcat(morse_code, morse_table[index]);
        strcat(morse_code, " ");
    } else if (isdigit(c)) {
        int digit = c - '0';
        strcat(morse_code, morse_table[digit + 26]);
        strcat(morse_code, " ");
    } else if (c == ' ') {
        strcat(morse_code, "/");
        strcat(morse_code, " ");
    } else {
        printf("Invalid character: %c\n", c);
        exit(1);
    }
}

/* Convert a string to Morse code */
void convert_morse() {
    length = strlen(input);
    for (int i = 0; i < length; i++) {
        print_morse(input[i]);
    }
    printf("\n%s\n", morse_code);
}

int main() {
    printf("Enter text to convert to Morse code: ");
    get_input();
    convert_morse();
    return 0;
}