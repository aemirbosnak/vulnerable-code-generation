//FormAI DATASET v1.0 Category: System process viewer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PROCESS 1024
#define MAX_PATH 1024
#define MAX_BUFFER 1024

typedef struct{
    char name[256];
    int pid;
    char state[2];
    float cpu_usage;
} process_t;

// Get the total number of system processes
int get_num_process(){
    int count = 0;
    DIR *dir;
    struct dirent *entry;

    if((dir = opendir("/proc")) == NULL){
        fprintf(stderr, "Error: Cannot open /proc directory\n");
        exit(EXIT_FAILURE);
    }

    while((entry = readdir(dir)) != NULL){
        if(isdigit(*entry->d_name)){
            count++;
        }
    }

    closedir(dir);
    return count;
}

// Read process information from the /proc directory
void read_process_info(process_t *processes, int num_process){
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH];
    char buffer[MAX_BUFFER];
    FILE *fp;
    int i, j;
    char c;

    for(i = 0; i < num_process; i++){
        sprintf(path, "/proc/%d/stat", processes[i].pid);
        if((fp = fopen(path, "r")) == NULL){
            fprintf(stderr, "Error: Cannot open file %s\n", path);
            exit(EXIT_FAILURE);
        }

        j = 0;
        while((c = fgetc(fp)) != EOF){
            if(c == ' '){
                j++;
            }
            else if(j == 1){
                processes[i].state[0] = c;
            }
            else if(j == 13){
                processes[i].cpu_usage = atof(fgets(buffer, MAX_BUFFER, fp));
                break;
            }
        }

        fclose(fp);
    }
}

// Sort processes by CPU usage in descending order
void sort_by_cpu_usage(process_t *processes, int num_process){
    int i, j;
    process_t temp;

    for(i = 0; i < num_process; i++){
        for(j = 0; j < num_process - i - 1; j++){
            if(processes[j].cpu_usage < processes[j+1].cpu_usage){
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

int main(){
    int num_process;
    int i;

    num_process = get_num_process();

    process_t *processes = (process_t*) malloc(num_process * sizeof(process_t));
    if(processes == NULL){
        fprintf(stderr, "Error: Cannot allocate memory for processes\n");
        exit(EXIT_FAILURE);
    }

    DIR *dir;
    struct dirent *entry;

    if((dir = opendir("/proc")) == NULL){
        fprintf(stderr, "Error: Cannot open /proc directory\n");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while((entry = readdir(dir)) != NULL){
        if(isdigit(*entry->d_name)){
            processes[i].pid = atoi(entry->d_name);

            sprintf(processes[i].name, "/proc/%d/cmdline", processes[i].pid);
            int fd = open(processes[i].name, O_RDONLY);
            if(fd != -1){
                read(fd, processes[i].name, sizeof(processes[i].name)-1);
                close(fd);
                for(int j = 0; j < strlen(processes[i].name); j++){
                    if(processes[i].name[j] == '\0'){
                        processes[i].name[j] = ' ';
                    }
                }
            }

            sprintf(processes[i].name, "%s [%d]", processes[i].name, processes[i].pid);

            processes[i].state[1] = '\0';

            i++;
        }
    }

    read_process_info(processes, num_process);
    sort_by_cpu_usage(processes, num_process);

    printf("%-20s %-10s %s\n", "Process Name", "PID", "CPU Usage");
    for(i = 0; i < num_process; i++){
        printf("%-20s %-10d %.2f%%\n", processes[i].name, processes[i].pid, processes[i].cpu_usage);
    }

    free(processes);
    closedir(dir);
    return 0;
}