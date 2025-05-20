//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define BLOCK_SIZE 512
#define MAX_FILES 100
#define BACKUP_DIR "data_recovery_backup" 

void create_backup_directory() {
    struct stat st = {0};

    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
        printf("Backup directory '%s' created.\n", BACKUP_DIR);
    } else {
        printf("Backup directory '%s' already exists.\n", BACKUP_DIR);
    }
}

void recover_file(const char *file_path) {
    char buffer[BLOCK_SIZE];
    int source_fd = open(file_path, O_RDONLY);
    
    if (source_fd == -1) {
        perror("Error opening file for recovery");
        return;
    }
    
    // Create the backup file in the specified directory
    char backup_file_path[256];
    snprintf(backup_file_path, sizeof(backup_file_path), "%s/%s", BACKUP_DIR, strrchr(file_path, '/') + 1);
    int backup_fd = open(backup_file_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    if (backup_fd == -1) {
        perror("Error creating backup file");
        close(source_fd);
        return;
    }

    int bytesRead;
    while ((bytesRead = read(source_fd, buffer, BLOCK_SIZE)) > 0) {
        if (write(backup_fd, buffer, bytesRead) != bytesRead) {
            perror("Error writing to backup file");
            break;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading from source file");
    } else {
        printf("Successfully recovered file: %s\n", backup_file_path);
    }

    close(source_fd);
    close(backup_fd);
}

void list_files(const char *directory, int recover) {
    struct dirent *de;
    DIR *dr = opendir(directory);
    
    if (dr == NULL) {
        perror("Could not open directory");
        return;
    }

    printf("Listing files in directory '%s':\n", directory);
    while ((de = readdir(dr)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) {
            char file_path[256];
            snprintf(file_path, sizeof(file_path), "%s/%s", directory, de->d_name);
            printf("Found file: %s\n", file_path);
            if (recover) {
                recover_file(file_path);
            }
        }
    }

    closedir(dr);
}

void print_usage(const char *program_name) {
    printf("Usage: %s <directory_to_recover> <recover_option>\n", program_name);
    printf("recover_option: 1 to recover files, 0 to just list files\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    int recover = atoi(argv[2]);
    if (recover < 0 || recover > 1) {
        printf("Invalid recover option. Use 1 for recovering files and 0 for listing only.\n");
        return EXIT_FAILURE;
    }

    // Create a backup directory if it doesn't exist
    create_backup_directory();

    // List files and optionally recover them
    list_files(argv[1], recover);

    return EXIT_SUCCESS;
}