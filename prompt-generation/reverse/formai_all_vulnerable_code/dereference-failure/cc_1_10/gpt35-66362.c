//FormAI DATASET v1.0 Category: File Synchronizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


// This function compares two files to see if they are the same
int areFilesIdentical(char *srcFile, char *dstFile){
    FILE *fp1 = fopen(srcFile, "r");
    FILE *fp2 = fopen(dstFile, "r");

    // check if files can be opened
    if(fp1 == NULL || fp2 == NULL){
        return 0;
    }

    int ch1 = getc(fp1);
    int ch2 = getc(fp2);

    while (ch1 != EOF && ch2 != EOF)
    {
        if (ch1 != ch2){
            fclose(fp1);
            fclose(fp2);
            return 0;
        }
        ch1 = getc(fp1);
        ch2 = getc(fp2);
    }

    if (ch1 == EOF && ch2 == EOF){
        fclose(fp1);
        fclose(fp2);
        return 1;
    }
    else{
        fclose(fp1);
        fclose(fp2);
        return 0;
    }
}

// This function recursively copies files and directories from source to destination
void copyFiles(char *srcDir, char *dstDir) {
    DIR *dir;
    struct dirent *ent;
    struct stat fileStats;
    char srcPath[1000],dstPath[1000];
    dir = opendir(srcDir);

    // check if source directory can be opened
    if (dir == NULL){
        printf("Could not open %s\n", srcDir);
        return;
    }
    // check if destination directory exists, else create one
    if(stat(dstDir, &fileStats) == -1){
        mkdir(dstDir,0777);
    }

    // read all files and directories from source directory
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_name[0] == '.') { // ignore hidden files and directories
            continue;
        }
        sprintf(srcPath,"%s/%s",srcDir,ent->d_name);
        sprintf(dstPath,"%s/%s",dstDir,ent->d_name);

        if (stat(srcPath,&fileStats) == -1){ // check if source file/directory can be read
            printf("Error reading %s\n",srcPath);
            continue;
        }

        if(S_ISDIR(fileStats.st_mode)){ // if current file is a directory, recursively copy it
            copyFiles(srcPath,dstPath);
        }
        else{
            if(access(dstPath,F_OK) == -1){ // if destination file doesn't exist copy it
                int srcFile = open(srcPath,O_RDONLY); 
                int dstFile = open(dstPath,O_CREAT | O_WRONLY, fileStats.st_mode);
                char buf[1024];
                int numRead = 0;
                
                while(numRead = read(srcFile, buf, 1024)){
                    write(dstFile, buf, numRead);
                }
                
                close(srcFile);
                close(dstFile);
            }
            else{ // if destination file exists and is different from source file, copy it
                if(!areFilesIdentical(srcPath,dstPath)){
                    int srcFile = open(srcPath,O_RDONLY); 
                    int dstFile = open(dstPath,O_WRONLY | O_TRUNC);
                    char buf[1024];
                    int numRead = 0;

                    while(numRead = read(srcFile, buf, 1024)){
                        write(dstFile, buf, numRead);
                    }
                    
                    close(srcFile);
                    close(dstFile);
                }
            }
        }
    }

    closedir(dir);
}

// This is the main function that takes in source and destination directories as command line arguments
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s source_dir target_dir\n", argv[0]);
        return 0;
    }
    copyFiles(argv[1], argv[2]);
    return 0;
}