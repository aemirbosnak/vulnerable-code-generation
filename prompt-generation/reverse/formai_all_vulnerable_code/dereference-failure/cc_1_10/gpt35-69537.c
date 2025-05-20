//FormAI DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PATH_SIZE 1024

/* Function declarations */
void sync_files(char* src_dir, char* dest_dir);
void sync_dir(char* src_dir, char* dest_dir);

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Usage: %s <src_dir> <dest_dir>\n", argv[0]);
        return 1;
    }

    /* Get source and destination directory paths */
    char* src_dir = argv[1];
    char* dest_dir = argv[2];

    /* Verify that both directories exist */
    struct stat statbuf;
    if(stat(src_dir, &statbuf) == -1) {
        printf("Error: Source directory does not exist.\n");
        return 1;
    }
    if(stat(dest_dir, &statbuf) == -1) {
        printf("Error: Destination directory does not exist.\n");
        return 1;
    }

    sync_files(src_dir, dest_dir);

    return 0;
}


/* Synchronize files in the given directories */
void sync_files(char* src_dir, char* dest_dir) {
    /* Open source directory */
    DIR* src_dir_ptr = opendir(src_dir);
    if(src_dir_ptr == NULL) {
        printf("Error opening source directory: %s\n", src_dir);
        return;
    }

    /* Open destination directory */
    DIR* dest_dir_ptr = opendir(dest_dir);
    if(dest_dir_ptr == NULL) {
        printf("Error opening destination directory: %s\n", dest_dir);
        return;
    }

    struct dirent* dir_entry;
    while((dir_entry = readdir(src_dir_ptr)) != NULL) {
        /* Ignore . and .. */
        if(strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
            continue;
        }

        /* Get source and destination file paths */
        char src_file_path[MAX_PATH_SIZE];
        snprintf(src_file_path, MAX_PATH_SIZE, "%s/%s", src_dir, dir_entry->d_name);

        char dest_file_path[MAX_PATH_SIZE];
        snprintf(dest_file_path, MAX_PATH_SIZE, "%s/%s", dest_dir, dir_entry->d_name);

        struct stat src_statbuf;
        if(stat(src_file_path, &src_statbuf) == -1) {
            printf("Error getting stat for file: %s\n", src_file_path);
            continue;
        }

        /* If file is a regular file, compare modification times and sync accordingly */
        if(S_ISREG(src_statbuf.st_mode)) {
            struct stat dest_statbuf;
            if(stat(dest_file_path, &dest_statbuf) == -1) {
                /* Destination file does not exist, so copy source file to destination */
                printf("Copying %s to %s\n", src_file_path, dest_file_path);
                FILE* src_file = fopen(src_file_path, "rb");

                if(src_file == NULL) {
                    printf("Error opening source file: %s\n", src_file_path);
                    continue;
                }

                FILE* dest_file = fopen(dest_file_path, "wb");

                if(dest_file == NULL) {
                    printf("Error opening destination file: %s\n", dest_file_path);
                    fclose(src_file);
                    continue;
                }

                char buffer[1024];
                size_t bytes_read;
                while((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                    if(fwrite(buffer, 1, bytes_read, dest_file) != bytes_read) {
                        printf("Error writing to destination file: %s\n", dest_file_path);
                        fclose(src_file);
                        fclose(dest_file);
                        remove(dest_file_path);
                        continue;
                    }
                }

                fclose(src_file);
                fclose(dest_file);
            }
            else if(src_statbuf.st_mtime > dest_statbuf.st_mtime) {
                /* Source file is newer than destination file, so copy source file to destination */
                printf("Copying %s to %s\n", src_file_path, dest_file_path);
                char buffer[1024];

                FILE* src_file = fopen(src_file_path, "rb");

                if(src_file == NULL) {
                    printf("Error opening source file: %s\n", src_file_path);
                    continue;
                }

                FILE* dest_file = fopen(dest_file_path, "wb");

                if(dest_file == NULL) {
                    printf("Error opening destination file: %s\n", dest_file_path);
                    fclose(src_file);
                    continue;
                }

                size_t bytes_read;
                while((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                    if(fwrite(buffer, 1, bytes_read, dest_file) != bytes_read) {
                        printf("Error writing to destination file: %s\n", dest_file_path);
                        fclose(src_file);
                        fclose(dest_file);
                        remove(dest_file_path);
                        continue;
                    }
                }

                fclose(src_file);
                fclose(dest_file);
            }
        }
        /* If file is a directory, synchronize contents */
        else if(S_ISDIR(src_statbuf.st_mode)) {
            /* Ignore . and .. */
            if(strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
                continue;
            }

            /* Create destination directory if it does not exist */
            mkdir(dest_file_path, src_statbuf.st_mode);

            sync_dir(src_file_path, dest_file_path);
        }
    }

    /* Close directory pointers */
    closedir(src_dir_ptr);
    closedir(dest_dir_ptr);
}


/* Synchronize contents of directories */
void sync_dir(char* src_dir, char* dest_dir) {
    sync_files(src_dir, dest_dir);
}