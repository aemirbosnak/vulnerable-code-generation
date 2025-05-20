//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_FILES 1000

void enchant_copy(const char *source, const char *destination);
int is_file_updated(const char *src_file, const char *dest_file);
void sync_folders(const char *source_dir, const char *dest_dir);
void explore_directory(const char *dir_path, const char *dest_path);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Welcome, brave explorer!\n");
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }

    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];
    
    sync_folders(source_dir, dest_dir);

    printf("The realms have been synchronized. Happy adventuring!\n");
    return 0;
}

void sync_folders(const char *source_dir, const char *dest_dir) {
    printf("Exploring the realm of: %s\n", source_dir);
    explore_directory(source_dir, dest_dir);
}

void explore_directory(const char *dir_path, const char *dest_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    
    if (dp == NULL) {
        perror("Error while opening directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip the "." and ".."
        }

        char source_file[MAX_PATH];
        char dest_file[MAX_PATH];

        snprintf(source_file, sizeof(source_file), "%s/%s", dir_path, entry->d_name);
        snprintf(dest_file, sizeof(dest_file), "%s/%s", dest_path, entry->d_name);
        
        struct stat statbuf;
        if (stat(source_file, &statbuf) == -1) {
            perror("Failed to get file status");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            printf("A new realm discovered! Descending into: %s\n", source_file);
            if (mkdir(dest_file, 0755) == -1) {
                perror("Failed to create directory");
                continue;
            }
            explore_directory(source_file, dest_file); // Recurse into the directory
        } else {
            printf("Found a treasure: %s\n", source_file);
            enchant_copy(source_file, dest_file);
        }
    }
    closedir(dp);
}

void enchant_copy(const char *source, const char *destination) {
    if (access(destination, F_OK) == 0) {
        // File exists, check if we need to update
        if (!is_file_updated(source, destination)) {
            printf("The treasure %s is already enchanted! Skipping...\n", destination);
            return;
        }
    }

    // Perform the actual file copy
    printf("Enchanting and copying: %s to %s\n", source, destination);
    
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");
    if (src == NULL || dest == NULL) {
        perror("Error during file access");
        if (src) fclose(src);
        if (dest) fclose(dest);
        return;
    }

    char buffer[8192];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

int is_file_updated(const char *src_file, const char *dest_file) {
    struct stat src_stat, dest_stat;

    if (stat(src_file, &src_stat) == -1 || stat(dest_file, &dest_stat) == -1) {
        return 1; // Consider as updated if we cannot stat
    }

    return difftime(src_stat.st_mtime, dest_stat.st_mtime) > 0; // Return true if source is newer
}