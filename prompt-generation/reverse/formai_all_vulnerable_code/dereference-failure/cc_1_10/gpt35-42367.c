//FormAI DATASET v1.0 Category: Database Indexing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_RECORDS 1000

typedef struct _record
{
    int id;
    char name[50];
    char email[50];
} Record;

typedef struct _index
{
    int id;
    long offset;
} Index;

void add_record_to_database(FILE *database, Record *record, Index *index, int *num_records)
{
    // Append record to the end of the database file
    fseek(database, 0, SEEK_END);
    long offset = ftell(database);
    fwrite(record, sizeof(Record), 1, database);

    // Add new index to the index array
    index[*num_records].id = record->id;
    index[*num_records].offset = offset;

    (*num_records)++;
}

int binary_search(Index *index, int num_records, int key)
{
    int low = 0, high = num_records - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (index[mid].id == key)
            return mid;
        else if (index[mid].id < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void print_record(Record *record)
{
    printf("ID: %d\n", record->id);
    printf("Name: %s\n", record->name);
    printf("Email: %s\n", record->email);
}

int main()
{
    FILE *database_file = fopen("database.dat", "wb+");
    if (!database_file)
    {
        fprintf(stderr, "Error: Could not create database file.\n");
        exit(1);
    }

    // Initialize index array
    Index *index = (Index*) malloc(MAX_NUM_RECORDS * sizeof(Index));
    int num_records = 0;

    // Add some sample records to the database
    Record record1 = { 1, "Alice Smith", "alice.smith@example.com" };
    add_record_to_database(database_file, &record1, index, &num_records);

    Record record2 = { 2, "Bob Johnson", "bob.johnson@example.com" };
    add_record_to_database(database_file, &record2, index, &num_records);

    Record record3 = { 3, "Charlie Brown", "charlie.brown@example.com" };
    add_record_to_database(database_file, &record3, index, &num_records);

    // Test searching for a record by ID
    int search_id = 2;
    int index_pos = binary_search(index, num_records, search_id);
    if (index_pos != -1)
    {
        // Seek to the offset in the database file and read the record
        fseek(database_file, index[index_pos].offset, SEEK_SET);
        Record record;
        fread(&record, sizeof(Record), 1, database_file);
        print_record(&record);
    }
    else
    {
        printf("Record with ID %d not found.\n", search_id);
    }

    fclose(database_file);
    free(index);

    return 0;
}