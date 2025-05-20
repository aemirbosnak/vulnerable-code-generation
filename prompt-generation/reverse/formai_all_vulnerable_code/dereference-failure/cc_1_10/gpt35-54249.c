//FormAI DATASET v1.0 Category: File Synchronizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 256
#define MAX_FILENAME_LEN 128

// Define a structure to keep track of files
struct file_info {
    char name[MAX_FILENAME_LEN];
    long size;
    int modified;
    int deleted;
};

// Define a function to compare file info
int compare_file(const void *a, const void *b) {
    struct file_info **ia = (struct file_info **)a;
    struct file_info **ib = (struct file_info **)b;
    return strcmp((*ia)->name, (*ib)->name);
}

// Define a function to retrieve file information
int get_file_info(const char *path, struct file_info **files, int *num_files, int depth) {
    DIR *dir;
    struct dirent *ent;

    // Open directory
    if ((dir = opendir(path)) == NULL) {
        return -1;
    }

    // Loop through directory entries
    while ((ent = readdir(dir)) != NULL) {
        struct stat st;
        char new_path[MAX_PATH_LEN];
        sprintf(new_path, "%s/%s", path, ent->d_name);

        // Ignore "." and ".."
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        // Retrieve file information
        if (lstat(new_path, &st) == 0) {
            if (S_ISREG(st.st_mode)) {
                struct file_info *file = (struct file_info *)malloc(sizeof(struct file_info));
                strcpy(file->name, ent->d_name);
                file->size = st.st_size;
                file->modified = st.st_mtime;
                file->deleted = 0;
                files[*num_files] = file;
                (*num_files)++;
            } else if (S_ISDIR(st.st_mode) && depth > 0) {
                if (get_file_info(new_path, files, num_files, depth - 1) == -1) {
                    return -1;
                }
            }
        }
    }

    // Close directory
    closedir(dir);

    return 0;
}

// Define a function to synchronize files
int synchronize_files(const char *path1, const char *path2) {
    // Retrieve file information for both paths
    struct file_info *files1[MAX_PATH_LEN], *files2[MAX_PATH_LEN];
    int num_files1 = 0, num_files2 = 0;
    if (get_file_info(path1, files1, &num_files1, 2) == -1 || get_file_info(path2, files2, &num_files2, 2) == -1) {
        return -1;
    }

    // Sort both sets of files
    qsort(files1, num_files1, sizeof(struct file_info *), compare_file);
    qsort(files2, num_files2, sizeof(struct file_info *), compare_file);

    // Loop through both sets of files and compare
    int i = 0, j = 0;
    while (i < num_files1 && j < num_files2) {
        struct file_info *file1 = files1[i], *file2 = files2[j];

        // Compare file names
        int cmp = strcmp(file1->name, file2->name);
        if (cmp == 0) {
            // Files have the same name
            if (file1->size == file2->size && file1->modified == file2->modified) {
                // Files are identical
                file1->deleted = 0;
                file2->deleted = 0;
            } else {
                // Files are different, copy from newer to older
                char source[MAX_PATH_LEN], destination[MAX_PATH_LEN];
                if (file1->modified > file2->modified) {
                    sprintf(source, "%s/%s", path1, file1->name);
                    sprintf(destination, "%s/%s", path2, file1->name);
                } else {
                    sprintf(source, "%s/%s", path2, file2->name);
                    sprintf(destination, "%s/%s", path1, file2->name);
                }
                printf("Copying %s to %s\n", source, destination);
                FILE *fp1 = fopen(source, "rb");
                FILE *fp2 = fopen(destination, "wb");
                char buffer[1024];
                int len = 0;
                while ((len = fread(buffer, 1, 1024, fp1)) > 0) {
                    fwrite(buffer, len, 1, fp2);
                }
                fclose(fp1);
                fclose(fp2);
            }
            i++;
            j++;
        } else if (cmp > 0) {
            // New file in path2
            char source[MAX_PATH_LEN], destination[MAX_PATH_LEN];
            sprintf(source, "%s/%s", path2, file2->name);
            sprintf(destination, "%s/%s", path1, file2->name);
            printf("Copying %s to %s\n", source, destination);
            FILE *fp1 = fopen(source, "rb");
            FILE *fp2 = fopen(destination, "wb");
            char buffer[1024];
            int len = 0;
            while ((len = fread(buffer, 1, 1024, fp1)) > 0) {
                fwrite(buffer, len, 1, fp2);
            }
            fclose(fp1);
            fclose(fp2);
            j++;
        } else {
            // New file in path1
            char source[MAX_PATH_LEN], destination[MAX_PATH_LEN];
            sprintf(source, "%s/%s", path1, file1->name);
            sprintf(destination, "%s/%s", path2, file1->name);
            printf("Copying %s to %s\n", source, destination);
            FILE *fp1 = fopen(source, "rb");
            FILE *fp2 = fopen(destination, "wb");
            char buffer[1024];
            int len = 0;
            while ((len = fread(buffer, 1, 1024, fp1)) > 0) {
                fwrite(buffer, len, 1, fp2);
            }
            fclose(fp1);
            fclose(fp2);
            i++;
        }
    }

    // Delete any files that were not found in both paths
    for (int k = 0; k < num_files1; k++) {
        struct file_info *file = files1[k];
        if (file->deleted) {
            char path[MAX_PATH_LEN];
            sprintf(path, "%s/%s", path1, file->name);
            printf("Deleting %s\n", path);
            unlink(path);
        }
    }
    for (int k = 0; k < num_files2; k++) {
        struct file_info *file = files2[k];
        if (file->deleted) {
            char path[MAX_PATH_LEN];
            sprintf(path, "%s/%s", path2, file->name);
            printf("Deleting %s\n", path);
            unlink(path);
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <path1> <path2>\n", argv[0]);
        return 1;
    }

    synchronize_files(argv[1], argv[2]);

    return 0;
}