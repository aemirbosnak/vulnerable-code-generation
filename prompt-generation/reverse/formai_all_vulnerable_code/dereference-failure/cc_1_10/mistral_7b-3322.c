//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <signal.h>

#define MAX_INPUT_LENGTH 1024
#define MORSE_CODE_SIZE 64

// Morse code dictionary
const char *morse_code[] = {
    ".-", "--.", "-...", "-.-.", "-..", ".", "..-.", "--", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...",
    "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Function to print Morse code symbol
void print_morse_symbol(const char *symbol) {
    int len = strlen(symbol);
    for (int i = 0; i < len; i++) {
        printf("%c", symbol[i]);
        usleep(500000);
    }
    printf(" ");
}

// Function to print Morse code for a character
void print_morse_char(char c) {
    if (isalpha(c)) {
        print_morse_symbol(morse_code[c - 'A']);
    } else if (isdigit(c)) {
        int num = c - '0';
        print_morse_symbol(morse_code['A' + (num / 10)]);
        print_morse_symbol(morse_code['A' + (num % 10)]);
    } else if (c == ' ') {
        usleep(700000);
        printf("/");
        usleep(700000);
    } else if (c == '\n') {
        printf("\n");
    } else {
        printf("_%c_", c);
    }
}

// Function to convert text to Morse code and print it
void text_to_morse(const char *text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        print_morse_char(text[i]);
    }
}

// Function to handle SIGINT signal and stop Morse code generation
void handle_signal(int sig) {
    printf("\nMorseMagus: Interrupted. Exiting...\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        exit(1);
    }

    signal(SIGINT, handle_signal);

    const char *text = argv[1];
    printf("Text: %s\n", text);

    int len = strlen(text);
    printf("MorseMagus starting conversion...\n");

    // Print start signal
    printf("---\n");

    text_to_morse(text);

    // Print end signal
    printf("---");

    return 0;
}