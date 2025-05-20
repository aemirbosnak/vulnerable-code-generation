//FormAI DATASET v1.0 Category: File Synchronizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 255
#define MAX_FILE_BUFFER_SIZE 1024

bool is_dir(const char* path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

bool create_dir(const char* path) {
    if(mkdir(path, 0700) == 0) {
        return true;
    }
    return false;
}

void sync_directories(const char* source_path, const char* dest_path) {
    DIR* source_dir = opendir(source_path);
    struct dirent* source_ent;
    struct stat source_stat;

    while((source_ent = readdir(source_dir)) != NULL) {
        char source_file_path[MAX_FILENAME_LENGTH];
        sprintf(source_file_path, "%s/%s", source_path, source_ent->d_name);

        if(strcmp(source_ent->d_name, ".") == 0 || strcmp(source_ent->d_name, "..") == 0) {
            continue;
        }

        if(stat(source_file_path, &source_stat) != 0) {
            continue;
        }

        if(is_dir(source_file_path)) {
            char dest_file_path[MAX_FILENAME_LENGTH];
            sprintf(dest_file_path, "%s/%s", dest_path, source_ent->d_name);

            if(!is_dir(dest_file_path)) {
                create_dir(dest_file_path);
            }

            sync_directories(source_file_path, dest_file_path);
        } else {
            char dest_file_path[MAX_FILENAME_LENGTH];
            sprintf(dest_file_path, "%s/%s", dest_path, source_ent->d_name);

            FILE* source_file = fopen(source_file_path, "rb");
            FILE* dest_file = fopen(dest_file_path, "wb");

            if(source_file == NULL || dest_file == NULL) {
                continue;
            }

            char file_buffer[MAX_FILE_BUFFER_SIZE];
            size_t num_bytes_read = 0;
            while((num_bytes_read = fread(file_buffer, 1, MAX_FILE_BUFFER_SIZE, source_file)) > 0) {
                fwrite(file_buffer, 1, num_bytes_read, dest_file);
            }

            fclose(source_file);
            fclose(dest_file);
        }
    }

    closedir(source_dir);
}

int main(int argc, char* argv[]) {

    if(argc != 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        exit(1);
    }

    sync_directories(argv[1], argv[2]);

    printf("Directories synchronized successfully!\n");

    return 0;
}