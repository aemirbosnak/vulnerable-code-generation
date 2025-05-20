//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry {
    char *word;
    int count;
} entry;

typedef struct node {
    entry *e;
    struct node *next;
} node;

typedef struct hash_table {
    node **table;
    int size;
} hash_table;

hash_table *create_hash_table(int size) {
    hash_table *ht = malloc(sizeof(hash_table));
    ht->table = malloc(sizeof(node *) * size);
    ht->size = size;
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void free_hash_table(hash_table *ht) {
    for (int i = 0; i < ht->size; i++) {
        node *n = ht->table[i];
        while (n) {
            node *next = n->next;
            free(n->e->word);
            free(n->e);
            free(n);
            n = next;
        }
    }
    free(ht->table);
    free(ht);
}

int hash(char *word, int size) {
    int h = 0;
    for (int i = 0; word[i]; i++) {
        h += word[i];
    }
    return h % size;
}

void insert(hash_table *ht, char *word) {
    int h = hash(word, ht->size);
    node *n = ht->table[h];
    while (n) {
        if (!strcmp(n->e->word, word)) {
            n->e->count++;
            return;
        }
        n = n->next;
    }
    entry *e = malloc(sizeof(entry));
    e->word = malloc(strlen(word) + 1);
    strcpy(e->word, word);
    e->count = 1;
    node *new = malloc(sizeof(node));
    new->e = e;
    new->next = ht->table[h];
    ht->table[h] = new;
}

int is_spam(hash_table *ht, char *message) {
    char *words[100];
    int nwords = 0;
    char *p = strtok(message, " ");
    while (p) {
        words[nwords++] = p;
        p = strtok(NULL, " ");
    }
    int spam = 0;
    for (int i = 0; i < nwords; i++) {
        node *n = ht->table[hash(words[i], ht->size)];
        while (n) {
            if (!strcmp(n->e->word, words[i])) {
                if (n->e->count > 1) {
                    spam = 1;
                }
                break;
            }
            n = n->next;
        }
    }
    return spam;
}

int main() {
    hash_table *ht = create_hash_table(100);
    insert(ht, "free");
    insert(ht, "money");
    insert(ht, "now");
    insert(ht, "click");
    insert(ht, "here");
    insert(ht, "offer");
    insert(ht, "cash");
    char message[100];
    while (fgets(message, sizeof(message), stdin)) {
        if (is_spam(ht, message)) {
            printf("This message is spam.\n");
        } else {
            printf("This message is not spam.\n");
        }
    }
    free_hash_table(ht);
    return 0;
}