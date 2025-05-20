//FormAI DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void backup(char* filename);

int main() {
    char file[50];
    printf("Enter name of file to backup: ");
    scanf("%s", file);

    backup(file);

    return 0;
}

void backup(char* filename) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char newfilename[50];

    // Create new file name with date stamp
    sprintf(newfilename, "Backup_%d-%02d-%02d_%s", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, filename);

    // Open the original file for reading
    FILE* original = fopen(filename, "r");
    if (original == NULL) {
        printf("Error: Could not open file: %s", filename);
        return;
    }

    // Open the new file for writing
    FILE* backup = fopen(newfilename, "w");
    if (backup == NULL) {
        printf("Error: Could not create file: %s", newfilename);
        fclose(original);
        return;
    }

    // Copy the contents of the original file to the backup file
    char buffer[4096];
    while (fgets(buffer, sizeof(buffer), original)) {
        if (fputs(buffer, backup) == EOF) {
            printf("Error: Could not write to file: %s", newfilename);
            fclose(original);
            fclose(backup);
            return;
        }
    }

    // Close both files
    fclose(original);
    fclose(backup);

    printf("Backup of %s created as %s\n", filename, newfilename);
}