//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH 1024

// Function to compare two files
int compare_files(const char *file1, const char *file2) {
    FILE *fp1, *fp2;
    char ch1, ch2;
    int ret = 0;

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((ch1 = fgetc(fp1)) == (ch2 = fgetc(fp2))) {
        if (ch1 == EOF && ch2 == EOF) {
            ret = 0;
            break;
        }
    }

    if (ch1!= ch2) {
        ret = 1;
    }

    fclose(fp1);
    fclose(fp2);

    return ret;
}

// Function to synchronize files in two directories
void sync_files(const char *dir1, const char *dir2) {
    DIR *dp1, *dp2;
    struct dirent *dirp1, *dirp2;
    char path[MAX_PATH];

    dp1 = opendir(dir1);
    dp2 = opendir(dir2);

    if (dp1 == NULL || dp2 == NULL) {
        printf("Error opening directory\n");
        exit(1);
    }

    while ((dirp1 = readdir(dp1))!= NULL && (dirp2 = readdir(dp2))!= NULL) {
        strcpy(path, dir1);
        strcat(path, "/");
        strcat(path, dirp1->d_name);

        strcpy(path + strlen(path), "/");
        strcat(path, dirp2->d_name);

        if (dirp1->d_type == DT_DIR && dirp2->d_type == DT_DIR) {
            sync_files(path, path);
        } else if (dirp1->d_type == DT_REG && dirp2->d_type == DT_REG) {
            if (compare_files(path, path)) {
                printf("Files are not synchronized: %s\n", path);
            }
        }
    }

    closedir(dp1);
    closedir(dp2);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_directory target_directory\n", argv[0]);
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    return 0;
}