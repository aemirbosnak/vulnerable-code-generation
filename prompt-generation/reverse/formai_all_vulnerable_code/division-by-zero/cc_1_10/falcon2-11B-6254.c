//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TABLE_SIZE 10
#define MAX_NUM_ROUNDS 1000

typedef struct {
    int table[MAX_TABLE_SIZE];
    int size;
} Table;

void initialize_table(Table *table) {
    table->size = 0;
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        table->table[i] = 0;
    }
}

bool is_valid_number(int number) {
    return number >= 0 && number <= MAX_TABLE_SIZE;
}

int get_random_number(Table *table, int min, int max) {
    int random_number = rand() % (max - min + 1) + min;
    return random_number;
}

void update_table(Table *table, int number, bool update_successful) {
    if (table->size < MAX_TABLE_SIZE) {
        table->table[table->size] = number;
        table->size++;
    } else {
        printf("Table is full.\n");
        update_successful = false;
    }
}

int main() {
    Table table;
    initialize_table(&table);
    int number;
    int random_number;
    bool update_successful;

    for (int i = 0; i < MAX_NUM_ROUNDS; i++) {
        printf("Enter a number: ");
        scanf("%d", &number);
        random_number = get_random_number(&table, number, MAX_TABLE_SIZE);
        update_successful = false;
        if (is_valid_number(random_number) && table.table[random_number] == 0) {
            update_table(&table, random_number, true);
            printf("Number %d updated.\n", random_number);
            update_successful = true;
        }
        if (!update_successful) {
            printf("Number %d is already in the table.\n", random_number);
        }
    }

    printf("Table size: %d\n", table.size);
    for (int i = 0; i < table.size; i++) {
        printf("%d: %d\n", i, table.table[i]);
    }

    return 0;
}