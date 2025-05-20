//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define MAX_INDEX_LENGTH 10

typedef struct Record {
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    struct Record* next;
} Record;

typedef struct Index {
    int id;
    long record_offset;
    struct Index* next;
} Index;

Record* head = NULL;
Index* index_head = NULL;

void add_record(int id, const char* name, const char* address) {
    Record* new_record = (Record*)malloc(sizeof(Record));
    new_record->id = id;
    strcpy(new_record->name, name);
    strcpy(new_record->address, address);
    new_record->next = head;
    head = new_record;

    long offset = (long)(new_record); // For simplicity, we use the address as offset
    Index* new_index = (Index*)malloc(sizeof(Index));
    new_index->id = id;
    new_index->record_offset = offset;
    new_index->next = index_head;
    index_head = new_index;
}

Record* get_record_by_id(int id) {
    Index* current_index = index_head;
    while (current_index != NULL) {
        if (current_index->id == id) {
            Record* record = (Record*)(current_index->record_offset);
            return record;
        }
        current_index = current_index->next;
    }
    return NULL;
}

void print_records() {
    Record* current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s, Address: %s\n", current->id, current->name, current->address);
        current = current->next;
    }
}

void free_memory() {
    Record* current = head;
    while (current != NULL) {
        Record* temp = current;
        current = current->next;
        free(temp);
    }

    Index* current_index = index_head;
    while (current_index != NULL) {
        Index* temp_index = current_index;
        current_index = current_index->next;
        free(temp_index);
    }
}

void read_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];

    while (fscanf(file, "%d, %99[^,], %199[^\n]\n", &id, name, address) == 3) {
        add_record(id, name, address);
    }

    fclose(file);
}

void write_to_file(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Record* current = head;
    while (current != NULL) {
        fprintf(file, "%d, %s, %s\n", current->id, current->name, current->address);
        current = current->next;
    }

    fclose(file);
}

int main() {
    add_record(1, "John Doe", "123 Main St");
    add_record(2, "Jane Smith", "456 Elm St");
    add_record(3, "Alice Brown", "789 Oak St");

    printf("Records after addition:\n");
    print_records();

    int search_id = 2;
    Record* found_record = get_record_by_id(search_id);
    if (found_record) {
        printf("Record found: ID: %d, Name: %s, Address: %s\n", found_record->id, found_record->name, found_record->address);
    } else {
        printf("Record with ID %d not found.\n", search_id);
    }

    write_to_file("records.csv");
    printf("Records written to 'records.csv'.\n");

    // Free memory
    free_memory();

    return 0;
}