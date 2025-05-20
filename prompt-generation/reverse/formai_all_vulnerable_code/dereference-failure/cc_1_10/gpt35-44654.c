//FormAI DATASET v1.0 Category: File Synchronizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

// Function to check if a file is regular
int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

// Function to recursively copy a directory and its contents
void copy_directory(char *source, char *destination)
{
    DIR *dir_source = opendir(source);
    struct dirent *dir_entry_source;
    while ((dir_entry_source = readdir(dir_source)) != NULL) {
        if (strcmp(dir_entry_source->d_name, ".") != 0 && strcmp(dir_entry_source->d_name, "..") != 0) {
            char path_source[1000], path_destination[1000];
            strcpy(path_source, source);
            strcat(path_source, "/");
            strcat(path_source, dir_entry_source->d_name);
            strcpy(path_destination, destination);
            strcat(path_destination, "/");
            strcat(path_destination, dir_entry_source->d_name);
            if (is_regular_file(path_source)) {
                FILE *file_source = fopen(path_source, "rb");
                FILE *file_destination = fopen(path_destination, "wb");
                char buffer[1000];
                int bytes_read;
                while ((bytes_read = fread(buffer, sizeof(char), 1000, file_source)) > 0) {
                    fwrite(buffer, sizeof(char), bytes_read, file_destination);
                }
                fclose(file_source);
                fclose(file_destination);
            }
            else {
                mkdir(path_destination, S_IRWXU | S_IRWXG | S_IRWXO);
                copy_directory(path_source, path_destination);
            }
        }
    }
    closedir(dir_source);
}

// Function to synchronize two directories
void sync_directories(char *directory_1, char *directory_2)
{
    DIR *dir_1 = opendir(directory_1);
    struct dirent *dir_entry_1;
    while ((dir_entry_1 = readdir(dir_1)) != NULL) {
        if (strcmp(dir_entry_1->d_name, ".") != 0 && strcmp(dir_entry_1->d_name, "..") != 0) {
            char path_1[1000], path_2[1000];
            strcpy(path_1, directory_1);
            strcat(path_1, "/");
            strcat(path_1, dir_entry_1->d_name);
            strcpy(path_2, directory_2);
            strcat(path_2, "/");
            strcat(path_2, dir_entry_1->d_name);
            if (is_regular_file(path_1)) {
                struct stat stat_1, stat_2;
                stat(path_1, &stat_1);
                stat(path_2, &stat_2);
                if (stat_1.st_mtime > stat_2.st_mtime) {
                    copy_directory(directory_1, directory_2);
                }
                else if (stat_2.st_mtime > stat_1.st_mtime) {
                    copy_directory(directory_2, directory_1);
                }
            }
            else {
                if (opendir(path_2) == NULL) {
                    mkdir(path_2, S_IRWXU | S_IRWXG | S_IRWXO);
                }
                sync_directories(path_1, path_2);
            }
        }
    }
    closedir(dir_1);
}

int main()
{
    // Example usage: sync directories folder1 and folder2
    sync_directories("folder1", "folder2");
    printf("Directories synchronized!\n");
    return 0;
}