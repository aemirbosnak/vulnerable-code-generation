//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Donald Knuth
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// A node in the word list
typedef struct WordNode {
    char *word;
    int count;
    struct WordNode *next;
} WordNode;

// A list of words
typedef struct WordList {
    WordNode *head;
    WordNode *tail;
} WordList;

// Create a new word list
WordList *new_word_list() {
    WordList *list = malloc(sizeof(WordList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Add a word to the word list
void add_word(WordList *list, char *word) {
    // Create a new node
    WordNode *node = malloc(sizeof(WordNode));
    node->word = strdup(word);
    node->count = 1;
    node->next = NULL;

    // Add the node to the list
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

// Print the word list
void print_word_list(WordList *list) {
    WordNode *node = list->head;
    while (node != NULL) {
        printf("%s: %d\n", node->word, node->count);
        node = node->next;
    }
}

// Free the word list
void free_word_list(WordList *list) {
    WordNode *node = list->head;
    while (node != NULL) {
        WordNode *next = node->next;
        free(node->word);
        free(node);
        node = next;
    }
    free(list);
}

// Read a line of text from the given file
char *read_line(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, file);
    return line;
}

// Tokenize the given line of text
char **tokenize(char *line) {
    char **tokens = malloc(MAX_LINE_LENGTH * sizeof(char *));
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return tokens;
}

// Count the words in the given file
WordList *count_words(FILE *file) {
    WordList *list = new_word_list();

    char *line;
    while ((line = read_line(file)) != NULL) {
        char **tokens = tokenize(line);
        for (int i = 0; tokens[i] != NULL; i++) {
            char *token = tokens[i];
            for (int j = 0; token[j] != '\0'; j++) {
                token[j] = tolower(token[j]);
            }
            add_word(list, token);
        }
        free(tokens);
        free(line);
    }

    return list;
}

// Summarize the given text
void summarize_text(FILE *file, int num_words) {
    WordList *list = count_words(file);

    // Sort the word list by count
    WordNode *node = list->head;
    while (node != NULL) {
        WordNode *next = node->next;
        while (next != NULL) {
            if (node->count < next->count) {
                char *temp = node->word;
                int temp_count = node->count;
                node->word = next->word;
                node->count = next->count;
                next->word = temp;
                next->count = temp_count;
            }
            next = next->next;
        }
        node = node->next;
    }

    // Print the top num_words words
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", list->head->word, list->head->count);
        list->head = list->head->next;
    }

    free_word_list(list);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <filename> <num_words>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    int num_words = atoi(argv[2]);

    summarize_text(file, num_words);

    fclose(file);

    return EXIT_SUCCESS;
}