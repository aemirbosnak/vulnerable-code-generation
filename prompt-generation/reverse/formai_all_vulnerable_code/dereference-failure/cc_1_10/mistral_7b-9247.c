//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TABLE_SIZE 1000
#define THRESHOLD 3

typedef struct {
    char *word;
    int count;
} HashTableEntry;

int hash(const char *str, int size) {
    int hash = 0;
    for (int i = 0; str[i]; i++) {
        hash += tolower(str[i]);
    }
    hash %= size;
    return hash;
}

HashTableEntry *create_entry(const char *word) {
    HashTableEntry *entry = malloc(sizeof(HashTableEntry));
    entry->word = strdup(word);
    entry->count = 1;
    return entry;
}

void insert(HashTableEntry **table, const char *word) {
    int index = hash(word, TABLE_SIZE);
    if (table[index]) {
        table[index]->count++;
    } else {
        table[index] = create_entry(word);
    }
}

void print_table(HashTableEntry **table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i]) {
            printf("Index %d: %s -> %d\n", i, table[i]->word, table[i]->count);
        }
    }
}

int main() {
    HashTableEntry *table[TABLE_SIZE] = {0};
    char email[1024];
    char *token;

    // Prepopulate the hash table with common spam words
    insert(table, "free");
    insert(table, "money");
    insert(table, "offer");
    insert(table, "viagra");
    insert(table, "prize");
    insert(table, "winning");
    insert(table, "claim");
    insert(table, "discount");
    insert(table, "offer");
    insert(table, "buy");
    insert(table, "sale");
    insert(table, "deal");

    printf("Enter the email content:\n");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    token = strtok(email, " ");
    while (token) {
        insert(table, token);
        token = strtok(NULL, " ");
    }

    printf("\nWord count table:\n");
    print_table(table);

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] && table[i]->count > THRESHOLD) {
            printf("\nSPAM DETECTED! Word '%s' occurs %d times in the email.\n", table[i]->word, table[i]->count);
            break;
        }
    }

    return 0;
}