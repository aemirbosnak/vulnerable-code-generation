//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_FILE_NAME 256
#define MAX_PATH 1024

struct entry {
    char filename[MAX_FILE_NAME];
    int is_file;
    struct stat st;
};

void print_help() {
    printf("Usage:./program -s source_dir -d destination_dir\n");
}

void print_dir(char* path, int is_file) {
    DIR* dir = opendir(path);
    struct dirent* entry;

    if (dir == NULL) {
        perror("Error opening directory");
        exit(1);
    }

    while ((entry = readdir(dir))!= NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        sprintf(full_path, "%s/%s", path, entry->d_name);

        struct stat st;
        stat(full_path, &st);

        if (S_ISDIR(st.st_mode)) {
            if (is_file) {
                continue;
            }
            printf("%s/\n", entry->d_name);
        } else {
            if (!is_file) {
                continue;
            }
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc!= 5) {
        print_help();
        return 1;
    }

    char* source_dir = argv[2];
    char* dest_dir = argv[4];

    print_dir(source_dir, 0);
    print_dir(dest_dir, 1);

    return 0;
}