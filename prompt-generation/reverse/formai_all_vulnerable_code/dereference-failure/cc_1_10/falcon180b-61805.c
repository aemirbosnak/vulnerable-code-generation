//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_ROWS_PER_BLOCK 10

typedef struct {
    char **data;
    int num_rows;
} Block;

typedef struct {
    Block *blocks;
    int num_blocks;
} Table;

void init_table(Table *table) {
    table->blocks = (Block *)malloc(sizeof(Block));
    table->num_blocks = 1;
    table->blocks[0].data = (char **)malloc(sizeof(char *));
    table->blocks[0].num_rows = 0;
}

void add_row(Table *table, char **row) {
    Block *current_block = table->blocks + table->num_blocks - 1;
    if (current_block->num_rows == MAX_ROWS_PER_BLOCK) {
        table->num_blocks++;
        table->blocks[table->num_blocks - 1].data = (char **)malloc(sizeof(char *));
        table->blocks[table->num_blocks - 1].num_rows = 0;
        current_block = table->blocks + table->num_blocks - 1;
    }
    current_block->data[current_block->num_rows++] = row;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_blocks; i++) {
        for (int j = 0; j < table->blocks[i].num_rows; j++) {
            printf("%s\n", table->blocks[i].data[j]);
        }
    }
}

void free_table(Table *table) {
    for (int i = 0; i < table->num_blocks; i++) {
        for (int j = 0; j < table->blocks[i].num_rows; j++) {
            free(table->blocks[i].data[j]);
        }
        free(table->blocks[i].data);
    }
    free(table->blocks);
}

int main() {
    Table table;
    init_table(&table);

    add_row(&table, (char *[]){"John", "Doe", "25"});
    add_row(&table, (char *[]){"Jane", "Doe", "30"});
    add_row(&table, (char *[]){"Bob", "Smith", "40"});

    print_table(&table);

    free_table(&table);

    return 0;
}