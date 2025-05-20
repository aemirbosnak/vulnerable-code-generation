//FormAI DATASET v1.0 Category: System process viewer ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<ctype.h>

//function to check if string is a number
int isNumber(char* s){
    for(int i=0; s[i]!='\0'; i++){
        if(!isdigit(s[i])) return 0;
    }
    return 1;
}

//function to get process name from PID
char* getName(char* pid){
    char* path = (char*)malloc(sizeof(char)*30);
    strcpy(path, "/proc/");
    strcat(path, pid);
    strcat(path, "/comm");
    
    FILE* fp = fopen(path, "r");
    if(fp==NULL) return NULL;
    
    char* name = (char*)malloc(sizeof(char)*30);
    fscanf(fp, "%s", name);
    fclose(fp);
    
    return name;
}

//function to display process information
void displayProcess(char* pid){
    char* path = (char*)malloc(sizeof(char)*30);
    strcpy(path, "/proc/");
    strcat(path, pid);
    
    printf("PID: %s\n", pid);
    
    //display process name
    char* name = getName(pid);
    printf("Name: %s\n", name);
    free(name);
    
    //display process status
    strcat(path, "/status");
    FILE* fp = fopen(path, "r");
    if(fp==NULL){
        printf("Status: N/A\n");
        return;
    }
    char status[30];
    while(!feof(fp)){
        if(fscanf(fp, "%s", status)==1 && strcmp(status, "State:")==0){
            fscanf(fp, "%s", status);
            printf("Status: %s\n", status);
            break;
        }
    }
    fclose(fp);
    
    //display process memory usage
    strcat(path, "/statm");
    fp = fopen(path, "r");
    if(fp==NULL){
        printf("Memory: N/A\n");
        return;
    }
    int size;
    fscanf(fp, "%d", &size);
    printf("Memory: %d kB\n", size);
    fclose(fp);
}

int main(){
    DIR* dir = opendir("/proc");
    struct dirent* file;
    char pid[10];
    
    printf("PID       NAME               STATUS     MEMORY\n");
    while((file=readdir(dir))!=NULL){
        if(isNumber(file->d_name)){
            strcpy(pid, file->d_name);
            displayProcess(pid);
        }
    }
    closedir(dir);
    
    return 0;
}