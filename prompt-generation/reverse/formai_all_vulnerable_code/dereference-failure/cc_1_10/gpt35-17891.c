//FormAI DATASET v1.0 Category: System process viewer ; Style: retro
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define PROCESS_PATH "/proc/"

void printHeader(){
    printf("+--------------------------------------------------------------------+\n");
    printf("| PID | Name                         | Status | Memory | Priority    |\n");
    printf("+--------------------------------------------------------------------+\n");
}

void printProcessInfo(char* pid){
    // Open the necessary files for process information
    char status_path[100];
    char meminfo_path[100];
    char statm_path[100];
    char cmd_path[100];
    char name[100];

    sprintf(status_path, "%s%s/status", PROCESS_PATH, pid);
    sprintf(meminfo_path, "%s%s/smaps", PROCESS_PATH, pid);
    sprintf(statm_path, "%s%s/statm", PROCESS_PATH, pid);
    sprintf(cmd_path, "%s%s/cmdline", PROCESS_PATH, pid);

    FILE* status_file = fopen(status_path, "r");
    FILE* meminfo_file = fopen(meminfo_path, "r");
    FILE* statm_file = fopen(statm_path, "r");
    FILE* cmdline_file = fopen(cmd_path, "r");

    // If any of the files failed to open, print error message and return
    if (!status_file || !meminfo_file || !statm_file || !cmdline_file){
        printf("| Error: Could not read process info for %s.\n", pid);
        return;
    }

    // Extract information from the "status" file
    while (fgets(name, 100, status_file)){
        if (strstr(name, "Name:")){
            strtok(name, "\t");
            char* process_name = strtok(NULL, "\n");
            printf("| %4s | %-28s |", pid, process_name);
            break;
        }
    }

    // Extract information from the "statm" file
    int size, resident, shared, text, lib, data, dt;
    fscanf(statm_file, "%d %d %d %d %d %d %d", &size, &resident, &shared, &text, &lib, &data, &dt);

    // Extract information from the "smaps" file
    long long pss_total = 0;
    char smaps_line[200];
    while (fgets(smaps_line, 200, meminfo_file)){
        if (strstr(smaps_line, "Pss:")){
            strtok(smaps_line, " \t");
            char* pss_str = strtok(NULL, " \t");
            long long pss = atoll(pss_str);
            pss_total += pss;
        }
    }

    // Calculate and print memory usage information
    int mem_kb = (int)(pss_total / 1024);
    printf(" %-6d | %-10d |\n", mem_kb, size);

    fclose(status_file);
    fclose(meminfo_file);
    fclose(statm_file);
    fclose(cmdline_file);
}

void listProcesses(){

    struct dirent *dp;
    DIR *dir = opendir(PROCESS_PATH);

    //If directory can not be opened, print error and return
    if (!dir){
        printf("Error: Unable to open process directory.\n");
        return;
    }

    printHeader();

    while ((dp = readdir(dir)) != NULL){
        char* pid = dp->d_name;

        //Ignore directories that are not numeric
        if (atoi(pid) <= 0){
            continue;
        }

        printProcessInfo(pid);
    }

    closedir(dir);
}


int main(){
    while(true){
        printf("\033[H\033[J"); // Clear the console
        printf("Current processes:\n");
        listProcesses();
        sleep(1);
    }
    return 0;
}