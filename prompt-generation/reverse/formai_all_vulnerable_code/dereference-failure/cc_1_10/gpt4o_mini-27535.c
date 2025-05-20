//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage: ./backup_system <source_directory> <backup_directory>\n");
}

void create_backup(const char *source, const char *backup) {
    struct stat statbuf;
    if (stat(source, &statbuf) != 0) {
        perror("Source path error");
        return;
    }

    if (S_ISDIR(statbuf.st_mode)) {
        DIR *dir = opendir(source);
        if (!dir) {
            perror("Failed to open directory");
            return;
        }

        struct dirent *entry;
        char source_path[MAX_PATH], backup_path[MAX_PATH];

        while ((entry = readdir(dir)) != NULL) {
            // Skipping the special entries "." and ".."
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            snprintf(source_path, sizeof(source_path), "%s/%s", source, entry->d_name);
            snprintf(backup_path, sizeof(backup_path), "%s/%s", backup, entry->d_name);

            if (entry->d_type == DT_DIR) {
                // Recursively create backup for directories
                mkdir(backup_path, 0700);
                create_backup(source_path, backup_path);
            } else {
                FILE *src_file = fopen(source_path, "rb");
                if (!src_file) {
                    perror("Failed to open source file");
                    continue;
                }

                FILE *dest_file = fopen(backup_path, "wb");
                if (!dest_file) {
                    perror("Failed to create backup file");
                    fclose(src_file);
                    continue;
                }

                char buffer[BUFFER_SIZE];
                size_t bytes;
                while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) != 0) {
                    fwrite(buffer, 1, bytes, dest_file);
                }

                fclose(src_file);
                fclose(dest_file);
                printf("Backed up: %s -> %s\n", source_path, backup_path);
            }
        }
        closedir(dir);
    } else {
        printf("Ignoring non-directory source: %s\n", source);
    }
}

void generate_backup_name(const char *base, char *backup_name) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(backup_name, "%s_backup_%04d-%02d-%02d_%02d-%02d-%02d", base, tm.tm_year + 1900,
            tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    char backup_name[MAX_PATH];
    generate_backup_name(argv[2], backup_name);
    
    // Create the backup directory
    if (mkdir(backup_name, 0700) != 0) {
        perror("Failed to create backup directory");
        return EXIT_FAILURE;
    }

    printf("Backup will be stored in: %s\n", backup_name);
    create_backup(argv[1], backup_name);

    printf("Backup completed successfully!\n");
    return EXIT_SUCCESS;
}