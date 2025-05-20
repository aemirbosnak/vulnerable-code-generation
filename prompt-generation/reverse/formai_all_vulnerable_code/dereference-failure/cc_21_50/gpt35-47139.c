//FormAI DATASET v1.0 Category: File system simulation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * Structure for the file system
 */
struct fileSystem{
    char fileName[10];
    int fileSize;
};

/*
 * Structure for the directory
 */
struct directory{
    char dirName[10];
    int numOfFiles;
    struct fileSystem files[10];
};

int main(){
    int numOfDirs = 0;
    int option = 0;
    struct directory dir[10]; //Maximum 10 directories
    char fileName[10], dirName[10];
    int fileSize, dirIndex;
    
    do{
        printf("\nMenu:\n");
        printf("1. Create a new directory\n");
        printf("2. Create a new file\n");
        printf("3. Delete a directory\n");
        printf("4. Delete a file\n");
        printf("5. View the file system\n");
        printf("6. Exit\n");
        printf("Enter your option: ");
        scanf("%d",&option);
        
        switch(option){
            
            case 1:
                printf("\nEnter the name of the new directory: ");
                scanf("%s",dir[numOfDirs].dirName);
                dir[numOfDirs].numOfFiles = 0;
                numOfDirs++;
                printf("\nNew directory created successfully!\n");
                break;
            
            case 2:
                printf("\nEnter the name of the file: ");
                scanf("%s",fileName);
                printf("Enter the file size: ");
                scanf("%d",&fileSize);
                printf("Enter the name of the directory: ");
                scanf("%s",dirName);
                for(int i=0;i<numOfDirs;i++){
                    if(strcmp(dirName,dir[i].dirName)==0){
                        dirIndex = i;
                        break;
                    }
                    if(i == numOfDirs-1){
                        printf("\nDirectory not found!\n");
                        dirIndex = -1;
                    }
                }
                if(dirIndex != -1){
                    if(dir[dirIndex].numOfFiles < 10){
                        strcpy(dir[dirIndex].files[dir[dirIndex].numOfFiles].fileName,fileName);
                        dir[dirIndex].files[dir[dirIndex].numOfFiles].fileSize = fileSize;
                        dir[dirIndex].numOfFiles++;
                        printf("\nNew file created successfully!\n");
                    }
                    else{
                        printf("\nDirectory is full, cannot create new file!\n");
                    }
                }
                break;
                    
            case 3:
                printf("\nEnter the name of the directory to be deleted: ");
                scanf("%s",dirName);
                for(int i=0;i<numOfDirs;i++){
                    if(strcmp(dirName,dir[i].dirName)==0){
                        for(int j=i;j<numOfDirs;j++){
                            dir[j] = dir[j+1];
                        }
                        numOfDirs--;
                        printf("\nDirectory deleted successfully!\n");
                        break;
                    }
                    if(i == numOfDirs-1){
                        printf("\nDirectory not found!\n");
                    }
                }
                break;
            
            case 4:
                printf("\nEnter the name of the directory the file is in: ");
                scanf("%s",dirName);
                for(int i=0;i<numOfDirs;i++){
                    if(strcmp(dirName,dir[i].dirName)==0){
                        printf("\nEnter the name of the file to be deleted: ");
                        scanf("%s",fileName);
                        for(int j=0;j<dir[i].numOfFiles;j++){
                            if(strcmp(fileName,dir[i].files[j].fileName)==0){
                                for(int k=j;k<dir[i].numOfFiles;k++){
                                    dir[i].files[k] = dir[i].files[k+1];
                                }
                                dir[i].numOfFiles--;
                                printf("\nFile deleted successfully!\n");
                                break;
                            }
                            if(j == dir[i].numOfFiles-1){
                                printf("\nFile not found!\n");
                            }
                        }
                        break;
                    }
                    if(i == numOfDirs-1){
                        printf("\nDirectory not found!\n");
                    }
                }
                break;
            
            case 5:
                printf("\nCurrent file system:\n\n");
                for(int i=0;i<numOfDirs;i++){
                    printf("%s\n",dir[i].dirName);
                    for(int j=0;j<dir[i].numOfFiles;j++){
                        printf("\t%s : %d bytes\n",dir[i].files[j].fileName,dir[i].files[j].fileSize);
                    }
                    printf("\n");
                }
                break;
            
            case 6:
                printf("\nExiting program...");
                break;
            
            default:
                printf("\nInvalid option!");
        }
    } while (option != 6);
    
    return 0;
}