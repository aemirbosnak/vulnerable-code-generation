//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

// Function to compare two files
int compareFiles(char *file1, char *file2) {
    // Open both files
    FILE *fp1 = fopen(file1, "rb");
    FILE *fp2 = fopen(file2, "rb");

    // Check if the files are the same size
    struct stat stat1, stat2;
    stat(file1, &stat1);
    stat(file2, &stat2);
    if (stat1.st_size != stat2.st_size) {
        fclose(fp1);
        fclose(fp2);
        return 0;
    }

    // Compare the files byte by byte
    char byte1, byte2;
    while ((byte1 = fgetc(fp1)) != EOF && (byte2 = fgetc(fp2)) != EOF) {
        if (byte1 != byte2) {
            fclose(fp1);
            fclose(fp2);
            return 0;
        }
    }

    // Close both files
    fclose(fp1);
    fclose(fp2);

    // The files are the same
    return 1;
}

// Function to copy a file
int copyFile(char *src, char *dest) {
    // Open the source file
    FILE *fp1 = fopen(src, "rb");
    if (fp1 == NULL) {
        return 0;
    }

    // Create the destination file
    FILE *fp2 = fopen(dest, "wb");
    if (fp2 == NULL) {
        fclose(fp1);
        return 0;
    }

    // Copy the file contents
    char buffer[4096];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), fp1)) > 0) {
        fwrite(buffer, 1, bytesRead, fp2);
    }

    // Close both files
    fclose(fp1);
    fclose(fp2);

    // The file was copied successfully
    return 1;
}

// Function to synchronize two directories
int syncDirectories(char *dir1, char *dir2) {
    // Open the directories
    DIR *dp1 = opendir(dir1);
    DIR *dp2 = opendir(dir2);
    if (dp1 == NULL || dp2 == NULL) {
        return 0;
    }

    // Create a list of files in the first directory
    struct dirent *entry1;
    char **files1 = malloc(sizeof(char *) * 1024);
    int numFiles1 = 0;
    while ((entry1 = readdir(dp1)) != NULL) {
        if (strcmp(entry1->d_name, ".") == 0 || strcmp(entry1->d_name, "..") == 0) {
            continue;
        }
        files1[numFiles1++] = malloc(strlen(entry1->d_name) + 1);
        strcpy(files1[numFiles1 - 1], entry1->d_name);
    }

    // Create a list of files in the second directory
    struct dirent *entry2;
    char **files2 = malloc(sizeof(char *) * 1024);
    int numFiles2 = 0;
    while ((entry2 = readdir(dp2)) != NULL) {
        if (strcmp(entry2->d_name, ".") == 0 || strcmp(entry2->d_name, "..") == 0) {
            continue;
        }
        files2[numFiles2++] = malloc(strlen(entry2->d_name) + 1);
        strcpy(files2[numFiles2 - 1], entry2->d_name);
    }

    // Compare the files in the two directories
    for (int i = 0; i < numFiles1; i++) {
        char *file1 = files1[i];
        int found = 0;
        for (int j = 0; j < numFiles2; j++) {
            char *file2 = files2[j];
            if (strcmp(file1, file2) == 0) {
                // Check if the files are the same
                if (compareFiles(file1, file2)) {
                    found = 1;
                    break;
                } else {
                    // The files are different, so update the file in the second directory
                    copyFile(file1, file2);
                    break;
                }
            }
        }

        // The file was not found in the second directory, so copy it
        if (!found) {
            char *dest = malloc(strlen(dir2) + strlen(file1) + 2);
            sprintf(dest, "%s/%s", dir2, file1);
            copyFile(file1, dest);
            free(dest);
        }
    }

    // Clean up
    for (int i = 0; i < numFiles1; i++) {
        free(files1[i]);
    }
    free(files1);
    for (int i = 0; i < numFiles2; i++) {
        free(files2[i]);
    }
    free(files2);
    closedir(dp1);
    closedir(dp2);

    // The directories were synchronized successfully
    return 1;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <dir1> <dir2>\n", argv[0]);
        return 1;
    }

    char *dir1 = argv[1];
    char *dir2 = argv[2];

    if (syncDirectories(dir1, dir2)) {
        printf("Directories synchronized successfully.\n");
    } else {
        printf("Error synchronizing directories.\n");
    }

    return 0;
}