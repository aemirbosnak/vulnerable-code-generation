//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024
#define BUF_SIZE 4096

// Function to check if a file is a regular file
int is_regular_file(const char *path) {
    struct stat path_stat;
    if (stat(path, &path_stat) != 0) {
        return 0;
    }
    return S_ISREG(path_stat.st_mode);
}

// Function to recursively traverse a directory and synchronize its files
void traverse_directory(const char *path1, const char *path2) {
    DIR *dir1 = opendir(path1);
    DIR *dir2 = opendir(path2);
    if (dir1 == NULL || dir2 == NULL) {
        printf("Error: Unable to open directories\n");
        return;
    }
    struct dirent *ent1;
    while ((ent1 = readdir(dir1)) != NULL) {
        char full_path1[MAX_PATH_LENGTH];
        snprintf(full_path1, MAX_PATH_LENGTH, "%s/%s", path1, ent1->d_name);
        if (strcmp(ent1->d_name, ".") == 0 || strcmp(ent1->d_name, "..") == 0) {
            continue;
        }
        if (is_regular_file(full_path1)) {
            char full_path2[MAX_PATH_LENGTH];
            snprintf(full_path2, MAX_PATH_LENGTH, "%s/%s", path2, ent1->d_name);
            FILE *file1 = fopen(full_path1, "rb");
            FILE *file2 = fopen(full_path2, "rb");
            if (file1 == NULL) {
                printf("Error: Unable to read file %s\n", full_path1);
                continue;
            }
            if (file2 == NULL) {
                printf("File %s does not exist in directory %s. Copying...\n", ent1->d_name, path2);
                fclose(file1);
                char create_dir[MAX_PATH_LENGTH];
                snprintf(create_dir, MAX_PATH_LENGTH, "mkdir -p %s", path2);
                system(create_dir);
                char copy_command[MAX_PATH_LENGTH + 100];
                snprintf(copy_command, MAX_PATH_LENGTH + 100, "cp %s %s", full_path1, full_path2);
                system(copy_command);
                continue;
            }
            char buf1[BUF_SIZE];
            char buf2[BUF_SIZE];
            size_t n1, n2;
            int equal = 1;
            do {
                n1 = fread(buf1, 1, BUF_SIZE, file1);
                n2 = fread(buf2, 1, BUF_SIZE, file2);
                if (n1 != n2 || memcmp(buf1, buf2, n1) != 0) {
                    equal = 0;
                    break;
                }
            } while (n1 > 0);
            if (!equal) {
                printf("File %s in directory %s is older than file in directory %s. Updating...\n",
                       ent1->d_name, path2, path1);
                fclose(file1);
                fclose(file2);
                char copy_command[MAX_PATH_LENGTH + 100];
                snprintf(copy_command, MAX_PATH_LENGTH + 100, "cp %s %s", full_path1, full_path2);
                system(copy_command);
            } else {
                fclose(file1);
                fclose(file2);
            }
        } else {
            char full_path2[MAX_PATH_LENGTH];
            snprintf(full_path2, MAX_PATH_LENGTH, "%s/%s", path2, ent1->d_name);
            traverse_directory(full_path1, full_path2);
        }
    }
    closedir(dir1);
    closedir(dir2);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: file_sync <path1> <path2>\n");
        return 1;
    }
  
    printf("Synchronizing files between %s and %s...\n", argv[1], argv[2]);
    traverse_directory(argv[1], argv[2]);
    printf("Done!\n");

    return 0;
}