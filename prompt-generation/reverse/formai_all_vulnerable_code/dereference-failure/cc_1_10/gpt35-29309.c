//FormAI DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 64
#define MAX_RECORDS 100

typedef struct {
    int key;
    char name[STRLEN];
} Record;

typedef struct {
    int key;
    int offset;
} Index;

void create_index_file(char* record_file, char* index_file) {
    FILE* f1 = fopen(record_file, "rb");
    if (f1 == NULL) {
        printf("Error: could not open record file\n");
        return;
    }

    FILE* f2 = fopen(index_file, "wb");
    if (f2 == NULL) {
        printf("Error: could not open index file\n");
        fclose(f1);
        return;
    }

    int count = 0;
    while (!feof(f1)) {
        Record r;
        int bytes_read = fread(&r, sizeof(Record), 1, f1);
        if (bytes_read == 1) {
            Index index;
            index.key = r.key;
            index.offset = count * sizeof(Record);
            fwrite(&index, sizeof(Index), 1, f2);
            count++;
        }
    }

    fclose(f1);
    fclose(f2);
}

int cmp_index(const void* a, const void* b) {
    return ((Index*)a)->key - ((Index*)b)->key;
}

void search_index_file(char* index_file, int key) {
    FILE* f = fopen(index_file, "rb");
    if (f == NULL) {
        printf("Error: could not open index file\n");
        return;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    int num_records = size / sizeof(Index);

    Index* index = (Index*)malloc(num_records * sizeof(Index));
    fseek(f, 0, SEEK_SET);
    fread(index, sizeof(Index), num_records, f);
    fclose(f);

    Index* keyidx = (Index*)bsearch(&key, index, num_records, sizeof(Index), cmp_index);

    if (keyidx != NULL) {
        FILE* f2 = fopen("records.bin", "rb");
        if (f2 == NULL) {
            printf("Error: could not open records file\n");
            return;
        }

        Record r;
        fseek(f2, keyidx->offset, SEEK_SET);
        fread(&r, sizeof(Record), 1, f2);
        fclose(f2);

        printf("key: %d, name: %s\n", r.key, r.name);
    } else {
        printf("Error: key not found\n");
    }

    free(index);
}

int main() {
    char* record_file = "records.bin";
    char* index_file = "index.bin";

    Record records[] = {
        {1, "John Smith"},
        {2, "Jane Doe"},
        {3, "Bob Johnson"},
        {4, "Alice Williams"},
        {5, "Charlie Brown"}
    };

    FILE* f = fopen(record_file, "wb");
    if (f == NULL) {
        printf("Error: could not open file\n");
        return -1;
    }

    fwrite(records, sizeof(Record), 5, f);
    fclose(f);

    create_index_file(record_file, index_file);

    int key = 3;
    search_index_file(index_file, key);

    return 0;
}