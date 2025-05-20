//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUFFER_SIZE 1024

// Define structure to hold extracted metadata
typedef struct {
    char artist[MAX_BUFFER_SIZE];
    char title[MAX_BUFFER_SIZE];
    char album[MAX_BUFFER_SIZE];
    int year;
} Metadata;

// Define function to extract metadata from file
Metadata* extractMetadata(const char* filename) {
    FILE* fileptr = NULL;
    Metadata* metadata = NULL;
    
    // Open file in read mode
    fileptr = fopen(filename, "r");
    if(fileptr == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }
    
    // Allocate memory for metadata structure
    metadata = (Metadata*)malloc(sizeof(Metadata));
    if(metadata == NULL) {
        printf("Error allocating memory.\n");
        fclose(fileptr); // close file before returning
        return NULL;
    }
    
    char buffer[MAX_BUFFER_SIZE];
    char* token = NULL;
    
    // Read through file and extract metadata
    while(fgets(buffer, MAX_BUFFER_SIZE, fileptr) != NULL) {
        token = strtok(buffer, ":");
        if(strcmp(token, "ARTIST") == 0) {
            token = strtok(NULL, "\n");
            strncpy(metadata->artist, token, MAX_BUFFER_SIZE);
        }
        else if(strcmp(token, "TITLE") == 0) {
            token = strtok(NULL, "\n");
            strncpy(metadata->title, token, MAX_BUFFER_SIZE);
        }
        else if(strcmp(token, "ALBUM") == 0) {
            token = strtok(NULL, "\n");
            strncpy(metadata->album, token, MAX_BUFFER_SIZE);
        }
        else if(strcmp(token, "YEAR") == 0) {
            token = strtok(NULL, "\n");
            metadata->year = atoi(token);
        }
    }
    
    fclose(fileptr);
    return metadata;
}

int main() {
    const char* filename = "example.txt";
    Metadata* metadata = extractMetadata(filename);
    
    if(metadata == NULL) {
        printf("Metadata extraction unsuccessful.\n");
        return 1;
    }
    
    printf("ARTIST: %s\n", metadata->artist);
    printf("TITLE: %s\n", metadata->title);
    printf("ALBUM: %s\n", metadata->album);
    printf("YEAR: %d\n", metadata->year);
    
    free(metadata);
    return 0;
}