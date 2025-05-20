//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a backup of the file
void createBackup(char *fileName) {
    char *backupFileName = (char*)malloc(strlen(fileName) + 5);
    sprintf(backupFileName, "%s.bak", fileName);

    FILE *fp = fopen(fileName, "r");
    FILE *fpBak = fopen(backupFileName, "w");
    if (fp && fpBak) {
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), fp)) {
            fprintf(fpBak, "%s", buffer);
        }
        fclose(fp);
        fclose(fpBak);
        free(backupFileName);
        printf("Backup created successfully.\n");
    } else {
        printf("Error creating backup.\n");
    }
}

// Function to restore the backup to the original file
void restoreBackup(char *fileName) {
    char *backupFileName = (char*)malloc(strlen(fileName) + 5);
    sprintf(backupFileName, "%s.bak", fileName);

    FILE *fp = fopen(fileName, "w");
    FILE *fpBak = fopen(backupFileName, "r");
    if (fp && fpBak) {
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), fpBak)) {
            fprintf(fp, "%s", buffer);
        }
        fclose(fp);
        fclose(fpBak);
        free(backupFileName);
        printf("Backup restored successfully.\n");
    } else {
        printf("Error restoring backup.\n");
    }
}

int main() {
    char *fileName = "data.txt";
    createBackup(fileName);
    restoreBackup(fileName);
    return 0;
}