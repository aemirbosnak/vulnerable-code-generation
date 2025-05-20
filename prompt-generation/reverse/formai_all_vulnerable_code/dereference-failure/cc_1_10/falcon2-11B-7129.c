//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store metadata information
typedef struct {
    char* name;
    int age;
    char* city;
} Metadata;

// Function to extract metadata from a file
void extractMetadata(const char* filename, Metadata* metadata) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Split the line into name, age, and city
        char* name = strtok(line, ":");
        char* ageStr = strtok(NULL, ":");
        char* city = strtok(NULL, ":");
        
        // Convert age string to integer
        int age;
        if (sscanf(ageStr, "%d", &age)!= 1) {
            printf("Invalid age format\n");
            continue;
        }
        
        // Store the metadata
        metadata->name = strdup(name);
        metadata->age = age;
        metadata->city = strdup(city);
    }
    
    fclose(file);
}

int main() {
    char filename[] = "metadata.txt";
    Metadata metadata;
    
    // Extract metadata from the file
    extractMetadata(filename, &metadata);
    
    // Print the extracted metadata
    printf("Name: %s\nAge: %d\nCity: %s\n", metadata.name, metadata.age, metadata.city);
    
    // Free the memory allocated for the metadata struct
    free(metadata.name);
    free(metadata.city);
    free(metadata.age);
    
    return 0;
}