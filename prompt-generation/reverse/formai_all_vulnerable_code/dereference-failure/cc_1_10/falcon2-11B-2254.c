//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FileSynchronizer {
    char *filename;
    char *directory;
    int *diff_count;
};

struct FileSynchronizer *file_synchronizer_create(char *filename, char *directory) {
    struct FileSynchronizer *fs = malloc(sizeof(struct FileSynchronizer));
    fs->filename = strdup(filename);
    fs->directory = strdup(directory);
    fs->diff_count = malloc(sizeof(int));
    *fs->diff_count = 0;
    return fs;
}

void file_synchronizer_destroy(struct FileSynchronizer *fs) {
    free(fs->filename);
    free(fs->directory);
    free(fs->diff_count);
    free(fs);
}

void file_synchronizer_compare(struct FileSynchronizer *fs) {
    FILE *f1 = fopen(fs->filename, "r");
    FILE *f2 = fopen(fs->directory, "r");

    char line1[100], line2[100];
    int diff_count = 0;

    while (fgets(line1, sizeof(line1), f1) && fgets(line2, sizeof(line2), f2)) {
        if (strcmp(line1, line2)!= 0) {
            ++diff_count;
        }
    }

    fclose(f1);
    fclose(f2);
    *fs->diff_count = diff_count;
}

int main() {
    char *filename = "input.txt";
    char *directory = "output.txt";

    struct FileSynchronizer *fs = file_synchronizer_create(filename, directory);
    file_synchronizer_compare(fs);
    printf("Difference count: %d\n", fs->diff_count);

    file_synchronizer_destroy(fs);

    return 0;
}