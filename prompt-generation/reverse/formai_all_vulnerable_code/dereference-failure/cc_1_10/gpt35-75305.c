//FormAI DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum size of the file to be recovered */
#define MAX_FILE_SIZE 1024

/* Define a struct to hold the recovered data */
typedef struct {
    char filename[32];
    char* data;
    size_t size;
} RecoveredFile;

/* Function prototype */
RecoveredFile* recoverData(char*);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(1);
    }

    RecoveredFile* recoveredFile = recoverData(argv[1]);

    if (recoveredFile == NULL) {
        printf("Failed to recover data from %s\n", argv[1]);
        exit(1);
    }

    printf("Recovered data from %s:\n%s\n", recoveredFile->filename, recoveredFile->data);

    free(recoveredFile->data);
    free(recoveredFile);

    return 0;
}

RecoveredFile* recoverData(char* filename) {
    /* Open the file */
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        return NULL;
    }

    /* Allocate memory for the recovered file */
    RecoveredFile* recoveredFile = malloc(sizeof(RecoveredFile));

    /* Copy the filename */
    strcpy(recoveredFile->filename, filename);

    /* Allocate memory for the data */
    recoveredFile->data = malloc(MAX_FILE_SIZE);

    /* Read the data */
    size_t bytesRead = fread(recoveredFile->data, sizeof(char), MAX_FILE_SIZE, file);

    /* Set the size of the recovered file */
    recoveredFile->size = bytesRead;

    /* Close the file */
    fclose(file);

    /* Return the recovered file */
    return recoveredFile;
}