//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to get current timestamp as a string
void get_timestamp(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, size, "%Y%m%d_%H%M%S", tm_info);
}

// Function to create a backup of a specified file
int backup_file(const char *source_file, const char *backup_dir) {
    char backup_file_name[256];
    char timestamp[20];
    
    get_timestamp(timestamp, sizeof(timestamp));

    // Construct the new backup file name
    snprintf(backup_file_name, sizeof(backup_file_name), "%s/backup_%s_%s", backup_dir, timestamp, strrchr(source_file, '/') ? strrchr(source_file, '/') + 1 : source_file);

    // Open the source file
    FILE *source = fopen(source_file, "rb");
    if (source == NULL) {
        perror("Failed to open source file");
        return -1;
    }

    // Open the backup file
    FILE *backup = fopen(backup_file_name, "wb");
    if (backup == NULL) {
        perror("Failed to open backup file");
        fclose(source);
        return -1;
    }

    // Copy contents from source file to backup file
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, backup);
    }

    // Clean up
    fclose(source);
    fclose(backup);
    
    printf("Backup successful: %s\n", backup_file_name);
    return 0;
}

// Function to display usage information
void display_usage(const char *prog_name) {
    printf("Usage: %s <source_file> <backup_directory>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_file = argv[1];
    const char *backup_dir = argv[2];

    // Ensure backup directory exists
    struct stat st;
    if (stat(backup_dir, &st) != 0 || !S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Error: Backup directory does not exist: %s\n", backup_dir);
        return EXIT_FAILURE;
    }

    // Perform the backup
    if (backup_file(source_file, backup_dir) != 0) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}