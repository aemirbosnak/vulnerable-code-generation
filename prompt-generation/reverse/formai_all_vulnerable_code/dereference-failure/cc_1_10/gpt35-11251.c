//FormAI DATASET v1.0 Category: File Synchronizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

// Function to recursively traverse the directory
void traversal(char *dir_path) {
    DIR *dir;
    struct dirent *entry;
    struct stat path_stat;
    char path[1000];
    dir = opendir(dir_path); // Open the directory

    // If directory does not exist
    if (dir == NULL) {
        printf("Error: Directory doesn't exist!\n");
        exit(1);
    }

    // Loop through each file/directory
    while ((entry = readdir(dir)) != NULL) {

        // Ignore "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Get the complete path
        sprintf(path, "%s/%s", dir_path, entry->d_name);
        stat(path, &path_stat);

        // If a directory is encountered
        if (S_ISDIR(path_stat.st_mode)) {
            traversal(path); // Traverse the subdirectory
        } else {
            printf("%s\n", path); // Print the file path
        }
    }
    closedir(dir); // Close the directory
}

// Function to compare the two directories
bool compare_directories(char *dir1, char *dir2) {
    DIR *d1, *d2;
    struct dirent *dir1_entry, *dir2_entry;
    char dir1_path[1000], dir2_path[1000];
    struct stat dir1_stat, dir2_stat;

    d1 = opendir(dir1);
    d2 = opendir(dir2);

    if (d1 == NULL || d2 == NULL) {
        printf("Error: Failed to Open Directory!\n");
        closedir(d1);
        closedir(d2);
        return false;
    }

    // Loop through each file/directory in dir1
    while ((dir1_entry = readdir(d1)) != NULL) {

        // Ignore "." and ".." directories
        if (strcmp(dir1_entry->d_name, ".") == 0 || strcmp(dir1_entry->d_name, "..") == 0)
            continue;

        // Get the complete path of dir1
        sprintf(dir1_path, "%s/%s", dir1, dir1_entry->d_name);
        stat(dir1_path, &dir1_stat);

        // Get the complete path of dir2
        sprintf(dir2_path, "%s/%s", dir2, dir1_entry->d_name);
        stat(dir2_path, &dir2_stat);

        // If the file does not exist in dir2
        if (access(dir2_path, F_OK) == -1) {
            printf("File doesn't exist in Directory 2: %s\n", dir1_path);
            continue;
        }

        // If a file is encountered
        if (S_ISREG(dir1_stat.st_mode)) {

            // If the file size mismatches between dir1 and dir2
            if (dir1_stat.st_size != dir2_stat.st_size) {
                printf("File size mismatches: %s\n", dir1_path);
                continue;
            }

            // Check the contents of the file
            FILE *fp1 = fopen(dir1_path, "r");
            FILE *fp2 = fopen(dir2_path, "r");
            char c1, c2;
            bool flag = true;

            while ((c1 = fgetc(fp1)) != EOF) {
                c2 = fgetc(fp2);
                if (c1 != c2) {
                    flag = false;
                    break;
                }
            }

            // Close the file pointers
            fclose(fp1);
            fclose(fp2);

            // If the contents of the file mismatches
            if (!flag) {
                printf("File content mismatches: %s\n", dir1_path);
                continue;
            }
        } else if (S_ISDIR(dir1_stat.st_mode)) { // If a directory is encountered
            if (compare_directories(dir1_path, dir2_path) == false)
                continue;
        }
    }

    // Check if all the files in dir2 exist in dir1
    while ((dir2_entry = readdir(d2)) != NULL) {
        if (strcmp(dir2_entry->d_name, ".") == 0 || strcmp(dir2_entry->d_name, "..") == 0)
            continue;

        sprintf(dir2_path, "%s/%s", dir2, dir2_entry->d_name);

        if (access(dir2_path, F_OK) != -1)
            continue;

        printf("File doesn't exist in Directory 1: %s\n", dir2_path);
    }

    closedir(d1);
    closedir(d2);
    return true;
}

// Main function
int main()
{
    char dir1[100], dir2[100];
    printf("Enter the first directory path: ");
    scanf("%s", dir1);
    printf("Enter the second directory path: ");
    scanf("%s", dir2);
    printf("Contents of Directory 1:\n");
    traversal(dir1);
    printf("Contents of Directory 2:\n");
    traversal(dir2);
    printf("Comparing the Directories...\n");
    if (compare_directories(dir1, dir2)) {
        printf("Directories are in Sync!\n");
    } else {
        printf("Directories are not in Sync!\n");
    }
    return 0;
}