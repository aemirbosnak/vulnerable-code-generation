//FormAI DATASET v1.0 Category: File Synchronizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000

int main(int argc, char *argv[]) {

    char filename1[MAX_FILENAME_LENGTH];
    char filename2[MAX_FILENAME_LENGTH];
    char fileContent1[MAX_FILE_CONTENT_LENGTH];
    char fileContent2[MAX_FILE_CONTENT_LENGTH];

    printf("Enter the name of the first file: ");
    scanf("%s", filename1);

    printf("Enter the name of the second file: ");
    scanf("%s", filename2);

    FILE *file1 = fopen(filename1, "r");
    FILE *file2 = fopen(filename2, "r");

    if (file1 == NULL || file2 == NULL) {
        printf("Error: One of the files doesn't exist.\n");
        exit(1);
    }

    fseek(file1, 0L, SEEK_END);
    int fileSize1 = ftell(file1);
    fseek(file1, 0L, SEEK_SET);

    fseek(file2, 0L, SEEK_END);
    int fileSize2 = ftell(file2);
    fseek(file2, 0L, SEEK_SET);

    if (fileSize1 != fileSize2) {
        printf("Warning: The files have different sizes.\n");
    }

    fread(fileContent1, sizeof(char), fileSize1, file1);
    fclose(file1);

    fread(fileContent2, sizeof(char), fileSize2, file2);
    fclose(file2);

    if (strcmp(fileContent1, fileContent2) == 0) {
        printf("The files are synchronized!\n");
    } else {
        printf("The files are not synchronized.\n");
    }

    return 0;
}