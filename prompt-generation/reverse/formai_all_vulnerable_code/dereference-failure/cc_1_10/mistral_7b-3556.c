//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 100

void generateBackupName(char *backupName, char *originalName) {
    time_t now = time(NULL);
    strftime(backupName, MAX_LEN, "%Y-%m-%d_%H-%M-%S", localtime(&now));
    strcat(backupName, "_backup_");
    strcat(backupName, originalName);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file to be backed up>\n", argv[0]);
        return 1;
    }

    char originalName[MAX_LEN];
    strcpy(originalName, argv[1]);

    char backupName[MAX_LEN];
    generateBackupName(backupName, originalName);

    FILE *originalFile = fopen(originalName, "r");
    if (originalFile == NULL) {
        perror("Error opening original file");
        return 1;
    }

    FILE *backupFile = fopen(backupName, "w");
    if (backupFile == NULL) {
        perror("Error creating backup file");
        fclose(originalFile);
        return 1;
    }

    char buffer[MAX_LEN];
    while (fgets(buffer, MAX_LEN, originalFile)) {
        fputs(buffer, backupFile);
    }

    fclose(originalFile);
    fclose(backupFile);

    printf("Backup created successfully: %s\n", backupName);

    return 0;
}