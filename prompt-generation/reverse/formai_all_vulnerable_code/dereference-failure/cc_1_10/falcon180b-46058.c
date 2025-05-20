//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PATH_LEN 1024

typedef struct {
    char path[MAX_PATH_LEN];
    int is_file;
} file_t;

void sync_files(char* source_path, char* dest_path, int is_copy) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(source_path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }
            char path[MAX_PATH_LEN];
            strcpy(path, source_path);
            strcat(path, "/");
            strcat(path, ent->d_name);

            struct stat st;
            stat(path, &st);

            file_t file;
            strcpy(file.path, path);
            file.is_file = S_ISREG(st.st_mode);

            sync_files(path, dest_path, is_copy);
        }
        closedir(dir);
    }
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s source_path dest_path [copy|sync]\n", argv[0]);
        exit(1);
    }

    char* source_path = argv[1];
    char* dest_path = argv[2];
    int is_copy = 0;

    if (argc == 4) {
        if (strcmp(argv[3], "copy") == 0) {
            is_copy = 1;
        } else if (strcmp(argv[3], "sync")!= 0) {
            printf("Invalid operation. Use 'copy' or'sync'.\n");
            exit(1);
        }
    }

    sync_files(source_path, dest_path, is_copy);

    return 0;
}