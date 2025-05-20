//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define MAX_DEPTH 1000

typedef struct {
    char path[MAX_DEPTH];
    unsigned long long size;
} FileInfo;

void read_directory(const char* path, int depth) {
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            char child_path[MAX_DEPTH];
            strcpy(child_path, path);
            strcat(child_path, "/");
            strcat(child_path, ent->d_name);

            struct stat st;
            if (stat(child_path, &st) == 0) {
                if (S_ISDIR(st.st_mode)) {
                    if (depth < MAX_DEPTH - 1) {
                        read_directory(child_path, depth + 1);
                    }
                } else {
                    FileInfo file_info;
                    strcpy(file_info.path, child_path);
                    file_info.size = st.st_size;
                    printf("%s %llu bytes\n", file_info.path, file_info.size);
                }
            }
        }
        closedir(dir);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    read_directory(argv[1], 0);

    return 0;
}