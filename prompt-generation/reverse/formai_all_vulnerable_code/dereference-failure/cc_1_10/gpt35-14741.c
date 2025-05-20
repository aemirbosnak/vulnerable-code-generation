//FormAI DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_WORDS 50000

typedef struct dictionary {
    char words[MAX_DICTIONARY_WORDS][MAX_WORD_LENGTH];
    int num_words;
} Dictionary;

typedef struct node {
    char word[MAX_WORD_LENGTH];
    struct node *next;
} Node;

int count_words_in_text(const char *text);
int load_words_into_memory(const char *file_path, char **words);
Dictionary* load_dictionary_into_memory(const char *file_path);
int is_word_misspelled(const char *word, Dictionary* dictionary);
void add_misspelled_word(Node **misspelled_words, const char *word);
void print_misspelled_words(Node *misspelled_words);
void free_memory(Node *misspelled_words, Dictionary *dictionary);

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Usage: %s <dictionary_file_path> <text_file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Dictionary *dictionary = load_dictionary_into_memory(argv[1]);

    char **words = (char **)malloc(MAX_WORD_LENGTH * sizeof(char *));
    if (words == NULL) {
        printf("Could not allocate memory\n");
        exit(EXIT_FAILURE);
    }

    int num_words = load_words_into_memory(argv[2], words);

    Node *misspelled_words = NULL;

    for (int i = 0; i < num_words; i++) {
        if (is_word_misspelled(words[i], dictionary)) {
            add_misspelled_word(&misspelled_words, words[i]);
        }
    }

    print_misspelled_words(misspelled_words);

    free_memory(misspelled_words, dictionary);

    return EXIT_SUCCESS;
}

int count_words_in_text(const char *text) {
    int count = 0;
    int i = 0;

    while (text[i] != '\0') {
        while (!isalpha(text[i]) && text[i] != '\0') {
            i++;
        }

        if (text[i] != '\0') {
            count++;
        }

        while (isalpha(text[i])) {
            i++;
        }
    }

    return count;
}

int load_words_into_memory(const char *file_path, char **words) {
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    int num_words = 0;

    while (fscanf(fp, "%s", word) != EOF) {
        words[num_words] = (char *)malloc(strlen(word) + 1);
        if (words[num_words] == NULL) {
            printf("Could not allocate memory\n");
            exit(EXIT_FAILURE);
        }

        strcpy(words[num_words], word);
        num_words++;
    }

    fclose(fp);

    return num_words;
}

Dictionary* load_dictionary_into_memory(const char *file_path) {
    Dictionary *dictionary = (Dictionary *)malloc(sizeof(Dictionary));
    if (dictionary == NULL) {
        printf("Could not allocate memory\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    int num_words = 0;

    while (fscanf(fp, "%s", word) != EOF) {
        if (num_words < MAX_DICTIONARY_WORDS) {
            strcpy(dictionary->words[num_words], word);
            num_words++;
        }
    }

    dictionary->num_words = num_words;

    fclose(fp);

    return dictionary;
}

int is_word_misspelled(const char *word, Dictionary* dictionary) {
    int i;

    // convert word to lowercase
    char lowercase_word[strlen(word) + 1];
    for (i = 0; word[i] != '\0'; i++) {
        lowercase_word[i] = tolower(word[i]);
    }
    lowercase_word[i] = '\0';

    // check if word is in dictionary
    for (i = 0; i < dictionary->num_words; i++) {
        if (strcmp(lowercase_word, dictionary->words[i]) == 0) {
            return 0;
        }
    }

    return 1;
}

void add_misspelled_word(Node **misspelled_words, const char *word) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Could not allocate memory\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_node->word, word);
    new_node->next = NULL;

    if (*misspelled_words == NULL) {
        *misspelled_words = new_node;
    } else {
        Node *current = *misspelled_words;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_misspelled_words(Node *misspelled_words) {
    if (misspelled_words == NULL) {
        printf("No misspelled words found\n");
    } else {
        printf("Misspelled words found:\n");

        Node *current = misspelled_words;
        while (current != NULL) {
            printf("- %s\n", current->word);
            current = current->next;
        }
    }
}

void free_memory(Node *misspelled_words, Dictionary *dictionary) {
    Node *current = misspelled_words;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(dictionary);
}