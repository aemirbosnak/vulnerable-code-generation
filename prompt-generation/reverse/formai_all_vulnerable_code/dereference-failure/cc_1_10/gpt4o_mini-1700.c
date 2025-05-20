//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS_PER_LINE 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char **words;
    int count;
} WordList;

WordList* create_word_list() {
    WordList *list = (WordList*)malloc(sizeof(WordList));
    list->words = (char**)malloc(MAX_WORDS_PER_LINE * sizeof(char*));
    for (int i = 0; i < MAX_WORDS_PER_LINE; i++) {
        list->words[i] = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
    }
    list->count = 0;
    return list;
}

void free_word_list(WordList *list) {
    for (int i = 0; i < MAX_WORDS_PER_LINE; i++) {
        free(list->words[i]);
    }
    free(list->words);
    free(list);
}

void process_line(char *line, WordList *word_list) {
    char *token = strtok(line, " \t\n");
    while (token != NULL) {
        if (word_list->count < MAX_WORDS_PER_LINE) {
            strcpy(word_list->words[word_list->count], token);
            word_list->count++;
        }
        token = strtok(NULL, " \t\n");
    }
}

void convert_to_uppercase(WordList *word_list) {
    for (int i = 0; i < word_list->count; i++) {
        for (int j = 0; word_list->words[i][j] != '\0'; j++) {
            word_list->words[i][j] = toupper(word_list->words[i][j]);
        }
    }
}

void print_word_list(WordList *word_list) {
    for (int i = 0; i < word_list->count; i++) {
        printf("%s\n", word_list->words[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordList *word_list = create_word_list();
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        process_line(line, word_list);
    }
    
    fclose(file);
    
    convert_to_uppercase(word_list);
    
    printf("Uppercase Words:\n");
    print_word_list(word_list);
    
    free_word_list(word_list);
    
    return EXIT_SUCCESS;
}