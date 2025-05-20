//FormAI DATASET v1.0 Category: File Backup System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * This is a C File Backup System program that creates a backup of a specified source
 * file and saves it with a timestamped filename in a specified backup directory.
 */

int main(int argc, char **argv)
{
    // Check that command line arguments are valid
    if (argc != 3) {
        printf("Usage: %s <source_file> <backup_dir>\n", argv[0]);
        exit(1);
    }

    // Open the source file
    FILE *src_file = fopen(argv[1], "r");

    // Check that source file exists and can be opened for reading
    if (src_file == NULL) {
        printf("Error: could not open source file '%s'\n", argv[1]);
        exit(1);
    }

    // Create timestamped filename for backup file
    time_t current_time = time(NULL);
    struct tm *tm = localtime(&current_time);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", tm);
    char backup_filename[strlen(argv[1]) + strlen(timestamp) + 2];
    sprintf(backup_filename, "%s.%s", argv[1], timestamp);

    // Open backup file for writing
    FILE *backup_file = fopen(backup_filename, "w");

    // Check that backup file was created and can be opened for writing
    if (backup_file == NULL) {
        printf("Error: could not create backup file '%s'\n", backup_filename);
        fclose(src_file);
        exit(1);
    }

    // Copy contents of source file to backup file
    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup_file);
    }

    // Close files
    fclose(src_file);
    fclose(backup_file);

    // Print success message with filenames
    printf("Successfully backed up '%s' to '%s'\n", argv[1], backup_filename);

    return 0;
}