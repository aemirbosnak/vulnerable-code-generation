//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    int file_type; // 0 = file, 1 = directory
} File;

void print_files(File* files, int num_files) {
    for (int i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].file_name, files[i].file_size);
    }
}

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd))!= NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd");
        return 1;
    }

    DIR* dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    int num_files = 0;
    File files[1024];
    struct dirent* dirent;
    while ((dirent = readdir(dir))!= NULL) {
        if (num_files >= 1024) {
            printf("Too many files in directory.\n");
            break;
        }
        strcpy(files[num_files].file_name, dirent->d_name);
        files[num_files].file_size = dirent->d_reclen;
        if (dirent->d_type == DT_DIR) {
            files[num_files].file_type = 1;
        } else {
            files[num_files].file_type = 0;
        }
        num_files++;
    }

    closedir(dir);

    print_files(files, num_files);

    return 0;
}