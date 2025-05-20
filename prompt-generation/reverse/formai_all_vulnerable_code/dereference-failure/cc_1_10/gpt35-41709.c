//FormAI DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// A function to check if a file exists or not
int file_exists(char *filename) {
    struct stat buf;
    return stat(filename, &buf) == 0;
}

// A function to copy the contents of a file
void copy_file(char *source, char *destination) {
    FILE *fp1, *fp2;
    char c;
    fp1 = fopen(source, "r");
    fp2 = fopen(destination, "w");
    while ((c = fgetc(fp1)) != EOF) {
        fputc(c, fp2);
    }
    fclose(fp1);
    fclose(fp2);
}

// A function to synchronize two directories
void sync_directory(char *source_dir, char *target_dir) {
    DIR *dir;
    struct dirent *entry;
    char source_file[100], target_file[100];
    if ((dir = opendir(source_dir)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            // Ignore . and .. directories
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
            sprintf(source_file, "%s/%s", source_dir, entry->d_name);
            sprintf(target_file, "%s/%s", target_dir, entry->d_name);
            if (file_exists(target_file)) {
                // Check if content is same
                FILE *fp1, *fp2;
                char c1, c2;
                fp1 = fopen(source_file, "r");
                fp2 = fopen(target_file, "r");
                int same = 1;
                while ((c1 = fgetc(fp1)) != EOF && (c2 = fgetc(fp2)) != EOF) {
                    if (c1 != c2) {
                        same = 0;
                        break;
                    }
                }
                if (c1 != c2) same = 0;
                fclose(fp1);
                fclose(fp2);
                if (!same) {
                    printf("File \"%s\" updated in %s.\n", entry->d_name, target_dir);
                    copy_file(source_file, target_file);
                }
            } else {
                printf("File \"%s\" added to %s.\n", entry->d_name, target_dir);
                copy_file(source_file, target_file);
            }
        }
        closedir(dir);
    } else {
        printf("Error opening directory: %s", source_dir);
        exit(1);
    }
}

int main() {
    sync_directory("dir1", "dir2");
    sync_directory("dir2", "dir1");
    return 0;
}