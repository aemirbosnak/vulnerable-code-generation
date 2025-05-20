//FormAI DATASET v1.0 Category: System process viewer ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>

// function to print process information
void printProcess(char* pid){
    char processPath[50];
    sprintf(processPath,"/proc/%s/status", pid);

    FILE* file = fopen(processPath,"r");
    char info[50];

    while(fscanf(file,"%s",info)!=EOF){
        if(strcmp(info,"Name:")==0){
            fscanf(file,"%s",info);
            printf("Process Name: %s\n",info);
        }
        if(strcmp(info,"State:")==0){
            fscanf(file,"%s",info);
            printf("Process State: %s\n",info);
        }
        if(strcmp(info,"PPid:")==0){
            fscanf(file,"%s",info);
            printf("Process Parent ID: %s\n",info);
        }
        if(strcmp(info,"Uid:")==0){
            fscanf(file,"%s",info);
            printf("User ID: %s\n",info);
        }
    }
    fclose(file);
}

// function to list all processes
void listAllProcesses(){
    DIR* directory;
    struct dirent* dir;
    directory = opendir("/proc");

    if(directory){
        printf("\n-------------List of All Processes-------------\n\n");
        printf("Process ID\tProcess Name\n");
        while((dir = readdir(directory)) != NULL){
            //check if directory is numeric
            if(digitDetection(dir->d_name)){
                char processPath[50];
                sprintf(processPath,"/proc/%s/stat", dir->d_name);
                FILE* file = fopen(processPath,"r");
                
                // get process name from file
                char processName[50];
                fscanf(file,"%s",processName);
                fclose(file);
                // print process information
                printf("%s\t\t%s\n",dir->d_name,processName);
            }
        }
        closedir(directory);
    }
}

// function to check if string only contains digit
int digitDetection(char* string) {
    for(int i=0; string[i]!='\0'; i++) {
        if (isdigit(string[i]) == 0) {
            return 0;
        }
    }
    return 1;
}

// main function
int main(){
    printf("\n---------------------------------\n");
    printf("~~~~C System Process Viewer~~~~\n");
    printf("---------------------------------\n\n");
    // call function to list all processes
    listAllProcesses();
    // prompt to get pid from user
    printf("\nEnter Process ID to view its information: ");
    char pid[10];
    scanf("%s",pid);
    // call function to print process information
    printProcess(pid);

    return 0;
}