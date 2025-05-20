//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database table definition
typedef struct {
    int id;
    char *name;
    int age;
} Person;

// Database index definition
typedef struct {
    int id;
    int offset;
} IndexEntry;

// Database file path
#define DB_FILE "database.bin"

// Index file path
#define INDEX_FILE "index.bin"

// Maximum number of records in the database
#define MAX_RECORDS 1000

// Maximum length of a record name
#define MAX_NAME_LENGTH 50

// Create a new database file
FILE *create_database_file() {
    FILE *fp = fopen(DB_FILE, "wb");
    if (fp == NULL) {
        perror("Error creating database file");
        exit(EXIT_FAILURE);
    }
    return fp;
}

// Create a new index file
FILE *create_index_file() {
    FILE *fp = fopen(INDEX_FILE, "wb");
    if (fp == NULL) {
        perror("Error creating index file");
        exit(EXIT_FAILURE);
    }
    return fp;
}

// Write a record to the database file
void write_record(FILE *fp, Person *person) {
    fwrite(&person->id, sizeof(int), 1, fp);
    fwrite(person->name, sizeof(char), strlen(person->name) + 1, fp);
    fwrite(&person->age, sizeof(int), 1, fp);
}

// Write an index entry to the index file
void write_index_entry(FILE *fp, IndexEntry *index_entry) {
    fwrite(&index_entry->id, sizeof(int), 1, fp);
    fwrite(&index_entry->offset, sizeof(int), 1, fp);
}

// Read a record from the database file
Person *read_record(FILE *fp, int offset) {
    Person *person = malloc(sizeof(Person));
    if (person == NULL) {
        perror("Error allocating memory for person");
        exit(EXIT_FAILURE);
    }
    fseek(fp, offset, SEEK_SET);
    fread(&person->id, sizeof(int), 1, fp);
    person->name = malloc(sizeof(char) * MAX_NAME_LENGTH);
    if (person->name == NULL) {
        perror("Error allocating memory for person name");
        exit(EXIT_FAILURE);
    }
    fread(person->name, sizeof(char), MAX_NAME_LENGTH, fp);
    fread(&person->age, sizeof(int), 1, fp);
    return person;
}

// Read an index entry from the index file
IndexEntry *read_index_entry(FILE *fp, int offset) {
    IndexEntry *index_entry = malloc(sizeof(IndexEntry));
    if (index_entry == NULL) {
        perror("Error allocating memory for index entry");
        exit(EXIT_FAILURE);
    }
    fseek(fp, offset, SEEK_SET);
    fread(&index_entry->id, sizeof(int), 1, fp);
    fread(&index_entry->offset, sizeof(int), 1, fp);
    return index_entry;
}

// Build an index for the database
void build_index(FILE *db_fp, FILE *index_fp) {
    int offset = 0;
    for (int i = 0; i < MAX_RECORDS; i++) {
        Person *person = read_record(db_fp, offset);
        IndexEntry *index_entry = malloc(sizeof(IndexEntry));
        if (index_entry == NULL) {
            perror("Error allocating memory for index entry");
            exit(EXIT_FAILURE);
        }
        index_entry->id = person->id;
        index_entry->offset = offset;
        write_index_entry(index_fp, index_entry);
        offset += sizeof(int) + strlen(person->name) + 1 + sizeof(int);
        free(person->name);
        free(person);
        free(index_entry);
    }
}

// Search for a record in the database using the index
Person *search_record(FILE *db_fp, FILE *index_fp, int id) {
    // Read the index entry for the given id
    IndexEntry *index_entry = malloc(sizeof(IndexEntry));
    if (index_entry == NULL) {
        perror("Error allocating memory for index entry");
        exit(EXIT_FAILURE);
    }
    fseek(index_fp, id * sizeof(IndexEntry), SEEK_SET);
    fread(&index_entry->id, sizeof(int), 1, index_fp);
    fread(&index_entry->offset, sizeof(int), 1, index_fp);

    // Read the record from the database file
    Person *person = read_record(db_fp, index_entry->offset);

    // Free the allocated memory
    free(index_entry);

    // Return the found record
    return person;
}

// Print the database records
void print_records(FILE *db_fp) {
    int offset = 0;
    for (int i = 0; i < MAX_RECORDS; i++) {
        Person *person = read_record(db_fp, offset);
        printf("Record %d: %d %s %d\n", i + 1, person->id, person->name, person->age);
        offset += sizeof(int) + strlen(person->name) + 1 + sizeof(int);
        free(person->name);
        free(person);
    }
}

// Main function
int main() {
    // Create the database file
    FILE *db_fp = create_database_file();

    // Create the index file
    FILE *index_fp = create_index_file();

    // Write some records to the database file
    Person person1 = {1, "John Doe", 30};
    Person person2 = {2, "Jane Doe", 25};
    Person person3 = {3, "Peter Parker", 20};
    write_record(db_fp, &person1);
    write_record(db_fp, &person2);
    write_record(db_fp, &person3);

    // Build the index for the database
    build_index(db_fp, index_fp);

    // Search for a record in the database using the index
    int id = 2;
    Person *person = search_record(db_fp, index_fp, id);

    // Print the found record
    printf("Found record: %d %s %d\n", person->id, person->name, person->age);

    // Print all the records in the database
    print_records(db_fp);

    // Close the database and index files
    fclose(db_fp);
    fclose(index_fp);

    return 0;
}