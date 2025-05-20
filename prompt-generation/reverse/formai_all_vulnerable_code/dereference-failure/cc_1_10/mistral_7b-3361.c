//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} HashEntry;

unsigned long hash(char *str, int size) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % size;
}

void add_word(HashEntry **table, char *word) {
    unsigned long index = hash(word, TABLE_SIZE);

    if (!table[index]) {
        table[index] = malloc(sizeof(HashEntry));
        strcpy(table[index]->word, word);
        table[index]->count = 1;
    } else {
        table[index]->count++;
    }
}

int check_message(HashEntry **table, char *message, int length) {
    int i, result = 0;

    for (i = 0; i < TABLE_SIZE; i++) {
        if (table[i]) {
            if (strncmp(table[i]->word, message, strlen(message)) == 0 && table[i]->count > 10) {
                printf("Spam detected: %s\n", message);
                result = 1;
                break;
            }
        }
    }

    return result;
}

int main() {
    HashEntry *table[TABLE_SIZE] = {0};
    char message[100];
    int i, length;

    add_word(&table, "Viagra");
    add_word(&table, "Cialis");
    add_word(&table, "Levitra");
    add_word(&table, "Male enhancement");

    while (1) {
        printf("Enter a message: ");
        fgets(message, sizeof(message), stdin);
        message[strlen(message) - 1] = '\0';

        length = strlen(message);
        check_message(table, message, length);

        if (strchr(message, '\n')) {
            message[strcspn(message, "\n")] = '\0';
        }
    }

    return 0;
}