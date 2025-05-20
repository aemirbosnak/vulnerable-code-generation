//FormAI DATASET v1.0 Category: File Synchronizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_FILE_NAME_LEN 512
#define BUF_SIZE 1024

// Function to check if file exists
int file_exists(char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Function to copy file content from source to destination
void copy_file(char *source_file, char *dest_file) {
    FILE *source = fopen(source_file, "rb");
    FILE *dest = fopen(dest_file, "wb");
    char buf[BUF_SIZE];
    size_t size;

    while ((size = fread(buf, 1, BUF_SIZE, source)) > 0) {
        fwrite(buf, 1, size, dest);
    }

    fclose(source);
    fclose(dest);
}

// Function to synchronize files from source to destination
void sync_files(char *source_dir, char *dest_dir) {
    DIR *dir;
    struct dirent *entry;
    char source_file[MAX_FILE_NAME_LEN], dest_file[MAX_FILE_NAME_LEN];

    if ((dir = opendir(source_dir)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_type == DT_REG) {
                sprintf(source_file, "%s/%s", source_dir, entry->d_name);
                sprintf(dest_file, "%s/%s", dest_dir, entry->d_name);

                if (!file_exists(dest_file)) {
                    copy_file(source_file, dest_file);
                    printf("Copied %s to %s\n", source_file, dest_file);
                } else {
                    struct stat source_st, dest_st;
                    stat(source_file, &source_st);
                    stat(dest_file, &dest_st);

                    if (source_st.st_mtim.tv_sec > dest_st.st_mtim.tv_sec) {
                        copy_file(source_file, dest_file);
                        printf("Updated %s to %s\n", source_file, dest_file);
                    }
                }
            }
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {    
    if (argc < 3) {
        printf("Usage: file_sync <source_dir> <dest_dir>\n");
        exit(1);
    }

    char *source_dir = argv[1];
    char *dest_dir = argv[2];

    while (1) {
        sync_files(source_dir, dest_dir);
        sleep(10);
    }

    return 0;
}