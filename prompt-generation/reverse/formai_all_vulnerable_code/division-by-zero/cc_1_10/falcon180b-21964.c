//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define MAX_TEXT_LENGTH 1000

typedef struct {
    char *text;
    int length;
} Text;

void generate_ascii_art(Text *text) {
    int i, j, k;
    char *line;
    int line_length;
    int num_chars = 0;
    int num_lines = 0;
    int max_line_length = 0;

    // Count the number of characters and lines in the text
    for (i = 0; i < text->length; i++) {
        if (text->text[i] == '\n') {
            num_lines++;
        }
        num_chars++;
    }

    // Calculate the maximum line length
    max_line_length = MAX_LINE_LENGTH / num_lines;

    // Allocate memory for the ASCII art
    line = malloc(MAX_LINE_LENGTH * sizeof(char));

    // Generate the ASCII art
    for (i = 0; i < num_lines; i++) {
        line_length = 0;
        for (j = i * max_line_length; j < (i + 1) * max_line_length && j < text->length; j++) {
            if (text->text[j] == '\n') {
                break;
            }
            if (isalpha(text->text[j])) {
                line[line_length++] = toupper(text->text[j]);
            }
        }
        line[line_length] = '\0';
        printf("%s\n", line);
    }

    free(line);
}

int main() {
    Text text;
    char input[MAX_TEXT_LENGTH];

    // Get user input
    printf("Enter some text: ");
    fgets(input, MAX_TEXT_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Copy input to text structure
    text.text = strdup(input);
    text.length = strlen(text.text);

    // Generate ASCII art
    generate_ascii_art(&text);

    return 0;
}