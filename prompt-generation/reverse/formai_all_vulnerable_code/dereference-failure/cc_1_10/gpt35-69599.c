//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Metadata {
    char name[50];
    int size;
    char type[10];
};

void extract_metadata(const char* file_path, struct Metadata* metadata) {
    // Open the file in read mode
    FILE* fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error: Unable to open the file!\n");
        exit(1);
    }

    // Initialize variables
    char line[100];
    char* key;
    char* value;
    int i = 0;

    // Read each line of the file
    while(fgets(line, sizeof(line), fp)) {
        // Split the line into key and value
        key = strtok(line, " ");
        value = strtok(NULL, "\n");

        // Copy the metadata to the struct
        if (strcmp(key, "Name:") == 0) {
            strcpy(metadata[i].name, value);
        } else if (strcmp(key, "Size:") == 0) {
            metadata[i].size = atoi(value);
        } else if (strcmp(key, "Type:") == 0) {
            strcpy(metadata[i].type, value);
            i++;
        }
    }

    // Close the file
    fclose(fp);
}

int main() {
    // Initialize variables
    const char* file_path = "example.txt";
    struct Metadata metadata[3];

    // Extract the metadata
    extract_metadata(file_path, metadata);

    // Print the metadata
    printf("Metadata:\n");
    for (int i = 0; i < 3; i++) {
        printf("Name: %s\n", metadata[i].name);
        printf("Size: %d\n", metadata[i].size);
        printf("Type: %s\n", metadata[i].type);
        printf("\n");
    }

    return 0;
}