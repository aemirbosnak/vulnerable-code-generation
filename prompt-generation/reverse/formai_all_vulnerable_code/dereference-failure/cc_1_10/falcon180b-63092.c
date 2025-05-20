//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define ASCII_ART_MAX_SIZE 10000

char ascii_art[ASCII_ART_MAX_SIZE];
int ascii_art_size = 0;

void add_ascii_art(const char* str) {
    int len = strlen(str);
    if (ascii_art_size + len >= ASCII_ART_MAX_SIZE) {
        printf("Error: ASCII art buffer is full.\n");
        exit(1);
    }
    strcat(ascii_art, str);
    ascii_art_size += len;
}

void generate_ascii_art(const char* text) {
    char line[MAX_LINE_LENGTH];
    int line_length = 0;
    int i = 0;

    while (text[i]) {
        if (line_length >= MAX_LINE_LENGTH) {
            strcat(ascii_art, "\n");
            line_length = 0;
        }
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                strcat(line, "X");
            } else {
                strcat(line, "x");
            }
            line_length++;
        } else if (isspace(text[i])) {
            strcat(line, " ");
            line_length++;
        } else {
            strcat(line, ".");
            line_length++;
        }
        i++;
    }
    strcat(ascii_art, line);
    ascii_art_size += strlen(line);
}

void print_ascii_art() {
    printf("%s", ascii_art);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    const char* text = argv[1];
    generate_ascii_art(text);
    print_ascii_art();

    return 0;
}