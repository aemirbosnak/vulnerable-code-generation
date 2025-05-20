//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

/* Define the maximum size of the metadata */
#define MAX_METADATA_SIZE 1000

/* Define the metadata structure */
typedef struct Metadata {
    char name[MAX_METADATA_SIZE];
    char value[MAX_METADATA_SIZE];
} Metadata;

/* Define the function to extract metadata from a file */
Metadata* extract_metadata(const char* filename, int* num_metadata) {
    
    FILE* file = fopen(filename, "r"); /* Open the file in read-only mode */
    
    /* Check if file exists */
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
    
    /* Allocate memory for metadata */
    Metadata* metadata = (Metadata*) malloc(sizeof(Metadata) * MAX_METADATA_SIZE);
    int metadata_count = 0; /* Keep track of the number of metadata lines */
    
    /* Read each line in the file */
    char line[MAX_METADATA_SIZE];
    while (fgets(line, MAX_METADATA_SIZE, file) != NULL) {
        
        /* Check if line contains metadata */
        if (line[0] == '#') {
            
            /* Extract the metadata name and value */
            char name[MAX_METADATA_SIZE], value[MAX_METADATA_SIZE];
            sscanf(line, "# %s %s", name, value);
            
            /* Add metadata to list */
            Metadata m;
            strcpy(m.name, name);
            strcpy(m.value, value);
            metadata[metadata_count++] = m;
        }
    }
    
    /* Close the file */
    fclose(file);
    
    /* Update number of metadata and return metadata array */
    *num_metadata = metadata_count;
    return metadata;
}

int main() {
    
    /* Example usage */
    int num_metadata;
    Metadata* metadata = extract_metadata("example.txt", &num_metadata);
    
    printf("Metadata:\n");
    for (int i = 0; i < num_metadata; i++) {
        printf("%s: %s\n", metadata[i].name, metadata[i].value);
    }
    
    /* Free memory allocated for metadata */
    free(metadata);
    
    return 0;
}