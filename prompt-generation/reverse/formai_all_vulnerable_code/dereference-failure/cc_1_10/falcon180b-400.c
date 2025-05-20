//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_FILE_NAME 256

// Function to sync two directories
void sync_directories(char* source_dir, char* dest_dir) {
    DIR* source_dir_ptr = opendir(source_dir);
    DIR* dest_dir_ptr = opendir(dest_dir);

    struct dirent* source_file;
    struct dirent* dest_file;

    // Loop through source directory
    while ((source_file = readdir(source_dir_ptr))!= NULL) {
        char source_file_name[MAX_FILE_NAME];
        strcpy(source_file_name, source_file->d_name);

        // Check if file exists in destination directory
        dest_file = readdir(dest_dir_ptr);
        while (dest_file!= NULL) {
            if (strcmp(source_file_name, dest_file->d_name) == 0) {
                // File exists in destination directory
                struct stat source_stat;
                struct stat dest_stat;

                // Get file stats
                stat(source_file_name, &source_stat);
                stat(dest_file->d_name, &dest_stat);

                // Check if files are different
                if (source_stat.st_mtime!= dest_stat.st_mtime) {
                    // File is different, copy to destination directory
                    char dest_file_path[MAX_FILE_NAME];
                    strcat(dest_file_path, dest_dir);
                    strcat(dest_file_path, "/");
                    strcat(dest_file_path, source_file_name);

                    FILE* source_file_ptr = fopen(source_file_name, "rb");
                    FILE* dest_file_ptr = fopen(dest_file_path, "wb");

                    char buffer[1024];
                    int bytes_read;

                    while ((bytes_read = fread(buffer, 1, 1024, source_file_ptr)) > 0) {
                        fwrite(buffer, 1, bytes_read, dest_file_ptr);
                    }

                    fclose(source_file_ptr);
                    fclose(dest_file_ptr);
                }

                break;
            }

            dest_file = readdir(dest_dir_ptr);
        }

        if (dest_file == NULL) {
            // File does not exist in destination directory, copy to destination directory
            char dest_file_path[MAX_FILE_NAME];
            strcat(dest_file_path, dest_dir);
            strcat(dest_file_path, "/");
            strcat(dest_file_path, source_file_name);

            FILE* source_file_ptr = fopen(source_file_name, "rb");
            FILE* dest_file_ptr = fopen(dest_file_path, "wb");

            char buffer[1024];
            int bytes_read;

            while ((bytes_read = fread(buffer, 1, 1024, source_file_ptr)) > 0) {
                fwrite(buffer, 1, bytes_read, dest_file_ptr);
            }

            fclose(source_file_ptr);
            fclose(dest_file_ptr);
        }
    }

    // Close directories
    closedir(source_dir_ptr);
    closedir(dest_dir_ptr);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }

    sync_directories(argv[1], argv[2]);

    return 0;
}