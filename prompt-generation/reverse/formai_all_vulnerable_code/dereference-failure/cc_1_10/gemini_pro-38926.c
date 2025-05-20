//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUF_SIZE 4096

// Function to compare two files
int compare_files(char *file1, char *file2) {
    FILE *fp1, *fp2;
    char buf1[BUF_SIZE], buf2[BUF_SIZE];

    // Open the files
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    // Check if the files could be opened
    if (fp1 == NULL || fp2 == NULL) {
        perror("Error opening files");
        return -1;
    }

    // Read the files into buffers
    fread(buf1, BUF_SIZE, 1, fp1);
    fread(buf2, BUF_SIZE, 1, fp2);

    // Compare the buffers
    if (strcmp(buf1, buf2) != 0) {
        return 1;
    }

    // Close the files
    fclose(fp1);
    fclose(fp2);

    return 0;
}

// Function to copy a file
int copy_file(char *src, char *dest) {
    FILE *fp_src, *fp_dest;
    char buf[BUF_SIZE];
    int n;

    // Open the source file
    fp_src = fopen(src, "r");

    // Check if the source file could be opened
    if (fp_src == NULL) {
        perror("Error opening source file");
        return -1;
    }

    // Open the destination file
    fp_dest = fopen(dest, "w");

    // Check if the destination file could be opened
    if (fp_dest == NULL) {
        perror("Error opening destination file");
        fclose(fp_src);
        return -1;
    }

    // Copy the file
    while ((n = fread(buf, BUF_SIZE, 1, fp_src)) > 0) {
        fwrite(buf, n, 1, fp_dest);
    }

    // Close the files
    fclose(fp_src);
    fclose(fp_dest);

    return 0;
}

// Function to synchronize two directories
int synchronize_directories(char *dir1, char *dir2) {
    DIR *dp1, *dp2;
    struct dirent *entry1, *entry2;
    struct stat st1, st2;
    char file1[PATH_MAX], file2[PATH_MAX];

    // Open the directories
    dp1 = opendir(dir1);
    dp2 = opendir(dir2);

    // Check if the directories could be opened
    if (dp1 == NULL || dp2 == NULL) {
        perror("Error opening directories");
        return -1;
    }

    // Iterate over the directories
    while ((entry1 = readdir(dp1)) != NULL) {
        if (strcmp(entry1->d_name, ".") == 0 || strcmp(entry1->d_name, "..") == 0) {
            continue;
        }

        // Get the full path of the file in the first directory
        snprintf(file1, PATH_MAX, "%s/%s", dir1, entry1->d_name);

        // Check if the file exists in the second directory
        snprintf(file2, PATH_MAX, "%s/%s", dir2, entry1->d_name);
        if (stat(file2, &st2) == -1) {
            // The file does not exist in the second directory, so copy it
            copy_file(file1, file2);
        } else {
            // The file exists in the second directory, so compare the files
            stat(file1, &st1);
            if (st1.st_mtime > st2.st_mtime) {
                // The file in the first directory is newer, so copy it to the second directory
                copy_file(file1, file2);
            } else if (st1.st_mtime < st2.st_mtime) {
                // The file in the second directory is newer, so copy it to the first directory
                copy_file(file2, file1);
            }
        }
    }

    // Iterate over the directories again, this time deleting any files that are in the second directory but not in the first directory
    while ((entry2 = readdir(dp2)) != NULL) {
        if (strcmp(entry2->d_name, ".") == 0 || strcmp(entry2->d_name, "..") == 0) {
            continue;
        }

        // Get the full path of the file in the second directory
        snprintf(file2, PATH_MAX, "%s/%s", dir2, entry2->d_name);

        // Check if the file exists in the first directory
        snprintf(file1, PATH_MAX, "%s/%s", dir1, entry2->d_name);
        if (stat(file1, &st1) == -1) {
            // The file does not exist in the first directory, so delete it from the second directory
            unlink(file2);
        }
    }

    // Close the directories
    closedir(dp1);
    closedir(dp2);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <dir1> <dir2>\n", argv[0]);
        return -1;
    }

    // Synchronize the directories
    synchronize_directories(argv[1], argv[2]);

    return 0;
}