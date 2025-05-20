//FormAI DATASET v1.0 Category: File Synchronizer ; Style: retro
#include <stdio.h>  // for standard I/O operations
#include <stdlib.h> // for dynamic memory allocation
#include <string.h> // for string operations
#include <dirent.h> // for directory operations
#include <unistd.h> // for UNIX system call
#include <errno.h>  // for error handling

#define MAX_PATH_LENGTH 256 // maximum length of file path
#define MAX_FILE_LENGTH 1024 // maximum length of file content
#define SYNC_INTERVAL 5 // interval between synchronizations in seconds

// function to check if file exists
int fileExists(char *fileName) {
    FILE *file;
    if (file = fopen(fileName, "r")) {
        fclose(file);
        return 1;
    } else {
        return 0;
    }
}

// function to get file content
char *getFileContent(char *fileName, long *length) {
    FILE *file;
    char *buffer;
    long fileLength;
    
    file = fopen(fileName, "rb");
    if (!file) {
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);
    fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    buffer = (char *) malloc(fileLength + 1);
    if (!buffer) {
        fclose(file);
        return NULL;
    }
    
    fread(buffer, fileLength, 1, file);
    fclose(file);
    
    buffer[fileLength] = '\0';
    *length = fileLength;
    
    return buffer;
}

// function to write file content
int putFileContent(char *fileName, char *content, long length) {
    FILE *file;
    
    file = fopen(fileName, "wb");
    if (!file) {
        return -1;
    }
    
    fwrite(content, length, 1, file);
    fclose(file);
    
    return 0;
}

// function to synchronize files
int syncFiles(char *dir1, char *dir2) {
    DIR *dp1, *dp2;
    struct dirent *ep1, *ep2;
    char file1[MAX_PATH_LENGTH], file2[MAX_PATH_LENGTH];
    char content1[MAX_FILE_LENGTH], content2[MAX_FILE_LENGTH];
    long length1, length2;
    
    dp1 = opendir(dir1);
    if (!dp1) {
        printf("Error: Cannot open directory '%s' (%s)\n", dir1, strerror(errno));
        return -1;
    }
    
    dp2 = opendir(dir2);
    if (!dp2) {
        printf("Error: Cannot open directory '%s' (%s)\n", dir2, strerror(errno));
        closedir(dp1);
        return -1;
    }
    
    while ((ep1 = readdir(dp1)) != NULL) {
        if (ep1->d_type == DT_REG) {
            sprintf(file1, "%s/%s", dir1, ep1->d_name);
            sprintf(file2, "%s/%s", dir2, ep1->d_name);
            
            if (!fileExists(file2)) {
                printf("Copying %s to %s\n", file1, file2);
                if (putFileContent(file2, getFileContent(file1, &length1), length1) != 0) {
                    printf("Error: Cannot copy file '%s' to '%s' (%s)\n", file1, file2, strerror(errno));
                }
            } else {
                if (strcmp(getFileContent(file1, &length1), getFileContent(file2, &length2)) != 0) {
                    printf("Updating %s to %s\n", file1, file2);
                    if (putFileContent(file2, getFileContent(file1, &length1), length1) != 0) {
                        printf("Error: Cannot update file '%s' to '%s' (%s)\n", file1, file2, strerror(errno));
                    }
                }
            }
        }
    }
    
    while ((ep2 = readdir(dp2)) != NULL) {
        if (ep2->d_type == DT_REG) {
            sprintf(file2, "%s/%s", dir2, ep2->d_name);
            sprintf(file1, "%s/%s", dir1, ep2->d_name);
            
            if (!fileExists(file1)) {
                printf("Copying %s to %s\n", file2, file1);
                if (putFileContent(file1, getFileContent(file2, &length2), length2) != 0) {
                    printf("Error: Cannot copy file '%s' to '%s' (%s)\n", file2, file1, strerror(errno));
                }
            }
        }
    }
    
    closedir(dp1);
    closedir(dp2);
    
    return 0;
}

int main() {
    char dir1[MAX_PATH_LENGTH], dir2[MAX_PATH_LENGTH];
    
    printf("Directory 1: ");
    scanf("%s", dir1);
    
    printf("Directory 2: ");
    scanf("%s", dir2);
    
    printf("Synchronizing %s with %s every %d seconds...\n", dir1, dir2, SYNC_INTERVAL);
    
    while (1) {
        syncFiles(dir1, dir2);
        sleep(SYNC_INTERVAL);
    }
    
    return 0;
}