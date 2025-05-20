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
#define MAX_CMD_LEN 256

void printFilePermissions(const char *filePath) {
    struct stat fileStat;
    if (stat(filePath, &fileStat) < 0) {
        perror("stat");
        return;
    }

    printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    
    printf(" %ld %s/%s %ld ", fileStat.st_nlink, getpwuid(fileStat.st_uid)->pw_name, getgrgid(fileStat.st_gid)->gr_name, fileStat.st_size);
    
    char timeBuf[80];
    struct tm lt;
    localtime_r(&fileStat.st_mtime, &lt);
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", &lt);
    printf("%s ", timeBuf);
    printf("%s\n", filePath);
}

void listDirectoryContents(const char *dirPath) {
    DIR *dir = opendir(dirPath);
    struct dirent *entry;

    if (!dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char fullPath[MAX_PATH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
        
        if (entry->d_name[0] != '.') {  // Ignore hidden files
            printFilePermissions(fullPath);
        }
    }

    closedir(dir);
}

void monitorFileChanges(const char *filePath) {
    struct stat fileStat;
    stat(filePath, &fileStat);
    time_t previousTime = fileStat.st_mtime;

    while (1) {
        sleep(5); // Check every 5 seconds
        
        stat(filePath, &fileStat);
        if (previousTime != fileStat.st_mtime) {
            printf("File %s has changed at %s", filePath, ctime(&fileStat.st_mtime));
            previousTime = fileStat.st_mtime;
        }
    }
}

void processCommand(const char *cmd) {
    char buffer[MAX_CMD_LEN];
    FILE *pipe = popen(cmd, "r");
    if (!pipe) {
        perror("popen");
        return;
    }

    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        printf("%s", buffer);
    }
    
    pclose(pipe);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory> or %s <file_to_monitor>\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

    struct stat sb;
    if (stat(argv[1], &sb) == 0) {
        if (S_ISDIR(sb.st_mode)) {
            printf("Listing contents of directory: %s\n", argv[1]);
            listDirectoryContents(argv[1]);
        } else if (S_ISREG(sb.st_mode)) {
            printf("Monitoring file for changes: %s\n", argv[1]);
            monitorFileChanges(argv[1]);
        } else {
            fprintf(stderr, "%s is neither a directory nor a regular file.\n", argv[1]);
            return EXIT_FAILURE;
        }
    } else {
        perror("stat");
        return EXIT_FAILURE;
    }

    // Command demonstration
    printf("\nRunning a system command:\n");
    processCommand("ls -l");

    return EXIT_SUCCESS;
}