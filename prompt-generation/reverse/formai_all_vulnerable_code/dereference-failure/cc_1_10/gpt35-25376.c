//FormAI DATASET v1.0 Category: File Backup System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_SIZE 100
#define MAX_FILE_SIZE 1000000

void backupFile(char* filename) {
    FILE* fp, * backup;
    char backupFilename[MAX_FILENAME_SIZE];
    char buffer[MAX_FILE_SIZE];
    time_t t = time(NULL);
    struct tm* now = localtime(&t);

    // create backup filename with timestamp
    sprintf(backupFilename, "%s_backup_%d-%d-%d_%d-%d-%d", filename, now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);

    // open file to be backed up
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s for backup.\n", filename);
        return;
    }

    // open backup file for writing
    backup = fopen(backupFilename, "w");
    if (backup == NULL) {
        printf("Error: could not create backup file %s.\n", backupFilename);
        return;
    }

    // copy contents of file to backup file
    while (fgets(buffer, MAX_FILE_SIZE, fp) != NULL) {
        fputs(buffer, backup);
    }

    // close files
    fclose(fp);
    fclose(backup);

    printf("%s backed up successfully as %s\n", filename, backupFilename);
}

int main(int argc, char *argv[]) {
    // check if filename provided in command line argument
    if (argc == 2) {
        backupFile(argv[1]);
    }
    else {
        printf("Please provide a filename to backup.\n");
    }

    return 0;
}