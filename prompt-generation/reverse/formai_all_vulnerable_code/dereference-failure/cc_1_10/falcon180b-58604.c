//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 1024
#define MAX_PATH_LENGTH 4096
#define MAX_FILES 10000

struct file_info {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
};

void get_file_info(char* path, struct file_info* file_info, int is_dir) {
    FILE* file;
    char line[MAX_FILE_NAME_LENGTH];
    struct stat stat_buf;

    if (is_dir) {
        file = NULL;
        stat(path, &stat_buf);
        file_info->file_size = stat_buf.st_size;
    } else {
        file = fopen(path, "r");
        if (file == NULL) {
            file_info->file_size = 0;
        } else {
            fgets(line, MAX_FILE_NAME_LENGTH, file);
            fclose(file);
            file_info->file_size = strlen(line);
        }
    }

    strncpy(file_info->file_name, path, MAX_FILE_NAME_LENGTH);
}

void get_file_size(char* path, int* file_size) {
    struct stat stat_buf;

    if (stat(path, &stat_buf) == 0) {
        *file_size = stat_buf.st_size;
    } else {
        *file_size = 0;
    }
}

void print_file_info(struct file_info* file_info) {
    printf("%s (%d bytes)\n", file_info->file_name, file_info->file_size);
}

void print_summary(int num_files, int total_size) {
    printf("Total files: %d\n", num_files);
    printf("Total size: %d bytes\n", total_size);
}

int main(int argc, char** argv) {
    DIR* dir;
    struct dirent* ent;
    char path[MAX_PATH_LENGTH];
    struct file_info file_info;
    int num_files = 0;
    int total_size = 0;

    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    strncpy(path, argv[1], MAX_PATH_LENGTH);
    strncat(path, "/", MAX_PATH_LENGTH);

    dir = opendir(path);

    if (dir == NULL) {
        printf("Error opening directory: %s\n", path);
        return 1;
    }

    while ((ent = readdir(dir))!= NULL) {
        if (num_files >= MAX_FILES) {
            printf("Maximum number of files reached.\n");
            break;
        }

        strncpy(file_info.file_name, ent->d_name, MAX_FILE_NAME_LENGTH);
        get_file_info(path, &file_info, 0);

        if (file_info.file_size > 0) {
            print_file_info(&file_info);
            total_size += file_info.file_size;
        }

        num_files++;
    }

    closedir(dir);
    print_summary(num_files, total_size);

    return 0;
}