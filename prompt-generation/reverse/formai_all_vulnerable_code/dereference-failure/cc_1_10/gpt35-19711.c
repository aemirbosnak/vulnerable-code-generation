//FormAI DATASET v1.0 Category: File Synchronizer ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

void cheer(char *msg) {
    printf("%s! Go team go!\n", msg);
}

void syncfiles(char *dir1, char *dir2) {
    DIR *d1, *d2;
    struct dirent *dir_entry1, *dir_entry2;
    struct stat st1, st2;
    char file1[255], file2[255], buf1[BUFSIZ], buf2[BUFSIZ];
    int cmp;

    d1 = opendir(dir1);
    d2 = opendir(dir2);

    if (d1 == NULL || d2 == NULL) {
        printf("Error opening directories.\n");
        return;
    }

    printf("Syncing %s with %s...\n", dir1, dir2);

    while((dir_entry1 = readdir(d1)) != NULL) {
        if (strcmp(dir_entry1->d_name, ".") == 0 || strcmp(dir_entry1->d_name, "..") == 0) {
            continue;
        }
        sprintf(file1, "%s/%s", dir1, dir_entry1->d_name);
        stat(file1, &st1);

        while((dir_entry2 = readdir(d2)) != NULL) {
            if (strcmp(dir_entry2->d_name, ".") == 0 || strcmp(dir_entry2->d_name, "..") == 0) {
                continue;
            }
            sprintf(file2, "%s/%s", dir2, dir_entry2->d_name);
            stat(file2, &st2);
            cmp = strcmp(dir_entry1->d_name, dir_entry2->d_name);

            if (cmp == 0) {
                if (st1.st_mtime > st2.st_mtime) {
                    FILE *f1 = fopen(file1, "r");
                    FILE *f2 = fopen(file2, "w");

                    while(fgets(buf1, BUFSIZ, f1)) {
                        fputs(buf1, f2);
                    }

                    fclose(f1);
                    fclose(f2);
                    cheer("File updated");
                } else if (st1.st_mtime < st2.st_mtime) {
                    FILE *f1 = fopen(file1, "w");
                    FILE *f2 = fopen(file2, "r");

                    while(fgets(buf2, BUFSIZ, f2)) {
                        fputs(buf2, f1);
                    }

                    fclose(f1);
                    fclose(f2);
                    cheer("File updated");
                } else {
                    cheer("Files are already in sync!");
                }
            }
        }
        rewinddir(d2);
    }

    closedir(d1);
    closedir(d2);
}

int main() {
    char dir1[255], dir2[255];

    printf("Enter first directory to sync: ");
    scanf("%s", dir1);

    printf("Enter second directory to sync: ");
    scanf("%s", dir2);

    syncfiles(dir1, dir2);

    printf("Sync complete!\n");

    return 0;
}