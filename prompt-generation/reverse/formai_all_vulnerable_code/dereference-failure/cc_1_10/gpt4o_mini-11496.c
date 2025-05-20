//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX_LINE_LENGTH 256

void print_file_info(const char* filepath) {
    struct stat file_stat;
    if (stat(filepath, &file_stat) != 0) {
        perror("stat failed");
        return;
    }

    printf("File: %s\n", filepath);
    printf("Size: %lld bytes\n", (long long) file_stat.st_size);
    printf("Owner: %s\n", getpwuid(file_stat.st_uid)->pw_name);
    printf("Group: %s\n", getgrgid(file_stat.st_gid)->gr_name);
    printf("Permissions: ");
    printf((S_ISDIR(file_stat.st_mode)) ? "d" : "-");
    printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
    printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
    printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
    printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
    printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
    printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    char time_buffer[80];
    struct tm* time_info = localtime(&file_stat.st_mtime);
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", time_info);
    printf("Last modified: %s\n", time_buffer);
    printf("-----------------------------\n");
}

void list_directory(const char* dir_name) {
    struct dirent* entry;
    DIR* dir = opendir(dir_name);
    if (dir == NULL) {
        perror("opendir failed");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[MAX_LINE_LENGTH];
            snprintf(full_path, MAX_LINE_LENGTH, "%s/%s", dir_name, entry->d_name);
            print_file_info(full_path);
        }
    }
    closedir(dir);
}

void display_usage() {
    printf("Usage: simple_ls <directory_path>\n");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    list_directory(argv[1]);
    return EXIT_SUCCESS;
}