//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct _Metadata {
    char *name;
    char *description;
    unsigned long long int size;
    unsigned int version;
} Metadata;

Metadata *extract_metadata(char *file_path) {
    // Initialize the metadata object.
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->name = NULL;
    metadata->description = NULL;
    metadata->size = 0;
    metadata->version = 0;

    // Open the file for reading.
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: unable to open file %s for reading.\n", file_path);
        return NULL;
    }

    // Read the header from the file.
    char header[4];
    if (fread(header, sizeof(char), 4, file) != 4) {
        fprintf(stderr, "Error: unable to read header from file %s.\n", file_path);
        fclose(file);
        return NULL;
    }

    // Check if the file is a valid metadata file.
    if (strncmp(header, "MDTA", 4) != 0) {
        fprintf(stderr, "Error: file %s is not a valid metadata file.\n", file_path);
        fclose(file);
        return NULL;
    }

    // Read the version of the metadata file.
    unsigned int version;
    if (fread(&version, sizeof(unsigned int), 1, file) != 1) {
        fprintf(stderr, "Error: unable to read version from file %s.\n", file_path);
        fclose(file);
        return NULL;
    }

    // Read the size of the metadata file.
    unsigned long long int size;
    if (fread(&size, sizeof(unsigned long long int), 1, file) != 1) {
        fprintf(stderr, "Error: unable to read size from file %s.\n", file_path);
        fclose(file);
        return NULL;
    }

    // Read the name of the metadata file.
    char *name = malloc(size + 1);
    if (fread(name, sizeof(char), size, file) != size) {
        fprintf(stderr, "Error: unable to read name from file %s.\n", file_path);
        fclose(file);
        return NULL;
    }
    name[size] = '\0';

    // Read the description of the metadata file.
    char *description = malloc(size + 1);
    if (fread(description, sizeof(char), size, file) != size) {
        fprintf(stderr, "Error: unable to read description from file %s.\n", file_path);
        fclose(file);
        return NULL;
    }
    description[size] = '\0';

    // Close the file.
    fclose(file);

    // Set the metadata object's fields.
    metadata->name = name;
    metadata->description = description;
    metadata->size = size;
    metadata->version = version;

    // Return the metadata object.
    return metadata;
}

void print_metadata(Metadata *metadata) {
    // Print the metadata object's fields.
    printf("Name: %s\n", metadata->name);
    printf("Description: %s\n", metadata->description);
    printf("Size: %llu\n", metadata->size);
    printf("Version: %u\n", metadata->version);
}

int main(int argc, char **argv) {
    // Check if the user specified a file path.
    if (argc < 2) {
        fprintf(stderr, "Error: no file path specified.\n");
        return 1;
    }

    // Extract the metadata from the file.
    Metadata *metadata = extract_metadata(argv[1]);
    if (metadata == NULL) {
        fprintf(stderr, "Error: unable to extract metadata from file %s.\n", argv[1]);
        return 1;
    }

    // Print the metadata.
    print_metadata(metadata);

    // Free the metadata object.
    free(metadata->name);
    free(metadata->description);
    free(metadata);

    return 0;
}