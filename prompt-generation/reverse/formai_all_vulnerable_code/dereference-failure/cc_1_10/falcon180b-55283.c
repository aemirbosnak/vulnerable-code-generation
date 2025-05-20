//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/vfs.h>
#include <sys/statvfs.h>

#define BLOCK_SIZE 1024

typedef struct {
    char name[100];
    int size;
    int dirs;
    int files;
} DirInfo;

void getDirInfo(const char* path, DirInfo* dirInfo) {
    DIR* d = opendir(path);
    struct dirent* de;
    struct statvfs fs;
    memset(dirInfo, 0, sizeof(DirInfo));

    if (d) {
        fstatvfs(dirfd(d), &fs);
        dirInfo->size = fs.f_blocks * fs.f_frsize;
        while ((de = readdir(d))!= NULL) {
            if (de->d_type == DT_DIR) {
                dirInfo->dirs++;
            } else if (de->d_type == DT_REG) {
                dirInfo->files++;
            }
        }
        closedir(d);
    }
}

void printDirInfo(DirInfo* dirInfo) {
    printf("Directory: %s\n", dirInfo->name);
    printf("Size: %.2f MB\n", (float)dirInfo->size / (1024 * 1024));
    printf("Directories: %d\n", dirInfo->dirs);
    printf("Files: %d\n", dirInfo->files);
    printf("\n");
}

void analyzeDiskSpace(const char* path) {
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    chdir(path);

    DirInfo rootInfo;
    getDirInfo(".", &rootInfo);
    printDirInfo(&rootInfo);

    chdir("..");

    DIR* d = opendir(".");
    struct dirent* de;
    while ((de = readdir(d))!= NULL) {
        if (de->d_type == DT_DIR) {
            DirInfo dirInfo;
            sprintf(dirInfo.name, "%s/%s", path, de->d_name);
            getDirInfo(dirInfo.name, &dirInfo);
            printDirInfo(&dirInfo);
        }
    }
    closedir(d);

    chdir(cwd);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    analyzeDiskSpace(argv[1]);
    return 0;
}