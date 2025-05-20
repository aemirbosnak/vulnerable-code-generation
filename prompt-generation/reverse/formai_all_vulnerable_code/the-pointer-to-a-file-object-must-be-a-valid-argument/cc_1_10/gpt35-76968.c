//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//defining maximum number of processes
#define MAX_PROCESSES 50
#define BUFFER_SIZE 1024

//structure to hold process details
typedef struct Process {
    int pid;
    char name[BUFFER_SIZE];
    int cpu_time;
} Process;

int main() {
    //create an array to hold process details
    Process processes[MAX_PROCESSES];
    
    //initialize array with zero
    memset(processes, 0, sizeof(processes));
    
    //get number of processors
    int num_processors = sysconf(_SC_NPROCESSORS_ONLN);
    
    //create a buffer to hold command output
    char command_output[BUFFER_SIZE];
    
    //initialize loop counter
    int i = 0;
    
    //create a time structure to hold current time
    time_t current_time;
    
    //define the time format to use
    char* time_format = "%Y-%m-%d %H:%M:%S";
    
    //get initial time
    time(&current_time);
    
    //display initial time
    printf("Monitoring CPU Usage at %s\n\n", ctime(&current_time));
    
    //start monitoring CPU usage
    while(1) {
        //get process list
        FILE* process_list = popen("ps -Ao pid,args,pcpu | tail -n +2", "r");
        
        //initialize process count
        int process_count = 0;
        
        //iterate through the output of ps command and store process details in array
        while(fgets(command_output, BUFFER_SIZE, process_list)) {
            //get pid, name and cpu time from command output
            int pid;
            char name[BUFFER_SIZE];
            double cpu_time;
            sscanf(command_output, "%d %[^\n] %lf", &pid, name, &cpu_time);
            
            //remove leading and trailing whitespaces from process name
            char* process_name = name;
            while(isspace(*process_name)) process_name++;
            char* end = process_name + strlen(process_name) - 1;
            while(end > process_name && isspace(*end)) end--;
            *(end+1) = '\0';
            
            //store process details in array
            processes[process_count].pid = pid;
            strncpy(processes[process_count].name, process_name, BUFFER_SIZE);
            processes[process_count].cpu_time = (int)(cpu_time * 100);
            
            //increment process count
            process_count++;
        }
        
        //close process list
        pclose(process_list);
        
        //sort the array of processes by highest CPU usage
        int j, k;
        for(j = 0; j < process_count; j++) {
            for(k = j+1; k < process_count; k++) {
                if(processes[k].cpu_time > processes[j].cpu_time) {
                    Process temp = processes[j];
                    processes[j] = processes[k];
                    processes[k] = temp;
                }
            }
        }
        
        //get current time
        time(&current_time);
        
        //display the current time
        printf("CPU usage at %s\n", ctime(&current_time));
        
        //iterate through the sorted array and display process details
        for(i = 0; i < process_count; i++) {
            printf("%d. %s (PID %d): %d%%\n", i+1, processes[i].name, processes[i].pid, processes[i].cpu_time);
        }
        
        //wait for 5 seconds before repeating
        sleep(5);
    }
    
    return 0;
}