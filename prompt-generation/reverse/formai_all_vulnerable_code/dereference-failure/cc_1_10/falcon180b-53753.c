//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_RECORD_LEN 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char record[MAX_RECORD_LEN];
} Record;

void createIndex(char* indexName, char* dataFile) {
    FILE* indexFile = fopen(indexName, "wb");
    if (indexFile == NULL) {
        printf("Error: could not create index file\n");
        exit(1);
    }

    FILE* data = fopen(dataFile, "rb");
    if (data == NULL) {
        printf("Error: could not open data file\n");
        exit(1);
    }

    Record record;
    while (fread(&record, sizeof(Record), 1, data) == 1) {
        fwrite(&record.key, sizeof(record.key), 1, indexFile);
    }

    fclose(data);
    fclose(indexFile);
}

void searchIndex(char* indexName, char* key, char* dataFile) {
    FILE* index = fopen(indexName, "rb");
    if (index == NULL) {
        printf("Error: could not open index file\n");
        exit(1);
    }

    char buffer[MAX_KEY_LEN];
    while (fread(buffer, sizeof(char), MAX_KEY_LEN, index) == MAX_KEY_LEN) {
        if (strcmp(buffer, key) == 0) {
            char* record = malloc(MAX_RECORD_LEN);
            fseek(index, -MAX_KEY_LEN, SEEK_CUR);
            fread(record, sizeof(char), MAX_RECORD_LEN, index);
            printf("%s\n", record);
            free(record);
        }
    }

    fclose(index);
}

int main() {
    char* indexName = "index.bin";
    char* dataFile = "data.txt";

    createIndex(indexName, dataFile);

    searchIndex(indexName, "hello", dataFile);

    return 0;
}