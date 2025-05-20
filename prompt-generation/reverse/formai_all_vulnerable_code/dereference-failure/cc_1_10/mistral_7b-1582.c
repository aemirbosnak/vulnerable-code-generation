//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE_SIZE 256
#define HASH_SIZE 100001

typedef struct {
    char base;
    int count;
} hash_table;

hash_table *create_hash_table() {
    int i;
    hash_table *ht = (hash_table *) calloc(HASH_SIZE, sizeof(hash_table));
    for (i = 0; i < HASH_SIZE; i++) {
        ht[i].base = '\0';
        ht[i].count = 0;
    }
    return ht;
}

int hash_func(char base) {
    return base % HASH_SIZE;
}

void insert_hash(hash_table *ht, char base) {
    int index = hash_func(base);
    if (ht[index].base == '\0') {
        ht[index].base = base;
        ht[index].count++;
    } else {
        ht[index].count++;
    }
}

void read_genome(hash_table *ht, char *genome, int len) {
    int i;
    for (i = 0; i < len; i++) {
        insert_hash(ht, genome[i]);
    }
}

void print_hash(hash_table *ht) {
    int i;
    for (i = 0; i < HASH_SIZE; i++) {
        if (ht[i].base != '\0') {
            printf("%c : %d\n", ht[i].base, ht[i].count);
        }
    }
}

int main() {
    hash_table *ht = create_hash_table();
    char genome[10000] = "ATCGATCGATCGATCGATCGATCGATCG";
    int len = strlen(genome);
    read_genome(ht, genome, len);
    print_hash(ht);
    free(ht);
    return 0;
}