//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

void sync_files(char* source_dir, char* dest_dir) {
    DIR* dir = opendir(source_dir);
    if (dir == NULL) {
        printf("Error: Could not open source directory %s\n", source_dir);
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        char path[1024];
        sprintf(path, "%s/%s", source_dir, entry->d_name);

        struct stat st;
        stat(path, &st);

        time_t mtime = st.st_mtime;

        char dest_path[1024];
        sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);

        DIR* dest_dir_ptr = opendir(dest_dir);
        if (dest_dir_ptr == NULL) {
            printf("Error: Could not open destination directory %s\n", dest_dir);
            exit(1);
        }

        struct dirent* dest_entry;
        while ((dest_entry = readdir(dest_dir_ptr))!= NULL) {
            if (strcmp(dest_entry->d_name, entry->d_name) == 0) {
                struct stat dest_st;
                stat(dest_path, &dest_st);

                if (mtime > dest_st.st_mtime) {
                    FILE* source_file = fopen(path, "rb");
                    FILE* dest_file = fopen(dest_path, "wb");

                    if (source_file == NULL || dest_file == NULL) {
                        printf("Error: Could not open files for synchronization\n");
                        exit(1);
                    }

                    char buffer[BUFFER_SIZE];
                    int bytes_read;

                    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
                        fwrite(buffer, 1, bytes_read, dest_file);
                    }

                    fclose(source_file);
                    fclose(dest_file);
                }
            }
        }

        closedir(dest_dir_ptr);
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}