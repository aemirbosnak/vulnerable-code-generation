//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void print_usage() {
    printf("Usage: file_sync <source_directory> <target_directory>\n");
}

int is_file_newer(const char *source_file, const char *target_file) {
    struct stat src_stat, tgt_stat;
    if (stat(source_file, &src_stat) != 0 || stat(target_file, &tgt_stat) != 0) {
        return 0; // If either file doesn't exist, we consider it not newer
    }
    return difftime(src_stat.st_mtime, tgt_stat.st_mtime) > 0;
}

void synchronize_file(const char *source_file, const char *target_file) {
    FILE *src = fopen(source_file, "rb");
    if (!src) {
        perror("Failed to open source file");
        return;
    }
    
    FILE *tgt = fopen(target_file, "wb");
    if (!tgt) {
        perror("Failed to open target file");
        fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, tgt);
    }

    fclose(src);
    fclose(tgt);
    printf("Synchronized: %s -> %s\n", source_file, target_file);
}

void sync_directory(const char *source_dir, const char *target_dir) {
    DIR *dir = opendir(source_dir);
    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files
        }

        char source_file[512];
        char target_file[512];

        snprintf(source_file, sizeof(source_file), "%s/%s", source_dir, entry->d_name);
        snprintf(target_file, sizeof(target_file), "%s/%s", target_dir, entry->d_name);

        struct stat buf;
        if (stat(source_file, &buf) == 0) {
            if (S_ISREG(buf.st_mode)) { // Regular file
                if (access(target_file, F_OK) == -1 || is_file_newer(source_file, target_file)) {
                    synchronize_file(source_file, target_file);
                }
            } else if (S_ISDIR(buf.st_mode)) { // Directory
                mkdir(target_file, 0755);
                sync_directory(source_file, target_file);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    const char *source_directory = argv[1];
    const char *target_directory = argv[2];

    sync_directory(source_directory, target_directory);

    return 0;
}