//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Claude Shannon
/* Claude Shannon Style C File Synchronizer Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILEPATH_LENGTH 512
#define MAX_NUM_FILES 1000

/* Function to check if a file exists */
int fileExists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

/* Function to recursively traverse directories and synchronize files */
void syncFiles(const char *dir1, const char *dir2) {
    DIR *d1, *d2;
    struct dirent *entry1, *entry2;
    char filepath1[MAX_FILEPATH_LENGTH], filepath2[MAX_FILEPATH_LENGTH];
    int i, numFiles1 = 0, numFiles2 = 0;
    char *files1[MAX_NUM_FILES], *files2[MAX_NUM_FILES];

    /* Open directories */
    d1 = opendir(dir1);
    d2 = opendir(dir2);
    if (d1 == NULL || d2 == NULL) {
        printf("Error: Unable to open directories\n");
        exit(1);
    }

    /* Traverse dir1 and save file names */
    while ((entry1 = readdir(d1)) != NULL) {
        if (entry1->d_type == DT_REG) {
            char *filename = malloc(MAX_FILENAME_LENGTH);
            sprintf(filename, "%s/%s", dir1, entry1->d_name);
            files1[numFiles1++] = filename;
        } else if (entry1->d_type == DT_DIR && strcmp(entry1->d_name, ".") != 0 && strcmp(entry1->d_name, "..") != 0) {
            char subDir1[MAX_FILEPATH_LENGTH];
            sprintf(subDir1, "%s/%s", dir1, entry1->d_name);
            char subDir2[MAX_FILEPATH_LENGTH];
            sprintf(subDir2, "%s/%s", dir2, entry1->d_name);
            syncFiles(subDir1, subDir2);
        }
    }

    /* Traverse dir2 and save file names */
    while ((entry2 = readdir(d2)) != NULL) {
        if (entry2->d_type == DT_REG) {
            char *filename = malloc(MAX_FILENAME_LENGTH);
            sprintf(filename, "%s/%s", dir2, entry2->d_name);
            files2[numFiles2++] = filename;
        } else if (entry2->d_type == DT_DIR && strcmp(entry2->d_name, ".") != 0 && strcmp(entry2->d_name, "..") != 0) {
            char subDir1[MAX_FILEPATH_LENGTH];
            sprintf(subDir1, "%s/%s", dir1, entry2->d_name);
            char subDir2[MAX_FILEPATH_LENGTH];
            sprintf(subDir2, "%s/%s", dir2, entry2->d_name);
            syncFiles(subDir1, subDir2);
        }
    }

    /* Synchronize files */
    for (i = 0; i < numFiles1; i++) {
        sprintf(filepath1, "%s", files1[i]);
        sprintf(filepath2, "%s/%s", dir2, strrchr(files1[i], '/') + 1);
        if (fileExists(filepath2)) {
            struct stat stat1, stat2;
            stat(filepath1, &stat1);
            stat(filepath2, &stat2);
            if (stat1.st_mtime > stat2.st_mtime) {
                printf("Copying file: %s -> %s\n", filepath1, filepath2);
                FILE *f1 = fopen(filepath1, "r");
                FILE *f2 = fopen(filepath2, "w");
                char c;
                while ((c = fgetc(f1)) != EOF) {
                    fputc(c, f2);
                }
                fclose(f1);
                fclose(f2);
            }
        } else {
            printf("Copying file: %s -> %s\n", filepath1, filepath2);
            FILE *f1 = fopen(filepath1, "r");
            FILE *f2 = fopen(filepath2, "w");
            char c;
            while ((c = fgetc(f1)) != EOF) {
                fputc(c, f2);
            }
            fclose(f1);
            fclose(f2);
        }
    }

    /* Clean up */
    for (i = 0; i < numFiles1; i++) {
        free(files1[i]);
    }
    for (i = 0; i < numFiles2; i++) {
        free(files2[i]);
    }
    closedir(d1);
    closedir(d2);
}

/* Main function */
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <directory 1> <directory 2>\n", argv[0]);
        return 1;
    }
    syncFiles(argv[1], argv[2]);
    return 0;
}