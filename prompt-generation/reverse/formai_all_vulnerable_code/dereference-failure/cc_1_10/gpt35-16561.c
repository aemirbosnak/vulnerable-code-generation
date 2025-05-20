//FormAI DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_KEY 100

// Struct to represent a record in the database
typedef struct {
    int id;
    char key[MAX_KEY];
    char data[MAX_KEY];
} Record;

// Struct to represent an index node
typedef struct {
    char key[MAX_KEY];
    int offset;
} Node;

// Function to read a record from the given file pointer
Record read_record(FILE *fp) {
    Record record;
    fscanf(fp, "%d %s %s", &record.id, record.key, record.data);
    return record;
}

// Function to write a record to the given file pointer
void write_record(FILE *fp, Record record) {
    fprintf(fp, "%d %s %s\n", record.id, record.key, record.data);
}

// Function to compare two nodes by their keys
int compare_nodes(const void *a, const void *b) {
    Node *node_a = (Node *) a;
    Node *node_b = (Node *) b;
    return strcmp(node_a->key, node_b->key);
}

int main() {
    // Open the input and output files
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    // Read the number of records and the block size
    int num_records, block_size;
    fscanf(input_file, "%d %d", &num_records, &block_size);

    // Compute the number of nodes in the index
    int num_nodes = num_records / block_size;
    if (num_records % block_size != 0) {
        num_nodes++;
    }

    // Allocate memory for the nodes in the index
    Node *nodes = (Node *) malloc(num_nodes * sizeof(Node));

    // Read the records from the input file and write them to the output file
    Record record;
    int i = 0, offset = 0;
    while (i < num_records && !feof(input_file)) {
        record = read_record(input_file);

        // Write the record to the output file
        write_record(output_file, record);

        // If this is the first record in a block, add an index node
        if (i % block_size == 0) {
            // Copy the key and offset to the index node
            strcpy(nodes[i / block_size].key, record.key);
            nodes[i / block_size].offset = offset;
        }

        // Increment the offset and record counter
        offset += sizeof(Record);
        i++;
    }

    // Sort the nodes in the index by their keys
    qsort(nodes, num_nodes, sizeof(Node), compare_nodes);

    // Write the index nodes to the output file
    fprintf(output_file, "INDEX:\n");
    for (i = 0; i < num_nodes; i++) {
        fprintf(output_file, "%s %d\n", nodes[i].key, nodes[i].offset);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    // Free the memory allocated for the nodes in the index
    free(nodes);

    return 0;
}