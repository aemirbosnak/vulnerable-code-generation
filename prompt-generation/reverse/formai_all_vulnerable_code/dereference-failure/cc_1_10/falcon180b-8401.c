//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_NAME_LENGTH 1024
#define MAX_PATH_LENGTH 2048

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    unsigned long long file_size;
} file_info;

void read_directory(char *path, int level) {
    DIR *d;
    struct dirent *dir;
    char next_path[MAX_PATH_LENGTH];

    d = opendir(path);

    if (d) {
        while ((dir = readdir(d))!= NULL) {
            if (dir->d_type == DT_DIR) {
                strcpy(next_path, path);
                strcat(next_path, "/");
                strcat(next_path, dir->d_name);
                read_directory(next_path, level + 1);
            } else {
                strcpy(next_path, path);
                strcat(next_path, "/");
                strcat(next_path, dir->d_name);
                struct stat st;
                stat(next_path, &st);

                file_info file;
                strncpy(file.file_name, dir->d_name, MAX_FILE_NAME_LENGTH - 1);
                file.file_name[MAX_FILE_NAME_LENGTH - 1] = '\0';
                file.file_size = st.st_size;

                printf("%*s %10llu bytes %s\n", level * 4, "", file.file_size, file.file_name);
            }
        }

        closedir(d);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    read_directory(argv[1], 0);

    return 0;
}