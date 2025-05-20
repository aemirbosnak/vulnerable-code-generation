//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

// Function to copy a file
void copyFile(char *src, char *dest) {
    FILE *fr, *fw;
    char buffer[BUFFER_SIZE];
    size_t n;

    fr = fopen(src, "rb");
    if (fr == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fw = fopen(dest, "wb");
    if (fw == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while ((n = fread(buffer, 1, BUFFER_SIZE, fr)) > 0) {
        if (fwrite(buffer, 1, n, fw) != n) {
            perror("fwrite");
            exit(EXIT_FAILURE);
        }
    }

    fclose(fr);
    fclose(fw);
}

// Function to compare two files
int compareFiles(char *file1, char *file2) {
    FILE *f1, *f2;
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    size_t n1, n2;

    f1 = fopen(file1, "rb");
    if (f1 == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    f2 = fopen(file2, "rb");
    if (f2 == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while ((n1 = fread(buffer1, 1, BUFFER_SIZE, f1)) > 0 && (n2 = fread(buffer2, 1, BUFFER_SIZE, f2)) > 0) {
        if (memcmp(buffer1, buffer2, n1) != 0) {
            fclose(f1);
            fclose(f2);
            return 0;
        }
    }

    if (n1 != n2) {
        fclose(f1);
        fclose(f2);
        return 0;
    }

    fclose(f1);
    fclose(f2);
    return 1;
}

// Function to synchronize two directories
void synchronizeDirectories(char *dir1, char *dir2) {
    DIR *d1, *d2;
    struct dirent *ent1, *ent2;
    char path1[256], path2[256];

    d1 = opendir(dir1);
    if (d1 == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    d2 = opendir(dir2);
    if (d2 == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((ent1 = readdir(d1)) != NULL) {
        if (strcmp(ent1->d_name, ".") == 0 || strcmp(ent1->d_name, "..") == 0) {
            continue;
        }

        snprintf(path1, 256, "%s/%s", dir1, ent1->d_name);
        snprintf(path2, 256, "%s/%s", dir2, ent1->d_name);

        if (ent1->d_type == DT_DIR) {
            synchronizeDirectories(path1, path2);
        } else {
            if (access(path2, F_OK) == -1) {
                copyFile(path1, path2);
            } else {
                if (!compareFiles(path1, path2)) {
                    copyFile(path1, path2);
                }
            }
        }
    }

    closedir(d1);
    closedir(d2);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dir1> <dir2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    synchronizeDirectories(argv[1], argv[2]);

    return 0;
}