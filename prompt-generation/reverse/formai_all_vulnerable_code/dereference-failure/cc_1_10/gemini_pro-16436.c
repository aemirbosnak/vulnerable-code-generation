//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

// Function to get the file size
long long get_file_size(const char *filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

// Function to compare two files
int compare_files(const char *file1, const char *file2) {
    long long size1 = get_file_size(file1);
    long long size2 = get_file_size(file2);

    if (size1 != size2) {
        return 0;
    }

    FILE *fp1 = fopen(file1, "rb");
    FILE *fp2 = fopen(file2, "rb");

    char buffer1[1024];
    char buffer2[1024];

    while (fread(buffer1, 1, 1024, fp1) == 1024 && fread(buffer2, 1, 1024, fp2) == 1024) {
        if (memcmp(buffer1, buffer2, 1024) != 0) {
            fclose(fp1);
            fclose(fp2);
            return 0;
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 1;
}

// Function to copy a file
void copy_file(const char *src, const char *dest) {
    FILE *fp1 = fopen(src, "rb");
    FILE *fp2 = fopen(dest, "wb");

    char buffer[1024];

    while (fread(buffer, 1, 1024, fp1) == 1024) {
        fwrite(buffer, 1, 1024, fp2);
    }

    fclose(fp1);
    fclose(fp2);
}

// Function to synchronize two directories
void sync_directories(const char *dir1, const char *dir2) {
    DIR *dp1 = opendir(dir1);
    DIR *dp2 = opendir(dir2);

    struct dirent *dent1;
    struct dirent *dent2;

    while ((dent1 = readdir(dp1)) != NULL && (dent2 = readdir(dp2)) != NULL) {
        if (strcmp(dent1->d_name, ".") == 0 || strcmp(dent1->d_name, "..") == 0) {
            continue;
        }

        if (strcmp(dent2->d_name, ".") == 0 || strcmp(dent2->d_name, "..") == 0) {
            continue;
        }

        char file1[1024];
        char file2[1024];

        sprintf(file1, "%s/%s", dir1, dent1->d_name);
        sprintf(file2, "%s/%s", dir2, dent2->d_name);

        struct stat st1;
        struct stat st2;

        stat(file1, &st1);
        stat(file2, &st2);

        if (st1.st_mtime > st2.st_mtime) {
            copy_file(file1, file2);
        } else if (st2.st_mtime > st1.st_mtime) {
            copy_file(file2, file1);
        }
    }

    closedir(dp1);
    closedir(dp2);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dir1> <dir2>\n", argv[0]);
        return 1;
    }

    sync_directories(argv[1], argv[2]);

    return 0;
}