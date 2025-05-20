//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_FILE_SIZE 1000

struct FileInfo {
    char filename[100];
    int size;
};

struct FileInfo scanFile(const char *filename) {
    struct FileInfo info;
    info.filename[0] = '\0';
    struct stat buffer;
    if (stat(filename, &buffer)!= 0) {
        perror("Error stat");
        return info;
    }
    info.size = buffer.st_size;
    strcpy(info.filename, filename);
    return info;
}

void printFileInfo(struct FileInfo *info) {
    printf("File name: %s\n", info->filename);
    printf("Size: %d\n", info->size);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    DIR *dir;
    struct dirent *ent;
    struct FileInfo info;

    dir = opendir(argv[1]);
    if (!dir) {
        perror("Error opening directory");
        return 1;
    }

    while ((ent = readdir(dir))!= NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        strcpy(info.filename, ent->d_name);
        info.size = MAX_FILE_SIZE;

        if (stat(ent->d_name, &info.size)!= 0) {
            perror("Error stat");
            continue;
        }

        if (info.size > MAX_FILE_SIZE) {
            printf("%s: File is larger than %d bytes\n", info.filename, MAX_FILE_SIZE);
        } else {
            printf("%s: File is smaller than %d bytes\n", info.filename, MAX_FILE_SIZE);
        }
    }

    closedir(dir);
    return 0;
}