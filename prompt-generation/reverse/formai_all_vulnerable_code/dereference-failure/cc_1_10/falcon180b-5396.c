//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char *key;
    int value;
} pair_t;

pair_t *hash_table = NULL;
int hash_table_size = 0;

void init_hash_table() {
    hash_table = (pair_t *)malloc(sizeof(pair_t) * 100);
    memset(hash_table, 0, sizeof(pair_t) * 100);
    hash_table_size = 100;
}

int hash_function(char *key) {
    int hash = 0;
    int i = 0;
    while (key[i]) {
        hash += tolower(key[i]);
        i++;
    }
    return hash % hash_table_size;
}

void insert_pair(char *key, int value) {
    int index = hash_function(key);
    while (hash_table[index].key!= NULL) {
        index = (index + 1) % hash_table_size;
    }
    hash_table[index].key = strdup(key);
    hash_table[index].value = value;
}

int get_value(char *key) {
    int index = hash_function(key);
    while (hash_table[index].key!= NULL) {
        if (strcmp(hash_table[index].key, key) == 0) {
            return hash_table[index].value;
        }
        index = (index + 1) % hash_table_size;
    }
    return -1;
}

void print_pairs() {
    int i = 0;
    while (i < hash_table_size) {
        if (hash_table[i].key!= NULL) {
            printf("%s -> %d\n", hash_table[i].key, hash_table[i].value);
        }
        i++;
    }
}

int main() {
    init_hash_table();
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, stdin)!= NULL) {
        char *key = strtok(line, " ");
        int value = atoi(strtok(NULL, " "));
        insert_pair(key, value);
    }
    print_pairs();
    return 0;
}