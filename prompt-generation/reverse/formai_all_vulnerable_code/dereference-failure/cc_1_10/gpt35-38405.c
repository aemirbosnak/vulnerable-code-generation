//FormAI DATASET v1.0 Category: File Backup System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILESIZE 10000000

struct file{
    char* name;
    int size;
};

void backupFiles(struct file* files, int numFiles, char* backupPath){
    // Create backup folder if it doesn't exist
    char command[100];
    sprintf(command, "mkdir -p %s", backupPath);
    system(command);
    
    // Copy each file to the backup folder
    for(int i=0; i<numFiles; i++){
        char buffer[MAX_FILESIZE];
        FILE* originalFile = fopen(files[i].name, "r");
        FILE* backupFile = fopen(strcat(backupPath, files[i].name), "w");
        
        while(fgets(buffer, MAX_FILESIZE, originalFile) != NULL){
            fprintf(backupFile, "%s", buffer);
        }
        
        fclose(originalFile);
        fclose(backupFile);
    }
    
    printf("Backup complete!\n");
}

int main(){
    int numFiles;
    char backupPath[MAX_FILENAME_LENGTH];
    printf("Enter the number of files you want to backup: ");
    scanf("%d", &numFiles);
    struct file* files = (struct file*) malloc(numFiles*sizeof(struct file));
    
    // Read in file names and sizes
    for(int i=0; i<numFiles; i++){
        files[i].name = (char*) malloc(MAX_FILENAME_LENGTH*sizeof(char));
        printf("Enter file name %d: ", i+1);
        scanf("%s", files[i].name);
        printf("Enter file size (in bytes) for file %d: ", i+1);
        scanf("%d", &files[i].size);
    }
    
    // Read in backup folder name
    printf("Enter backup folder name: ");
    scanf("%s", backupPath);
    
    backupFiles(files, numFiles, backupPath);
    return 0;
}