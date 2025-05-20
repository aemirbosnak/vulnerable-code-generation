//Falcon2-11B DATASET v1.0 Category: Cryptographic hash function ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HASH_SIZE 1024

typedef struct hash_entry {
    char data[MAX_HASH_SIZE];
    struct hash_entry *next;
} HashEntry;

HashEntry *head = NULL;

void insert(char *data) {
    HashEntry *new_entry = (HashEntry *) malloc(sizeof(HashEntry));
    strcpy(new_entry->data, data);
    new_entry->next = NULL;
    if (head == NULL) {
        head = new_entry;
    } else {
        HashEntry *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_entry;
    }
}

void print_hash() {
    HashEntry *current = head;
    while (current!= NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    char *data1 = "Hello, World!";
    char *data2 = "This is a test";
    char *data3 = "Another hash test";

    insert(data1);
    insert(data2);
    insert(data3);

    print_hash();

    return 0;
}