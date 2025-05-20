//FormAI DATASET v1.0 Category: File Synchronizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void copyFile(char *sourcePath, char *destinationPath){
    FILE *source, *destination;
    char ch;
    source = fopen(sourcePath, "rb");
    destination = fopen(destinationPath, "wb");
    while(1){
        ch = fgetc(source);
        if(ch == EOF){
            break;
        }
        fputc(ch, destination);
    }
    printf("File synchronized successfully!\n");
    fclose(source);
    fclose(destination);
}

void synchronizeFiles(char *sourcePath, char *destinationPath){
    struct stat sb;
    if(stat(sourcePath, &sb) == 0){
        if(S_ISREG(sb.st_mode)){
            copyFile(sourcePath, destinationPath);
        }else if(S_ISDIR(sb.st_mode)){
            DIR *d1, *d2;
            struct dirent *dir;
            char sourceFilePath[1000], destinationFilePath[1000];
            
            d1 = opendir(sourcePath);
            d2 = opendir(destinationPath);
            
            if(!d1 || !d2){
                printf("Unable to synchronize the folders!\n");
                return;
            }else{
                while((dir = readdir(d1)) != NULL){
                    char *fileName = dir->d_name;
                    if(strcmp(fileName, ".") == 0 || strcmp(fileName, "..") == 0){
                        continue;
                    }
                    sprintf(sourceFilePath, "%s/%s", sourcePath, fileName);
                    sprintf(destinationFilePath, "%s/%s", destinationPath, fileName);
                    synchronizeFiles(sourceFilePath, destinationFilePath);
                }
                closedir(d1);
                closedir(d2);
                printf("Folder synchronized successfully!\n");
            }
        }
    }else{
        printf("Unable to access the file/folder!\n");
    }
}

int main(){
    char sourcePath[1000], destinationPath[1000];
    printf("Enter the source path: ");
    scanf("%s", sourcePath);
    printf("Enter the destination path: ");
    scanf("%s", destinationPath);
    synchronizeFiles(sourcePath, destinationPath);
    return 0;
}