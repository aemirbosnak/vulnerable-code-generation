//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

struct node {
    char word[MAX_WORD_LEN];
    struct node *next;
};

struct dictionary {
    struct node *head;
    int size;
};

struct dictionary *dictionary_new() {
    struct dictionary *dict = malloc(sizeof(struct dictionary));
    dict->head = NULL;
    dict->size = 0;
    return dict;
}

void dictionary_free(struct dictionary *dict) {
    struct node *current = dict->head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;
    }
    free(dict);
}

int dictionary_add(struct dictionary *dict, char *word) {
    struct node *new_node = malloc(sizeof(struct node));
    strcpy(new_node->word, word);
    new_node->next = dict->head;
    dict->head = new_node;
    dict->size++;
    return 0;
}

int dictionary_load(struct dictionary *dict, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }
    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, file) != NULL) {
        line[strcspn(line, "\n")] = 0;
        dictionary_add(dict, line);
    }
    fclose(file);
    return 0;
}

int dictionary_save(struct dictionary *dict, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return -1;
    }
    struct node *current = dict->head;
    while (current != NULL) {
        fprintf(file, "%s\n", current->word);
        current = current->next;
    }
    fclose(file);
    return 0;
}

int dictionary_check(struct dictionary *dict, char *word) {
    struct node *current = dict->head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void spell_check(char *filename) {
    struct dictionary *dict = dictionary_new();
    dictionary_load(dict, "dictionary.txt");

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    char line[1024];
    while (fgets(line, 1024, file) != NULL) {
        char *word = strtok(line, " ");
        while (word != NULL) {
            if (!dictionary_check(dict, word)) {
                printf("%s is not in the dictionary\n", word);
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(file);
    dictionary_free(dict);
}

int main() {
    spell_check("text.txt");
    return 0;
}