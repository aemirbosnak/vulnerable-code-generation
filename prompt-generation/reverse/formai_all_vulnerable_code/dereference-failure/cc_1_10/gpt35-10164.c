//FormAI DATASET v1.0 Category: File Synchronizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to check if a file exists
int fileExists(const char *path) {
    if (access(path, F_OK) != -1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to synchronize two directories
void synchDirs(const char *dir1, const char *dir2) {
    DIR *d1, *d2;
    struct dirent *dir1Entry, *dir2Entry;
    struct stat dir1Stat, dir2Stat;
    char filePath1[256], filePath2[256];

    d1 = opendir(dir1);
    if (d1 == NULL) {
        printf("Error opening directory %s\n", dir1);
        exit(EXIT_FAILURE);
    }

    d2 = opendir(dir2);
    if (d2 == NULL) {
        printf("Error opening directory %s\n", dir2);
        exit(EXIT_FAILURE);
    }

    // Check files in dir1 and sync with dir2
    while ((dir1Entry = readdir(d1)) != NULL) {
        if (dir1Entry->d_type == DT_REG) {
            snprintf(filePath1, sizeof(filePath1), "%s/%s", dir1, dir1Entry->d_name);
            snprintf(filePath2, sizeof(filePath2), "%s/%s", dir2, dir1Entry->d_name);

            if (fileExists(filePath2)) {
                // File already exists, check timestamps
                stat(filePath1, &dir1Stat);
                stat(filePath2, &dir2Stat);

                if (dir1Stat.st_mtime > dir2Stat.st_mtime) {
                    // dir1 file is newer, copy to dir2
                    FILE *file1, *file2;
                    char ch;

                    file1 = fopen(filePath1, "r");
                    file2 = fopen(filePath2, "w");
                    if (file1 == NULL || file2 == NULL) {
                        printf("Error copying file %s\n", filePath1);
                        continue;
                    }

                    while ((ch = fgetc(file1)) != EOF) {
                        fputc(ch, file2);
                    }

                    printf("Copied %s to %s\n", filePath1, filePath2);

                    fclose(file1);
                    fclose(file2);
                }
            } else {
                // File does not exist, copy to dir2
                FILE *file1, *file2;
                char ch;

                file1 = fopen(filePath1, "r");
                file2 = fopen(filePath2, "w");
                if (file1 == NULL || file2 == NULL) {
                    printf("Error copying file %s\n", filePath1);
                    continue;
                }

                while ((ch = fgetc(file1)) != EOF) {
                    fputc(ch, file2);
                }

                printf("Copied %s to %s\n", filePath1, filePath2);

                fclose(file1);
                fclose(file2);
            }
        }
    }

    // Check files in dir2 and sync with dir1
    rewinddir(d1);
    while ((dir2Entry = readdir(d2)) != NULL) {
        if (dir2Entry->d_type == DT_REG) {
            snprintf(filePath1, sizeof(filePath1), "%s/%s", dir1, dir2Entry->d_name);
            snprintf(filePath2, sizeof(filePath2), "%s/%s", dir2, dir2Entry->d_name);

            if (!fileExists(filePath1)) {
                // File does not exist in dir1, copy from dir2
                FILE *file1, *file2;
                char ch;

                file2 = fopen(filePath2, "r");
                file1 = fopen(filePath1, "w");
                if (file1 == NULL || file2 == NULL) {
                    printf("Error copying file %s\n", filePath2);
                    continue;
                }

                while ((ch = fgetc(file2)) != EOF) {
                    fputc(ch, file1);
                }

                printf("Copied %s to %s\n", filePath2, filePath1);

                fclose(file1);
                fclose(file2);
            }
        }
    }

    closedir(d1);
    closedir(d2);

    printf("Done synchronizing %s with %s\n", dir1, dir2);
}

int main() {
    synchDirs("dir1", "dir2");
    synchDirs("dir2", "dir1");

    return 0;
}