//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * A simple metadata extractor that reads a file and extracts metadata information
 * Usage: ./metadata_extractor file_path
 */

typedef struct {
    char *key;
    char *value;
} Metadata;

void print_usage() {
    printf("Usage: ./metadata_extractor file_path\n");
}

void extract_metadata(char *file_path) {
    // Open the file
    FILE *fp = fopen(file_path, "r");
    if (!fp) {
        printf("Could not open file: %s\n", file_path);
        return;
    }
    
    // Initialize metadata array
    Metadata metadata[10];
    int metadata_count = 0;
    
    // Read file line by line and extract metadata
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1) {
        // Check if line is a metadata line
        if (line[0] == '[') {
            char *key = strtok(line, "]");
            char *value = strtok(NULL, "]");
            
            // Trim leading and trailing whitespace
            key = strtok(key, " ");
            value = strtok(value, " ");
            
            // Add metadata to array
            metadata[metadata_count].key = key;
            metadata[metadata_count].value = value;
            metadata_count++;
        }
    }
    
    // Print metadata
    printf("Metadata:\n");
    for (int i = 0; i < metadata_count; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }
    
    // Close file
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        print_usage();
        return 1;
    }
    
    extract_metadata(argv[1]);
    
    return 0;
}