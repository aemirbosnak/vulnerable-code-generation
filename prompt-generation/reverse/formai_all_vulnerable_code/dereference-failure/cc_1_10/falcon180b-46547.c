//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100

typedef struct {
    int value;
    int frequency;
} Frequency;

typedef struct {
    Frequency *data;
    int size;
} FrequencyTable;

FrequencyTable *createFrequencyTable(void) {
    FrequencyTable *table = (FrequencyTable *) malloc(sizeof(FrequencyTable));
    table->data = (Frequency *) malloc(MAX_VALUE * sizeof(Frequency));
    table->size = 0;
    for (int i = 0; i < MAX_VALUE; i++) {
        table->data[i].value = i;
        table->data[i].frequency = 0;
    }
    return table;
}

void updateFrequencyTable(FrequencyTable *table, int value) {
    for (int i = 0; i < table->size; i++) {
        if (table->data[i].value == value) {
            table->data[i].frequency++;
            return;
        }
    }
    table->data[table->size].value = value;
    table->data[table->size].frequency = 1;
    table->size++;
}

void printFrequencyTable(FrequencyTable *table) {
    for (int i = 0; i < table->size; i++) {
        printf("%d : %d\n", table->data[i].value, table->data[i].frequency);
    }
}

int main() {
    FrequencyTable *table = createFrequencyTable();
    int value;
    while (1) {
        printf("Enter a value (0 to exit): ");
        scanf("%d", &value);
        if (value == 0) {
            break;
        }
        updateFrequencyTable(table, value);
    }
    printFrequencyTable(table);
    return 0;
}