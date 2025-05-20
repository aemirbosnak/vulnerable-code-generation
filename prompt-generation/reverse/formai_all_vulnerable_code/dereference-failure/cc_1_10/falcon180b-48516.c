//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

// Function to compare two files
int compare_files(FILE *file1, FILE *file2) {
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    int bytes_read1, bytes_read2;

    do {
        bytes_read1 = fread(buffer1, sizeof(char), BUFFER_SIZE, file1);
        bytes_read2 = fread(buffer2, sizeof(char), BUFFER_SIZE, file2);

        if (bytes_read1!= bytes_read2) {
            return 1;
        }

        int result = memcmp(buffer1, buffer2, bytes_read1);

        if (result!= 0) {
            return 1;
        }
    } while (bytes_read1 == BUFFER_SIZE && bytes_read2 == BUFFER_SIZE);

    return 0;
}

// Function to synchronize files in two directories
void synchronize_directories(char *dir1, char *dir2) {
    DIR *d1, *d2;
    struct dirent *dir_entry;

    d1 = opendir(dir1);
    d2 = opendir(dir2);

    if (d1 == NULL || d2 == NULL) {
        printf("Error: One or both directories do not exist.\n");
        exit(1);
    }

    while ((dir_entry = readdir(d1))!= NULL) {
        char file_path1[MAX_PATH];
        char file_path2[MAX_PATH];

        sprintf(file_path1, "%s/%s", dir1, dir_entry->d_name);
        sprintf(file_path2, "%s/%s", dir2, dir_entry->d_name);

        FILE *file1 = fopen(file_path1, "rb");
        FILE *file2 = fopen(file_path2, "rb");

        if (file1 == NULL || file2 == NULL) {
            printf("Error: One or both files do not exist.\n");
            exit(1);
        }

        int result = compare_files(file1, file2);

        if (result == 1) {
            printf("Files are different: %s\n", file_path1);
        }

        fclose(file1);
        fclose(file2);
    }

    closedir(d1);
    closedir(d2);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <directory1> <directory2>\n", argv[0]);
        exit(1);
    }

    synchronize_directories(argv[1], argv[2]);

    return 0;
}