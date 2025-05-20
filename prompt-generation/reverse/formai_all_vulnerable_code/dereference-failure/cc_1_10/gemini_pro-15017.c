//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Backup Master Function
void backup_master(char *src_path, char *dest_path) {
    // Get current time for timestamp
    time_t rawtime;
    struct tm *current_time;
    time(&rawtime);
    current_time = localtime(&rawtime);

    // Create destination file path with timestamp
    char dest_file_path[256];
    strftime(dest_file_path, 256, "%Y-%m-%d_%H-%M-%S_", current_time);
    strcat(dest_file_path, src_path);

    // Open source and destination files
    FILE *src_file = fopen(src_path, "rb");
    FILE *dest_file = fopen(dest_file_path, "wb");

    // Check if files were opened successfully
    if (src_file == NULL || dest_file == NULL) {
        perror("Error opening files");
        return;
    }

    // Read and write bytes until end of source file
    int c;
    while ((c = fgetc(src_file)) != EOF) {
        fputc(c, dest_file);
    }

    // Close files
    fclose(src_file);
    fclose(dest_file);

    // Display success message
    printf("File '%s' backed up successfully to '%s'\n", src_path, dest_file_path);
}

int main() {
    // Declare source and destination paths
    char src_path[256];
    char dest_path[256];

    // Get source path from user
    printf("Enter the path of the file you want to back up: ");
    scanf("%s", src_path);

    // Get destination path from user
    printf("Enter the destination path for the backup file: ");
    scanf("%s", dest_path);

    // Call backup master function
    backup_master(src_path, dest_path);

    return 0;
}