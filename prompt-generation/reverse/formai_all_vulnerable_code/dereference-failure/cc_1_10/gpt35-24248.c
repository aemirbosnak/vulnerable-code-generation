//FormAI DATASET v1.0 Category: File Synchronizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

// Global Variables
char path1[256];    // Path of Source
char path2[256];    // Path of Destination

// Functions
int fileExists(char* file_path){
    struct stat buffer;
    return (stat(file_path, &buffer) == 0);
}

void syncFiles(){
    DIR *dir1 = opendir(path1);
    DIR *dir2 = opendir(path2);

    struct dirent *file1 = NULL;
    struct dirent *file2 = NULL;

    char filepath1[500], filepath2[500];
    int fd1, fd2;
    char buffer[1000];
    int count = 1;

    while((file1 = readdir(dir1)) && (file2 = readdir(dir2))){
        if((strcmp(file1->d_name, ".") == 0) || (strcmp(file1->d_name, "..") == 0)){
            continue;
        }

        snprintf(filepath1, 500, "%s/%s", path1, file1->d_name);
        snprintf(filepath2, 500, "%s/%s", path2, file2->d_name);

        if(!fileExists(filepath2)){
            printf("\nFile %d: %s does not exist in %s", count++, filepath2, path2);
            printf("\nCopying %s to %s", filepath1, filepath2);

            fd1 = open(filepath1, O_RDONLY);
            fd2 = open(filepath2, O_CREAT | O_WRONLY, 0644);

            while(read(fd1, buffer, sizeof(buffer)) > 0){
                write(fd2, buffer, strlen(buffer));
            }

            close(fd1);
            close(fd2);
        }
        else{
            struct stat file1_stat, file2_stat;
            stat(filepath1, &file1_stat);
            stat(filepath2, &file2_stat);

            if(file1_stat.st_mtime > file2_stat.st_mtime){
                printf("\nFile %d: Updating %s in %s", count++, filepath2, path2);
                remove(filepath2);

                fd1 = open(filepath1, O_RDONLY);
                fd2 = open(filepath2, O_CREAT | O_WRONLY, 0644);

                while(read(fd1, buffer, sizeof(buffer)) > 0){
                    write(fd2, buffer, strlen(buffer));
                }

                close(fd1);
                close(fd2);
            }
            else if(file1_stat.st_mtime < file2_stat.st_mtime){
                printf("\nFile %d: Updating %s in %s", count++, filepath1, path1);
                remove(filepath1);

                fd2 = open(filepath2, O_RDONLY);
                fd1 = open(filepath1, O_CREAT | O_WRONLY, 0644);

                while(read(fd2, buffer, sizeof(buffer)) > 0){
                    write(fd1, buffer, strlen(buffer));
                }

                close(fd1);
                close(fd2);
            }
        }
    }

    closedir(dir1);
    closedir(dir2);
}

int main(){
    printf("Enter the directory path of the Source Folder: ");
    scanf("%s", path1);
    printf("Enter the directory path of the Destination Folder: ");
    scanf("%s", path2);

    syncFiles();

    return 0;
}