//FormAI DATASET v1.0 Category: File Synchronizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILE_LENGTH 256
#define SYNC_INTERVAL 10 // seconds

char pathA[MAX_PATH_LENGTH];
char pathB[MAX_PATH_LENGTH];
char diffA[MAX_PATH_LENGTH];
char diffB[MAX_PATH_LENGTH];

void sync_directories();
void sync_files(char* fileA, char* fileB);
bool same_file_contents(FILE* fp1, FILE* fp2);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [directory A] [directory B]\n", argv[0]);
        exit(1);
    }

    strncpy(pathA, argv[1], MAX_PATH_LENGTH);
    strncpy(pathB, argv[2], MAX_PATH_LENGTH);

    while(true) {
        sync_directories();
        sleep(SYNC_INTERVAL); // wait before syncing again
    }
}

void sync_directories() {
    DIR *dirA, *dirB;
    struct dirent *direntA, *direntB;

    if ((dirA = opendir(pathA)) == NULL) {
        printf("Error: Could not open directory %s - %s\n", pathA, strerror(errno));
        return;
    }
    if ((dirB = opendir(pathB)) == NULL) {
        printf("Error: Could not open directory %s - %s\n", pathB, strerror(errno));
        return;
    }

    while ((direntA = readdir(dirA)) != NULL) {
        if (direntA->d_type == DT_REG) { // if file
            snprintf(diffA, MAX_PATH_LENGTH, "%s/%s", pathA, direntA->d_name);
            snprintf(diffB, MAX_PATH_LENGTH, "%s/%s", pathB, direntA->d_name);

            // check if file exists in directory B
            if ((direntB = readdir(dirB)) != NULL) {
                if (strcmp(direntA->d_name, direntB->d_name) != 0) {
                    printf("Directory out of sync: %s and %s\n", pathA, pathB);
                    return;
                }

                // file exists, check if contents are different
                sync_files(diffA, diffB);
            } else { // file does not exist in directory B, create it
                FILE* fp1 = fopen(diffA, "r");
                FILE* fp2 = fopen(diffB, "w");

                if (fp1 == NULL || fp2 == NULL) {
                    printf("Error: Could not open files %s or %s - %s\n", diffA, diffB, strerror(errno));
                    return;
                }

                int c;
                while ((c = fgetc(fp1)) != EOF) {
                    fputc(c, fp2);
                }

                printf("File copied: %s --> %s\n", diffA, diffB);

                fclose(fp1);
                fclose(fp2);
            }

            rewinddir(dirB);
        }
    }

    closedir(dirA);
    closedir(dirB);
}

void sync_files(char* fileA, char* fileB) {
    FILE* fp1 = fopen(fileA, "r");
    FILE* fp2 = fopen(fileB, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error: Could not open files %s and %s - %s\n", fileA, fileB, strerror(errno));
        return;
    }

    if (same_file_contents(fp1, fp2)) {
        fclose(fp1);
        fclose(fp2);
        return; // files have the same contents, no need to sync
    }

    int pid = fork();
    
    if (pid == -1) {
        printf("Error: fork() failed - %s\n", strerror(errno));
        fclose(fp1);
        fclose(fp2);
        return;
    }
    else if (pid == 0) { // child process
        // overwrite file in directory B with contents of file in directory A
        FILE* fp = fopen(fileB, "w");
        
        if (fp == NULL) {
            printf("Error: Could not open file %s - %s\n", fileB, strerror(errno));
            fclose(fp1);
            fclose(fp2);
            return;
        }
        
        int c;
        while ((c = fgetc(fp1)) != EOF) {
            fputc(c, fp);
        }
        
        printf("File synchronized: %s --> %s\n", fileA, fileB);

        fclose(fp);
        fclose(fp1);
        fclose(fp2);
        exit(0);
    }
    else { // parent process
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            printf("File synchronized: %s --> %s\n", fileA, fileB);
        }
        else {
            printf("Error: Failed to synchronize %s and %s\n", fileA, fileB);
        }
    }
}

bool same_file_contents(FILE* fp1, FILE* fp2) {
    fseek(fp1, 0L, SEEK_END);
    long int size1 = ftell(fp1);
    rewind(fp1);

    fseek(fp2, 0L, SEEK_END);
    long int size2 = ftell(fp2);
    rewind(fp2);

    if (size1 != size2) {
        return false;
    }

    int c1, c2;
    while ((c1 = fgetc(fp1)) != EOF) {
        c2 = fgetc(fp2);
        if (c1 != c2) {
            return false;
        }
    }

    return true;
}