//FormAI DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 20
#define MAX_DATA_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char data[MAX_DATA_LENGTH];
} Record;

typedef struct {
    Record *records;
    int size;
} Table;

int hashCode(char *key) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash += (key[i] - '0');
    }
    return hash;
}

void insertRecord(Table *table, Record record) {
    int index = hashCode(record.key) % table->size;
    int i = 1;
    while (table->records[index].key[0] != '\0') {
        index = (index + i * i) % table->size;
        i++;
    }
    table->records[index] = record;
}

Record findRecord(Table *table, char *key) {
    int index = hashCode(key) % table->size;
    int i = 1;
    while (strcmp(table->records[index].key, key) != 0) {
        index = (index + i * i) % table->size;
        i++;
        if (i > table->size) {
            Record record = {"", ""};
            return record;
        }
    }
    return table->records[index];
}

int main() {
    Table table = {(Record *)calloc(10, sizeof(Record)), 10};
    insertRecord(&table, (Record){"001", "John Smith"});
    insertRecord(&table, (Record){"002", "Jane Doe"});
    insertRecord(&table, (Record){"003", "Bob Johnson"});
    insertRecord(&table, (Record){"004", "Alice Wang"});
    Record record = findRecord(&table, "003");
    printf("Key: %s, Data: %s\n", record.key, record.data);
    return 0;
}