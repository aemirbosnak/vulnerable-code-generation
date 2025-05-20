//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PATH 4096

struct dirent *readdir(DIR *dirp);

int main(int argc, char *argv[]) {
    DIR *dir1, *dir2;
    struct dirent *ent;
    FILE *fp1, *fp2;
    char path1[MAX_PATH], path2[MAX_PATH];
    char filename[MAX_PATH];
    char buffer1[MAX_PATH], buffer2[MAX_PATH];
    int file1, file2;
    int bytes1, bytes2;
    int files_synced = 0;

    if (argc!= 3) {
        printf("Usage:./program <source_directory> <destination_directory>\n");
        exit(1);
    }

    strcpy(path1, argv[1]);
    strcpy(path2, argv[2]);

    dir1 = opendir(path1);
    if (dir1 == NULL) {
        printf("Error: Could not open source directory.\n");
        exit(1);
    }

    dir2 = opendir(path2);
    if (dir2 == NULL) {
        printf("Error: Could not open destination directory.\n");
        exit(1);
    }

    while ((ent = readdir(dir1))!= NULL) {
        strcpy(filename, ent->d_name);
        strcat(filename, "/");
        strcat(filename, ent->d_name);
        strcpy(path1, path1);
        strcat(path1, filename);

        strcpy(path2, path2);
        strcat(path2, filename);

        file1 = open(path1, O_RDONLY);
        if (file1 == -1) {
            printf("Error: Could not open source file.\n");
            exit(1);
        }

        file2 = open(path2, O_WRONLY | O_CREAT);
        if (file2 == -1) {
            printf("Error: Could not open destination file.\n");
            exit(1);
        }

        bytes1 = read(file1, buffer1, MAX_PATH);
        bytes2 = write(file2, buffer1, bytes1);

        if (bytes1!= bytes2) {
            printf("Error: File synchronization failed.\n");
            exit(1);
        }

        close(file1);
        close(file2);

        files_synced++;
    }

    closedir(dir1);
    closedir(dir2);

    printf("File synchronization complete. %d files synced.\n", files_synced);

    return 0;
}

struct dirent *readdir(DIR *dirp) {
    struct dirent *result;

    result = readdir(dirp);

    return result;
}