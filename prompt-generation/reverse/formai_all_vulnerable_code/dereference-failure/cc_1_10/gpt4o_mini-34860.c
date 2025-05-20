//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void print_usage() {
    printf("Usage: file_backup [source_directory] [backup_directory]\n");
}

int create_backup(const char *source_dir, const char *backup_dir) {
    struct stat st;
    if (stat(source_dir, &st) != 0) {
        perror("Error accessing source directory");
        return -1;
    }

    // Check if source_dir is a directory
    if (!S_ISDIR(st.st_mode)) {
        fprintf(stderr, "%s is not a directory\n", source_dir);
        return -1;
    }

    DIR *dir = opendir(source_dir);
    if (dir == NULL) {
        perror("Error opening source directory");
        return -1;
    }

    // Create backup directory if it doesn't exist
    if (stat(backup_dir, &st) != 0) {
        mkdir(backup_dir, 0755);
    } else if (!S_ISDIR(st.st_mode)) {
        fprintf(stderr, "%s is not a directory\n", backup_dir);
        closedir(dir);
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[1024];
        char backup_path[1024];

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(backup_path, sizeof(backup_path), "%s/%s", backup_dir, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Recursive call for directories
            printf("Backing up directory: %s\n", source_path);
            create_backup(source_path, backup_path);
        } else {
            // Copy files
            printf("Backing up file: %s\n", source_path);
            FILE *source_file = fopen(source_path, "rb");
            if (source_file == NULL) {
                perror("Error opening source file");
                continue;
            }

            FILE *backup_file = fopen(backup_path, "wb");
            if (backup_file == NULL) {
                perror("Error opening backup file");
                fclose(source_file);
                continue;
            }

            char buffer[1024];
            size_t bytes;
            while ((bytes = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                fwrite(buffer, 1, bytes, backup_file);
            }

            fclose(source_file);
            fclose(backup_file);
        }
    }

    closedir(dir);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *backup_directory = argv[2];

    printf("Starting backup from '%s' to '%s'\n", source_directory, backup_directory);
    int result = create_backup(source_directory, backup_directory);

    if (result == 0) {
        printf("Backup completed successfully!\n");
    } else {
        fprintf(stderr, "Backup process encountered errors.\n");
    }

    return EXIT_SUCCESS;
}