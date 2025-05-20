//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 256

typedef struct {
    char name[MAX_PATH];
    int size;
    int mode;
    int inode;
    char linkname[MAX_PATH];
    char path[MAX_PATH];
    char dev[MAX_PATH];
    char rdev[MAX_PATH];
} File;

void get_metadata(FILE* file, File* file_info) {
    char buf[MAX_PATH];
    fread(buf, sizeof(char), MAX_PATH, file);
    sscanf(buf, "%s %*s %*s %*s %*s %*s %*s %*s %*s",
            file_info->name,
            file_info->size,
            file_info->mode,
            file_info->inode,
            file_info->linkname,
            file_info->path,
            file_info->dev,
            file_info->rdev);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    DIR* dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    struct stat info;
    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        char full_path[MAX_PATH];
        strcpy(full_path, argv[1]);
        strcat(full_path, "/");
        strcat(full_path, entry->d_name);
        int res = stat(full_path, &info);
        if (res == 0 && S_ISDIR(info.st_mode)) {
            continue;
        }
        File file_info;
        FILE* file = fopen(full_path, "r");
        if (file == NULL) {
            perror("fopen");
            continue;
        }
        get_metadata(file, &file_info);
        printf("%s\n", file_info.name);
        fclose(file);
    }
    closedir(dir);

    return 0;
}