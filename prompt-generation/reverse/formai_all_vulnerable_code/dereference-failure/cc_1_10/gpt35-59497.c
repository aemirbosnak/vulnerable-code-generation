//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to store the data in the database
typedef struct {
    int id;
    char name[50];
    char email[50];
    int age;
} Data;

// A structure to store the index data
typedef struct {
    int id;
    long offset;
} IndexData;

// A structure to store the index entries
typedef struct {
    IndexData* entries;
    int count;
} Index;

// Writes the data to the database file
void writeData(FILE* file, Data data) {
    fwrite(&data.id, sizeof(int), 1, file);
    fwrite(data.name, sizeof(char), 50, file);
    fwrite(data.email, sizeof(char), 50, file);
    fwrite(&data.age, sizeof(int), 1, file);
}

// Reads the data from the database file
Data readData(FILE* file) {
    Data data;
    fread(&data.id, sizeof(int), 1, file);
    fread(data.name, sizeof(char), 50, file);
    fread(data.email, sizeof(char), 50, file);
    fread(&data.age, sizeof(int), 1, file);
    return data;
}

// Writes the index data to the index file
void writeIndexData(FILE* file, IndexData data) {
    fwrite(&data.id, sizeof(int), 1, file);
    fwrite(&data.offset, sizeof(long), 1, file);
}

// Reads the index data from the index file
IndexData readIndexData(FILE* file) {
    IndexData data;
    fread(&data.id, sizeof(int), 1, file);
    fread(&data.offset, sizeof(long), 1, file);
    return data;
}

// Creates a new index and initializes it
Index* createIndex(int maxEntries) {
    Index* index = (Index*)malloc(sizeof(Index));
    index->entries = (IndexData*)malloc(maxEntries * sizeof(IndexData));
    index->count = 0;
    return index;
}

// Adds an entry to the index
void addToIndex(Index* index, IndexData data) {
    index->entries[index->count++] = data;
}

// Searches for an entry in the index by its id
IndexData* searchIndex(Index* index, int id) {
    for (int i = 0; i < index->count; i++) {
        if (index->entries[i].id == id) {
            return &index->entries[i];
        }
    }
    return NULL;
}

// Compares two index entries by their id
int compareIndexEntries(const void* a, const void* b) {
    return ((IndexData*)a)->id - ((IndexData*)b)->id;
}

// Sorts the index entries by their id
void sortIndex(Index* index) {
    qsort(index->entries, index->count, sizeof(IndexData), compareIndexEntries);
}

int main() {
    FILE* indexFile = fopen("index.dat", "w");
    FILE* dataFile = fopen("data.dat", "w");

    Data data1 = { 1, "John Doe", "john@doe.com", 30 };
    Data data2 = { 2, "Jane Doe", "jane@doe.com", 25 };
    Data data3 = { 3, "Bob Smith", "bob@smith.com", 40 };

    // Write the data to the database file and add index entries
    Index* index = createIndex(3);
    writeData(dataFile, data1);
    IndexData indexData1 = { data1.id, ftell(dataFile) - sizeof(Data) };
    addToIndex(index, indexData1);
    writeIndexData(indexFile, indexData1);
    writeData(dataFile, data2);
    IndexData indexData2 = { data2.id, ftell(dataFile) - sizeof(Data) };
    addToIndex(index, indexData2);
    writeIndexData(indexFile, indexData2);
    writeData(dataFile, data3);
    IndexData indexData3 = { data3.id, ftell(dataFile) - sizeof(Data) };
    addToIndex(index, indexData3);
    writeIndexData(indexFile, indexData3);

    // Sort the index entries and search for an entry by its id
    sortIndex(index);
    int idToSearch = 2;
    IndexData* result = searchIndex(index, idToSearch);
    if (result != NULL) {
        printf("Found data for id %d:\n", idToSearch);
        fseek(dataFile, result->offset, SEEK_SET);
        Data data = readData(dataFile);
        printf("Name: %s\tEmail: %s\tAge: %d\n", data.name, data.email, data.age);
    } else {
        printf("No data found for id %d\n", idToSearch);
    }

    fclose(indexFile);
    fclose(dataFile);
    free(index->entries);
    free(index);
    return 0;
}