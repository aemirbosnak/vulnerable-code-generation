//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to ASCII art
char *char_to_ascii(char c) {
    char *art[] = {
        "  __  __ ",
        " |  \/  | ",
        " | \  / | ",
        " | |\/| | ",
        " |_|  |_| ",
        "          "
    };

    switch (c) {
        case 'A': return art[0];
        case 'B': return art[1];
        case 'C': return art[2];
        case 'D': return art[3];
        case 'E': return art[4];
        case 'F': return art[5];
        default: return NULL;
    }
}

// Function to convert a string to ASCII art
char **string_to_ascii(char *str) {
    char **art = malloc(strlen(str) * sizeof(char *));
    for (int i = 0; i < strlen(str); i++) {
        art[i] = char_to_ascii(str[i]);
    }
    return art;
}

// Function to print ASCII art
void print_art(char **art) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < strlen(art); j++) {
            printf("%s ", art[j][i]);
        }
        printf("\n");
    }
}

int main() {
    char *str = "ASCII";
    char **art = string_to_ascii(str);
    print_art(art);
    return 0;
}