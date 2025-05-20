//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare the backup function
void backup_file(const char *source_file, const char *destination_file);

int main() {
    // Get the current time
    time_t now = time(NULL);
    struct tm *now_tm = localtime(&now);

    // Create a filename for the backup file
    char backup_file_name[256];
    strftime(backup_file_name, sizeof(backup_file_name), "backup-%Y-%m-%d-%H-%M-%S.tar", now_tm);

    // Backup the file
    backup_file("important_file.txt", backup_file_name);

    printf("Backup complete.\n");

    return 0;
}

// Define the backup function
void backup_file(const char *source_file, const char *destination_file) {
    // Open the source file
    FILE *source = fopen(source_file, "rb");
    if (source == NULL) {
        fprintf(stderr, "Error opening source file: %s\n", source_file);
        exit(1);
    }

    // Open the destination file
    FILE *destination = fopen(destination_file, "wb");
    if (destination == NULL) {
        fprintf(stderr, "Error opening destination file: %s\n", destination_file);
        exit(1);
    }

    // Copy the data from the source file to the destination file
    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes_read, destination);
    }

    // Close the files
    fclose(source);
    fclose(destination);
}