//FormAI DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Function to copy the source file to the destination file
void copy_file(const char *src_path, const char *dest_path) {
    FILE *src_file = fopen(src_path, "r");
    FILE *dest_file = fopen(dest_path, "w");
    if (src_file == NULL) {
        printf("Error: Unable to open the source file!\n");
        exit(1);
    }
    if (dest_file == NULL) {
        printf("Error: Unable to open the destination file!\n");
        fclose(src_file);
        exit(1);
    }

    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    printf("File copied successfully!\n");
}

// Function to create a backup of the specified file
void create_backup(const char *path) {
    // Generate the backup file name
    time_t current_time = time(NULL);
    char backup_path[256];
    strftime(backup_path, sizeof(backup_path), "backup_%Y-%m-%d_%H-%M-%S", localtime(&current_time));
    strcat(backup_path, ".bak");

    // Create the backup file
    copy_file(path, backup_path);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: Please specify a file to backup!\n");
        return 1;
    }
    const char *path = argv[1];
    create_backup(path);
    return 0;
}