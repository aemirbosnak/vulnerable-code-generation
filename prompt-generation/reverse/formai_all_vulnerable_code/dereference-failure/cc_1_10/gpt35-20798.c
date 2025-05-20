//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for metadata types
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define STRING 4

// Define the metadata structure
typedef struct {
    int type;
    void* data;
} metadata;

// Function to extract metadata from a string
metadata* extract_metadata(char* str, int count) {
    // Allocate memory for metadata array
    metadata* meta = (metadata*)malloc(sizeof(metadata) * count);

    // Loop through string, looking for metadata
    char* token = strtok(str, ",");
    int i = 0;
    while (token != NULL) {
        // Check for integer type
        int val_i;
        if (sscanf(token, "%d", &val_i) == 1) {
            meta[i].type = INT;
            int* data = (int*)malloc(sizeof(int));
            *data = val_i;
            meta[i].data = (void*)data;
        }
        // Check for float type
        float val_f;
        if (sscanf(token, "%f", &val_f) == 1) {
            meta[i].type = FLOAT;
            float* data = (float*)malloc(sizeof(float));
            *data = val_f;
            meta[i].data = (void*)data;
        }
        // Check for double type
        double val_d;
        if (sscanf(token, "%lf", &val_d) == 1) {
            meta[i].type = DOUBLE;
            double* data = (double*)malloc(sizeof(double));
            *data = val_d;
            meta[i].data = (void*)data;
        }
        // Check for string type
        if (strlen(token) > 0) {
            meta[i].type = STRING;
            char* data = (char*)malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(data, token);
            meta[i].data = (void*)data;
        }

        // Get next token
        token = strtok(NULL, ",");
        i++;
    }

    // Return metadata array
    return meta;
}

int main() {
    // Define sample metadata string
    char* str = "123,3.14,2.71828,hello world";

    // Extract metadata from string
    metadata* meta = extract_metadata(str, 4);

    // Print out metadata values
    printf("Metadata:\n");
    for (int i = 0; i < 4; i++) {
        printf("Type: %d, Value: ", meta[i].type);
        if (meta[i].type == INT) {
            printf("%d", *((int*)meta[i].data));
        } else if (meta[i].type == FLOAT) {
            printf("%f", *((float*)meta[i].data));
        } else if (meta[i].type == DOUBLE) {
            printf("%lf", *((double*)meta[i].data));
        } else if (meta[i].type == STRING) {
            printf("%s", (char*)meta[i].data);
        }
        printf("\n");
    }

    // Free metadata memory
    for (int i = 0; i < 4; i++) {
        free(meta[i].data);
    }
    free(meta);

    return 0;
}