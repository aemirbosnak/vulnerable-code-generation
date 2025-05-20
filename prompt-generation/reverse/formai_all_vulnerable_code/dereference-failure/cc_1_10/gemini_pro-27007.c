//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

// Compares two files by their name and size.
int compare_files(const void *p1, const void *p2) {
    const char *f1 = *(const char **)p1;
    const char *f2 = *(const char **)p2;
    return strcmp(f1, f2);
}

// Recursively synchronizes two directories.
void sync_dirs(const char *dir1, const char *dir2) {
    // Open the two directories.
    DIR *d1 = opendir(dir1);
    DIR *d2 = opendir(dir2);

    // If either directory cannot be opened, print an error message and exit.
    if (!d1 || !d2) {
        fprintf(stderr, "Error opening directory: %s\n", (d1 ? dir2 : dir1));
        exit(1);
    }

    // Get a list of all the files in the two directories.
    struct dirent **files1, **files2;
    int num_files1, num_files2;

    num_files1 = scandir(dir1, &files1, NULL, compare_files);
    num_files2 = scandir(dir2, &files2, NULL, compare_files);

    // If either directory has no files, close the directories and return.
    if (num_files1 == 0 || num_files2 == 0) {
        closedir(d1);
        closedir(d2);
        return;
    }

    // Loop through the files in the two directories.
    int i;
    for (i = 0; i < num_files1; i++) {
        // Get the full path to the file in the first directory.
        char f1_path[PATH_MAX];
        snprintf(f1_path, PATH_MAX, "%s/%s", dir1, files1[i]->d_name);

        // Check if the file exists in the second directory.
        int found = 0;
        int j;
        for (j = 0; j < num_files2; j++) {
            if (!strcmp(files1[i]->d_name, files2[j]->d_name)) {
                found = 1;
                break;
            }
        }

        // If the file does not exist in the second directory, copy it from the first directory.
        if (!found) {
            printf("Copying file %s to %s\n", f1_path, dir2);
            if (copy_file(f1_path, dir2)) {
                fprintf(stderr, "Error copying file: %s\n", f1_path);
                exit(1);
            }
        }
    }

    // Loop through the files in the second directory.
    for (i = 0; i < num_files2; i++) {
        // Get the full path to the file in the second directory.
        char f2_path[PATH_MAX];
        snprintf(f2_path, PATH_MAX, "%s/%s", dir2, files2[i]->d_name);

        // Check if the file exists in the first directory.
        int found = 0;
        int j;
        for (j = 0; j < num_files1; j++) {
            if (!strcmp(files2[i]->d_name, files1[j]->d_name)) {
                found = 1;
                break;
            }
        }

        // If the file does not exist in the first directory, copy it from the second directory.
        if (!found) {
            printf("Copying file %s to %s\n", f2_path, dir1);
            if (copy_file(f2_path, dir1)) {
                fprintf(stderr, "Error copying file: %s\n", f2_path);
                exit(1);
            }
        }
    }

    // Close the two directories.
    closedir(d1);
    closedir(d2);

    // Free the memory allocated for the file lists.
    free(files1);
    free(files2);
}

// Copies a file from one directory to another.
int copy_file(const char *from, const char *to) {
    // Open the source file.
    FILE *f1 = fopen(from, "rb");
    if (!f1) {
        fprintf(stderr, "Error opening source file: %s\n", from);
        return 1;
    }

    // Open the destination file.
    FILE *f2 = fopen(to, "wb");
    if (!f2) {
        fprintf(stderr, "Error opening target file: %s\n", to);
        fclose(f1);
        return 1;
    }

    // Copy the file.
    char buffer[BUFSIZ];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), f1)) > 0) {
        if (fwrite(buffer, 1, bytes_read, f2) != bytes_read) {
            fprintf(stderr, "Error writing to target file: %s\n", to);
            fclose(f1);
            fclose(f2);
            return 1;
        }
    }

    // Close the two files.
    fclose(f1);
    fclose(f2);

    return 0;
}

int main(int argc, char **argv) {
    // Check if there are enough arguments.
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <dir1> <dir2>\n", argv[0]);
        exit(1);
    }

    // Synchronize the two directories.
    sync_dirs(argv[1], argv[2]);

    return 0;
}