//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for metadata
typedef struct metadata {
    char key[50];
    char value[1000];
} metadata;

// Define the structure for the extracted metadata
typedef struct extractedMetadata {
    int count;
    metadata *data[50];
} extractedMetadata;

// Function to extract metadata
extractedMetadata* extractMetadata(char *inputString) {
    extractedMetadata *result = (extractedMetadata*) malloc(sizeof(extractedMetadata));
    result->count = 0;
    metadata *temp = (metadata*) malloc(sizeof(metadata));

    // Extract metadata from string
    char *token = strtok(inputString, "\n");
    while(token != NULL) {
        int len = strlen(token);
        if(token[len - 1] == '\r') {
            token[len - 1] = '\0';
        }
        if(strncmp(token, "METADATA", 8) == 0) {
            temp = (metadata*) malloc(sizeof(metadata));
            sscanf(token, "%s %s", temp->key, temp->value);
            result->data[result->count] = temp;
            result->count++;
        } 
        token = strtok(NULL, "\n");
    }
    return result;
}

// Driver code
int main() {
    char inputString[] = "SOME JUNK DATA\nMETADATA AUTHOR Jane Doe\nMETADATA TITLE Sample Title\nMETADATA DATE 01-01-2021\nSOME MORE JUNK DATA\n";
    extractedMetadata *result = extractMetadata(inputString);

    // Print extracted metadata
    for(int i = 0; i < result->count; i++) {
        printf("Key: %s\n", result->data[i]->key);
        printf("Value: %s\n", result->data[i]->value);
    }
    return 0;
}