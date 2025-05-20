//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_FILES 100

void display_instructions() {
    printf("Welcome to the File Backup System!\n");
    printf("This program allows you to backup files easily.\n");
    printf("Instructions:\n");
    printf("1. Enter the file path to backup.\n");
    printf("2. Specify the backup destination path.\n");
    printf("3. You may enter up to %d files to backup in one session.\n", MAX_FILES);
    printf("4. Type 'exit' to finish and exit the program.\n\n");
}

int backup_file(const char *source, const char *destination) {
    FILE *srcFile, *destFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    srcFile = fopen(source, "rb");
    if (!srcFile) {
        fprintf(stderr, "Error opening source file '%s': %s\n", source, strerror(errno));
        return -1;
    }

    destFile = fopen(destination, "wb");
    if (!destFile) {
        fprintf(stderr, "Error creating backup file '%s': %s\n", destination, strerror(errno));
        fclose(srcFile);
        return -1;
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
    printf("Successfully backed up '%s' to '%s'\n", source, destination);
    return 0;
}

int main() {
    char source[256];
    char destination[256];
    int fileCount = 0;

    display_instructions();

    while (fileCount < MAX_FILES) {
        printf("Enter the path of the file to backup (or 'exit' to quit): ");
        fgets(source, sizeof(source), stdin);
        source[strcspn(source, "\n")] = 0; // Remove newline character

        if (strcmp(source, "exit") == 0) {
            break;
        }

        printf("Enter the destination path for the backup: ");
        fgets(destination, sizeof(destination), stdin);
        destination[strcspn(destination, "\n")] = 0; // Remove newline character

        if (backup_file(source, destination) == 0) {
            fileCount++;
        }
    }

    printf("Backup session ended. Total files backed up: %d\n", fileCount);
    return 0;
}