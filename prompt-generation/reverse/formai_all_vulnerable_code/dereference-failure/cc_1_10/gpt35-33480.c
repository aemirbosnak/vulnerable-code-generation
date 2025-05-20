//FormAI DATASET v1.0 Category: System process viewer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

//Function to get the process name from the process ID
char* get_process_name(char* pid){
    char* stat_file_path = (char*)malloc(100*sizeof(char));
    strcpy(stat_file_path, "/proc/");
    strcat(stat_file_path, pid);
    strcat(stat_file_path, "/stat");
    int fd = open(stat_file_path, O_RDONLY);
    if(fd==-1){
        perror("Error in opening file");
        return "Error";
    }
    char* file_contents = (char*)malloc(1000*sizeof(char));
    read(fd, file_contents, 1000);
    char* process_name = (char*)malloc(100*sizeof(char));
    sscanf(file_contents, "%*d (%[^)])", process_name);
    return process_name;
}

//Function to get the process status from the process ID
char* get_process_status(char* pid){
    char* stat_file_path = (char*)malloc(100*sizeof(char));
    strcpy(stat_file_path, "/proc/");
    strcat(stat_file_path, pid);
    strcat(stat_file_path, "/status");
    int fd = open(stat_file_path, O_RDONLY);
    if(fd==-1){
        perror("Error in opening file");
        return "Error";
    }
    char* file_contents = (char*)malloc(1000*sizeof(char));
    read(fd, file_contents, 1000);
    char* process_status = (char*)malloc(100*sizeof(char));
    char* status_string = "State:";
    char* line_ptr;
    line_ptr = strtok(file_contents, "\n");
    while(line_ptr!=NULL){
        if(strncmp(line_ptr, status_string, strlen(status_string))==0){
            strcpy(process_status, line_ptr+strlen(status_string)+1);
            break;
        }
        line_ptr = strtok(NULL, "\n");
    }
    return process_status;
}

void print_processes(){
    DIR* proc_dir = opendir("/proc");
    if(proc_dir==NULL){
        perror("Error in opening proc directory");
        exit(1);
    }
    else{
        int count = 0;
        struct dirent* entry;
        while((entry = readdir(proc_dir)) != NULL){
            if(entry->d_type == DT_DIR && isdigit(entry->d_name[0])){
                char* pid = entry->d_name;
                char* process_name = get_process_name(pid);
                char* process_status = get_process_status(pid);
                printf("%-10s %-30s %-30s\n", pid, process_name, process_status);
            }
        }
        closedir(proc_dir);
    }
}

int main(){
    printf("%-10s %-30s %-30s\n", "PID", "PROCESS NAME", "STATUS");
    printf("-----------------------------------------------------\n");
    print_processes();
    return 0;
}