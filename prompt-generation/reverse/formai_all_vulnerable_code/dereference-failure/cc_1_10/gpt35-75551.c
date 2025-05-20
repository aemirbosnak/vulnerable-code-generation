//FormAI DATASET v1.0 Category: File Backup System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *filename;
    char *content;
} File;

File createFile(char *filename, char *content);
void backupFiles(File *files, int numOfFiles, char *backupFolder);

int main()
{
    int numOfFiles = 3;
    char *backupFolder = "backup_folder";
    
    File files[numOfFiles];
    files[0] = createFile("file1.txt", "This is file 1 content");
    files[1] = createFile("file2.txt", "This is file 2 content");
    files[2] = createFile("file3.txt", "This is file 3 content");
    
    backupFiles(files, numOfFiles, backupFolder);
    
    return 0;
}

File createFile(char *filename, char *content)
{
    File file;
    file.filename = malloc(sizeof(char) * strlen(filename));
    strcpy(file.filename, filename);
    
    file.content = malloc(sizeof(char) * strlen(content));
    strcpy(file.content, content);
    
    return file;
}

void backupFiles(File *files, int numOfFiles, char *backupFolder)
{
    if(mkdir(backupFolder, 0777) == -1) {
        printf("Error: Could not create backup folder\n");
        return;
    }
    
    for(int i = 0; i < numOfFiles; i++) {
        char *backupFilePath = malloc(sizeof(char) * (strlen(backupFolder) + strlen(files[i].filename) + 2));
        sprintf(backupFilePath, "%s/%s", backupFolder, files[i].filename);
        
        FILE *backupFile = fopen(backupFilePath, "w");
        if(backupFile == NULL) {
            printf("Error: Could not create backup file for %s\n", files[i].filename);
            continue;
        }
        
        fprintf(backupFile, "%s", files[i].content);
        fclose(backupFile);
        printf("Backup created for %s\n", files[i].filename);
    }
}