//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a backup of the given file
void backupFile(char *fileName) {
    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL) {
        printf("Error opening the file\n");
        return;
    }
    
    fseek(fp, 0L, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    
    char *backupName = malloc(strlen(fileName) + 8);
    sprintf(backupName, "%s.bak", fileName);
    
    FILE *fpBackup = fopen(backupName, "wb");
    if (fpBackup == NULL) {
        printf("Error creating the backup file\n");
        fclose(fp);
        return;
    }
    
    fwrite(fp, 1, fileSize, fpBackup);
    
    fclose(fp);
    fclose(fpBackup);
    
    printf("Backup created successfully\n");
}

// Function to restore the backup of the given file
void restoreFile(char *fileName) {
    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL) {
        printf("Error opening the file\n");
        return;
    }
    
    fseek(fp, 0L, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    
    char *backupName = malloc(strlen(fileName) + 8);
    sprintf(backupName, "%s.bak", fileName);
    
    FILE *fpBackup = fopen(backupName, "rb");
    if (fpBackup == NULL) {
        printf("Error opening the backup file\n");
        fclose(fp);
        return;
    }
    
    fread(fp, 1, fileSize, fpBackup);
    
    fclose(fp);
    fclose(fpBackup);
    
    printf("File restored successfully\n");
}

int main() {
    char *fileName = "test.txt";
    
    backupFile(fileName);
    
    restoreFile(fileName);
    
    return 0;
}