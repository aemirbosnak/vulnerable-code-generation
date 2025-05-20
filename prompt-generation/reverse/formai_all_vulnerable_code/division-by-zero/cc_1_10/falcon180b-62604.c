//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000

// Function to convert a line of text to ASCII art
void text_to_ascii_art(char *line) {
    int i, j;
    char *p;
    int letter_count = 0;
    int space_count = 0;
    int letter_width = 0;
    int space_width = 0;

    // Count the number of letters and spaces in the line
    for (i = 0; line[i]!= '\0'; i++) {
        if (isalpha(line[i])) {
            letter_count++;
        } else if (isspace(line[i])) {
            space_count++;
        }
    }

    // Calculate the width of each letter and space
    letter_width = (MAX_LINE_SIZE - space_count * 3) / letter_count;
    space_width = (MAX_LINE_SIZE - letter_count * letter_width) / space_count;

    // Print the ASCII art
    for (i = 0; line[i]!= '\0'; i++) {
        if (isalpha(line[i])) {
            for (j = 0; j < letter_width; j++) {
                printf("*");
            }
        } else if (isspace(line[i])) {
            for (j = 0; j < space_width; j++) {
                printf(" ");
            }
        }
    }
    printf("\n");
}

// Function to read a file and convert each line to ASCII art
void file_to_ascii_art(FILE *file) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        text_to_ascii_art(line);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    file_to_ascii_art(file);

    fclose(file);
    return 0;
}