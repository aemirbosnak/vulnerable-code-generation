//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 5
#define BUFFER_SIZE 1024

typedef struct record {
    char name[50];
    int age;
    float salary;
} record_t;

typedef struct database {
    char *file_name;
    int records_count;
    record_t *records;
} database_t;

void create_database(database_t *db) {
    // Create a new database file
    int fd = open(db->file_name, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error creating database file");
        exit(EXIT_FAILURE);
    }

    // Set the database file size
    ftruncate(fd, sizeof(record_t) * MAX_RECORDS);

    // Map the database file into memory
    db->records = mmap(NULL, sizeof(record_t) * MAX_RECORDS, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (db->records == MAP_FAILED) {
        perror("Error mapping database file into memory");
        exit(EXIT_FAILURE);
    }

    // Close the database file
    close(fd);
}

void insert_record(database_t *db, char *name, int age, float salary) {
    // Find the last record in the database
    record_t *last_record = db->records + db->records_count;

    // Create a new record and insert it into the database
    record_t new_record = {
        .name = name,
        .age = age,
        .salary = salary
    };
    memcpy(last_record, &new_record, sizeof(record_t));
    db->records_count++;

    // Flush the changes to disk
    fsync(db->records);
}

void query_records(database_t *db, char *query) {
    // Find the first record in the database
    record_t *first_record = db->records;

    // Iterate over the records and print the ones that match the query
    for (int i = 0; i < db->records_count; i++) {
        record_t *current_record = first_record + i;
        if (strcmp(current_record->name, query) == 0) {
            printf("%s %d %f\n", current_record->name, current_record->age, current_record->salary);
        }
    }
}

int main() {
    // Create a new database
    database_t db = {
        .file_name = "my_database",
        .records_count = 0,
        .records = NULL
    };
    create_database(&db);

    // Insert some records
    insert_record(&db, "Alice", 25, 50000.0);
    insert_record(&db, "Bob", 30, 60000.0);
    insert_record(&db, "Charlie", 35, 70000.0);

    // Query the records
    query_records(&db, "Alice");

    // Clean up
    munmap(db.records, sizeof(record_t) * MAX_RECORDS);
    close(open(db.file_name, O_RDWR, 0644));

    return 0;
}