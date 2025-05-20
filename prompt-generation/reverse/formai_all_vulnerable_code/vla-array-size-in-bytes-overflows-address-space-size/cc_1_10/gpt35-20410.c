//FormAI DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the record information
struct Record {
    int id;
    char name[50];
    char address[100];
};

// Define a structure for the index that holds the record IDs and the file position of the corresponding record in the database
struct Index {
    int id;
    int position;
};

int main() {
    FILE *database_file, *index_file;
    int num_records = 0, num_indexes = 0;

    // First open the database file and calculate the number of records
    database_file = fopen("database.dat", "rb");
    if (database_file != NULL) {
        fseek(database_file, 0, SEEK_END);
        num_records = ftell(database_file) / sizeof(struct Record);
        fclose(database_file);
    }

    // Now open the index file and calculate the number of indexes
    index_file = fopen("index.dat", "rb");
    if (index_file != NULL) {
        fseek(index_file, 0, SEEK_END);
        num_indexes = ftell(index_file) / sizeof(struct Index);
        fclose(index_file);
    }

    // If the number of records and indexes don't match, we need to rebuild the index
    if (num_records != num_indexes) {
        printf("Index needs to be rebuilt...\n");

        // First delete the old index file, if it exists
        index_file = fopen("index.dat", "wb");
        fclose(index_file);
        remove("index.dat");

        // Now create a new index by reading in all the records and adding them to the index
        struct Record records[num_records];
        struct Index index[num_records];
        int i;

        // Read in all the records from the database file
        database_file = fopen("database.dat", "rb");
        fread(records, sizeof(struct Record), num_records, database_file);
        fclose(database_file);

        // Loop through each record and add it to the index array
        for (i = 0; i < num_records; i++) {
            index[i].id = records[i].id;
            index[i].position = i;
        }

        // Now sort the index array by ID using bubble sort
        int j;
        struct Index temp_index;
        for (i = 0; i < num_records - 1; i++) {
            for (j = 0; j < num_records - i - 1; j++) {
                if (index[j].id > index[j+1].id) {
                    // Swap the two elements in the index array
                    temp_index = index[j];
                    index[j] = index[j+1];
                    index[j+1] = temp_index;
                }
            }
        }

        // Finally, write the sorted index to the index file
        index_file = fopen("index.dat", "ab");
        fwrite(index, sizeof(struct Index), num_records, index_file);
        fclose(index_file);

        printf("Index successfully rebuilt!\n");
    } else {
        printf("Index is up to date and does not need to be rebuilt.\n");
    }

    return 0;
}