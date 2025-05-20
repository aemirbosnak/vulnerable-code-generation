//FormAI DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_AGE 120

// Define a struct to represent a person
typedef struct Person {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

// Define a struct to represent an index entry
typedef struct IndexEntry {
    char name[MAX_NAME_LENGTH];
    long offset;
} IndexEntry;

// Define a function to compare two IndexEntry structs by name
int index_name_cmp(const void *a, const void *b) {
    return strcmp(((IndexEntry*)a)->name, ((IndexEntry*)b)->name);
}

// Define a function to create an index file for a given data file
void create_index(const char *data_file, const char *index_file) {
    // Open the data file for reading
    FILE *data_fp = fopen(data_file, "rb");
    if (!data_fp) {
        perror("Failed to open data file");
        exit(EXIT_FAILURE);
    }

    // Open the index file for writing
    FILE *index_fp = fopen(index_file, "wb");
    if (!index_fp) {
        perror("Failed to open index file");
        exit(EXIT_FAILURE);
    }

    // Read each record in the data file and write an index entry to the index file
    long offset = 0;
    Person p;
    IndexEntry ie;
    while (fread(&p, sizeof(Person), 1, data_fp) == 1) {
        strncpy(ie.name, p.name, MAX_NAME_LENGTH);
        ie.offset = offset;
        fwrite(&ie, sizeof(IndexEntry), 1, index_fp);
        offset += sizeof(Person);
    }

    // Close the files
    fclose(data_fp);
    fclose(index_fp);
}

// Define a function to look up a record in a data file using an index file
int lookup_record(const char *name, const char *data_file, const char *index_file, Person *result) {
    // Open the index file for reading
    FILE *index_fp = fopen(index_file, "rb");
    if (!index_fp) {
        perror("Failed to open index file");
        return 0;
    }

    // Binary search the index file for the given name
    IndexEntry ie;
    fseek(index_fp, 0, SEEK_END);
    long index_size = ftell(index_fp) / sizeof(IndexEntry);
    long low = 0, high = index_size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        fseek(index_fp, mid * sizeof(IndexEntry), SEEK_SET);
        fread(&ie, sizeof(IndexEntry), 1, index_fp);
        int cmp = strcmp(name, ie.name);
        if (cmp < 0) {
            high = mid - 1;
        } else if (cmp > 0) {
            low = mid + 1;
        } else {
            break;
        }
    }

    // If the name was not found in the index file, return 0
    if (low > high) {
        fclose(index_fp);
        return 0;
    }

    // Open the data file for reading and seek to the record pointed to by the index entry
    FILE *data_fp = fopen(data_file, "rb");
    if (!data_fp) {
        perror("Failed to open data file");
        fclose(index_fp);
        return 0;
    }
    fseek(data_fp, ie.offset, SEEK_SET);

    // Read the record from the data file and return it
    fread(result, sizeof(Person), 1, data_fp);

    // Close the files and return 1 to indicate success
    fclose(data_fp);
    fclose(index_fp);
    return 1;
}

int main() {
    // Create some test data
    Person data[] = {
        {"Alice", 23},
        {"Bob", 34},
        {"Charlie", 52},
        {"David", 19},
        {"Eve", 46},
    };
    int data_size = sizeof(data) / sizeof(Person);

    // Write the test data to a binary file
    FILE *data_fp = fopen("data.bin", "wb");
    if (!data_fp) {
        perror("Failed to create data file");
        return EXIT_FAILURE;
    }
    fwrite(data, sizeof(Person), data_size, data_fp);
    fclose(data_fp);

    // Create an index for the test data
    create_index("data.bin", "index.bin");

    // Lookup a record by name using the index
    Person result;
    if (lookup_record("Charlie", "data.bin", "index.bin", &result)) {
        printf("Found record: %s (%d)\n", result.name, result.age);
    } else {
        printf("Record not found\n");
    }

    // Cleanup and exit
    remove("data.bin");
    remove("index.bin");
    return EXIT_SUCCESS;
}