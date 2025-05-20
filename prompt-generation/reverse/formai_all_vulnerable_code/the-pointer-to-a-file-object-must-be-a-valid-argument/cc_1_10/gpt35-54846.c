//FormAI DATASET v1.0 Category: File Backup System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILENAME_LEN 100
#define MAX_FILE_COUNT 100

typedef struct {
    char filename[MAX_FILENAME_LEN];
    int size;
} File;

int main() {
    File files[MAX_FILE_COUNT];
    int fileCount = 0;

    // read from config file
    FILE *configFile = fopen("config.txt", "r");
    char buffer[100];
    while(fgets(buffer, sizeof(buffer), configFile)) {
        char filename[MAX_FILENAME_LEN];
        int size;
        sscanf(buffer, "%s %d", filename, &size);

        // save file data into files array
        File newFile;
        strcpy(newFile.filename, filename);
        newFile.size = size;
        files[fileCount++] = newFile;
    }

    fclose(configFile);

    // create backup directory if it doesn't exist
    system("mkdir -p backup");

    // iterate through files array and backup each file
    for(int i=0; i<fileCount; i++) {
        File currentFile = files[i];

        char backupFilename[MAX_FILENAME_LEN+10];
        sprintf(backupFilename, "backup/%s", currentFile.filename);

        char command[100+MAX_FILENAME_LEN*2];
        sprintf(command, "cp %s %s", currentFile.filename, backupFilename);

        system(command);
        printf("Backed up file %s\n", currentFile.filename);
    }

    return 0;
}