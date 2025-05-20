//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void create_backup(const char *source, const char *backup_dir) {
    struct stat source_info;
    if (stat(source, &source_info) != 0) {
        perror("Failed to get file information");
        return;
    }

    // Check if source is a file or a directory
    if (S_ISDIR(source_info.st_mode)) {
        // It is a directory, create a corresponding backup directory
        char new_backup_dir[512];
        snprintf(new_backup_dir, sizeof(new_backup_dir), "%s/%s_backup", backup_dir, strrchr(source, '/') + 1);

        mkdir(new_backup_dir, 0755);

        DIR *dir = opendir(source);
        if (dir == NULL) {
            perror("Failed to open source directory");
            return;
        }

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char source_path[512];
                snprintf(source_path, sizeof(source_path), "%s/%s", source, entry->d_name);
                create_backup(source_path, new_backup_dir);
            }
        }
        closedir(dir);
    } else if (S_ISREG(source_info.st_mode)) {
        // It is a file, copy it to the backup directory
        FILE *source_file = fopen(source, "rb");
        if (source_file == NULL) {
            perror("Failed to open source file");
            return;
        }

        char backup_file[512];
        snprintf(backup_file, sizeof(backup_file), "%s/%s", backup_dir, strrchr(source, '/') + 1);

        FILE *dest_file = fopen(backup_file, "wb");
        if (dest_file == NULL) {
            perror("Failed to create backup file");
            fclose(source_file);
            return;
        }

        size_t n;
        char buffer[1024];
        while ((n = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
            fwrite(buffer, 1, n, dest_file);
        }

        fclose(source_file);
        fclose(dest_file);
    } else {
        fprintf(stderr, "%s is not a regular file or directory.\n", source);
    }
}

void print_usage() {
    printf("Usage: backup <source_directory_or_file> <backup_directory>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *source = argv[1];
    const char *backup_dir = argv[2];

    // Create backup directory if it doesn't exist
    struct stat st;
    if (stat(backup_dir, &st) != 0 || !S_ISDIR(st.st_mode)) {
        if (mkdir(backup_dir, 0755) != 0) {
            perror("Failed to create backup directory");
            return EXIT_FAILURE;
        }
    }

    create_backup(source, backup_dir);
    printf("Backup completed successfully!\n");
    return EXIT_SUCCESS;
}