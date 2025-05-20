//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define the ASCII art alphabet
char *alphabet[] = {
    "  _   _ ",
    " | | | |",
    " | |_| |",
    " |  _  |",
    " |_| |_|"
};

// Define the ASCII art numbers
char *numbers[] = {
    " _ ",
    "| |",
    "|_|"
};

// Define the ASCII art symbols
char *symbols[] = {
    "  ",
    "| ",
    "|_"
};

// Function to convert a character to ASCII art
char *char_to_ascii(char c) {
    if (c >= 'A' && c <= 'Z') {
        return alphabet[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return alphabet[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return numbers[c - '0'];
    } else {
        return symbols[0];
    }
}

// Function to convert a string to ASCII art
char *string_to_ascii(char *str) {
    int len = strlen(str);
    char *ascii = malloc(len * 3 + 1);
    for (int i = 0; i < len; i++) {
        strcat(ascii, char_to_ascii(str[i]));
    }
    return ascii;
}

// Function to print ASCII art
void print_ascii(char *ascii) {
    int len = strlen(ascii);
    for (int i = 0; i < len; i += 3) {
        printf("%s\n", ascii + i);
    }
}

// Main function
int main() {
    char str[] = "Hello World!";
    char *ascii = string_to_ascii(str);
    print_ascii(ascii);
    free(ascii);
    return 0;
}