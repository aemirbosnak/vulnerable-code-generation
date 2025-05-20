//FormAI DATASET v1.0 Category: File Backup System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

// Define constants for max lengths of strings
#define MAX_PATH_LENGTH 1024
#define MAX_FILENAME_LENGTH 256
#define MAX_DATE_LENGTH 20

// Define a struct to hold file metadata
struct file_metadata {
    char path[MAX_PATH_LENGTH];
    char name[MAX_FILENAME_LENGTH];
    char date_modified[MAX_DATE_LENGTH];
    long size;
};

// Function to get file size
long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0)
        return st.st_size;
    return -1;
}

// Function to get date modified in yyyy-mm-dd format
void get_date_modified(const char *filename, char *date_modified) {
    struct stat st;
    if (stat(filename, &st) == 0)
        strftime(date_modified, MAX_DATE_LENGTH, "%Y-%m-%d", localtime(&st.st_mtime));
    else
        strcpy(date_modified, "");
}

// Function to recursively traverse directory and add file metadata to array
int get_files(char *directory, struct file_metadata *files, int num_files) {
    DIR *dir;
    struct dirent *dir_entry;
    char path[MAX_PATH_LENGTH];
    dir = opendir(directory);
    if (dir != NULL) {
        while ((dir_entry = readdir(dir)) != NULL) {
            if (dir_entry->d_type == DT_REG) { // If file
                struct file_metadata file;
                strcpy(file.path, directory);
                strcat(file.path, "/");
                strcpy(file.name, dir_entry->d_name);
                strcat(file.path, file.name);
                file.size = get_file_size(file.path);
                get_date_modified(file.path, file.date_modified);
                files[num_files++] = file;
            } else if (dir_entry->d_type == DT_DIR 
                       && strcmp(dir_entry->d_name, ".") != 0 
                       && strcmp(dir_entry->d_name, "..") != 0) { // If directory
                strcpy(path, directory);
                strcat(path, "/");
                strcat(path, dir_entry->d_name);
                num_files = get_files(path, files, num_files);
            }
        }
        closedir(dir);
    }
    return num_files;
}

// Function to backup files to specified directory
void backup_files(struct file_metadata *files, int num_files, const char *backup_directory) {
    FILE *src_file, *dest_file;
    char dest_path[MAX_PATH_LENGTH];
    char cmd[MAX_PATH_LENGTH + 20];
    int i;
    for (i = 0; i < num_files; i++) {
        strcpy(dest_path, backup_directory);
        strcat(dest_path, "/");
        strcat(dest_path, files[i].name);
        src_file = fopen(files[i].path, "rb");
        dest_file = fopen(dest_path, "wb");
        if (src_file != NULL && dest_file != NULL) {
            int ch;
            while ((ch = fgetc(src_file)) != EOF) {
                fputc(ch, dest_file);
            }
            fclose(src_file);
            fclose(dest_file);
            strcpy(cmd, "chmod --reference=");
            strcat(cmd, files[i].path);
            strcat(cmd, " ");
            strcat(cmd, dest_path);
            system(cmd);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: cbackup <source_directory> <backup_directory>\n");
        return 1;
    }
    char *source_directory = argv[1];
    char *backup_directory = argv[2];
    struct file_metadata files[MAX_PATH_LENGTH];
    int num_files = get_files(source_directory, files, 0);
    backup_files(files, num_files, backup_directory);
    printf("Backup complete!\n");
    return 0;
}