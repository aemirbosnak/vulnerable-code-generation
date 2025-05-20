//FormAI DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_NUMBER_LENGTH 15
#define MAX_CONTACTS 1000

struct Contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

struct Bucket {
    struct Contact contacts[MAX_CONTACTS];
    int count;
};

struct HashTable {
    struct Bucket* buckets;
    int size;
};

int hash(char* key, int size) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % size;
}

struct HashTable* create_table(int size) {
    struct HashTable* table = malloc(sizeof(struct HashTable));
    table->buckets = calloc(size, sizeof(struct Bucket));
    table->size = size;
    return table;
}

void add_contact(struct HashTable* table, char* name, char* number) {
    int index = hash(name, table->size);
    struct Bucket* bucket = &table->buckets[index];
    struct Contact contact = {
        .name = name,
        .number = number
    };
    bucket->contacts[bucket->count++] = contact;
}

void display_contact(struct Contact contact) {
    printf("%s : %s\n", contact.name, contact.number);
}

void display_bucket(struct Bucket bucket) {
    for (int i = 0; i < bucket.count; i++) {
        display_contact(bucket.contacts[i]);
    }
}

void display_table(struct HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        printf("\nBucket %d:", i);
        display_bucket(table->buckets[i]);
    }
}

int main() {
    struct HashTable* table = create_table(100);

    add_contact(table, "Alice", "123-456-7890");
    add_contact(table, "Bob", "234-567-8901");
    add_contact(table, "Charlie", "345-678-9012");
    add_contact(table, "David", "456-789-0123");
    add_contact(table, "Eve", "567-890-1234");

    display_table(table);

    return 0;
}