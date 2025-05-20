//FormAI DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a line of text from a file
char *readLine(FILE *file) {
    int bufferSize = 100;
    char *line = malloc(bufferSize);
    int i = 0;
    char c = fgetc(file);
    while (c != EOF && c != '\n') {
        if (i == bufferSize - 1) {
            bufferSize *= 2;
            line = realloc(line, bufferSize);
        }
        line[i++] = c;
        c = fgetc(file);
    }
    line[i] = '\0';
    return line;
}

// Function to backup a file
void backupFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    char *line = readLine(file);
    char backupFilename[100];
    sprintf(backupFilename, "%s.bak", filename);
    FILE *backupFile = fopen(backupFilename, "w");
    if (backupFile == NULL) {
        printf("Error: Could not create backup file %s\n", backupFilename);
        return;
    }
    while (line != NULL) {
        fprintf(backupFile, "%s\n", line);
        free(line);
        line = readLine(file);
    }
    fclose(file);
    fclose(backupFile);
    printf("Backup of file %s completed successfully!\n", filename);
}

// Main function to prompt the user for a file name and backup the file
int main() {
    char filename[100];
    printf("Please enter the name of the file to backup: ");
    scanf("%s", filename);
    backupFile(filename);
    return 0;
}