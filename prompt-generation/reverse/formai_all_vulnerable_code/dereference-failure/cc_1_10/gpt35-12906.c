//FormAI DATASET v1.0 Category: File Synchronizer ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void copy_file(const char* source, const char* destination) {
    FILE* fs = fopen(source, "rb");
    FILE* fd = fopen(destination, "wb");
    if (fs == NULL || fd == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    char buffer[1024];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), fs)) > 0) {
        fwrite(buffer, 1, n, fd);
    }
    fclose(fs);
    fclose(fd);
}

void copy_dir(const char* source, const char* destination) {
    DIR* dir = opendir(source);
    if (dir == NULL) {
        printf("Error: Unable to open directory.\n");
        exit(1);
    }
    mkdir(destination, 0755);
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char source_path[1024];
        sprintf(source_path, "%s/%s", source, entry->d_name);
        char destination_path[1024];
        sprintf(destination_path, "%s/%s", destination, entry->d_name);
        struct stat st;
        stat(source_path, &st);
        if (S_ISDIR(st.st_mode)) {
            copy_dir(source_path, destination_path);
        } else {
            copy_file(source_path, destination_path);
        }
    }
    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        return 1;
    }
    copy_dir(argv[1], argv[2]);
    printf("Files synchronized successfully.\n");
    return 0;
}