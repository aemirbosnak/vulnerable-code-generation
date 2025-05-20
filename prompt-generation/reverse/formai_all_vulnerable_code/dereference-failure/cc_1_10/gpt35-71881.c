//FormAI DATASET v1.0 Category: File Synchronizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_DIR_LEN 255
#define MAX_FULL_PATH_LEN MAX_DIR_LEN + 1024

void syncFiles(const char* srcPath, const char* dstPath);

int main(int argc, char *argv[]) {
    //Verifying usage of the program
    if(argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }

    printf("Starting file sync...\n"); 

    syncFiles(argv[1], argv[2]);

    printf("File sync completed successfully!\n");

    return 0;

}

// Recursively syncs files from a source directory to a destination directory
void syncFiles(const char* srcPath, const char* dstPath) {
    DIR *srcDir;
    struct dirent *srcEntry;
    struct stat srcAttr, dstAttr;
    char fullSrcPath[MAX_FULL_PATH_LEN];
    char fullDstPath[MAX_FULL_PATH_LEN];

    // Open the source directory
    if ((srcDir = opendir(srcPath)) == NULL) {
        printf("Unable to open source directory %s. Sync aborted.\n", srcPath);
        return;
    }

    // Process each entry in the source directory
    while ((srcEntry = readdir(srcDir)) != NULL) {
        // Ignore the . and .. directories
        if(strcmp(srcEntry->d_name, ".") == 0 || strcmp(srcEntry->d_name, "..") == 0)
            continue;

        // Build the full path of the source file/directory
        snprintf(fullSrcPath, MAX_FULL_PATH_LEN, "%s/%s", srcPath, srcEntry->d_name);

        // Get the attributes of the source file/directory
        if (lstat(fullSrcPath, &srcAttr) == -1) {
            printf("Unable to get attributes of %s. Skipping.\n", fullSrcPath);
            continue;
        }

        // Build the full path of the destination file/directory
        snprintf(fullDstPath, MAX_FULL_PATH_LEN, "%s/%s", dstPath, srcEntry->d_name);

        // Get the attributes of the destination file/directory
        if (lstat(fullDstPath, &dstAttr) == -1) {
            printf("Destination %s does not exist. Creating...\n", fullDstPath);

            // Create a new directory if the source is a directory
            if (S_ISDIR(srcAttr.st_mode)) {
                if (mkdir(fullDstPath, srcAttr.st_mode) == -1) {
                    printf("Failed to create directory: %s\n", fullDstPath);
                    continue;
                }
                printf("Created directory: %s\n", fullDstPath);
            }
        }

        // Recursively sync directories
        if (S_ISDIR(srcAttr.st_mode)) {
            syncFiles(fullSrcPath, fullDstPath);
            continue;
        }

        // Sync file if it has changed or destination is not present
        if (srcAttr.st_mtime > dstAttr.st_mtime) {
            FILE* srcFile;
            FILE* dstFile;
            int ch;

            printf("Syncing file %s...\n", fullSrcPath);

            // Open source file for reading
            if ((srcFile = fopen(fullSrcPath, "r")) == NULL) {
                printf("Unable to open %s for reading. Skipping.\n", fullSrcPath);
                continue;
            }

            // Open destination file for writing
            if ((dstFile = fopen(fullDstPath, "w")) == NULL) {
                printf("Unable to open %s for writing. Skipping.\n", fullDstPath);
                fclose(srcFile); 
                continue;
            }

            // Copy contents of source file to destination file
            while ((ch = fgetc(srcFile)) != EOF) {
                fputc(ch, dstFile);
            }

            // Close files
            fclose(srcFile);
            fclose(dstFile);
            printf("Synced file: %s\n", fullSrcPath);
        }
    }

    // Close source directory
    closedir(srcDir);
}