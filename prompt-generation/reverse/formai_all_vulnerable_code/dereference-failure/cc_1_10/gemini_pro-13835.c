//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a line of text
#define MAX_LINE_LENGTH 1024

// Define the maximum number of lines of text
#define MAX_LINES 100

// Define the maximum number of characters in a word
#define MAX_WORD_LENGTH 32

// Define the structure of a word
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} word_t;

// Define the structure of a line of text
typedef struct {
    char line[MAX_LINE_LENGTH];
    int word_count;
    word_t words[MAX_LINES];
} line_t;

// Define the structure of a text
typedef struct {
    int line_count;
    line_t lines[MAX_LINES];
} text_t;

// Create a new text
text_t *new_text() {
    text_t *text = malloc(sizeof(text_t));
    text->line_count = 0;
    return text;
}

// Add a line of text to a text
void add_line(text_t *text, char *line) {
    strcpy(text->lines[text->line_count].line, line);
    text->lines[text->line_count].word_count = 0;
    text->line_count++;
}

// Add a word to a line of text
void add_word(text_t *text, int line_index, char *word) {
    strcpy(text->lines[line_index].words[text->lines[line_index].word_count].word, word);
    text->lines[line_index].words[text->lines[line_index].word_count].count = 1;
    text->lines[line_index].word_count++;
}

// Sort the words in a line of text
void sort_words(text_t *text, int line_index) {
    int i, j;
    for (i = 0; i < text->lines[line_index].word_count - 1; i++) {
        for (j = 0; j < text->lines[line_index].word_count - i - 1; j++) {
            if (strcmp(text->lines[line_index].words[j].word, text->lines[line_index].words[j + 1].word) > 0) {
                word_t temp = text->lines[line_index].words[j];
                text->lines[line_index].words[j] = text->lines[line_index].words[j + 1];
                text->lines[line_index].words[j + 1] = temp;
            }
        }
    }
}

// Print a text
void print_text(text_t *text) {
    int i, j;
    for (i = 0; i < text->line_count; i++) {
        printf("%s\n", text->lines[i].line);
        for (j = 0; j < text->lines[i].word_count; j++) {
            printf("\t%s (%d)\n", text->lines[i].words[j].word, text->lines[i].words[j].count);
        }
    }
}

// Free the memory allocated for a text
void free_text(text_t *text) {
    free(text);
}

// Main function
int main() {
    // Create a new text
    text_t *text = new_text();

    // Add some lines of text to the text
    add_line(text, "This is a test");
    add_line(text, "This is another test");
    add_line(text, "This is yet another test");

    // Add some words to the lines of text
    add_word(text, 0, "This");
    add_word(text, 0, "is");
    add_word(text, 0, "a");
    add_word(text, 0, "test");
    add_word(text, 1, "This");
    add_word(text, 1, "is");
    add_word(text, 1, "another");
    add_word(text, 1, "test");
    add_word(text, 2, "This");
    add_word(text, 2, "is");
    add_word(text, 2, "yet");
    add_word(text, 2, "another");
    add_word(text, 2, "test");

    // Sort the words in each line of text
    sort_words(text, 0);
    sort_words(text, 1);
    sort_words(text, 2);

    // Print the text
    print_text(text);

    // Free the memory allocated for the text
    free_text(text);

    return 0;
}