//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char **words;
    int count;
} WordList;

void initialize_word_list(WordList *word_list) {
    word_list->words = (char **)malloc(MAX_WORDS * sizeof(char *));
    for (int i = 0; i < MAX_WORDS; i++) {
        word_list->words[i] = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
    }
    word_list->count = 0;
}

void free_word_list(WordList *word_list) {
    for (int i = 0; i < word_list->count; i++) {
        free(word_list->words[i]);
    }
    free(word_list->words);
}

void print_word_list(WordList *word_list) {
    printf("Words in the text:\n");
    for (int i = 0; i < word_list->count; i++) {
        printf("%s\n", word_list->words[i]);
    }
}

int is_word_in_list(WordList *word_list, const char *word) {
    for (int i = 0; i < word_list->count; i++) {
        if (strcmp(word_list->words[i], word) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

void add_word_to_list(WordList *word_list, const char *word) {
    if (!is_word_in_list(word_list, word)) {
        strcpy(word_list->words[word_list->count], word);
        word_list->count++;
    }
}

void process_line(const char *line, WordList *word_list) {
    char *token;
    char *line_copy = strdup(line);
    
    token = strtok(line_copy, " \n\t");
    while (token != NULL) {
        add_word_to_list(word_list, token);
        token = strtok(NULL, " \n\t");
    }
    free(line_copy);
}

void read_file(const char *filename, WordList *word_list) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        process_line(line, word_list);
    }
    
    fclose(file);
}

void write_word_count(const char *filename, WordList *word_list) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < word_list->count; i++) {
        fprintf(file, "%s: %d\n", word_list->words[i], 1); // For simplicity, counting occurrences
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    WordList word_list;
    initialize_word_list(&word_list);
    
    read_file(argv[1], &word_list);
    print_word_list(&word_list);
    write_word_count(argv[2], &word_list);
    
    free_word_list(&word_list);
    return EXIT_SUCCESS;
}