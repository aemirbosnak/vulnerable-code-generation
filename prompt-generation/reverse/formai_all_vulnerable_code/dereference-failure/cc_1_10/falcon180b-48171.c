//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_DIRECTORIES 100
#define MAX_FILES 1000
#define MAX_FILE_NAME_LEN 512

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    int is_file;
} FileInfo;

void print_help() {
    printf("Usage:./program directory_path\n");
}

int is_directory(const char* path) {
    struct stat stat_buf;
    if (stat(path, &stat_buf) == -1) {
        return 0;
    }
    return S_ISDIR(stat_buf.st_mode);
}

void scan_directory(const char* path, FileInfo files[]) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    struct dirent* entry;
    int count = 0;
    while ((entry = readdir(dir))!= NULL) {
        if (count >= MAX_FILES) {
            break;
        }

        char full_path[MAX_FILE_NAME_LEN];
        snprintf(full_path, MAX_FILE_NAME_LEN, "%s/%s", path, entry->d_name);

        if (is_directory(full_path)) {
            if (count >= MAX_DIRECTORIES) {
                break;
            }
            files[count].is_file = 0;
            strcpy(files[count].name, entry->d_name);
            count++;
        } else {
            if (count >= MAX_FILES) {
                break;
            }
            files[count].is_file = 1;
            strcpy(files[count].name, entry->d_name);
            count++;
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    FileInfo files[MAX_FILES];
    memset(files, 0, sizeof(files));

    scan_directory(argv[1], files);

    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].name[0]!= '\0') {
            printf("%s\n", files[i].name);
        }
    }

    return 0;
}