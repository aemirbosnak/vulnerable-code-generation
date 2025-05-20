//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

int main(int argc, char *argv[]) {
    char original_filename[MAX_FILENAME_LENGTH];
    char backup_filename[MAX_FILENAME_LENGTH];
    FILE *original_file, *backup_file;

    // Check if the correct number of arguments is provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(original_filename, argv[1]);

    // Create backup filename
    strcpy(backup_filename, original_filename);
    strcat(backup_filename, ".bak");

    // Open the original file
    original_file = fopen(original_filename, "r");
    if (original_file == NULL) {
        perror("Error opening original file");
        return 1;
    }

    // Open the backup file for writing
    backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        perror("Error creating backup file");
        fclose(original_file);
        return 1;
    }

    // Copy the contents of the original file to the backup file
    while (!feof(original_file)) {
        int c = fgetc(original_file);
        fputc(c, backup_file);
    }

    // Close the files
    fclose(original_file);
    fclose(backup_file);

    // Print a happy message upon successful completion
    printf("\033[38;5;202mSUCCESS!\033[0m Backup file '%s' created.", backup_filename);

    return 0;
}