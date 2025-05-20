//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void sync_files(char* source_dir, char* dest_dir) {
    DIR* source_dir_ptr = opendir(source_dir);
    if (source_dir_ptr == NULL) {
        printf("Error: source directory does not exist.\n");
        exit(1);
    }

    DIR* dest_dir_ptr = opendir(dest_dir);
    if (dest_dir_ptr == NULL) {
        printf("Error: destination directory does not exist.\n");
        exit(1);
    }

    struct dirent* source_dir_entry = readdir(source_dir_ptr);
    while (source_dir_entry!= NULL) {
        char source_file_path[512];
        sprintf(source_file_path, "%s/%s", source_dir, source_dir_entry->d_name);

        struct stat source_file_stat;
        stat(source_file_path, &source_file_stat);

        if (S_ISDIR(source_file_stat.st_mode)) {
            char dest_file_path[512];
            sprintf(dest_file_path, "%s/%s", dest_dir, source_dir_entry->d_name);

            if (mkdir(dest_file_path, 0777) == -1) {
                printf("Error: could not create directory %s in destination directory.\n", dest_file_path);
                exit(1);
            }
        } else {
            char dest_file_path[512];
            sprintf(dest_file_path, "%s/%s", dest_dir, source_dir_entry->d_name);

            FILE* source_file_ptr = fopen(source_file_path, "r");
            if (source_file_ptr == NULL) {
                printf("Error: could not open source file %s.\n", source_file_path);
                exit(1);
            }

            FILE* dest_file_ptr = fopen(dest_file_path, "w");
            if (dest_file_ptr == NULL) {
                printf("Error: could not open destination file %s.\n", dest_file_path);
                exit(1);
            }

            char buffer[BUFFER_SIZE];
            while (fgets(buffer, BUFFER_SIZE, source_file_ptr)!= NULL) {
                fputs(buffer, dest_file_ptr);
            }

            fclose(source_file_ptr);
            fclose(dest_file_ptr);
        }

        source_dir_entry = readdir(source_dir_ptr);
    }

    closedir(source_dir_ptr);
    closedir(dest_dir_ptr);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        exit(1);
    }

    char* source_dir = argv[1];
    char* dest_dir = argv[2];

    sync_files(source_dir, dest_dir);

    printf("File synchronization complete.\n");

    return 0;
}