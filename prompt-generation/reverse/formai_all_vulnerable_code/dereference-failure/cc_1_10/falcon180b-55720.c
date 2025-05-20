//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_SIZE 4096
#define MAX_CODE_TABLE_SIZE 4096

struct code {
    char *prefix;
    int code;
};

struct code_table {
    int size;
    struct code *table;
};

void init_code_table(struct code_table *table) {
    table->size = 0;
    table->table = NULL;
}

void add_code(struct code_table *table, char *prefix, int code) {
    struct code *new_code = malloc(sizeof(struct code));
    new_code->prefix = strdup(prefix);
    new_code->code = code;
    table->table = realloc(table->table, sizeof(struct code) * ++table->size);
    table->table[table->size-1] = *new_code;
}

int find_code(struct code_table *table, char *prefix) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->table[i].prefix, prefix) == 0) {
            return table->table[i].code;
        }
    }
    return -1;
}

void print_code_table(struct code_table *table) {
    printf("Prefix\tCode\n");
    for (int i = 0; i < table->size; i++) {
        printf("%s\t%d\n", table->table[i].prefix, table->table[i].code);
    }
}

int main() {
    struct code_table table;
    init_code_table(&table);

    add_code(&table, "a", 1);
    add_code(&table, "b", 2);
    add_code(&table, "c", 3);
    add_code(&table, "d", 4);
    add_code(&table, "e", 5);

    print_code_table(&table);

    return 0;
}