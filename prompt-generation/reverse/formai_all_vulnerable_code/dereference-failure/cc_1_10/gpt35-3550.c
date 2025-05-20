//FormAI DATASET v1.0 Category: System process viewer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void printHeader() {
    printf("\n\n--------------------------------------------\n");
    printf("\tWelcome to the C System Process Viewer\n");
    printf("--------------------------------------------\n\n");
}

void printProcessDetails(char* pid, char* name, char* status, char* memory) {
    printf("%-10s %-20s %-10s %-10s\n", pid, name, status, memory);
}

int main(int argc, char* argv[]) {
    DIR* proc = opendir("/proc");
    struct dirent* entry;
    char* pid;
    char* name;
    char* status;
    char* memory;
    char path[100];
    char line[100];
    FILE* statusFile;
    long int memoryLong;

    // Check if the /proc folder could be opened
    if (proc == NULL) {
        printf("An error occurred while trying to open the /proc folder\n");
        return 0;
    }

    // Print the header of the program
    printHeader();

    // Print the headers of the table with process details
    printf("%-10s %-20s %-10s %-10s\n", "PID", "Name", "Status", "Memory");

    // Loop through all the entries in the /proc folder
    while ((entry = readdir(proc)) != NULL) {
        if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0) {
            pid = entry->d_name;
            strcpy(path, "/proc/");
            strcat(path, pid);
            strcat(path, "/status");
            statusFile = fopen(path, "r");
            if (statusFile != NULL) {
                while(fgets(line, sizeof(line), statusFile)) {
                    if(strncmp(line, "Name:", 5) == 0) {
                        name = strchr(line, '\t') + 1;
                        name[strlen(name) - 1] = '\0';
                    } else if(strncmp(line, "State:", 6) == 0) {
                        status = strchr(line, '\t') + 1;
                        status[strlen(status) - 1] = '\0';
                    } else if(strncmp(line, "VmRSS:", 6) == 0) {
                        memoryLong = atol(strchr(line, '\t') + 1);
                        memoryLong = memoryLong / 1024;
                        memory = malloc(sizeof(char) * 20);
                        sprintf(memory, "%ld KB", memoryLong);
                    }
                }
                fclose(statusFile);
                printProcessDetails(pid, name, status, memory);
                free(memory);
            }
        }   
    }

    closedir(proc);

    return 0;
}