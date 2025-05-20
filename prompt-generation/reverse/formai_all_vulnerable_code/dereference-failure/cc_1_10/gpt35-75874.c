//FormAI DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILE_SIZE 1048576   // 1MB
#define BACKUP_DIR "backup/"

void backupFile(char* filename)
{
    FILE* file = fopen(filename, "rb");
    if(!file)
    {
        printf("Error opening file %s", filename);
        return;
    }

    char backupFilename[MAX_FILENAME_LENGTH + 15];
    strcpy(backupFilename, BACKUP_DIR);
    strcat(backupFilename, filename);
    strcat(backupFilename, ".backup");

    FILE* backupFile = fopen(backupFilename, "wb");
    if(!backupFile)
    {
        printf("Error creating backup file for %s", filename);
        fclose(file);
        return;
    }

    char buffer[MAX_FILE_SIZE];
    size_t bytesRead = fread(buffer, 1, MAX_FILE_SIZE, file);
    fwrite(buffer, 1, bytesRead, backupFile);

    fclose(file);
    fclose(backupFile);

    printf("%s backed up successfully to %s\n", filename, backupFilename);
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    char* filename = argv[1];
    backupFile(filename);

    return 0;
}