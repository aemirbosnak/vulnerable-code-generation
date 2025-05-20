//FormAI DATASET v1.0 Category: Database Indexing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length for key and data
#define MAX_KEY_LEN 100
#define MAX_DATA_LEN 200

// Define maximum number of records in the database
#define MAX_RECORDS 100

// Define struct for a record
struct Record {
    char key[MAX_KEY_LEN];
    char data[MAX_DATA_LEN];
};

// Define struct for an index
struct Index {
    char key[MAX_KEY_LEN];
    int offset;
};

// Define struct for the database
struct Database {
    FILE* file;
    int num_records;
};

// Initialize the database
void init_database(struct Database* db, const char* filename) {
    db->file = fopen(filename, "wb+");
    db->num_records = 0;
    fseek(db->file, 0, SEEK_SET);
    fwrite(&db->num_records, sizeof(int), 1, db->file);
}

// Close the database
void close_database(struct Database* db) {
    fseek(db->file, 0, SEEK_SET);
    fwrite(&db->num_records, sizeof(int), 1, db->file);
    fclose(db->file);
}

// Add a record to the database
void add_record(struct Database* db, struct Record* record) {
    // Write record to database
    fseek(db->file, 0, SEEK_END);
    fwrite(record, sizeof(struct Record), 1, db->file);
    db->num_records++;

    // Update index
    fseek(db->file, sizeof(int) + db->num_records * sizeof(struct Index), SEEK_SET);
    struct Index index;
    strcpy(index.key, record->key);
    index.offset = ftell(db->file) - sizeof(struct Record);
    fwrite(&index, sizeof(struct Index), 1, db->file);
}

// Get a record from the database by key
struct Record* get_record(struct Database* db, const char* key) {
    // Read index
    fseek(db->file, sizeof(int), SEEK_SET);
    struct Index index;
    for (int i = 0; i < db->num_records; i++) {
        fread(&index, sizeof(struct Index), 1, db->file);
        if (strcmp(index.key, key) == 0) {
            // Found record, read it from database
            fseek(db->file, index.offset, SEEK_SET);
            struct Record* record = malloc(sizeof(struct Record));
            fread(record, sizeof(struct Record), 1, db->file);
            return record;
        }
    }

    // Record not found
    return NULL;
}

int main() {
    // Initialize database
    struct Database db;
    init_database(&db, "database.bin");

    // Add records to database
    struct Record record1 = {"key1", "data1"};
    struct Record record2 = {"key2", "data2"};
    add_record(&db, &record1);
    add_record(&db, &record2);

    // Get records from database
    struct Record* record3 = get_record(&db, "key1");
    struct Record* record4 = get_record(&db, "key2");
    printf("%s: %s\n", record3->key, record3->data);
    printf("%s: %s\n", record4->key, record4->data);

    // Close database
    close_database(&db);

    // Free memory
    free(record3);
    free(record4);

    return 0;
}