//FormAI DATASET v1.0 Category: Data recovery tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define data structure for recovered data
typedef struct {
    char* filename;
    char* data;
    int size;
} RecoveredData;

// function to recover data by filename
RecoveredData* recoverData(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File could not be opened.\n");
        return NULL;
    }

    // get file size
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // allocate memory for file data
    char* data = (char*)malloc(size * sizeof(char));
    if (data == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    // read file data into memory
    fread(data, sizeof(char), size, fp);
    if (ferror(fp)) {
        printf("Error: File could not be read.\n");
        free(data);
        return NULL;
    }

    // create recovered data struct and populate with data
    RecoveredData* recoveredData = (RecoveredData*)malloc(sizeof(RecoveredData));
    if (recoveredData == NULL) {
        printf("Error: Memory allocation failed.\n");
        free(data);
        return NULL;
    }
    recoveredData->filename = filename;
    recoveredData->data = data;
    recoveredData->size = size;

    fclose(fp);
    return recoveredData;
}

int main(int argc, char** argv) {
    char* filename = argv[1];

    // recover data and display if successful
    RecoveredData* recoveredData = recoverData(filename);
    if (recoveredData != NULL) {
        printf("Recovered %d bytes from file %s.\n", recoveredData->size, recoveredData->filename);
        printf("Data: %s\n", recoveredData->data);
    }

    return 0;
}