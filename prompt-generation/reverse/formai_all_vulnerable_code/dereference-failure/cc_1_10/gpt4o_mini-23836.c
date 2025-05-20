//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

// Function prototypes
void listFiles(const char *dirPath);
void displayFileInfo(const char *filePath);
void createDirectory(const char *dirPath);
void deleteDirectory(const char *dirPath);
void displayUserInfo(const char *username);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [options]\n", argv[0]);
        fprintf(stderr, "Commands:\n");
        fprintf(stderr, "  list <directory> - List all files in a directory\n");
        fprintf(stderr, "  info <file> - Display information about a file\n");
        fprintf(stderr, "  mkdir <directory> - Create a new directory\n");
        fprintf(stderr, "  rmdir <directory> - Remove a directory\n");
        fprintf(stderr, "  userinfo <username> - Display information about a user\n");
        return 1;
    }

    if (strcmp(argv[1], "list") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Please provide a directory to list.\n");
            return 1;
        }
        listFiles(argv[2]);
    } else if (strcmp(argv[1], "info") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Please provide a file to get information about.\n");
            return 1;
        }
        displayFileInfo(argv[2]);
    } else if (strcmp(argv[1], "mkdir") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Please provide a directory name to create.\n");
            return 1;
        }
        createDirectory(argv[2]);
    } else if (strcmp(argv[1], "rmdir") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Please provide a directory name to remove.\n");
            return 1;
        }
        deleteDirectory(argv[2]);
    } else if (strcmp(argv[1], "userinfo") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Please provide a username to get information about.\n");
            return 1;
        }
        displayUserInfo(argv[2]);
    } else {
        fprintf(stderr, "Unknown command: %s\n", argv[1]);
        return 1;
    }

    return 0;
}

void listFiles(const char *dirPath) {
    DIR *dir = opendir(dirPath);
    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}

void displayFileInfo(const char *filePath) {
    struct stat fileStat;

    if (stat(filePath, &fileStat) == -1) {
        perror("Failed to get file status");
        return;
    }

    printf("File: %s\n", filePath);
    printf("Size: %lld bytes\n", (long long)fileStat.st_size);
    printf("Owner: %s (UID: %d)\n", getpwuid(fileStat.st_uid)->pw_name, fileStat.st_uid);
    printf("Group: %s (GID: %d)\n", getgrgid(fileStat.st_gid)->gr_name, fileStat.st_gid);
    printf("Permissions: ");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
    
    printf("Last modified: %s", ctime(&fileStat.st_mtime));
}

void createDirectory(const char *dirPath) {
    if (mkdir(dirPath, 0755) == -1) {
        perror("Failed to create directory");
        return;
    }
    printf("Directory '%s' created successfully.\n", dirPath);
}

void deleteDirectory(const char *dirPath) {
    if (rmdir(dirPath) == -1) {
        perror("Failed to remove directory");
        return;
    }
    printf("Directory '%s' removed successfully.\n", dirPath);
}

void displayUserInfo(const char *username) {
    struct passwd *pw = getpwnam(username);
    if (pw == NULL) {
        fprintf(stderr, "No such user: %s\n", username);
        return;
    }

    printf("User: %s\n", pw->pw_name);
    printf("UID: %d\n", pw->pw_uid);
    printf("GID: %d\n", pw->pw_gid);
    printf("Home Directory: %s\n", pw->pw_dir);
    printf("Shell: %s\n", pw->pw_shell);
}