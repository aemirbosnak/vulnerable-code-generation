//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 100

void createBackup(char *filename) {
    char backupName[MAX_LEN];
    char *dotPos;
    time_t now;

    // Get current time
    time(&now);

    // Create a backup name with a romantic touch
    strcpy(backupName, "MyLoveBackup_");
    strcat(backupName, ctime(&now));
    strcat(backupName, "_");
    strcat(backupName, filename);

    // Open the original file for reading
    FILE *originalFile = fopen(filename, "r");
    if (originalFile == NULL) {
        perror("Error opening original file.");
        exit(EXIT_FAILURE);
    }

    // Open the backup file for writing
    FILE *backupFile = fopen(backupName, "w");
    if (backupFile == NULL) {
        perror("Error creating backup file.");
        fclose(originalFile);
        exit(EXIT_FAILURE);
    }

    // Read the contents of the original file and write to the backup file
    char buffer[MAX_LEN];
    while (fgets(buffer, sizeof(buffer), originalFile) != NULL) {
        fputs(buffer, backupFile);
    }

    // Close both files
    fclose(originalFile);
    fclose(backupFile);

    printf("Backed up %s as %s.\n", filename, backupName);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    createBackup(argv[1]);

    return EXIT_SUCCESS;
}