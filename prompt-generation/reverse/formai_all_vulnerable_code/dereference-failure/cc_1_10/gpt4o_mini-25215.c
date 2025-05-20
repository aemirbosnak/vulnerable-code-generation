//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

#define MAX_BUFFER 256

typedef struct {
    char filename[MAX_BUFFER];
    char filepath[MAX_BUFFER];
    struct stat fileStat;
} FileInfo;

void printFileInfo(FileInfo *fileInfo) {
    printf("File: %s\n", fileInfo->filename);
    printf("Path: %s\n", fileInfo->filepath);
    printf("Size: %lld bytes\n", (long long)fileInfo->fileStat.st_size);
    printf("Owner: %s\n", getpwuid(fileInfo->fileStat.st_uid)->pw_name);
    printf("Group: %s\n", getgrgid(fileInfo->fileStat.st_gid)->gr_name);
    printf("Permissions: %o\n", fileInfo->fileStat.st_mode & 0777);
    printf("Links: %ld\n", (long)fileInfo->fileStat.st_nlink);
    printf("Last modified: %s", ctime(&fileInfo->fileStat.st_mtime));
    printf("-----------------------------------\n");
}

void listFiles(const char *dirpath) {
    DIR *dir;
    struct dirent *entry;
    FileInfo fileInfo;

    if ((dir = opendir(dirpath)) == NULL) {
        perror("opendir() error");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files
        }

        snprintf(fileInfo.filename, MAX_BUFFER, "%s", entry->d_name);
        snprintf(fileInfo.filepath, MAX_BUFFER, "%s/%s", dirpath, entry->d_name);

        if (stat(fileInfo.filepath, &fileInfo.fileStat) == -1) {
            perror("stat() error");
            continue;
        }

        printFileInfo(&fileInfo);
    }

    closedir(dir);
}

void usage() {
    printf("Usage: fileinfo [directory_path]\n");
    printf("If no directory path is provided, it lists the current working directory.\n");
}

int main(int argc, char *argv[]) {
    char *dirpath;

    if (argc < 2) {
        dirpath = ".";
    } else {
        dirpath = argv[1];
    }

    listFiles(dirpath);

    return EXIT_SUCCESS;
}