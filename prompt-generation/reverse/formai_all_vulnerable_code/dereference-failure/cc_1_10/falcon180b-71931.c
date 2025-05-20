//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 200
#define MAX_INDEX_SIZE 50

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} record;

typedef struct {
    record record;
    int index;
} indexed_record;

int main() {
    FILE *index_file = fopen("index.txt", "w");
    FILE *data_file = fopen("data.txt", "w");

    if (index_file == NULL || data_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Create the index file
    fprintf(index_file, "Index\n");

    // Write the first record to the data file
    record first_record = {"First record", "This is the first record"};
    fwrite(&first_record, sizeof(record), 1, data_file);

    // Create the index for the first record
    indexed_record first_index = {first_record, 0};
    fwrite(&first_index, sizeof(indexed_record), 1, index_file);

    // Write the second record to the data file
    record second_record = {"Second record", "This is the second record"};
    fwrite(&second_record, sizeof(record), 1, data_file);

    // Create the index for the second record
    indexed_record second_index = {second_record, 1};
    fwrite(&second_index, sizeof(indexed_record), 1, index_file);

    // Write the third record to the data file
    record third_record = {"Third record", "This is the third record"};
    fwrite(&third_record, sizeof(record), 1, data_file);

    // Create the index for the third record
    indexed_record third_index = {third_record, 2};
    fwrite(&third_index, sizeof(indexed_record), 1, index_file);

    // Close the files
    fclose(index_file);
    fclose(data_file);

    return 0;
}