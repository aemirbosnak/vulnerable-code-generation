//GEMINI-pro DATASET v1.0 Category: File handling ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a line in the file.
#define MAX_LINE_SIZE 1024

// Define the maximum number of lines in the file.
#define MAX_LINES 1000

// Define the maximum number of characters in a word.
#define MAX_WORD_SIZE 100

// Define the maximum number of words in a line.
#define MAX_WORDS_PER_LINE 100

// Define the structure of a word.
typedef struct word {
    char *string;
    int length;
} word_t;

// Define the structure of a line.
typedef struct line {
    word_t *words;
    int num_words;
} line_t;

// Define the structure of a file.
typedef struct file {
    line_t *lines;
    int num_lines;
} file_t;

// Create a new file.
file_t *new_file() {
    file_t *file = malloc(sizeof(file_t));
    file->lines = NULL;
    file->num_lines = 0;
    return file;
}

// Add a new line to a file.
void add_line(file_t *file, line_t *line) {
    file->lines = realloc(file->lines, (file->num_lines + 1) * sizeof(line_t));
    file->lines[file->num_lines] = *line;
    file->num_lines++;
}

// Create a new line.
line_t *new_line() {
    line_t *line = malloc(sizeof(line_t));
    line->words = NULL;
    line->num_words = 0;
    return line;
}

// Add a new word to a line.
void add_word(line_t *line, word_t *word) {
    line->words = realloc(line->words, (line->num_words + 1) * sizeof(word_t));
    line->words[line->num_words] = *word;
    line->num_words++;
}

// Create a new word.
word_t *new_word(char *string, int length) {
    word_t *word = malloc(sizeof(word_t));
    word->string = malloc(length + 1);
    memcpy(word->string, string, length);
    word->string[length] = '\0';
    word->length = length;
    return word;
}

// Read a file from disk.
file_t *read_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    file_t *file = new_file();

    char line_buffer[MAX_LINE_SIZE];
    while (fgets(line_buffer, MAX_LINE_SIZE, fp) != NULL) {
        line_t *line = new_line();

        char *word_buffer = strtok(line_buffer, " ");
        while (word_buffer != NULL) {
            int length = strlen(word_buffer);
            word_t *word = new_word(word_buffer, length);
            add_word(line, word);
            word_buffer = strtok(NULL, " ");
        }

        add_line(file, line);
    }

    fclose(fp);

    return file;
}

// Write a file to disk.
void write_file(file_t *file, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    for (int i = 0; i < file->num_lines; i++) {
        line_t *line = &file->lines[i];
        for (int j = 0; j < line->num_words; j++) {
            word_t *word = &line->words[j];
            fprintf(fp, "%s ", word->string);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Free the memory allocated for a file.
void free_file(file_t *file) {
    for (int i = 0; i < file->num_lines; i++) {
        line_t *line = &file->lines[i];
        for (int j = 0; j < line->num_words; j++) {
            word_t *word = &line->words[j];
            free(word->string);
            free(word);
        }
        free(line->words);
        free(line);
    }
    free(file->lines);
    free(file);
}

// Print a file to the console.
void print_file(file_t *file) {
    for (int i = 0; i < file->num_lines; i++) {
        line_t *line = &file->lines[i];
        for (int j = 0; j < line->num_words; j++) {
            word_t *word = &line->words[j];
            printf("%s ", word->string);
        }
        printf("\n");
    }
}

// Get the number of lines in a file.
int get_num_lines(file_t *file) {
    return file->num_lines;
}

// Get the number of words in a line.
int get_num_words(line_t *line) {
    return line->num_words;
}

// Get the length of a word.
int get_word_length(word_t *word) {
    return word->length;
}

// Get the string of a word.
char *get_word_string(word_t *word) {
    return word->string;
}

// Get the line at a given index.
line_t *get_line(file_t *file, int index) {
    return &file->lines[index];
}

// Get the word at a given index in a line.
word_t *get_word(line_t *line, int index) {
    return &line->words[index];
}

// Main function.
int main() {
    // Create a new file.
    file_t *file = new_file();

    // Add some lines to the file.
    line_t *line1 = new_line();
    add_word(line1, new_word("Hello", 5));
    add_word(line1, new_word("world", 5));
    add_line(file, line1);

    line_t *line2 = new_line();
    add_word(line2, new_word("This", 4));
    add_word(line2, new_word("is", 2));
    add_word(line2, new_word("a", 1));
    add_word(line2, new_word("test", 4));
    add_line(file, line2);

    // Print the file to the console.
    print_file(file);

    // Free the memory allocated for the file.
    free_file(file);

    return 0;
}