//FormAI DATASET v1.0 Category: Error handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

void handleError(char* message){
    perror(message);
    exit(errno);
}

int main(int argc, char *argv[])
{

    DIR *directory;
    struct dirent *file;
    char fileName[100];

    if(argc != 2) {
        printf("Usage: %s directory\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    directory = opendir(argv[1]);
    if (directory == NULL)
        handleError("opendir");

    while((file = readdir(directory)) != NULL){
        if(strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0)
            continue;

        if((file->d_type & DT_REG) != 0) {//Regular file
            printf("File Name: %s\n", file->d_name);
            sprintf(fileName, "%s/%s", argv[1], file->d_name);
            if(access(fileName, R_OK) == -1) {
                printf("Access denied for file: %s. Error: %s\n", fileName, strerror(errno));
                continue;
            }
            //Do some operation on the file
        } else if((file->d_type & DT_DIR) != 0) {//Directory file
            printf("Directory Name: %s\n", file->d_name);
            //Open directory recursively
        }
    }

    closedir(directory);

    return EXIT_SUCCESS;
}