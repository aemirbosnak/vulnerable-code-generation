//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a line of text
#define MAX_LINE_LENGTH 1024

// Define the maximum number of lines of text
#define MAX_NUM_LINES 100

// Define the maximum number of words per line
#define MAX_NUM_WORDS 100

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the data structure for a line of text
typedef struct line {
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int num_words;
} line;

// Define the data structure for a collection of lines of text
typedef struct text {
    line lines[MAX_NUM_LINES];
    int num_lines;
} text;

// Read a line of text from the standard input
char *read_line() {
    char *line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        fprintf(stderr, "Error allocating memory for line\n");
        exit(1);
    }
    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading line from standard input\n");
        exit(1);
    }
    return line;
}

// Free the memory allocated for a line of text
void free_line(char *line) {
    free(line);
}

// Read a collection of lines of text from the standard input
text *read_text() {
    text *text = malloc(sizeof(text));
    if (text == NULL) {
        fprintf(stderr, "Error allocating memory for text\n");
        exit(1);
    }
    text->num_lines = 0;
    while (1) {
        char *line = read_line();
        if (strcmp(line, "\n") == 0) {
            free_line(line);
            break;
        }
        strcpy(text->lines[text->num_lines].words[text->lines[text->num_lines].num_words], line);
        text->lines[text->num_lines].num_words++;
        text->num_lines++;
        free_line(line);
    }
    return text;
}

// Free the memory allocated for a collection of lines of text
void free_text(text *text) {
    for (int i = 0; i < text->num_lines; i++) {
        free_line(text->lines[i].words[i]);
    }
    free(text);
}

// Print a line of text to the standard output
void print_line(line *line) {
    for (int i = 0; i < line->num_words; i++) {
        printf("%s ", line->words[i]);
    }
    printf("\n");
}

// Print a collection of lines of text to the standard output
void print_text(text *text) {
    for (int i = 0; i < text->num_lines; i++) {
        print_line(&text->lines[i]);
    }
}

// Main function
int main() {
    // Read a collection of lines of text from the standard input
    text *text = read_text();

    // Print the collection of lines of text to the standard output
    print_text(text);

    // Free the memory allocated for the collection of lines of text
    free_text(text);

    return 0;
}