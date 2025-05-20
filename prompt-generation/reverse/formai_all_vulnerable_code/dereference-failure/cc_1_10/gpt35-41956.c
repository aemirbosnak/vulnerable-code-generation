//FormAI DATASET v1.0 Category: File Synchronizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAXPATH 100

int sync_files(char* path1, char* path2);

int main(){
    char path1[MAXPATH] = "/home/user/documents/folder1";
    char path2[MAXPATH] = "/home/user/documents/folder2";
    
    sync_files(path1, path2);
    
    return 0;
}

int sync_files(char* path1, char* path2){
    DIR *dir1, *dir2;
    struct dirent *dp1, *dp2;
    struct stat buf1, buf2;
    char path1_new[MAXPATH], path2_new[MAXPATH];
    
    // open directories
    if ((dir1 = opendir(path1)) == NULL) {
        perror("Error opening folder 1");
        return -1;
    }
    if ((dir2 = opendir(path2)) == NULL) {
        perror("Error opening folder 2");
        return -1;
    }
    
    // sync files from folder 1 to folder 2
    while((dp1 = readdir(dir1)) != NULL){
        if(strcmp(dp1->d_name, ".") != 0 && strcmp(dp1->d_name, "..") != 0){
            sprintf(path1_new, "%s/%s", path1, dp1->d_name);
            sprintf(path2_new, "%s/%s", path2, dp1->d_name);
            
            if(stat(path1_new, &buf1) == -1){
                perror("Error getting file status");
                return -1;
            }
            
            if(stat(path2_new, &buf2) == -1){
                // file in folder 1 does not exist in folder 2, so copy it over
                char command[MAXPATH+13] = "cp ";
                strcat(command, path1_new);
                strcat(command, " ");
                strcat(command, path2_new);
                system(command);
            }
            else{
                if(buf1.st_mtime > buf2.st_mtime){
                    // file in folder 1 is newer than file in folder 2, so copy it over
                    char command[MAXPATH+13] = "cp ";
                    strcat(command, path1_new);
                    strcat(command, " ");
                    strcat(command, path2_new);
                    system(command);
                }
            }
            
        }
    }
    
    // sync files from folder 2 to folder 1
    while((dp2 = readdir(dir2)) != NULL){
        if(strcmp(dp2->d_name, ".") != 0 && strcmp(dp2->d_name, "..") != 0){
            sprintf(path1_new, "%s/%s", path1, dp2->d_name);
            sprintf(path2_new, "%s/%s", path2, dp2->d_name);
            
            if(stat(path2_new, &buf2) == -1){
                perror("Error getting file status");
                return -1;
            }
            
            if(stat(path1_new, &buf1) == -1){
                // file in folder 2 does not exist in folder 1, so copy it over
                char command[MAXPATH+13] = "cp ";
                strcat(command, path2_new);
                strcat(command, " ");
                strcat(command, path1_new);
                system(command);
            }
            else{
                if(buf2.st_mtime > buf1.st_mtime){
                    // file in folder 2 is newer than file in folder 1, so copy it over
                    char command[MAXPATH+13] = "cp ";
                    strcat(command, path2_new);
                    strcat(command, " ");
                    strcat(command, path1_new);
                    system(command);
                }
            }
            
        }
    }
    
    // close directories
    closedir(dir1);
    closedir(dir2);
    
    return 0;
}