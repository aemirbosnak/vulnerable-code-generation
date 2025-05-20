//FormAI DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Function to check if a given file exists or not
int fileExists(char *fileName){
    struct stat buffer;
    int exist = stat(fileName,&buffer);
    if(exist == 0) return 1;
    else return 0;
}

// Function to copy a file src to dst
void copyFile(char *src, char *dst){
    int srcFile, dstFile, n;
    char buffer[1024];
    srcFile = open(src, O_RDONLY);
    dstFile = open(dst, O_WRONLY | O_CREAT, 0666);
    while((n = read(srcFile, buffer, sizeof(buffer))) != 0){
        write(dstFile, buffer, n);
    }
    close(srcFile);
    close(dstFile);
}

// Function to synchronize the contents of two directories
void synchronizeDirectories(char *dir1, char *dir2){
    DIR *dir;
    struct dirent *ent;
    char fileName1[256];
    char fileName2[256];
    char dirName1[256];
    char dirName2[256];

    // Synchronize files in dir1 with dir2
    dir = opendir(dir1);
    while((ent = readdir(dir)) != NULL){
        if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) continue;
        if(ent->d_type == DT_DIR){
            // Synchronize directories recursively
            sprintf(dirName1, "%s/%s", dir1, ent->d_name);
            sprintf(dirName2, "%s/%s", dir2, ent->d_name);
            if(!fileExists(dirName2)) mkdir(dirName2, 0777);
            synchronizeDirectories(dirName1, dirName2);
        } else {
            // Synchronize files
            sprintf(fileName1, "%s/%s", dir1, ent->d_name);
            sprintf(fileName2, "%s/%s", dir2, ent->d_name);
            if(!fileExists(fileName2)) copyFile(fileName1, fileName2);
            else if(fileExists(fileName2) && 
                    (access(fileName2, W_OK) != -1) &&
                    (access(fileName1, R_OK) != -1)){
                struct stat statbuf1, statbuf2;
                lstat(fileName1, &statbuf1);
                lstat(fileName2, &statbuf2);
                if(statbuf1.st_mtime > statbuf2.st_mtime) copyFile(fileName1, fileName2);
                else if(statbuf2.st_mtime > statbuf1.st_mtime) copyFile(fileName2, fileName1);
            }
        }
    }
    closedir(dir);

    // Synchronize files in dir2 with dir1
    dir = opendir(dir2);
    while((ent = readdir(dir)) != NULL){
        if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) continue;
        if(ent->d_type == DT_DIR){
            // Synchronize directories recursively
            sprintf(dirName1, "%s/%s", dir2, ent->d_name);
            sprintf(dirName2, "%s/%s", dir1, ent->d_name);
            if(!fileExists(dirName2)) mkdir(dirName2, 0777);
            synchronizeDirectories(dirName1, dirName2);
        } else {
            // Synchronize files
            sprintf(fileName1, "%s/%s", dir2, ent->d_name);
            sprintf(fileName2, "%s/%s", dir1, ent->d_name);
            if(!fileExists(fileName2)) copyFile(fileName1, fileName2);
            else if(fileExists(fileName2) && 
                    (access(fileName2, W_OK) != -1) &&
                    (access(fileName1, R_OK) != -1)){
                struct stat statbuf1, statbuf2;
                lstat(fileName1, &statbuf1);
                lstat(fileName2, &statbuf2);
                if(statbuf1.st_mtime > statbuf2.st_mtime) copyFile(fileName1, fileName2);
                else if(statbuf2.st_mtime > statbuf1.st_mtime) copyFile(fileName2, fileName1);
            }
        }
    }
    closedir(dir);
}

// Main function to test the synchronization program
int main(){
    char dir1[256];
    char dir2[256];
    printf("Enter the first directory path: ");
    scanf("%s", dir1);
    printf("Enter the second directory path: ");
    scanf("%s", dir2);
    synchronizeDirectories(dir1, dir2);
    printf("Directories synchronized successfully!\n");
    return 0;
}