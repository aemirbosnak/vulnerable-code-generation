//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_SIZE 64

typedef struct HashEntry {
    char *key;
    int value;
    struct HashEntry *next;
} HashEntry;

HashEntry *hash_insert(HashEntry *head, char *key, int value) {
    HashEntry *new_entry = malloc(sizeof(HashEntry));
    new_entry->key = strdup(key);
    new_entry->value = value;
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        HashEntry *prev = NULL;
        HashEntry *curr = head;
        while (curr) {
            if (strcmp(curr->key, key) == 0) {
                prev = curr;
                curr = curr->next;
            }
            prev = curr;
            curr = curr->next;
        }

        if (prev) {
            prev->next = new_entry;
        } else {
            head = new_entry;
        }
    }

    return head;
}

int main() {
    HashEntry *head = NULL;
    head = hash_insert(head, "abc", 10);
    head = hash_insert(head, "def", 20);
    head = hash_insert(head, "ghi", 30);

    HashEntry *curr = head;
    while (curr) {
        printf("%s: %d\n", curr->key, curr->value);
        curr = curr->next;
    }

    return 0;
}