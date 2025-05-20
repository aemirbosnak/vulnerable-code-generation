//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define KEY_SIZE 20
#define RECORD_SIZE 100

typedef struct {
    char key[KEY_SIZE];
    char data[RECORD_SIZE];
} Record;

typedef struct Node {
    Record record;
    struct Node *next;
} Node;

typedef struct {
    Node *head[26];
    int num_records;
} Index;

Index *createIndex(void) {
    Index *index = (Index *) malloc(sizeof(Index));
    int i;

    for (i = 0; i < 26; i++) {
        index->head[i] = NULL;
    }

    index->num_records = 0;
    return index;
}

void insertRecord(Index *index, char *key, char *data) {
    Node *new_node = (Node *) malloc(sizeof(Node));

    strcpy(new_node->record.key, key);
    strcpy(new_node->record.data, data);
    new_node->next = NULL;

    int pos = key[0] - 'A';
    new_node->next = index->head[pos];
    index->head[pos] = new_node;

    index->num_records++;
}

void searchRecord(Index *index, char *key) {
    int pos = key[0] - 'A';
    Node *current = index->head[pos];

    while (current != NULL) {
        if (strcmp(current->record.key, key) == 0) {
            printf("Record found: %s\n", current->record.data);
            return;
        }
        current = current->next;
    }

    printf("Record not found.\n");
}

void printIndex(Index *index) {
    printf("Index contents:\n");
    int i;

    for (i = 0; i < 26; i++) {
        printf("%c: ", 'A' + i);
        Node *current = index->head[i];

        while (current != NULL) {
            printf("%s -> ", current->record.key);
            current = current->next;
        }

        printf("NULL\n");
    }
}

int main() {
    Index *index = createIndex();

    // Insert some records
    insertRecord(index, "APPLE", "Color: Red, Taste: Sweet");
    insertRecord(index, "BANANA", "Color: Yellow, Taste: Sweet");
    insertRecord(index, "ORANGE", "Color: Orange, Taste: Sour");
    insertRecord(index, "GRAPE", "Color: Purple, Taste: Sour");
    insertRecord(index, "AVOCADO", "Color: Green, Taste: Neutral");

    // Search for a record
    searchRecord(index, "BANANA");

    // Print the index contents
    printIndex(index);

    // Free memory
    Index *current = index;
    while (index != NULL) {
        index = index->head[0];
        free(current);
        current = index;
    }

    free(index);

    return 0;
}