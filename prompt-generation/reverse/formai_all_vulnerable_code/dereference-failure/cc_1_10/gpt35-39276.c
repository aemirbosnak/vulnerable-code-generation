//FormAI DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

//Function declarations
void syncDirectory(char *srcPath, char *dstPath);
int fileExists(char *filePath);
void copyFile(char *srcPath, char *dstPath);
void copyDir(char *srcPath, char *dstPath);

int main(int argc, char **argv)
{
    if(argc < 3)
    {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(1);
    }
    
    //srcPath and dstPath
    char *srcPath = argv[1];
    char *dstPath = argv[2];
    
    //Call the syncDirectory function
    syncDirectory(srcPath, dstPath);
    
    printf("Sync complete!\n");
    
    return 0;
}

//Function to synchronize directories
void syncDirectory(char *srcPath, char *dstPath)
{
    DIR *srcDir, *dstDir;
    struct dirent *srcEntry, *dstEntry;
    char *srcFilePath, *dstFilePath;
    int retVal;
    struct stat srcFileStat, dstFileStat;
    
    //Open both directories
    srcDir = opendir(srcPath);
    dstDir = opendir(dstPath);
    
    //If the destination directory doesn't exist, create it
    if(dstDir == NULL)
    {
        mkdir(dstPath, 0777);
        dstDir = opendir(dstPath);
    }
    
    //Loop through the source directory
    while((srcEntry = readdir(srcDir)) != NULL)
    {
        //If the entry is Not a directory, compare with the destination directory
        if(srcEntry->d_type == DT_REG)
        {
            srcFilePath = malloc(strlen(srcPath) + strlen(srcEntry->d_name) + 2);
            sprintf(srcFilePath, "%s/%s", srcPath, srcEntry->d_name);
            
            //Get the stat structure for the file
            stat(srcFilePath, &srcFileStat);
            
            //If the file does not exist in the destination directory, copy it
            if(!fileExists(srcFilePath))
            {
                dstFilePath = malloc(strlen(dstPath) + strlen(srcEntry->d_name) + 2);
                sprintf(dstFilePath, "%s/%s", dstPath, srcEntry->d_name);
                copyFile(srcFilePath, dstFilePath);
                free(dstFilePath);
            }
            //If the file already exists in the destination directory, compare their modification times
            else
            {
                dstFilePath = malloc(strlen(dstPath) + strlen(srcEntry->d_name) + 2);
                sprintf(dstFilePath, "%s/%s", dstPath, srcEntry->d_name);
                
                //Get the stat structure for the destination file and compare with the source file
                stat(dstFilePath, &dstFileStat);
                retVal = difftime(srcFileStat.st_mtime, dstFileStat.st_mtime);
                
                //If the source file is newer than the destination, copy the file
                if(retVal > 0)
                {
                    copyFile(srcFilePath, dstFilePath);
                }
                
                free(dstFilePath);
            }
            free(srcFilePath);
        }
        //If the entry is a directory, compare with the destination directory
        else if(srcEntry->d_type == DT_DIR)
        {
            //Ignore the "." and ".." directories
            if(strcmp(srcEntry->d_name, ".") == 0 || strcmp(srcEntry->d_name, "..") == 0)
            {
                continue;
            }
            
            srcFilePath = malloc(strlen(srcPath) + strlen(srcEntry->d_name) + 2);
            sprintf(srcFilePath, "%s/%s", srcPath, srcEntry->d_name);
            
            //If the directory does not exist in the destination directory, create it and copy all contents of the directory
            if(!fileExists(srcFilePath))
            {
                dstFilePath = malloc(strlen(dstPath) + strlen(srcEntry->d_name) + 2);
                sprintf(dstFilePath, "%s/%s", dstPath, srcEntry->d_name);
                mkdir(dstFilePath, 0777);
                copyDir(srcFilePath, dstFilePath);
                free(dstFilePath);
            }
            //If the directory already exists in the destination directory, synchronize it
            else
            {
                dstFilePath = malloc(strlen(dstPath) + strlen(srcEntry->d_name) + 2);
                sprintf(dstFilePath, "%s/%s", dstPath, srcEntry->d_name);
                syncDirectory(srcFilePath, dstFilePath);
                free(dstFilePath);
            }
            free(srcFilePath);
        }
    }
    
    closedir(srcDir);
    closedir(dstDir);
}

//Function to check if a file exists
int fileExists(char *filePath)
{
    FILE *file;
    if ((file = fopen(filePath, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

//Function to copy a file
void copyFile(char *srcPath, char *dstPath)
{
    FILE *srcFile, *dstFile;
    char buf[1024];
    size_t size;
    
    srcFile = fopen(srcPath, "rb");
    dstFile = fopen(dstPath, "wb");
    
    while((size = fread(buf, 1, 1024, srcFile)) != 0)
    {
        fwrite(buf, 1, size, dstFile);
    }
    
    fclose(srcFile);
    fclose(dstFile);
}

//Function to copy a directory and its contents
void copyDir(char *srcPath, char *dstPath)
{
    DIR *srcDir;
    struct dirent *entry;
    char *srcFilePath, *dstFilePath;
    
    //Open the source directory
    srcDir = opendir(srcPath);
    
    //Loop through the source directory
    while((entry = readdir(srcDir)) != NULL)
    {
        //Ignore the "." and ".." directories
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }
        
        srcFilePath = malloc(strlen(srcPath) + strlen(entry->d_name) + 2);
        sprintf(srcFilePath, "%s/%s", srcPath, entry->d_name);
        
        //If the entry is a file, copy it to the destination directory
        if(entry->d_type == DT_REG)
        {
            dstFilePath = malloc(strlen(dstPath) + strlen(entry->d_name) + 2);
            sprintf(dstFilePath, "%s/%s", dstPath, entry->d_name);
            copyFile(srcFilePath, dstFilePath);
            free(dstFilePath);
        }
        //If the entry is a directory, create it in the destination directory and copy all contents of the directory to it
        else if(entry->d_type == DT_DIR)
        {
            dstFilePath = malloc(strlen(dstPath) + strlen(entry->d_name) + 2);
            sprintf(dstFilePath, "%s/%s", dstPath, entry->d_name);
            mkdir(dstFilePath, 0777);
            copyDir(srcFilePath, dstFilePath);
            free(dstFilePath);
        }
        
        free(srcFilePath);
    }
    
    closedir(srcDir);
}