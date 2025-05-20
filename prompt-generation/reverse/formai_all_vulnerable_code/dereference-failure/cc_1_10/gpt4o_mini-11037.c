//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_FILENAME 256
#define MAX_DIR 256

void print_welcome_message() {
    printf("🎉🎈 Welcome to the Happy File Backup System! 🎈🎉\n");
    printf("This program will help you safely back up your precious files! 😊\n\n");
}

void get_source_file(char *source) {
    printf("Please enter the file you want to back up: ");
    fgets(source, MAX_FILENAME, stdin);
    source[strcspn(source, "\n")] = 0; // Remove trailing newline
}

void get_backup_directory(char *backup_dir) {
    printf("Please enter the directory where you want to save the backup: ");
    fgets(backup_dir, MAX_DIR, stdin);
    backup_dir[strcspn(backup_dir, "\n")] = 0; // Remove trailing newline
}

int create_backup(const char *source, const char *backup_dir) {
    char backup_path[MAX_FILENAME + MAX_DIR + 10]; // Space for filename and additional parts
    snprintf(backup_path, sizeof(backup_path), "%s/%s_backup", backup_dir, source);

    int source_fd = open(source, O_RDONLY);
    if (source_fd < 0) {
        printf("😢 Failed to open the source file: %s. Error: %s\n", source, strerror(errno));
        return -1;
    }

    int backup_fd = open(backup_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (backup_fd < 0) {
        printf("😢 Failed to create the backup file in %s. Error: %s\n", backup_dir, strerror(errno));
        close(source_fd);
        return -1;
    }

    char buffer[1024];
    ssize_t bytes_read;
    
    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
        if (write(backup_fd, buffer, bytes_read) != bytes_read) {
            printf("😢 Error writing to the backup file. Error: %s\n", strerror(errno));
            close(source_fd);
            close(backup_fd);
            return -1;
        }
    }

    if (bytes_read < 0) {
        printf("😢 Error reading the source file. Error: %s\n", strerror(errno));
    } else {
        printf("🎉📂 Backup successful! Your file has been backed up to %s\n", backup_path);
    }

    close(source_fd);
    close(backup_fd);
    return 0;
}

int main() {
    print_welcome_message();

    char source[MAX_FILENAME];
    char backup_dir[MAX_DIR];

    // Get the source file and backup directory from the user
    get_source_file(source);
    get_backup_directory(backup_dir);

    // Create the backup
    create_backup(source, backup_dir);
    
    printf("\nThank you for using the Happy File Backup System! Have a wonderful day! 🌈😊\n");
    return 0;
}