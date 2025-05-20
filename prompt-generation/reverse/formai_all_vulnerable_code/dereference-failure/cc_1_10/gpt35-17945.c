//FormAI DATASET v1.0 Category: File Backup System ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>

void backup(char* sourceFilepath, char* targetDirectoryPath){
    
    //check if target directory exists, if not create one
    DIR* targetDirectory = opendir(targetDirectoryPath);
    if(targetDirectory == NULL){
        mkdir(targetDirectoryPath, 0700);
    }
    
    //get the filename from source filepath
    char* filename = strrchr(sourceFilepath, '/');
    if(filename == NULL){
        filename = sourceFilepath;
    }else{
         filename++;
    }
    
    //construct the backup file's complete path
    time_t now;
    char dateString[20];
    struct tm *timeinfo;
    
    time(&now);
    timeinfo = localtime(&now);
    strftime(dateString, 20, "%Y-%m-%d-%H-%M-%S", timeinfo);
    
    char* targetFilepath = malloc(strlen(targetDirectoryPath) + strlen(filename) + strlen(dateString) + 2);
    sprintf(targetFilepath, "%s/%s.%s", targetDirectoryPath, filename, dateString);
    
    //open source file and target file
    FILE* sourceFile = fopen(sourceFilepath, "rb");
    if(sourceFile == NULL){
        printf("Error: Source file could not be opened.\n");
        return;
    }
    
    FILE* targetfile = fopen(targetFilepath, "wb");
    if(targetfile == NULL){
        printf("Error: Target file could not be opened.\n");
        fclose(sourceFile);
        return;
    }
    
    //read data from source file and write it to target file
    char buffer[1024];
    int bytesRead = 0;
    do{
        bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile);
        fwrite(buffer, 1, bytesRead, targetfile);
    }while(bytesRead == sizeof(buffer));
    
    //close files and free memory
    fclose(sourceFile);
    fclose(targetfile);
    free(targetFilepath);
    
    printf("Backup created successfully!\n");
}

int main(){
    //test the backup function
    backup("/etc/passwd", "./backups");
    return 0;
}