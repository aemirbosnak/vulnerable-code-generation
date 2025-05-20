//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LENGTH 100
#define MAX_UNIX_TIMESTAMP (UINT_MAX - 1)

// Hash table to store the mapping between natural language words and their corresponding Unix timestamps
typedef struct {
    char *word;
    unsigned long timestamp;
} HashEntry;

typedef struct {
    HashEntry *entries;
    int size;
} HashTable;

HashTable *createHashTable() {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->entries = (HashEntry *)malloc(MAX_LENGTH * sizeof(HashEntry));
    table->size = MAX_LENGTH;
    return table;
}

void addToHashTable(HashTable *table, char *word, unsigned long timestamp) {
    if (table->size == MAX_LENGTH) {
        table->entries = (HashEntry *)realloc(table->entries, 2 * MAX_LENGTH * sizeof(HashEntry));
        table->size *= 2;
    }
    table->entries[table->size - 1].word = strdup(word);
    table->entries[table->size - 1].timestamp = timestamp;
    table->size++;
}

bool isInHashTable(HashTable *table, char *word) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->entries[i].word, word) == 0) {
            return true;
        }
    }
    return false;
}

unsigned long getUnixTimestamp(HashTable *table, char *word) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->entries[i].word, word) == 0) {
            return table->entries[i].timestamp;
        }
    }
    return 0;
}

// Priority queue to store the natural language dates that need to be converted
typedef struct {
    char *date;
    unsigned long timestamp;
} PQEntry;

typedef struct {
    PQEntry *entries;
    int size;
} PQ;

PQ *createPQ() {
    PQ *queue = (PQ *)malloc(sizeof(PQ));
    queue->entries = (PQEntry *)malloc(MAX_LENGTH * sizeof(PQEntry));
    queue->size = MAX_LENGTH;
    return queue;
}

bool isEmpty(PQ *queue) {
    return queue->size == 0;
}

void push(PQ *queue, char *date, unsigned long timestamp) {
    queue->entries[queue->size - 1].date = strdup(date);
    queue->entries[queue->size - 1].timestamp = timestamp;
    queue->size++;
}

void pop(PQ *queue) {
    queue->size--;
}

char *top(PQ *queue) {
    return queue->entries[queue->size - 1].date;
}

unsigned long getTimestamp(PQ *queue) {
    return queue->entries[queue->size - 1].timestamp;
}

// Main function
int main(int argc, char **argv) {
    // Create the hash table
    HashTable *hashTable = createHashTable();

    // Add natural language words and their corresponding Unix timestamps to the hash table
    addToHashTable(hashTable, "yesterday", (unsigned long)time(NULL) - 24 * 3600);
    addToHashTable(hashTable, "tomorrow", (unsigned long)time(NULL) + 24 * 3600);
    addToHashTable(hashTable, "two weeks ago", (unsigned long)time(NULL) - 14 * 24 * 3600);
    addToHashTable(hashTable, "one month ago", (unsigned long)time(NULL) - 30 * 24 * 3600);
    addToHashTable(hashTable, "last month", (unsigned long)time(NULL) - 30 * 24 * 3600);
    addToHashTable(hashTable, "two months ago", (unsigned long)time(NULL) - 60 * 24 * 3600);
    addToHashTable(hashTable, "three months ago", (unsigned long)time(NULL) - 90 * 24 * 3600);
    addToHashTable(hashTable, "six months ago", (unsigned long)time(NULL) - 180 * 24 * 3600);
    addToHashTable(hashTable, "one year ago", (unsigned long)time(NULL) - 365 * 24 * 3600);
    addToHashTable(hashTable, "two years ago", (unsigned long)time(NULL) - 730 * 24 * 3600);
    addToHashTable(hashTable, "three years ago", (unsigned long)time(NULL) - 1095 * 24 * 3600);
    addToHashTable(hashTable, "four years ago", (unsigned long)time(NULL) - 1460 * 24 * 3600);
    addToHashTable(hashTable, "five years ago", (unsigned long)time(NULL) - 1825 * 24 * 3600);
    addToHashTable(hashTable, "six years ago", (unsigned long)time(NULL) - 2190 * 24 * 3600);
    addToHashTable(hashTable, "seven years ago", (unsigned long)time(NULL) - 2555 * 24 * 3600);
    addToHashTable(hashTable, "eight years ago", (unsigned long)time(NULL) - 2920 * 24 * 3600);
    addToHashTable(hashTable, "nine years ago", (unsigned long)time(NULL) - 3285 * 24 * 3600);

    // Create the priority queue
    PQ *queue = createPQ();

    // Read the input file and add the natural language dates to the priority queue
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }
    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *date = strtok(line, " \t\n");
        while (date!= NULL) {
            if (isInHashTable(hashTable, date)) {
                push(queue, date, getUnixTimestamp(hashTable, date));
                pop(queue);
            }
            date = strtok(NULL, " \t\n");
        }
    }
    fclose(inputFile);

    // Write the converted timestamps to the output file
    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        return 1;
    }
    while (!isEmpty(queue)) {
        PQEntry entry = { 0 };
        pop(queue);
        entry.date = top(queue);
        entry.timestamp = getTimestamp(queue);
        fprintf(outputFile, "%s\t%lu\n", entry.date, entry.timestamp);
    }
    fclose(outputFile);

    return 0;
}