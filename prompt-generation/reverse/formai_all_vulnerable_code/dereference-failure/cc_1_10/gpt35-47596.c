//FormAI DATASET v1.0 Category: Spell checking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILE "dictionary.txt"

struct dict_node {
    char word[MAX_WORD_LENGTH];
    struct dict_node *next_node;
};

typedef struct dict_node *dict_ptr;

int is_word_char(char c);
void read_dict_file(dict_ptr *dict);
void insert_word(char *word, dict_ptr *dict);
int check_word(char *word, dict_ptr dict);

int main() {
    dict_ptr dict = NULL;
    char input[MAX_WORD_LENGTH];
    int line_num = 1;

    read_dict_file(&dict);
    printf("Enter text (type 'exit' to quit):\n");

    while (1) {
        printf("%d. ", line_num);
        fgets(input, MAX_WORD_LENGTH, stdin);

        if (!strcmp(input, "exit\n")) {
            break;
        }

        char *word_start = input;
        for (int i = 0; i < strlen(input); i++) {
            if (!is_word_char(input[i]) || i == strlen(input) - 1) {
                if (i == strlen(input) - 1 && is_word_char(input[i])) {
                    i++;
                }

                int word_len = i - (word_start - input);

                if (word_len > 0) {
                    char word[MAX_WORD_LENGTH];
                    strncpy(word, word_start, word_len);
                    word[word_len] = '\0';

                    for (int j = 0; j < strlen(word); j++) {
                        word[j] = tolower(word[j]);
                    }

                    if (!check_word(word, dict)) {
                        printf("Unknown word '%s'\n", word);
                    }
                }

                word_start = &input[i + 1];
            }
        }

        line_num++;
    }

    return 0;
}

int is_word_char(char c) {
    return (isalpha(c) || c == '-');
}

void read_dict_file(dict_ptr *dict) {
    FILE *fp;
    char word[MAX_WORD_LENGTH];

    fp = fopen(DICTIONARY_FILE, "r");

    if (fp == NULL) {
        printf("Error opening dictionary file '%s'\n", DICTIONARY_FILE);
        exit(1);
    }

    while (fgets(word, MAX_WORD_LENGTH, fp)) {
        char *newline_pos = strchr(word, '\n');
        if (newline_pos) {
            *newline_pos = '\0';
        }

        insert_word(word, dict);
    }

    fclose(fp);
}

void insert_word(char *word, dict_ptr *dict) {
    dict_ptr new_node = (dict_ptr) malloc(sizeof(struct dict_node));
    if (new_node == NULL) {
        printf("Error allocating memory for new dictionary node\n");
        exit(1);
    }

    strncpy(new_node->word, word, MAX_WORD_LENGTH);
    new_node->next_node = *dict;
    *dict = new_node;
}

int check_word(char *word, dict_ptr dict) {
    dict_ptr current_node = dict;

    while (current_node != NULL) {
        if (!strcmp(current_node->word, word)) {
            return 1;
        }

        current_node = current_node->next_node;
    }

    return 0;
}