//FormAI DATASET v1.0 Category: Database Indexing System ; Style: systematic
#include <stdio.h>

// Structure to hold the database record
struct record {
    int id;
    char name[50];
    int age;
};

// Structure to hold the index data
struct index {
    int id;
    int recordNumber;
};

// Function to create the index
void createIndex(char *filename) {

    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        return;
    }

    int i, n;
    struct record rec;

    // Find the number of records in the file
    fseek(fp, 0L, SEEK_END);
    n = ftell(fp) / sizeof(struct record);
    rewind(fp);

    // Allocate memory for the index
    struct index *idx = malloc(n * sizeof(struct index));

    // Read the records and create the index
    for (i = 0; i < n; i++) {
        fread(&rec, sizeof(struct record), 1, fp);
        idx[i].id = rec.id;
        idx[i].recordNumber = i;
    }

    fclose(fp);

    // Write the index to file
    char indexFilename[100];
    strcpy(indexFilename, filename);
    strcat(indexFilename, ".idx");

    FILE *idxfp = fopen(indexFilename, "wb");

    if (idxfp == NULL) {
        printf("Error: Unable to create index file\n");
        return;
    }

    fwrite(idx, sizeof(struct index), n, idxfp);
    fclose(idxfp);

    printf("Index created successfully\n");
}

// Function to search the index and return the record
struct record searchIndex(char *filename, int id) {

    char indexFilename[100];
    strcpy(indexFilename, filename);
    strcat(indexFilename, ".idx");

    FILE *idxfp = fopen(indexFilename, "rb");

    if (idxfp == NULL) {
        printf("Error: Unable to open index file\n");
        struct record recErr = { -1, "Not found", -1 };
        return recErr;
    }

    int i, n;
    struct index idx;
    struct record rec;

    // Find the number of index entries in the file
    fseek(idxfp, 0L, SEEK_END);
    n = ftell(idxfp) / sizeof(struct index);
    rewind(idxfp);

    // Search for the index entry with the given ID
    for (i = 0; i < n; i++) {
        fread(&idx, sizeof(struct index), 1, idxfp);
        if (idx.id == id) {
            break;
        }
    }

    fclose(idxfp);

    // Open the database file and find the record using the index
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        struct record recErr = { -1, "Not found", -1 };
        return recErr;
    }

    fseek(fp, idx.recordNumber * sizeof(struct record), SEEK_SET);
    fread(&rec, sizeof(struct record), 1, fp);

    fclose(fp);

    return rec;
}

int main() {

    struct record rec1 = { 1, "John", 25 };
    struct record rec2 = { 2, "Jane", 30 };
    struct record rec3 = { 3, "Bill", 35 };

    // Write the records to file
    FILE *fp = fopen("data.db", "wb");

    fwrite(&rec1, sizeof(struct record), 1, fp);
    fwrite(&rec2, sizeof(struct record), 1, fp);
    fwrite(&rec3, sizeof(struct record), 1, fp);

    fclose(fp);

    // Create the index
    createIndex("data.db");

    // Search for a record
    struct record rec = searchIndex("data.db", 2);

    // Output the record
    printf("Record found:\n");
    printf("ID: %d\n", rec.id);
    printf("Name: %s\n", rec.name);
    printf("Age: %d\n", rec.age);

    return 0;
}