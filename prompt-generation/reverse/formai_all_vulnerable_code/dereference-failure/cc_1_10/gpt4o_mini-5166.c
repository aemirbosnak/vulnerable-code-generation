//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function to display usage instructions
void display_help() {
    printf("Usage: filebackup <source_file> <backup_location>\n");
    printf("Example: filebackup myfile.txt /path/to/backup/\n");
}

// Function to back up the file
int backup_file(const char *source, const char *dest) {
    FILE *src_file = fopen(source, "rb");
    if (!src_file) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return -1;
    }

    // Constructing the destination filename
    char *dest_file_path = malloc(strlen(dest) + strlen(source) + 2);
    if (!dest_file_path) {
        fprintf(stderr, "Memory allocation error\n");
        fclose(src_file);
        return -1;
    }
    sprintf(dest_file_path, "%s/%s", dest, strrchr(source, '/') ? strrchr(source, '/') + 1 : source);

    FILE *backup_file = fopen(dest_file_path, "wb");
    if (!backup_file) {
        fprintf(stderr, "Error creating backup file: %s\n", strerror(errno));
        free(dest_file_path);
        fclose(src_file);
        return -1;
    }

    size_t bytes_read;
    char buffer[1024];
    
    // Read from the source file and write to the backup file
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    // Check for any read errors
    if (ferror(src_file)) {
        fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
    }

    fclose(src_file);
    fclose(backup_file);
    free(dest_file_path);
    
    printf("Backup of %s completed successfully to %s\n", source, dest_file_path);
    return 0;
}

int main(int argc, char *argv[]) {
    // Validate input arguments
    if (argc != 3) {
        display_help();
        return EXIT_FAILURE;
    }

    const char *source_file = argv[1];
    const char *backup_location = argv[2];

    return backup_file(source_file, backup_location);
}