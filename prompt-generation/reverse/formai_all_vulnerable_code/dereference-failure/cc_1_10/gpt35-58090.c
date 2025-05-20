//FormAI DATASET v1.0 Category: File Backup System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_BUFFER_SIZE 1024

// Function to check if file exists
int fileExists(char *filename){
    FILE *file = fopen(filename, "r");
    if (file){
        fclose(file);
        return 1;
    }else{
        return 0;
    }
}

// Function to backup a file
void backupFile(char *filename){
    char backupFilename[MAX_FILENAME_LENGTH];
    strcpy(backupFilename, filename);
    strcat(backupFilename, ".bak");

    // Check if backup file already exists
    if (fileExists(backupFilename)){
        printf("Backup file already exists. Deleting old backup.\n");
        if(remove(backupFilename) != 0 ){
            printf("Error deleting file: %s\n", backupFilename);
            return;
        }
    }

    // Create backup file
    FILE *file = fopen(filename, "r");
    FILE *backupFile = fopen(backupFilename, "w");
    if(file && backupFile){
        char buffer[MAX_BUFFER_SIZE];
        int n;
        while((n = fread(buffer, 1, MAX_BUFFER_SIZE, file)) > 0){
            fwrite(buffer, 1, n, backupFile);
        }
        printf("Backup file created: %s\n", backupFilename);
    }else{
        printf("Error creating backup file.\n");
    }

    fclose(file);
    fclose(backupFile);
}

int main(int argc, char *argv[]){
    // Check if filename provided and if it exists
    if (argc < 2){
        printf("Please provide a filename to backup.\n");
        return 1;
    }else if (!fileExists(argv[1])){
        printf("File does not exist.\n");
        return 1;
    }

    printf("Backup system running...\n\n");
    backupFile(argv[1]);
    printf("\nBackup complete.\n");

    return 0;
}