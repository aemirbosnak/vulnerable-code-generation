//FormAI DATASET v1.0 Category: File Backup System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    char* srcFilePath = NULL;
    char* destFilePath = NULL;

    // check if correct number of arguments provided
    if (argc != 3) {
        printf("Usage: program_name source_file_path destination_file_path\n");
        return 1;
    }

    srcFilePath = argv[1];
    destFilePath = argv[2];

    // open source file for reading
    FILE* srcFile = fopen(srcFilePath, "rb");
    if (srcFile == NULL) {
        printf("Failed to open source file");
        return 1;
    }

    // open destination file for writing
    FILE* destFile = fopen(destFilePath, "wb");
    if (destFile == NULL) {
        printf("Failed to open destination file");
        return 1;
    }

    // create a buffer to hold the contents of the source file
    char buffer[BUFFER_SIZE];

    // read source file in chunks and write to destination file
    while (!feof(srcFile)) {
        size_t bytesRead = fread(buffer, 1, BUFFER_SIZE, srcFile);
        size_t bytesWritten = fwrite(buffer, 1, bytesRead, destFile);
        if (bytesWritten != bytesRead) {
            printf("Failed to write to destination file");
            return 1;
        }
    }

    printf("File backup successful");

    // close files
    fclose(srcFile);
    fclose(destFile);

    return 0;
}