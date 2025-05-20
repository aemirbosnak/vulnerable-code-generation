//FormAI DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum file name length and file path length
#define MAX_FILENAME_LENGTH 50
#define MAX_FILEPATH_LENGTH 100

// Function to generate random backup file name with timestamp
char* generateBackupFileName(char* filename){
    char* backupfilename = malloc(MAX_FILENAME_LENGTH+20);
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    sprintf(backupfilename,"%s_%04d%02d%02d_%02d%02d%02d.bak",filename, timeinfo->tm_year+1900,timeinfo->tm_mon+1,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
    return backupfilename;
}

int main(){
    char* filename = malloc(MAX_FILENAME_LENGTH);
    char* filepath = malloc(MAX_FILEPATH_LENGTH);
    char* backupfilename = malloc(MAX_FILENAME_LENGTH+20);
    printf("Enter the file name: ");
    scanf("%s", filename);
    printf("Enter the file path: ");
    scanf("%s", filepath);

    // Open the file to backup
    FILE* file = fopen(filepath,"r");
    if(file == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    // Generate backup file name
    backupfilename = generateBackupFileName(filename);
    printf("Backup file name: %s\n", backupfilename);

    // Combine backup directory, filename and extension to get backup file path
    char* backupdir = malloc(MAX_FILEPATH_LENGTH);
    sprintf(backupdir, "%s%s",filepath,"/backup");
    mkdir(backupdir,0777);
    char* backupfilepath = malloc(MAX_FILEPATH_LENGTH+20);
    sprintf(backupfilepath, "%s/%s",backupdir,backupfilename);
    
    // Open the backup file
    FILE* backupfile = fopen(backupfilepath,"w");
    
    // Read from the file and write to the backup file
    char c;
    while((c = fgetc(file)) != EOF){
        fputc(c, backupfile);
    }
    
    // Close the files
    fclose(file);
    fclose(backupfile);

    printf("Backup created successfully.\n");
    free(filename);
    free(filepath);
    free(backupfilename);
    free(backupdir);
    free(backupfilepath);
    return 0;
}