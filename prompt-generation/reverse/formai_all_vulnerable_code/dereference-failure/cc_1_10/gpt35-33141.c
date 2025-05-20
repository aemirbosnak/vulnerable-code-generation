//FormAI DATASET v1.0 Category: File Backup System ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define BUFFER_SIZE 1024

typedef struct {
    char* source_dir;
    char* backup_dir;
    time_t last_backup;
} BackupConfig;

void print_usage() {
    printf("Usage: backup <source directory> <backup directory>\n");
}

int is_dir(const char* path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

int has_extension(const char* filename, const char* extension) {
    size_t len_file = strlen(filename);
    size_t len_ext = strlen(extension);
    if (len_file < len_ext) {
        return 0;
    }
    return strcmp(filename + len_file - len_ext, extension) == 0;
}

int copy_file(const char* src_path, const char* dst_path) {
    char buffer[BUFFER_SIZE];
    FILE* src_file = fopen(src_path, "rb");
    if (src_file == NULL) {
        perror("Error opening source file");
        return 0;
    }
    FILE* dst_file = fopen(dst_path, "wb");
    if (dst_file == NULL) {
        perror("Error opening destination file");
        fclose(src_file);
        return 0;
    }
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        size_t bytes_written = fwrite(buffer, 1, bytes_read, dst_file);
        if (bytes_written < bytes_read) {
            perror("Error writing to destination file");
            fclose(src_file);
            fclose(dst_file);
            return 0;
        }
    }
    fclose(src_file);
    fclose(dst_file);
    return 1;
}

int backup_file(const char* src_path, const char* dst_path) {
    if (copy_file(src_path, dst_path)) {
        printf("Backed up '%s' to '%s'\n", src_path, dst_path);
        return 1;
    } else {
        return 0;
    }
}

int backup_dir(const char* src_dir, const char* dst_dir) {
    DIR* dir = opendir(src_dir);
    if (dir == NULL) {
        perror("Error opening directory");
        return 0;
    }
    int num_backed_up = 0;
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG && has_extension(entry->d_name, ".c")) {
            char src_path[256];
            char dst_path[256];
            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
            snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);
            if (backup_file(src_path, dst_path)) {
                num_backed_up++;
            }
        }
    }
    closedir(dir);
    printf("Backed up %d files from '%s' to '%s'\n", num_backed_up, src_dir, dst_dir);
    return 1;
}

int backup_files(const BackupConfig* config) {
    return backup_dir(config->source_dir, config->backup_dir);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }
    BackupConfig config = {
        .source_dir = argv[1],
        .backup_dir = argv[2],
        .last_backup = time(NULL)
    };
    backup_files(&config);
    return EXIT_SUCCESS;
}