//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 128

typedef struct {
    unsigned char key;
    int count;
} hash_table_entry;

unsigned int hash(unsigned char key) {
    return key % TABLE_SIZE;
}

hash_table_entry* create_hash_table() {
    hash_table_entry* table = (hash_table_entry*) calloc(TABLE_SIZE, sizeof(hash_table_entry));
    if (!table) {
        fprintf(stderr, "Error allocating memory for hash table.\n");
        exit(EXIT_FAILURE);
    }
    return table;
}

void insert_into_hash_table(hash_table_entry* table, unsigned char key) {
    int index = hash(key);
    if (table[index].key == 0) {
        table[index].key = key;
        table[index].count = 1;
    } else {
        table[index].count++;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    hash_table_entry* table = create_hash_table();

    int string_length = strlen(argv[1]);
    for (int i = 0; i < string_length; i++) {
        unsigned char character = toupper((unsigned char) argv[1][i]);
        insert_into_hash_table(table, character);
    }

    int unique_characters = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].count > 0) {
            unique_characters++;
        }
    }

    printf("Number of unique characters in \"%s\": %d\n", argv[1], unique_characters);

    free(table);
    return EXIT_SUCCESS;
}