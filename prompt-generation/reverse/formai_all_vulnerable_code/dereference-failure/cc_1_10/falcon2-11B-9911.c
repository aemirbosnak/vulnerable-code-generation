//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

// Function to compare two files for equality
int compare_files(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    if (f1 == NULL || f2 == NULL) {
        return -1;
    }
    char c1, c2;
    while ((c1 = fgetc(f1))!= EOF && (c2 = fgetc(f2))!= EOF) {
        if (c1!= c2) {
            return 0;
        }
    }
    fclose(f1);
    fclose(f2);
    return 1;
}

// Function to compare two directories for equality
int compare_directories(const char *dir1, const char *dir2) {
    DIR *d1, *d2;
    struct dirent *ent1, *ent2;
    if ((d1 = opendir(dir1)) == NULL || (d2 = opendir(dir2)) == NULL) {
        return -1;
    }
    while ((ent1 = readdir(d1))!= NULL) {
        const char *ent1_path = dirname(ent1->d_name);
        if (strcmp(ent1_path, dir1) == 0) {
            if (compare_files(ent1_path, ent1->d_name) == 0) {
                continue;
            }
        }
        if ((d1 = opendir(ent1_path)) == NULL) {
            continue;
        }
        while ((ent2 = readdir(d1))!= NULL) {
            if (compare_files(ent1->d_name, ent2->d_name) == 0) {
                continue;
            }
            if (compare_directories(ent1->d_name, ent2->d_name) == 0) {
                continue;
            }
        }
    }
    closedir(d1);
    closedir(d2);
    return 1;
}

int main() {
    char *dir1 = "path1";
    char *dir2 = "path2";
    if (compare_directories(dir1, dir2) == 0) {
        printf("The directories are equal\n");
    } else {
        printf("The directories are not equal\n");
    }
    return 0;
}