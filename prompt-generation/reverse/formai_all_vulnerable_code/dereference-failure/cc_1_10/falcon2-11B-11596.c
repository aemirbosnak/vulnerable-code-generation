//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createBackupFile(char* filename) {
    FILE* fp;
    char buffer[256];
    sprintf(buffer, "%s.bak", filename);
    fp = fopen(buffer, "w");
    if (fp == NULL) {
        printf("Error creating backup file.\n");
        return;
    }
    fclose(fp);
    printf("Backup file created: %s.\n", buffer);
}

void copyFileContents(char* src, char* dst) {
    FILE* fp1, *fp2;
    char buffer[256];
    sprintf(buffer, "%s.bak", src);
    fp1 = fopen(src, "r");
    if (fp1 == NULL) {
        printf("Error opening source file.\n");
        return;
    }
    fclose(fp1);
    fp2 = fopen(dst, "w");
    if (fp2 == NULL) {
        printf("Error opening destination file.\n");
        return;
    }
    fclose(fp2);
    fread(buffer, 1, 256, fp1);
    fwrite(buffer, 1, 256, fp2);
    fclose(fp1);
    fclose(fp2);
    printf("File contents copied to %s.\n", dst);
}

void compareFiles(char* filename) {
    FILE* fp1, *fp2;
    char buffer[256];
    fp1 = fopen(filename, "r");
    if (fp1 == NULL) {
        printf("Error opening source file.\n");
        return;
    }
    fclose(fp1);
    fp2 = fopen(filename, "r");
    if (fp2 == NULL) {
        printf("Error opening source file.\n");
        return;
    }
    fclose(fp2);
    fread(buffer, 1, 256, fp1);
    fread(buffer, 1, 256, fp2);
    if (strcmp(buffer, buffer) == 0) {
        printf("Files match.\n");
    } else {
        printf("Files do not match.\n");
    }
}

int main() {
    char filename[256];
    char src[256], dst[256];

    printf("Enter the name of the file to backup: ");
    fgets(filename, 256, stdin);

    createBackupFile(filename);

    printf("Enter the name of the backup file: ");
    fgets(src, 256, stdin);

    copyFileContents(filename, src);

    printf("Enter the name of the original file: ");
    fgets(dst, 256, stdin);

    compareFiles(dst);

    return 0;
}