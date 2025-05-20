//FormAI DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 1000
#define MAX_MISSPELLED_WORDS 1000

typedef struct node {
    char word[MAX_WORD_LENGTH + 1];
    struct node *next;
} node;

int get_word(char *buf, int buf_size, FILE *infile) {
    int pos = 0;
    char c;
    while ((c = getc(infile)) != EOF) {
        if (isalpha(c))
            break;
    }
    if (c == EOF)
        return 0;
    buf[pos++] = tolower(c);
    while (pos < buf_size - 1 && (c = getc(infile)) != EOF && isalpha(c))
        buf[pos++] = tolower(c);

    buf[pos] = '\0';
    return pos;
}

void load_dictionary(const char *filename, node **hash_table) {
    FILE *infile = fopen(filename, "r");
    char word[MAX_WORD_LENGTH + 1];
    int hash_index;
    node *new_node;

    while (get_word(word, MAX_WORD_LENGTH + 1, infile)) {
        new_node = malloc(sizeof(node));
        if (new_node == NULL) {
            fprintf(stderr, "Error: malloc failed in load_dictionary.\n");
            exit(EXIT_FAILURE);
        }
        strcpy(new_node->word, word);
        hash_index = hash(word);
        new_node->next = hash_table[hash_index];
        hash_table[hash_index] = new_node;
    }
    fclose(infile);
}

void check_words(const char *filename, node **hash_table, char **misspelled) {
    FILE *infile = fopen(filename, "r");
    char word[MAX_WORD_LENGTH + 1];
    int index = 0, misspelled_index = 0;
    node *temp;
    while (get_word(word, MAX_WORD_LENGTH + 1, infile)) {
        if (!check_word(word, hash_table)) {
            strcpy(misspelled[misspelled_index], word);
            misspelled_index++;
        }
        index++;
    }
    misspelled[misspelled_index] = NULL;
    fclose(infile);
}

void free_memory(node **hash_table, char **misspelled) {
    int i;
    node *temp, *current;
    for (i = 0; i < MAX_DICTIONARY_SIZE; i++) {
        current = hash_table[i];
        while (current != NULL) {
            temp = current;
            current = current->next;
            free(temp);
        }
    }
    for (i = 0; i < MAX_MISSPELLED_WORDS; i++) {
        if (misspelled[i] != NULL)
            free(misspelled[i]);
    }
}

int main(int argc, char **argv) {
    node *hash_table[MAX_DICTIONARY_SIZE] = { NULL };
    char *misspelled[MAX_MISSPELLED_WORDS] = { NULL };
    int misspelled_index = 0;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary-file> <input-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_dictionary(argv[1], hash_table);
    check_words(argv[2], hash_table, misspelled);

    printf("Misspelled words:\n");
    while (misspelled[misspelled_index] != NULL) {
        printf("%s\n", misspelled[misspelled_index]);
        misspelled_index++;
    }

    free_memory(hash_table, misspelled);

    return EXIT_SUCCESS;
}

int hash(const char *word) {
    int hash_index = 0, i = 0;
    while (word[i] != '\0') {
        hash_index += tolower(word[i]);
        i++;
    }
    return hash_index % MAX_DICTIONARY_SIZE;
}

int check_word(const char *word, node **hash_table) {
    int hash_index = hash(word);
    node *current = hash_table[hash_index];
    while (current != NULL) {
        if (strcmp(word, current->word) == 0)
            return 1;
        current = current->next;
    }
    return 0;
}