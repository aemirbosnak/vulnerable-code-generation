//FormAI DATASET v1.0 Category: File Synchronizer ; Style: shape shifting
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILE_LENGTH 128
#define NUM_FILES 10

typedef struct FileInfo {
    char filename[MAX_FILE_LENGTH];
    size_t size;
    time_t modified_at;
} FileInfo;

void list_files(const char* path, FileInfo files[NUM_FILES], int* num_files) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", strerror(errno));
        return;
    }

    struct dirent* dent;
    while ((dent = readdir(dir)) != NULL && *num_files < NUM_FILES) {
        if (dent->d_type != DT_REG || strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0) {
            continue;
        }

        FileInfo* file = &files[*num_files];
        snprintf(file->filename, MAX_FILE_LENGTH, "%s/%s", path, dent->d_name);

        struct stat st;
        if (stat(file->filename, &st) == 0) {
            file->size = st.st_size;
            file->modified_at = st.st_mtime;
            (*num_files)++;
        }
    }

    closedir(dir);
}

void sync_files(const char* path1, const char* path2) {
    FileInfo files1[NUM_FILES], files2[NUM_FILES];
    int num_files1 = 0, num_files2 = 0;

    list_files(path1, files1, &num_files1);
    list_files(path2, files2, &num_files2);

    for (int i = 0; i < num_files1; i++) {
        FileInfo* file1 = &files1[i];

        // check if file exists in path2
        int file_exists = 0;
        for (int j = 0; j < num_files2; j++) {
            FileInfo* file2 = &files2[j];
            if (strcmp(file1->filename, file2->filename) == 0) {
                file_exists = 1;

                // check if file has been modified
                if (file1->modified_at > file2->modified_at) {
                    printf("Updating %s\n", file1->filename);
                    unlink(file2->filename);
                    if (link(file1->filename, file2->filename) != 0) {
                        fprintf(stderr, "Error creating link: %s\n", strerror(errno));
                    }
                }
                break;
            }
        }

        // if file doesn't exist, copy it over
        if (!file_exists) {
            FileInfo* file2 = &files2[num_files2++];
            strncpy(file2->filename, file1->filename, MAX_FILE_LENGTH);
            file2->size = file1->size;
            file2->modified_at = file1->modified_at;

            printf("Copying %s\n", file1->filename);
            char command[MAX_PATH_LENGTH * 2 + 20];
            snprintf(command, MAX_PATH_LENGTH * 2 + 20, "cp %s %s", file1->filename, path2);
            system(command);
        }
    }

    for (int j = 0; j < num_files2; j++) {
        FileInfo* file2 = &files2[j];

        // check if file exists in path1
        int file_exists = 0;
        for (int i = 0; i < num_files1; i++) {
            FileInfo* file1 = &files1[i];
            if (strcmp(file1->filename, file2->filename) == 0) {
                file_exists = 1;
                break;
            }
        }

        // if file doesn't exist, delete it
        if (!file_exists) {
            printf("Deleting %s\n", file2->filename);
            unlink(file2->filename);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <path1> <path2>\n", argv[0]);
        return 1;
    }

    while (1) {
        sync_files(argv[1], argv[2]);
        sleep(5);
    }

    return 0;
}