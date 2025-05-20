//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH 1024

typedef struct dirent dirent;

void sync_files(char* source, char* destination) {
    DIR *d1, *d2;
    struct dirent *dir;
    d1 = opendir(source);
    d2 = opendir(destination);

    if (d1 == NULL || d2 == NULL) {
        printf("Error opening directories\n");
        exit(1);
    }

    while ((dir = readdir(d1))!= NULL) {
        char path[MAX_PATH];
        strcpy(path, source);
        strcat(path, "/");
        strcat(path, dir->d_name);

        if (dir->d_type == DT_DIR) {
            mkdir(path, 0777);
            sync_files(path, destination);
        } else {
            char dest_path[MAX_PATH];
            strcpy(dest_path, destination);
            strcat(dest_path, "/");
            strcat(dest_path, dir->d_name);

            FILE *file1, *file2;
            file1 = fopen(path, "r");
            file2 = fopen(dest_path, "r");

            if (file1 == NULL || file2 == NULL) {
                printf("Error opening files\n");
                exit(1);
            }

            fseek(file1, 0, SEEK_END);
            int size1 = ftell(file1);
            fseek(file2, 0, SEEK_END);
            int size2 = ftell(file2);

            if (size1!= size2) {
                fclose(file1);
                fclose(file2);
                remove(dest_path);
                rename(path, dest_path);
            } else {
                fclose(file1);
                fclose(file2);
            }
        }
    }

    closedir(d1);
    closedir(d2);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source destination\n", argv[0]);
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    return 0;
}