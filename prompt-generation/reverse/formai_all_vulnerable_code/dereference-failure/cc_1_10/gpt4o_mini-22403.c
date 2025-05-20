//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: expert-level
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

#define MAX_PATH 1024

void print_file_info(const char *path) {
    struct stat file_stat;
    if (stat(path, &file_stat) < 0) {
        perror("stat");
        return;
    }

    printf("File: %s\n", path);
    printf("Size: %lld bytes\n", (long long)file_stat.st_size);
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

    struct passwd *pw = getpwuid(file_stat.st_uid);
    struct group  *gr = getgrgid(file_stat.st_gid);
    
    printf("Owner: %s (UID: %d)\n", pw ? pw->pw_name : "unknown", file_stat.st_uid);
    printf("Group: %s (GID: %d)\n", gr ? gr->gr_name : "unknown", file_stat.st_gid);

    char time_buf[80];
    struct tm *tm_info;

    tm_info = localtime(&file_stat.st_mtime);
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Last modified: %s\n", time_buf);
}

void list_directory(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') { // Skip hidden files
            char full_path[MAX_PATH];
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
            print_file_info(full_path);
            printf("\n");
        }
    }

    closedir(dp);
}

void display_help() {
    printf("Usage: sysadmin_tool [directory_path]\n");
    printf("If no path is provided, the current directory is used.\n");
}

int main(int argc, char *argv[]) {
    const char *path = ".";
    
    if (argc > 2) {
        display_help();
        return EXIT_FAILURE;
    } else if (argc == 2) {
        path = argv[1];
    }

    struct stat path_stat;
    
    if (stat(path, &path_stat) < 0) {
        perror("stat");
        return EXIT_FAILURE;
    }

    if (!S_ISDIR(path_stat.st_mode)) {
        fprintf(stderr, "%s is not a directory.\n", path);
        return EXIT_FAILURE;
    }

    printf("Listing files in directory: %s\n", path);
    list_directory(path);
    
    return EXIT_SUCCESS;
}