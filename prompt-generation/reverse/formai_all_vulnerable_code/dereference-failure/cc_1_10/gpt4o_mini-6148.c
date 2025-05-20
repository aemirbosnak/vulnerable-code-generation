//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: realistic
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

#define MAX_PATH 256

void display_usage(const char *program_name) {
    printf("Usage: %s <directory>\n", program_name);
}

void list_directory(const char *dir_path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH];

    if ((dir = opendir(dir_path)) == NULL) {
        perror("opendir");
        return;
    }

    printf("Contents of directory: %s\n", dir_path);
    printf("%-30s %-10s %-10s %-10s %-20s\n", 
           "File Name", "Size (bytes)", "Owner", "Group", "Last Modified");

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;  // Skip hidden files
        }
        
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (stat(full_path, &file_stat) == -1) {
            perror("stat");
            continue;
        }
        
        struct passwd *pw = getpwuid(file_stat.st_uid);
        struct group  *gr = getgrgid(file_stat.st_gid);
        char time_buffer[26];
        struct tm *tm_info;

        tm_info = localtime(&file_stat.st_mtime);
        strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_info);

        printf("%-30s %-10ld %-10s %-10s %-20s\n",
               entry->d_name,
               file_stat.st_size,
               pw ? pw->pw_name : "N/A",
               gr ? gr->gr_name : "N/A",
               time_buffer);
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Check if the provided path is a directory
    struct stat path_stat;
    if (stat(argv[1], &path_stat) != 0) {
        perror("stat");
        return EXIT_FAILURE;
    }

    if (!S_ISDIR(path_stat.st_mode)) {
        fprintf(stderr, "Error: %s is not a directory\n", argv[1]);
        return EXIT_FAILURE;
    }

    list_directory(argv[1]);

    return EXIT_SUCCESS;
}