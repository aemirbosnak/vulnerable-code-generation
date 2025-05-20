//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure of a metadata entry
typedef struct metadata_entry {
    char *name;
    char *value;
} metadata_entry;

// Define the structure of a metadata table
typedef struct metadata_table {
    int num_entries;
    metadata_entry *entries;
} metadata_table;

// Create a new metadata table
metadata_table *create_metadata_table() {
    metadata_table *table = malloc(sizeof(metadata_table));
    table->num_entries = 0;
    table->entries = NULL;
    return table;
}

// Add an entry to a metadata table
void add_metadata_entry(metadata_table *table, char *name, char *value) {
    table->num_entries++;
    table->entries = realloc(table->entries, table->num_entries * sizeof(metadata_entry));
    table->entries[table->num_entries - 1].name = name;
    table->entries[table->num_entries - 1].value = value;
}

// Print a metadata table
void print_metadata_table(metadata_table *table) {
    for (int i = 0; i < table->num_entries; i++) {
        printf("%s: %s\n", table->entries[i].name, table->entries[i].value);
    }
}

// Free a metadata table
void free_metadata_table(metadata_table *table) {
    for (int i = 0; i < table->num_entries; i++) {
        free(table->entries[i].name);
        free(table->entries[i].value);
    }
    free(table->entries);
    free(table);
}

// Extract metadata from a file
metadata_table *extract_metadata_from_file(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    // Create a metadata table
    metadata_table *table = create_metadata_table();

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Split the line into name and value
        char *name = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Add the entry to the table
        add_metadata_entry(table, name, value);
    }

    // Close the file
    fclose(file);

    // Return the table
    return table;
}

// Main function
int main() {
    // Extract metadata from a file
    metadata_table *table = extract_metadata_from_file("metadata.txt");

    // Print the metadata table
    print_metadata_table(table);

    // Free the metadata table
    free_metadata_table(table);

    return 0;
}