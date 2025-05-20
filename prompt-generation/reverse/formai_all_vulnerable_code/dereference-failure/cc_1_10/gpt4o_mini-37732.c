//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void recover_file(const char *src_path, const char *dest_path) {
    FILE *src = fopen(src_path, "rb");
    if (!src) {
        perror("Failed to open source file for recovery");
        return;
    }
    
    FILE *dest = fopen(dest_path, "wb");
    if (!dest) {
        perror("Failed to create destination file");
        fclose(src);
        return;
    }
    
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }
    
    fclose(src);
    fclose(dest);
    
    printf("Recovered: %s -> %s\n", src_path, dest_path);
}

void scan_directory(const char *dir_path, const char *extension) {
    struct dirent *entry;
    DIR *dir = opendir(dir_path);
    
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    char src_path[512];
    char dest_path[512];
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            if (strstr(entry->d_name, extension)) {
                snprintf(src_path, sizeof(src_path), "%s/%s", dir_path, entry->d_name);
                snprintf(dest_path, sizeof(dest_path), "recovery/%s", entry->d_name);
                recover_file(src_path, dest_path);
            }
        }
    }
    
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <directory> <extension>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct stat st = {0};
    if (stat("recovery", &st) == -1) {
        mkdir("recovery", 0700);
    }

    char *dir_path = argv[1];
    char *extension = argv[2];

    printf("Scavenging through: %s for files with extension: %s\n", dir_path, extension);
    scan_directory(dir_path, extension);
    
    printf("Recovery operation completed!\n");
    return 0;
}