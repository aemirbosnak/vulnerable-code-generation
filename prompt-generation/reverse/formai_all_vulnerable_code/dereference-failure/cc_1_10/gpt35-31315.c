//FormAI DATASET v1.0 Category: File Synchronizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// function to check if a file exists
int file_exists(char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// function to recursively copy a directory
void copy_directory(char *src_path, char *dst_path) {
    DIR *dir = opendir(src_path);
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // if the entry is a directory, recursively call the function
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char new_src_path[256];
                char new_dst_path[256];
                sprintf(new_src_path, "%s/%s", src_path, entry->d_name);
                sprintf(new_dst_path, "%s/%s", dst_path, entry->d_name);
                mkdir(new_dst_path, 0777);
                copy_directory(new_src_path, new_dst_path);
            }
        } else {
            // if the entry is a file, copy it to the destination
            char src_file_path[256];
            char dst_file_path[256];
            sprintf(src_file_path, "%s/%s", src_path, entry->d_name);
            sprintf(dst_file_path, "%s/%s", dst_path, entry->d_name);
            if (!file_exists(dst_file_path)) {
                // if the file doesn't exist in the destination, copy it over
                FILE *src_file = fopen(src_file_path, "rb");
                FILE *dst_file = fopen(dst_file_path, "wb");
                char buffer[1024];
                int len;
                while (len = fread(buffer, 1, 1024, src_file))
                    fwrite(buffer, 1, len, dst_file);
                fclose(src_file);
                fclose(dst_file);
            } else {
                // if the file already exists in the destination, check if they are different
                FILE *src_file = fopen(src_file_path, "rb");
                FILE *dst_file = fopen(dst_file_path, "rb");
                char src_buffer[1024];
                char dst_buffer[1024];
                int src_len, dst_len;
                while ((src_len = fread(src_buffer, 1, 1024, src_file)) && (dst_len = fread(dst_buffer, 1, 1024, dst_file))) {
                    if (src_len != dst_len || memcmp(src_buffer, dst_buffer, src_len)) {
                        // if the files are different, overwrite the destination file with the source file
                        rewind(dst_file);
                        fwrite(src_buffer, 1, src_len, dst_file);
                        fclose(src_file);
                        fclose(dst_file);
                        break;
                    }
                }
            }
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }

    if (!file_exists(argv[1])) {
        printf("Error: source directory does not exist\n");
        return 1;
    }

    if (!file_exists(argv[2])) {
        printf("Error: destination directory does not exist\n");
        return 1;
    }

    copy_directory(argv[1], argv[2]);

    printf("File synchronization complete!\n");

    return 0;
}