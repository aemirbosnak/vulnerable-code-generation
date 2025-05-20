//FormAI DATASET v1.0 Category: File Synchronizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void copyFile(char* sourcePath, char* destinationPath) {
    FILE *sourceFile, *destinationFile;

    sourceFile = fopen(sourcePath, "r");
    destinationFile = fopen(destinationPath, "w");

    if (sourceFile == NULL || destinationFile == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    char c = fgetc(sourceFile);

    while (c != EOF) {
        fputc(c, destinationFile);
        c = fgetc(sourceFile);
    }

    printf("%s copied to %s successfully.\n", sourcePath, destinationPath);

    fclose(sourceFile);
    fclose(destinationFile);
}

void synchronizeFiles(char* sourceDirectory, char* destinationDirectory) {
    DIR *sourceDir, *destinationDir;
    struct dirent *sourceEntry, *destinationEntry;

    sourceDir = opendir(sourceDirectory);
    destinationDir = opendir(destinationDirectory);

    if (sourceDir == NULL || destinationDir == NULL) {
        printf("Error opening directory!");
        exit(1);
    }

    printf("Synchronizing Files from %s to %s...\n", sourceDirectory, destinationDirectory);

    while ((sourceEntry = readdir(sourceDir)) != NULL) {
        if (sourceEntry->d_type == DT_REG) {
            char* sourceFilePath = malloc(strlen(sourceDirectory) + strlen(sourceEntry->d_name) + 2);
            sprintf(sourceFilePath, "%s/%s", sourceDirectory, sourceEntry->d_name);

            int found = 0;
            while ((destinationEntry = readdir(destinationDir)) != NULL) {
                if (destinationEntry->d_type == DT_REG) {
                    char* destinationFilePath = malloc(strlen(destinationDirectory) + strlen(destinationEntry->d_name) + 2);
                    sprintf(destinationFilePath, "%s/%s", destinationDirectory, destinationEntry->d_name);

                    if (strcmp(sourceEntry->d_name, destinationEntry->d_name) == 0) {
                        found = 1;

                        FILE *sourceFile, *destinationFile;

                        sourceFile = fopen(sourceFilePath, "r");
                        destinationFile = fopen(destinationFilePath, "r");

                        if (sourceFile == NULL || destinationFile == NULL) {
                            printf("Error opening file!");
                            exit(1);
                        }

                        fseek(sourceFile, 0L, SEEK_END);
                        long sourceFileSize = ftell(sourceFile);
                        fseek(sourceFile, 0L, SEEK_SET);

                        fseek(destinationFile, 0L, SEEK_END);
                        long destinationFileSize = ftell(destinationFile);
                        fseek(destinationFile, 0L, SEEK_SET);

                        if (sourceFileSize != destinationFileSize) {
                            copyFile(sourceFilePath, destinationFilePath);
                        }

                        fclose(sourceFile);
                        fclose(destinationFile);

                        free(destinationFilePath);

                        break;
                    }

                    free(destinationFilePath);
                }
            }

            if (!found) {
                char* destinationFilePath = malloc(strlen(destinationDirectory) + strlen(sourceEntry->d_name) + 2);
                sprintf(destinationFilePath, "%s/%s", destinationDirectory, sourceEntry->d_name);

                copyFile(sourceFilePath, destinationFilePath);

                free(destinationFilePath);
            }

            free(sourceFilePath);
            rewind(destinationDir);
        }
    }

    closedir(sourceDir);
    closedir(destinationDir);

    printf("File synchronization complete!\n");
}

int main() {
    synchronizeFiles("/home/user/Desktop/Project1", "/home/user/Desktop/Project2");

    return 0;
}