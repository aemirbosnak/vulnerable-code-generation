//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>   // For close()
#include <fcntl.h>    // For open()
#include <sys/types.h> // For read() and write()
#include <sys/stat.h>  // For file permissions
#include <errno.h>     // For error handling

#define BUFFER_SIZE 1024
#define BACKUP_SUFFIX ".bak"

// Function prototypes
void create_backup(const char *filename);
void display_usage();

int main(int argc, char *argv[]) {
    // Puzzling aspect: Check for correct usage
    if (argc < 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        create_backup(argv[i]);
    }

    return EXIT_SUCCESS;
}

void create_backup(const char *filename) {
    // Check if the original file exists
    if (access(filename, F_OK) != 0) {
        fprintf(stderr, "Error: File '%s' does not exist.\n", filename);
        return;
    }

    // Construct backup filename
    char backup_filename[256];
    snprintf(backup_filename, sizeof(backup_filename), "%s%s", filename, BACKUP_SUFFIX);

    // Open original file for reading
    int original_fd = open(filename, O_RDONLY);
    if (original_fd < 0) {
        fprintf(stderr, "Error: Unable to open '%s' for reading. %s.\n", filename, strerror(errno));
        return;
    }

    // Create backup file for writing
    int backup_fd = open(backup_filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (backup_fd < 0) {
        fprintf(stderr, "Error: Unable to create backup file '%s'. %s.\n", backup_filename, strerror(errno));
        close(original_fd); // Close original fd in case of error
        return;
    }

    // Read from original and write to backup
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    while ((bytesRead = read(original_fd, buffer, sizeof(buffer))) > 0) {
        if (write(backup_fd, buffer, bytesRead) != bytesRead) {
            fprintf(stderr, "Error: Failed to write to backup file '%s'. %s.\n", backup_filename, strerror(errno));
            break;
        }
    }
    
    // Handle read error
    if (bytesRead < 0) {
        fprintf(stderr, "Error: Failed to read from file '%s'. %s.\n", filename, strerror(errno));
    } else {
        printf("Backup of '%s' created successfully as '%s'\n", filename, backup_filename);
    }

    // Close file descriptors
    close(original_fd);
    close(backup_fd);
}

void display_usage() {
    printf("Usage: backup - Create backups of files\n");
    printf("Example: ./backup file1.txt file2.txt\n");
}