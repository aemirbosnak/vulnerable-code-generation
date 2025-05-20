//FormAI DATASET v1.0 Category: File Synchronizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void syncFiles(const char* sourceDir, const char* destDir)
{
    DIR* dir;
    struct dirent* de;
    char fullPathSource[512];
    char fullPathDest[512];
    char command[1024];
    struct stat st;
    
    dir = opendir(sourceDir);
    if (dir)
    {
        while ((de = readdir(dir)) != NULL)
        {
            if (de->d_type == DT_REG) // If it's a file
            {
                snprintf(fullPathSource, sizeof(fullPathSource), "%s/%s", sourceDir, de->d_name);
                snprintf(fullPathDest, sizeof(fullPathDest), "%s/%s", destDir, de->d_name);
                
                if (stat(fullPathSource, &st) == -1) // Get file attributes
                {
                    printf("ERROR: Could not get file attributes for %s: %s\n", fullPathSource, strerror(errno));
                    continue;
                }
                
                if (access(fullPathDest, F_OK) == 0) // If file exists in destination folder
                {
                    struct stat stDest;
                    
                    if (stat(fullPathDest, &stDest) == -1) // Get file attributes
                    {
                        printf("ERROR: Could not get file attributes for %s: %s\n", fullPathDest, strerror(errno));
                        continue;
                    }
                    
                    if (st.st_mtime > stDest.st_mtime) // If source file is newer than destination file
                    {
                        snprintf(command, sizeof(command), "cp -f %s %s", fullPathSource, destDir);
                        printf("Updating %s\n", fullPathDest);
                        system(command);
                    }
                }
                else // If file does not exist in destination folder
                {
                    snprintf(command, sizeof(command), "cp %s %s", fullPathSource, destDir);
                    printf("Adding %s\n", fullPathDest);
                    system(command);
                }
            }
            else if (de->d_type == DT_DIR && strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) // If it's a directory
            {
                char newSourceDir[512];
                char newDestDir[512];
                
                snprintf(newSourceDir, sizeof(newSourceDir), "%s/%s", sourceDir, de->d_name);
                snprintf(newDestDir, sizeof(newDestDir), "%s/%s", destDir, de->d_name);
                
                if (access(newDestDir, F_OK) != 0) // If directory does not exist in destination folder
                {
                    mkdir(newDestDir, 0777); // Create directory
                    printf("Creating directory %s\n", newDestDir);
                }
                
                syncFiles(newSourceDir, newDestDir); // Recurse into subdirectory
            }
        }
        
        closedir(dir);
    }
}

int main()
{
    syncFiles("/home/username/folder1", "/home/username/folder2");
    
    return 0;
}