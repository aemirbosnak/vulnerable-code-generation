//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

void create_backup(const char *source_file, const char *dest_dir) {
    // Check if source file exists
    if (access(source_file, F_OK) != 0) {
        fprintf(stderr, "Error: Source file %s does not exist.\n", source_file);
        return;
    }

    // Construct the backup filename with timestamp
    time_t now = time(NULL);
    struct tm *tm_info;
    char timestamp[20];
    char backup_filename[256];

    tm_info = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", tm_info);
    
    snprintf(backup_filename, sizeof(backup_filename), "%s/backup_%s_%s", dest_dir, 
             strrchr(source_file, '/') ? strrchr(source_file, '/') + 1 : source_file, timestamp);
    
    // Create the destination directory if it doesn't exist
    struct stat st = {0};
    if (stat(dest_dir, &st) == -1) {
        mkdir(dest_dir, 0700);
    }

    // Open the source file for reading
    FILE *source_fp = fopen(source_file, "rb");
    if (!source_fp) {
        fprintf(stderr, "Error: Could not open source file %s.\n", source_file);
        return;
    }

    // Open the backup file for writing
    FILE *backup_fp = fopen(backup_filename, "wb");
    if (!backup_fp) {
        fprintf(stderr, "Error: Could not create backup file %s.\n", backup_filename);
        fclose(source_fp);
        return;
    }

    // Copy contents from the source file to the backup file
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source_fp)) > 0) {
        fwrite(buffer, 1, bytes, backup_fp);
    }

    fclose(source_fp);
    fclose(backup_fp);
    
    printf("Backup created: %s\n", backup_filename);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_file = argv[1];
    const char *dest_dir = argv[2];

    create_backup(source_file, dest_dir);

    return EXIT_SUCCESS;
}