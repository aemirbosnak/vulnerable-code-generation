//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: authentic
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

// Define a structure to hold file information
typedef struct FileInfo {
    char name[256];
    char path[512];
    long size;
    char permissions[10];
    char owner[32];
    char group[32];
    char last_modified[20];
} FileInfo;

// Function prototypes
void list_directory(const char *path);
void get_file_info(const char *filepath, FileInfo *file_info);
void print_file_info(const FileInfo *file_info);
void print_usage();

int main(int argc, char *argv[]) {
    // Check if the command line argument is provided
    if (argc < 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    // List the contents of the specified directory
    list_directory(argv[1]);
    return EXIT_SUCCESS;
}

void print_usage() {
    printf("Usage: ./file_info <directory_path>\n");
    printf("Example: ./file_info /home/user/\n");
}

void list_directory(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    
    // Check if directory can be opened
    if (dp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Iterate over directory entries
    while ((entry = readdir(dp)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char filepath[512];
            snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);
            
            FileInfo file_info;
            get_file_info(filepath, &file_info);
            print_file_info(&file_info);
        }
    }

    closedir(dp);
}

void get_file_info(const char *filepath, FileInfo *file_info) {
    struct stat file_stat;
    
    // Get file status
    if (stat(filepath, &file_stat) < 0) {
        perror("stat");
        return;
    }

    // Fill FileInfo structure
    strcpy(file_info->name, basename(filepath));
    strcpy(file_info->path, filepath);
    file_info->size = file_stat.st_size;
    
    // Get permissions
    snprintf(file_info->permissions, sizeof(file_info->permissions), 
             (S_ISREG(file_stat.st_mode)) ? "-" : (S_ISDIR(file_stat.st_mode)) ? "d" : "l",
             (file_stat.st_mode & S_IRUSR) ? "r" : "-",
             (file_stat.st_mode & S_IWUSR) ? "w" : "-",
             (file_stat.st_mode & S_IXUSR) ? "x" : "-",
             (file_stat.st_mode & S_IRGRP) ? "r" : "-",
             (file_stat.st_mode & S_IWGRP) ? "w" : "-",
             (file_stat.st_mode & S_IXGRP) ? "x" : "-",
             (file_stat.st_mode & S_IROTH) ? "r" : "-",
             (file_stat.st_mode & S_IWOTH) ? "w" : "-",
             (file_stat.st_mode & S_IXOTH) ? "x" : "-");

    // Get owner and group
    struct passwd *pw = getpwuid(file_stat.st_uid);
    struct group  *gr = getgrgid(file_stat.st_gid);
    if (pw != NULL) {
        strcpy(file_info->owner, pw->pw_name);
    } else {
        strcpy(file_info->owner, "unknown");
    }
    if (gr != NULL) {
        strcpy(file_info->group, gr->gr_name);
    } else {
        strcpy(file_info->group, "unknown");
    }

    // Get last modified time
    struct tm *timeinfo = localtime(&file_stat.st_mtime);
    strftime(file_info->last_modified, sizeof(file_info->last_modified), "%Y-%m-%d %H:%M:%S", timeinfo);
}

void print_file_info(const FileInfo *file_info) {
    printf("Name: %s\n", file_info->name);
    printf("Path: %s\n", file_info->path);
    printf("Size: %ld bytes\n", file_info->size);
    printf("Permissions: %s\n", file_info->permissions);
    printf("Owner: %s\n", file_info->owner);
    printf("Group: %s\n", file_info->group);
    printf("Last Modified: %s\n", file_info->last_modified);
    printf("-----------------------------\n");
}