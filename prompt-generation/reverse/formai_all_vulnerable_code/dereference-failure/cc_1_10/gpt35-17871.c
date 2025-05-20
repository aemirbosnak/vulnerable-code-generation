//FormAI DATASET v1.0 Category: System process viewer ; Style: immersive
#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>

#define MAX_SIZE 1024

/*Struct to hold information about processes*/
typedef struct{
    char pid[10];
    char name[MAX_SIZE];
    char state[10];
    char mem[MAX_SIZE];
    char time[MAX_SIZE];
}ProcessInfo;

/*Function to check if a string only contains digits*/
int isAllDigits(char *str){
    int i=0;
    while(str[i]!='\0'){
        if(!isdigit(str[i])){
            return 0;
        }
        i++;
    }
    return 1;
}

/*Function to get the name of a process given its pid*/
char* getProcessName(char* pid){
    FILE *cmd;
    static char cmd_str[MAX_SIZE];
    char line[MAX_SIZE];
    char* name = malloc(MAX_SIZE*sizeof(char));
    sprintf(cmd_str,"/proc/%s/status", pid);
    cmd = fopen(cmd_str,"r");
    if(cmd!=NULL){
        while(fgets(line,sizeof(line),cmd)!=NULL){
            /*Find the line with the process name*/
            if(strncmp(line,"Name:",5) == 0){
                sscanf(line,"%*s %s",name);
                break;
            }
        }
    }
    fclose(cmd);
    return name;
}

/*Function to get the memory usage of a process given its pid*/
char* getProcessMem(char* pid){
    FILE *cmd;
    static char cmd_str[MAX_SIZE];
    char line[MAX_SIZE];
    char* mem = malloc(MAX_SIZE*sizeof(char));
    sprintf(cmd_str,"/proc/%s/status", pid);
    cmd = fopen(cmd_str,"r");
    if(cmd!=NULL){
        while(fgets(line,sizeof(line),cmd)!=NULL){
            /*Find the line with the memory usage*/
            if(strncmp(line,"VmRSS:",6) == 0){
                sscanf(line,"%*s %s",mem);
                strcat(mem," KiB");
                break;
            }
        }
    }
    fclose(cmd);
    return mem;
}

/*Function to get the state of a process given its pid*/
char* getProcessState(char* pid){
    FILE *cmd;
    static char cmd_str[MAX_SIZE];
    char line[MAX_SIZE];
    char* state = malloc(MAX_SIZE*sizeof(char));
    sprintf(cmd_str,"/proc/%s/status", pid);
    cmd = fopen(cmd_str,"r");
    if(cmd!=NULL){
        while(fgets(line,sizeof(line),cmd)!=NULL){
            /*Find the line with the state*/
            if(strncmp(line,"State:",6) == 0){
                sscanf(line,"%*s %s",state);
                break;
            }
        }
    }
    fclose(cmd);
    return state;
}

/*Function to get the time at which a process was started given its pid*/
char* getProcessStartTime(char* pid){
    FILE *cmd;
    static char cmd_str[MAX_SIZE];
    char line[MAX_SIZE];
    char* start_time = malloc(MAX_SIZE*sizeof(char));
    sprintf(cmd_str,"/proc/%s/stat", pid);
    cmd = fopen(cmd_str,"r");
    if(cmd!=NULL){
        fgets(line,sizeof(line),cmd);
        sscanf(line,"%*d %s",start_time);
    }
    fclose(cmd);
    return start_time;
}

/*Function to get the current system time*/
char* getCurrentTime(){
    time_t rawtime;
    struct tm * timeinfo;
    char* time_str = malloc(MAX_SIZE*sizeof(char));
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(time_str,MAX_SIZE,"%H:%M:%S",timeinfo);
    return time_str;
}

/*Function to print the process information*/
void printProcessInfo(ProcessInfo* pid_info){
    printf("%-10s %-20s %-10s %-20s %-20s\n",pid_info->pid,pid_info->name,pid_info->state,pid_info->mem,pid_info->time);
}

/*Function to get the process information from the system*/
void getProcessInfo(){
    DIR* proc = opendir("/proc");
    struct dirent* entry;
    ProcessInfo pid_info;
    printf("%-10s %-20s %-10s %-20s %-20s\n","PID","PROCESS NAME","STATE","MEMORY USAGE","START TIME");
    while((entry = readdir(proc)) != NULL){
        /*Check if entry name is a directory and contains only digits*/
        if(entry->d_type == DT_DIR && isAllDigits(entry->d_name)){
            strcpy(pid_info.pid,entry->d_name);
            strcpy(pid_info.name,getProcessName(pid_info.pid));
            strcpy(pid_info.mem,getProcessMem(pid_info.pid));
            strcpy(pid_info.state,getProcessState(pid_info.pid));
            strcpy(pid_info.time,getProcessStartTime(pid_info.pid));
            strcat(pid_info.time,"\t");
            strcat(pid_info.time,getCurrentTime());
            printProcessInfo(&pid_info);
        }
    }
    closedir(proc);
}

int main(){
    while(1){
        printf("********** SYSTEM PROCESS VIEWER **********\n");
        printf("*******************************************\n");
        printf("PID\t PROCESS NAME\t\t STATE\t MEMORY USAGE\t START TIME\n");
        printf("*******************************************\n");
        getProcessInfo();
        printf("\n\n");
        /*Wait for 1 second*/
        sleep(1);
        /*Clear the console*/
        system("clear");
    }
    return 0;
}