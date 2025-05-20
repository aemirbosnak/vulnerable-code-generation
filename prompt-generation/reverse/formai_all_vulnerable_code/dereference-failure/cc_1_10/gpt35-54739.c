//FormAI DATASET v1.0 Category: Data recovery tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
    // check if argument is provided
    if (argc < 2) {
        printf("Usage: %s <file path>\n", argv[0]);
        return 0;
    }

    // open file
    FILE* fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Failed to open file %s\n", argv[1]);
        return 0;
    }

    // get size of file
    fseek(fp, 0L, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // allocate buffer
    char* buffer = (char*)malloc(fileSize);
    if (!buffer) {
        printf("Failed to allocate memory\n");
        fclose(fp);
        return 0;
    }

    // read file to buffer
    if (fread(buffer, fileSize, 1, fp) != 1) {
        printf("Failed to read file\n");
        fclose(fp);
        free(buffer);
        return 0;
    }

    // check for invalid characters
    for (int i = 0; i < fileSize; i++) {
        if (buffer[i] < 32 || buffer[i] > 126) {
            printf("Invalid character at position %d\n", i);
        }
    }

    // create backup file
    char* backupName = (char*)malloc(strlen(argv[1]) + 5);
    strcpy(backupName, argv[1]);
    strcat(backupName, ".bak");
    FILE* backup = fopen(backupName, "wb");
    if (!backup) {
        printf("Failed to create backup file\n");
        free(buffer);
        fclose(fp);
        return 0;
    }

    // write buffer to backup file
    if (fwrite(buffer, fileSize, 1, backup) != 1) {
        printf("Failed to write backup file\n");
        free(buffer);
        fclose(fp);
        fclose(backup);
        return 0;
    }

    // close files and free memory
    fclose(fp);
    fclose(backup);
    free(buffer);
    free(backupName);

    printf("Data recovery tool completed successfully\n");

    return 0;
}