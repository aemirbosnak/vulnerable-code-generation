//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char *name;
    uint32_t size;
    uint32_t offset;
} metadata_entry_t;

typedef struct {
    char *name;
    uint32_t num_entries;
    metadata_entry_t *entries;
} metadata_table_t;

typedef struct {
    char *name;
    uint32_t num_tables;
    metadata_table_t *tables;
} metadata_file_t;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <metadata file>\n", argv[0]);
        return 1;
    }

    // Open the metadata file
    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("Error opening metadata file: %s\n", argv[1]);
        return 1;
    }

    // Read the metadata file header
    metadata_file_t metadata_file;
    fread(&metadata_file, sizeof(metadata_file_t), 1, f);

    // Print the metadata file name
    printf("Metadata file: %s\n", metadata_file.name);

    // Print the metadata file number of tables
    printf("Number of tables: %u\n", metadata_file.num_tables);

    // Print the metadata file tables
    for (uint32_t i = 0; i < metadata_file.num_tables; i++) {
        metadata_table_t *table = &metadata_file.tables[i];

        // Print the metadata table name
        printf("Table: %s\n", table->name);

        // Print the metadata table number of entries
        printf("Number of entries: %u\n", table->num_entries);

        // Print the metadata table entries
        for (uint32_t j = 0; j < table->num_entries; j++) {
            metadata_entry_t *entry = &table->entries[j];

            // Print the metadata entry name
            printf("Entry: %s\n", entry->name);

            // Print the metadata entry size
            printf("Size: %u\n", entry->size);

            // Print the metadata entry offset
            printf("Offset: %u\n", entry->offset);
        }
    }

    // Close the metadata file
    fclose(f);

    return 0;
}