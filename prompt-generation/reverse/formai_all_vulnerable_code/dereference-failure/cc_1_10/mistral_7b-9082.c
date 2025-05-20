//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 101
#define MAX_KEY_LENGTH 50

typedef struct {
    char key[MAX_KEY_LENGTH];
    int value;
} Entry;

typedef struct {
    Entry* data;
} HashTable;

unsigned long hash_func(char* key) {
    unsigned long hash = 0;
    for (int i = 0; key[i]; i++) {
        hash += key[i] * (i + 1);
    }
    return hash % TABLE_SIZE;
}

HashTable create_hash_table() {
    HashTable table;
    table.data = (Entry*)calloc(TABLE_SIZE, sizeof(Entry));
    if (!table.data) {
        fprintf(stderr, "Error allocating memory for hash table\n");
        exit(1);
    }
    return table;
}

void insert(HashTable* table, char* key, int value) {
    int index = hash_func(key) % TABLE_SIZE;
    Entry entry = {key, value};

    for (Entry* e = table->data + index; e->key; e++) {
        if (strcmp(e->key, key) == 0) {
            e->value = value;
            return;
        }
    }

    strcpy(table->data[index].key, key);
    table->data[index].value = value;
}

int search(HashTable* table, char* key) {
    int index = hash_func(key) % TABLE_SIZE;

    for (Entry* e = table->data + index; e->key; e++) {
        if (strcmp(e->key, key) == 0) {
            return e->value;
        }
    }

    return -1;
}

int main() {
    srand(time(NULL));

    HashTable whimsical_wondrous_wonderland = create_hash_table();

    // Populate the database with magical creatures
    for (int i = 0; i < 10; i++) {
        char creature_name[MAX_KEY_LENGTH];
        sprintf(creature_name, "Creature %d", i + 1);
        int magical_property = rand() % 100 + 1;

        printf("Inserting %s with a magical property of %d\n", creature_name, magical_property);
        insert(&whimsical_wondrous_wonderland, creature_name, magical_property);
    }

    // Perform some magical queries
    printf("\nQuerying for the magical property of the Flabber Gobble:\n");
    char flabber_gobble_name[MAX_KEY_LENGTH];
    strcpy(flabber_gobble_name, "Flabber Gobble");
    int flabber_gobble_property = search(&whimsical_wondrous_wonderland, flabber_gobble_name);
    printf("The Flabber Gobble has a magical property of %d\n", flabber_gobble_property);

    printf("\nQuerying for the magical property of the Nose Picking Elf:\n");
    char nose_picking_elf_name[MAX_KEY_LENGTH];
    strcpy(nose_picking_elf_name, "Nose Picking Elf");
    int nose_picking_elf_property = search(&whimsical_wondrous_wonderland, nose_picking_elf_name);

    if (nose_picking_elf_property == -1) {
        printf("The Nose Picking Elf is not in the database\n");
    } else {
        printf("The Nose Picking Elf has a magical property of %d\n", nose_picking_elf_property);
    }

    return 0;
}