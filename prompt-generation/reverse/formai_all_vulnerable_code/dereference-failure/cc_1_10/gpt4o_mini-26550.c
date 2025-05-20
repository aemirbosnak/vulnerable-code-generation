//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 8192

void print_usage() {
    printf("Usage: filebackup <source_directory> <backup_directory>\n");
    printf("Example: filebackup /home/user/documents /home/user/backup\n");
}

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("Error opening source file");
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes_read, dest);
    }

    fclose(src);
    fclose(dest);
}

void backup_directory(const char *src_dir, const char *dest_dir) {
    struct stat st;
    if (stat(src_dir, &st) != 0 || !S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Source directory is invalid: %s\n", src_dir);
        return;
    }

    DIR *dir = opendir(src_dir);
    if (!dir) {
        perror("Error opening source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directory entries
        }

        char src_path[MAX_PATH];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        
        char dest_path[MAX_PATH];
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);
        
        if (entry->d_type == DT_DIR) {
            // Create sub-directory in backup
            mkdir(dest_path, 0755);
            // Recur into the directory
            backup_directory(src_path, dest_path);
        } else if (entry->d_type == DT_REG) {
            // Copy the file
            copy_file(src_path, dest_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *source = argv[1];
    const char *backup = argv[2];

    // Create the backup directory
    mkdir(backup, 0755);

    // Start backup process
    backup_directory(source, backup);

    printf("Backup completed from '%s' to '%s'\n", source, backup);
    return EXIT_SUCCESS;
}