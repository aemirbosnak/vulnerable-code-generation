//FormAI DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a database record
typedef struct {
    int id;
    char name[50];
    int age;
    char address[100];
} Record;

// A structure to represent the database index
typedef struct {
    int id;
    long offset;
} Index;

// The main function
int main() {
    printf("Welcome to our cheerful database indexing system!\n");

    // Open the database file and index file
    FILE *db_file = fopen("database.dat", "rb+");
    FILE *index_file = fopen("index.dat", "wb+");

    // Check if the files opened successfully
    if (db_file == NULL || index_file == NULL) {
        printf("Oops! Couldn't open the database or index file.\n");
        return 1;
    } else {
        printf("Database and index files opened successfully!\n");
    }

    // Build the index
    printf("Building the index...\n");
    Index index[1000];
    Record record;
    int num_records = 0;
    while (fread(&record, sizeof(record), 1, db_file)) {
        index[num_records].id = record.id;
        index[num_records].offset = ftell(db_file) - sizeof(record);
        num_records++;
    }
    fwrite(&index, sizeof(Index), num_records, index_file);
    printf("Index built successfully for %d records.\n", num_records);

    // Search for a record
    printf("Searching for a record...\n");
    int search_id = 123;
    Index block[10];
    fseek(index_file, 0, SEEK_SET);
    int num_blocks = fread(&block, sizeof(Index), 10, index_file);
    while (num_blocks > 0) {
        for (int i = 0; i < num_blocks; i++) {
            if (block[i].id == search_id) {
                printf("Record found! Reading...\n");
                fseek(db_file, block[i].offset, SEEK_SET);
                fread(&record, sizeof(record), 1, db_file);
                printf("Id: %d\nName: %s\nAge: %d\nAddress: %s\n",
                       record.id, record.name, record.age, record.address);
                fclose(db_file);
                fclose(index_file);
                return 0;
            }
        }
        num_blocks = fread(&block, sizeof(Index), 10, index_file);
    }
    printf("Oops! Record not found.\n");

    // Close the files and exit
    fclose(db_file);
    fclose(index_file);
    return 0;
}