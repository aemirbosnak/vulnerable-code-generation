//FormAI DATASET v1.0 Category: File Backup System ; Style: Ken Thompson
/*
* C File Backup System
* By: Ken Thompson
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void backupFile(char *fileName);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(1);
    } else {
        backupFile(argv[1]);
    }
    return 0;
}

void backupFile(char *fileName) {
    FILE *fp;
    char backupName[50];
    time_t currentTime;

    // Open the original file for reading
    fp = fopen(fileName, "rb");
    if (fp == NULL) {
        printf("Error opening file %s!\n", fileName);
        exit(1);
    }

    // Create backup file name with timestamp
    currentTime = time(NULL);
    strftime(backupName, sizeof(backupName), "%Y-%m-%d-%H-%M-%S", localtime(&currentTime));
    strcat(backupName, "_");
    strcat(backupName, fileName);

    // Create backup file
    FILE *backup = fopen(backupName, "wb");
    if (backup == NULL) {
        printf("Error creating backup file!\n");
        exit(1);
    }

    // Copy contents of original file to backup file
    int c;
    while ((c = fgetc(fp)) != EOF) {
        fputc(c, backup);
    }

    // Close both files
    fclose(fp);
    fclose(backup);

    printf("Backup created in file: %s\n", backupName);
}