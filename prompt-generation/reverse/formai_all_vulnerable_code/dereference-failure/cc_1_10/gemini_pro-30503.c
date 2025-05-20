//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a database record
typedef struct record {
    int id;
    char name[256];
    char email[256];
} record_t;

// Define the structure of an index node
typedef struct index_node {
    int id;
    int offset;
    struct index_node *next;
} index_node_t;

// Create a new database record
record_t *create_record(int id, char *name, char *email) {
    record_t *record = malloc(sizeof(record_t));
    record->id = id;
    strcpy(record->name, name);
    strcpy(record->email, email);
    return record;
}

// Insert a record into the database
void insert_record(record_t *record, FILE *fp) {
    fseek(fp, 0, SEEK_END);
    fwrite(record, sizeof(record_t), 1, fp);
}

// Create a new index node
index_node_t *create_index_node(int id, int offset) {
    index_node_t *node = malloc(sizeof(index_node_t));
    node->id = id;
    node->offset = offset;
    node->next = NULL;
    return node;
}

// Insert an index node into the index
void insert_index_node(index_node_t *node, FILE *fp) {
    fseek(fp, 0, SEEK_END);
    fwrite(node, sizeof(index_node_t), 1, fp);
}

// Search for a record in the database using the index
record_t *search_record(int id, FILE *fp) {
    // Read the index file
    FILE *index_fp = fopen("index.bin", "rb");
    if (index_fp == NULL) {
        return NULL;
    }

    // Search for the index node
    index_node_t *node = NULL;
    while (fread(node, sizeof(index_node_t), 1, index_fp) == 1) {
        if (node->id == id) {
            break;
        }
    }

    // Close the index file
    fclose(index_fp);

    // If the index node was not found, return NULL
    if (node == NULL) {
        return NULL;
    }

    // Read the record from the database file
    fseek(fp, node->offset, SEEK_SET);
    record_t *record = malloc(sizeof(record_t));
    fread(record, sizeof(record_t), 1, fp);

    // Return the record
    return record;
}

// Print the contents of the database
void print_database(FILE *fp) {
    // Read the database file
    fseek(fp, 0, SEEK_SET);
    record_t record;
    while (fread(&record, sizeof(record_t), 1, fp) == 1) {
        printf("ID: %d\n", record.id);
        printf("Name: %s\n", record.name);
        printf("Email: %s\n\n", record.email);
    }
}

// Main function
int main() {
    // Create a database file
    FILE *fp = fopen("database.bin", "wb");
    if (fp == NULL) {
        perror("Error creating database file");
        return EXIT_FAILURE;
    }

    // Insert some records into the database
    insert_record(create_record(1, "John Doe", "john.doe@example.com"), fp);
    insert_record(create_record(2, "Jane Doe", "jane.doe@example.com"), fp);
    insert_record(create_record(3, "Peter Parker", "peter.parker@example.com"), fp);

    // Create an index file
    FILE *index_fp = fopen("index.bin", "wb");
    if (index_fp == NULL) {
        perror("Error creating index file");
        return EXIT_FAILURE;
    }

    // Insert some index nodes into the index
    insert_index_node(create_index_node(1, 0), index_fp);
    insert_index_node(create_index_node(2, sizeof(record_t)), index_fp);
    insert_index_node(create_index_node(3, sizeof(record_t) * 2), index_fp);

    // Close the database and index files
    fclose(fp);
    fclose(index_fp);

    // Search for a record in the database using the index
    record_t *record = search_record(2, fp);
    if (record == NULL) {
        printf("Record not found\n");
    } else {
        printf("ID: %d\n", record->id);
        printf("Name: %s\n", record->name);
        printf("Email: %s\n", record->email);
    }

    // Print the contents of the database
    fp = fopen("database.bin", "rb");
    print_database(fp);

    // Close the database file
    fclose(fp);

    return EXIT_SUCCESS;
}