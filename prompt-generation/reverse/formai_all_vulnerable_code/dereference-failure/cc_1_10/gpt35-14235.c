//FormAI DATASET v1.0 Category: System process viewer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

// Function to remove whitespaces from a string
void remove_spaces(char* str){
    int i, j;
    for(i = 0, j = 0; str[i]; i++){
        if(!isspace(str[i])){
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to format the command string for printing
void format_command(char* command){
    remove_spaces(command);
    char* token = strtok(command, "/");
    while(token != NULL){
        strcpy(command, token);
        token = strtok(NULL, "/");
    }
}

// Function to display process information
void display_info(char* pid, char* user, char* status, char* command){
    printf("%12s %12s %12s %12s\n", pid, user, status, command);
}

int main(){
    DIR* dir;
    struct dirent* dp;
    char path[50];
    char pid[10], user[10], status[10], command[50];

    printf("Welcome to the Process Viewer!\n");

    // Display table header
    printf("\n%12s %12s %12s %12s\n", "PID", "USER", "STATUS", "COMMAND");

    // Open /proc directory
    if((dir = opendir("/proc")) == NULL){
        perror("Failed to open /proc");
        exit(1);
    }

    // Loop through all directories in /proc and display process information
    while((dp = readdir(dir)) != NULL){
        if(isdigit(dp->d_name[0])){ // Check if directory name is a number (PID)
            // Open status file for process
            sprintf(path, "/proc/%s/status", dp->d_name);
            FILE* file = fopen(path, "r");

            // Read first four lines of status file
            fgets(pid, 10, file);
            fgets(user, 10, file);
            fgets(status, 10, file);
            fgets(command, 50, file);

            // Format command string for printing
            format_command(command);

            // Display process information
            display_info(pid+4, user+6, status+7, command+6);

            fclose(file);
        }
    }
    closedir(dir);

    return 0;
}