//FormAI DATASET v1.0 Category: System process viewer ; Style: light-weight
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*Function to print the process info*/
void printProcessInfo(char* pid, char* name, char* status, char* memory) {
    printf("%-10s\t%-20s\t%-10s\t%-10s\n", pid, name, status, memory);
}

int main() {
    DIR* directory = opendir("/proc"); //Open the Linux proc directory
    struct dirent* file;
    char* line = NULL;
    size_t len = 0;
    
    printf("%-10s\t%-20s\t%-10s\t%-10s\n", "PID", "Name", "Status", "Memory"); //Print the header
    
    while((file = readdir(directory)) != NULL) {

        /*Check if the file is a directory and its name is a number*/
        if(file->d_type == DT_DIR && isdigit(file->d_name[0])) {
            char* pid = file->d_name;
            char* statusPath = malloc(snprintf(NULL, 0, "/proc/%s/status", pid) + 1);
            sprintf(statusPath, "/proc/%s/status", pid); //Get the status file path
            
            FILE* statusFile = fopen(statusPath, "r"); //Open the status file
            if(statusFile) {
                /*Read the status file and extract the necessary information*/
                while(getline(&line, &len, statusFile) != -1) {
                    if(strncmp(line, "Name:", 5) == 0) {
                        char* name = line + 6;
                        name[strlen(name) - 1] = '\0'; //Remove the newline character
                        char* memoryPath = malloc(snprintf(NULL, 0, "/proc/%s/statm", pid) + 1);
                        sprintf(memoryPath, "/proc/%s/statm", pid); //Get the memory file path
                        
                        FILE* memoryFile = fopen(memoryPath, "r"); //Open the memory file
                        if(memoryFile) {
                            /*Read the memory file and extract the necessary information*/
                            int memoryInKB;
                            fscanf(memoryFile, "%d", &memoryInKB);
                            memoryInKB *= getpagesize() / 1024;
                            char* memory = malloc(snprintf(NULL, 0, "%d", memoryInKB) + 1);
                            sprintf(memory, "%d", memoryInKB);
                            fclose(memoryFile);
                            
                            char* status = strtok(line, " ");
                            status = strtok(NULL, " ");
                            printProcessInfo(pid, name, status, memory);
                        }
                        free(memoryPath);
                    }
                }
                fclose(statusFile);
            }
            free(statusPath);
        }
    }
    free(line);
    closedir(directory);
    return 0;
}