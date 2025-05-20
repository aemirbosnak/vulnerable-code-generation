//FormAI DATASET v1.0 Category: File Synchronizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILENAME_SIZE 100

void syncFiles(char *file1, char *file2);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("USAGE: ./sync <file1> <file2>\n");
        exit(1);
    }
    char *file1 = argv[1];
    char *file2 = argv[2];
    syncFiles(file1, file2);
    return 0;
}

void syncFiles(char *file1, char *file2) {
    char filename1[MAX_FILENAME_SIZE];
    char filename2[MAX_FILENAME_SIZE];
    strcpy(filename1, file1);
    strcpy(filename2, file2);

    char *file1Contents = malloc(MAX_FILE_SIZE * sizeof(char));
    char *file2Contents = malloc(MAX_FILE_SIZE * sizeof(char));

    if (file1Contents == NULL || file2Contents == NULL) {
        printf("Error in allocating memory!\n");
        exit(1);
    }

    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");
    if (fp1 == NULL || fp2 == NULL) {
        printf("Unable to open files!\n");
        exit(1);
    }

    fread(file1Contents, sizeof(char), MAX_FILE_SIZE, fp1);
    fread(file2Contents, sizeof(char), MAX_FILE_SIZE, fp2);

    if (strcmp(file1Contents, file2Contents) != 0) {
        printf("Files are not in sync!\n");

        // paranoid file sync
        int i = 0;
        while (i < MAX_FILE_SIZE) {
            if (file1Contents[i] != file2Contents[i]) {
                printf("Content mismatch at byte %d\n", i);

                // write file1 byte at mismatch location to file2
                FILE *fp = fopen(file2, "w");
                if (fp == NULL) {
                    printf("Error in opening file!\n");
                    exit(1);
                }
                fwrite(&file1Contents[i], sizeof(char), 1, fp);
                fclose(fp);

                // verify sync
                char *updatedFile2 = malloc(MAX_FILE_SIZE * sizeof(char));
                if (updatedFile2 == NULL) {
                    printf("Error in allocating memory!\n");
                    exit(1);
                }
                fp = fopen(file2, "r");
                if (fp == NULL) {
                    printf("Error in opening file!\n");
                    exit(1);
                }
                fread(updatedFile2, sizeof(char), MAX_FILE_SIZE, fp);
                fclose(fp);

                if (file1Contents[i] != updatedFile2[i]) {
                    printf("Error in syncing file1 byte to file2!\n");
                    exit(1);
                }

                free(updatedFile2);
            }
            i++;
        }
        printf("Files synced successfully!\n");
    } else {
        printf("Files are already in sync!\n");
    }

    free(file1Contents);
    free(file2Contents);
    fclose(fp1);
    fclose(fp2);
}