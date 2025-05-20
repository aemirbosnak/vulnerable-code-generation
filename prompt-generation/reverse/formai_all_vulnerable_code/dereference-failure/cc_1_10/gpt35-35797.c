//FormAI DATASET v1.0 Category: File Synchronizer ; Style: invasive
// Invasive C File Synchronizer Example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define constants for buffer size, max number of files to sync, and sync path
#define BUFFER_SIZE 1024
#define MAX_SYNC_FILES 10
#define SYNC_PATH "/home/user/Documents/"

// Define function to check if a file exists
int fileExists(char *fileName) {
    return access(fileName, F_OK) != -1;
}

// Define function to get the size of a file
off_t fileSize(char *fileName) {
    struct stat st;
    if (stat(fileName, &st) == 0) {
        return st.st_size;
    }
    return -1;
}

int main() {
    // Create variables to hold file names to sync
    char syncFiles[][BUFFER_SIZE] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt", "file6.txt", "file7.txt", "file8.txt", "file9.txt", "file10.txt"};
    
    // Get the number of files to sync
    int numSyncFiles = sizeof(syncFiles) / sizeof(syncFiles[0]);

    // Create a directory pointer to loop through files in sync path
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(SYNC_PATH)) != NULL) {
        // Loop through all files in sync path
        while ((ent = readdir(dir)) != NULL) {
            // Check if file exists in sync files array
            int found = 0;
            for (int i = 0; i < numSyncFiles; i++) {
                if (strcmp(syncFiles[i], ent->d_name) == 0) {
                    found = 1;
                    break;
                }
            }

            // If file not in sync files array, delete it
            if (!found) {
                char fileName[BUFFER_SIZE];
                strcpy(fileName, SYNC_PATH);
                strcat(fileName, ent->d_name);

                if (fileExists(fileName)) {
                    if (remove(fileName) == 0) {
                        printf("Removed file: %s\n", fileName);
                    } else {
                        printf("Error removing file: %s\n", fileName);
                    }
                }
            }
        }
        closedir(dir);
    } else {
        perror("");
        return EXIT_FAILURE;
    }

    // Loop through all files in sync files array and check if they need syncing
    for (int i = 0; i < numSyncFiles; i++) {
        char fileName[BUFFER_SIZE];
        strcpy(fileName, SYNC_PATH);
        strcat(fileName, syncFiles[i]);

        if (fileExists(fileName)) {
            int fileSizeLocal = fileSize(fileName);

            // Check if file needs syncing
            if (fileSizeLocal == -1 || fileSizeLocal != fileSize(syncFiles[i])) {
                // Fork a new process to execute rsync command
                pid_t pid = fork();
                if (pid == -1) {
                    printf("Error creating child process\n");
                    return EXIT_FAILURE;
                } else if (pid == 0) {
                    // Child process executes rsync command
                    char command[BUFFER_SIZE];
                    sprintf(command, "rsync -avz %s %s", syncFiles[i], SYNC_PATH);
                    system(command);
                    exit(EXIT_SUCCESS);
                } else {
                    // Parent process waits for child process to finish
                    int status;
                    waitpid(pid, &status, 0);

                    if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS) {
                        printf("Synced file: %s\n", fileName);
                    } else {
                        printf("Error syncing file: %s\n", fileName);
                    }
                }
            }
        } else {
            printf("File not found: %s\n", fileName);
        }
    }

    return EXIT_SUCCESS;
}