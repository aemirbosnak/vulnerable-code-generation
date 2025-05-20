//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define MAX_PATH_LENGTH 1024

void display_file_info(const char* path) {
    struct stat fileStat;
    if (stat(path, &fileStat) < 0) {
        perror("Could not get file stats");
        return;
    }
    
    printf("File: %s\n", path);
    printf("Type: %s\n", S_ISDIR(fileStat.st_mode) ? "Directory" : "File");
    printf("Size: %lld bytes\n", (long long)fileStat.st_size);
    printf("Owner: %d\n", fileStat.st_uid);
    printf("Group: %d\n", fileStat.st_gid);
    printf("Permissions: %o\n", fileStat.st_mode & 0777);
    printf("Last modified: %s", ctime(&fileStat.st_mtime));
    printf("---------------------------------------------\n");
}

void list_directory(const char* dirPath) {
    struct dirent *entry;
    DIR *dp = opendir(dirPath);
    
    if (dp == NULL) {
        perror("Unable to open directory");
        return;
    }

    printf("Listing files in directory: %s\n", dirPath);
    printf("---------------------------------------------\n");
    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') {  // Skip hidden files
            char fullPath[MAX_PATH_LENGTH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
            display_file_info(fullPath);
        }
    }
    closedir(dp);
}

void print_system_info() {
    struct passwd *pw = getpwuid(getuid());
    struct group *gr = getgrgid(getgid());
    printf("Current user: %s\n", pw->pw_name);
    printf("User ID: %d\n", pw->pw_uid);
    printf("Group ID: %d\n", gr->gr_gid);
    printf("Group name: %s\n", gr->gr_name);
    printf("---------------------------------------------\n");
}

void show_help() {
    printf("Usage: ./sysadmin_tool [directory]\n");
    printf("If no directory is provided, the current directory will be listed.\n");
    printf("Options:\n");
    printf("  -h, --help   Show this help message\n");
}

int main(int argc, char *argv[]) {
    char *directory;
    
    if (argc == 1) {
        directory = ".";
    } else if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        show_help();
        return 0;
    } else if (argc == 2) {
        directory = argv[1];
    } else {
        fprintf(stderr, "Invalid arguments.\n");
        show_help();
        return 1;
    }

    print_system_info();
    list_directory(directory);

    return 0;
}