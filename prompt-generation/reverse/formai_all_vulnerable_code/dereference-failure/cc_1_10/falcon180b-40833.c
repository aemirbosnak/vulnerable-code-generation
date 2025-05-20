//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH 1024

struct dirent *readdir(DIR *dir);
int closedir(DIR *dir);

int main(int argc, char *argv[]) {
    DIR *dir1, *dir2;
    struct dirent *ent1, *ent2;
    char path1[MAX_PATH], path2[MAX_PATH];
    int i, j;

    // Open directories
    dir1 = opendir(argv[1]);
    dir2 = opendir(argv[2]);

    // Check if directories are valid
    if (dir1 == NULL || dir2 == NULL) {
        printf("Invalid directory path.\n");
        exit(1);
    }

    // Read directories
    while ((ent1 = readdir(dir1))!= NULL) {
        strcpy(path1, argv[1]);
        strcat(path1, "/");
        strcat(path1, ent1->d_name);

        while ((ent2 = readdir(dir2))!= NULL) {
            strcpy(path2, argv[2]);
            strcat(path2, "/");
            strcat(path2, ent2->d_name);

            // Compare file names
            if (strcmp(path1, path2) == 0) {
                // Check if files have same size
                struct stat stat1, stat2;
                stat(path1, &stat1);
                stat(path2, &stat2);

                if (stat1.st_size!= stat2.st_size) {
                    printf("Files have different sizes.\n");
                } else {
                    // Check if files have same content
                    FILE *fp1, *fp2;
                    char ch1, ch2;

                    fp1 = fopen(path1, "r");
                    fp2 = fopen(path2, "r");

                    while ((ch1 = fgetc(fp1))!= EOF && (ch2 = fgetc(fp2))!= EOF) {
                        if (ch1!= ch2) {
                            printf("Files have different content.\n");
                            break;
                        }
                    }

                    fclose(fp1);
                    fclose(fp2);
                }
            }
        }
    }

    // Close directories
    closedir(dir1);
    closedir(dir2);

    return 0;
}

struct dirent *readdir(DIR *dir) {
    return readdir(dir);
}

int closedir(DIR *dir) {
    return closedir(dir);
}