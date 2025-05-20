//FormAI DATASET v1.0 Category: File Synchronizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_PATH_LENGTH 1024

bool are_files_equal(const char* file1_path, const char* file2_path) {
    FILE* file1 = fopen(file1_path, "rb");
    FILE* file2 = fopen(file2_path, "rb");

    if (file1 == NULL || file2 == NULL) {
        return false;
    }

    fseek(file1, 0, SEEK_END);
    fseek(file2, 0, SEEK_END);

    const int file1_size = ftell(file1);
    const int file2_size = ftell(file2);

    if (file1_size != file2_size) {
        fclose(file1);
        fclose(file2);
        return false;
    }

    rewind(file1);
    rewind(file2);

    int byte1, byte2;

    do {
        byte1 = fgetc(file1);
        byte2 = fgetc(file2);
    } while (byte1 != EOF && byte2 != EOF && byte1 == byte2);

    fclose(file1);
    fclose(file2);

    return byte1 == byte2;
}

void sync_files(const char* file1_path, const char* file2_path) {
    FILE* file1 = fopen(file1_path, "rb");
    FILE* file2 = fopen(file2_path, "wb");

    if (file1 == NULL || file2 == NULL) {
        return;
    }

    fseek(file1, 0, SEEK_END);
    const int file1_size = ftell(file1);
    rewind(file1);

    char* buffer = (char*) malloc(file1_size * sizeof(char));
    fread(buffer, 1, file1_size, file1);

    fwrite(buffer, 1, file1_size, file2);

    fclose(file1);
    fclose(file2);

    free(buffer);
}

void sync_directories(const char* dir1_path, const char* dir2_path) {
    DIR* dir1 = opendir(dir1_path);
    DIR* dir2 = opendir(dir2_path);

    if (dir1 == NULL || dir2 == NULL) {
        return;
    }

    struct dirent* entry1;
    struct dirent* entry2;

    while ((entry1 = readdir(dir1))) {
        if (entry1->d_name[0] == '.') {
            continue;
        }

        char file1_path[MAX_PATH_LENGTH];
        strcpy(file1_path, dir1_path);
        strcat(file1_path, "/");
        strcat(file1_path, entry1->d_name);

        char file2_path[MAX_PATH_LENGTH];
        strcpy(file2_path, dir2_path);
        strcat(file2_path, "/");
        strcat(file2_path, entry1->d_name);

        struct stat file1_stat;
        struct stat file2_stat;

        if (stat(file1_path, &file1_stat) < 0 || stat(file2_path, &file2_stat) < 0) {
            continue;
        }

        if (S_ISREG(file1_stat.st_mode) && S_ISREG(file2_stat.st_mode)) {
            if (!are_files_equal(file1_path, file2_path)) {
                sync_files(file1_path, file2_path);
            }
        } else if (S_ISDIR(file1_stat.st_mode) && S_ISDIR(file2_stat.st_mode)) {
            sync_directories(file1_path, file2_path);
        }
    }

    closedir(dir1);
    closedir(dir2);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <directory1_path> <directory2_path>\n", argv[0]);
        return 1;
    }

    sync_directories(argv[1], argv[2]);

    return 0;
}