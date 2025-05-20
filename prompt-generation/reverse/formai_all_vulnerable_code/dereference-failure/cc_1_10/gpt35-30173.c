//FormAI DATASET v1.0 Category: Data recovery tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[100];
    printf("Please enter the name of the file you want to recover: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb"); // Open file in binary mode
    if (fp == NULL) {
        printf("Error: file not found.\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END); // Seek to end of file
    long size = ftell(fp); // Get file size
    fseek(fp, 0, SEEK_SET); // Reset file position to beginning

    char *buffer = (char*) malloc(size); // Allocate memory for file content
    if (buffer == NULL) {
        printf("Error: not enough memory to allocate buffer.\n");
        return 0;
    }

    size_t result = fread(buffer, 1, size, fp); // Read file content into buffer
    if (result != size) {
        printf("Error: failed to read file.\n");
        return 0;
    }
    fclose(fp); // Close file

    char newFilename[100];
    printf("Please enter a new name for the recovered file: ");
    scanf("%s", newFilename);

    FILE *newFp = fopen(newFilename, "wb"); // Create new file in binary mode
    if (newFp == NULL) {
        printf("Error: failed to create new file.\n");
        free(buffer);
        return 0;
    }

    fwrite(buffer, 1, size, newFp); // Write content of buffer to new file
    fclose(newFp); // Close new file

    printf("File successfully recovered!\n");
    free(buffer); // free buffer memory
    return 0;
}