//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    int count;
    char **words;
} HashTable;

typedef struct {
    char *word;
    int is_spam;
} Word;

int hash(char *word) {
    int hash_value = 0;
    int i = 0;
    while (word[i]) {
        hash_value += word[i];
        i++;
    }
    return hash_value % MAX_WORD_LENGTH;
}

void create_table(HashTable *table) {
    table->words = (char **)malloc(MAX_WORD_LENGTH * sizeof(char *));
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        table->words[i] = NULL;
    }
}

void add_word(HashTable *table, char *word) {
    int index = hash(word);
    if (table->words[index] == NULL) {
        table->words[index] = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
        strcpy(table->words[index], word);
        table->count++;
    }
}

int is_spam(HashTable *table, char *word) {
    int index = hash(word);
    if (table->words[index] == NULL) {
        return 0;
    }
    if (strcmp(table->words[index], word) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    HashTable table;
    create_table(&table);

    FILE *fp = fopen("spam_words.txt", "r");
    char word[MAX_WORD_LENGTH];
    int count = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        add_word(&table, word);
        count++;
    }
    printf("Loaded %d spam words\n", count);

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a string: ");
        scanf("%s", input);
        int is_spam_input = is_spam(&table, input);
        if (is_spam_input) {
            printf("Spam detected!\n");
        } else {
            printf("No spam detected.\n");
        }
    }
    return 0;
}