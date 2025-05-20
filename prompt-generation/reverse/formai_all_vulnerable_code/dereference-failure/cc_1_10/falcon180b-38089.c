//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_NAME_LEN 1024
#define BUF_SIZE 1024

// File Synchronizer Function
void sync_files(const char* source_dir, const char* dest_dir) {
    DIR* src_dir = opendir(source_dir);
    DIR* dest_dir_ptr = opendir(dest_dir);

    struct dirent* entry;
    while ((entry = readdir(src_dir))!= NULL) {
        char src_file_path[MAX_FILE_NAME_LEN];
        char dest_file_path[MAX_FILE_NAME_LEN];

        strcpy(src_file_path, source_dir);
        strcat(src_file_path, "/");
        strcat(src_file_path, entry->d_name);

        strcpy(dest_file_path, dest_dir);
        strcat(dest_file_path, "/");
        strcat(dest_file_path, entry->d_name);

        struct stat src_file_stat, dest_file_stat;
        stat(src_file_path, &src_file_stat);
        stat(dest_file_path, &dest_file_stat);

        if (src_file_stat.st_size!= dest_file_stat.st_size) {
            FILE* src_file = fopen(src_file_path, "rb");
            FILE* dest_file = fopen(dest_file_path, "wb");

            if (src_file == NULL || dest_file == NULL) {
                printf("Error opening file\n");
                exit(1);
            }

            char buffer[BUF_SIZE];
            size_t bytes_read;

            while ((bytes_read = fread(buffer, 1, BUF_SIZE, src_file)) > 0) {
                fwrite(buffer, 1, bytes_read, dest_file);
            }

            fclose(src_file);
            fclose(dest_file);
        }
    }

    closedir(src_dir);
    closedir(dest_dir_ptr);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}