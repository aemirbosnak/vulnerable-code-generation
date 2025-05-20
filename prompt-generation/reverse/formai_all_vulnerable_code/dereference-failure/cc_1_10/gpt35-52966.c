//FormAI DATASET v1.0 Category: System process viewer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a valid number
int is_number(char *str) {
    for(int i = 0; str[i]; i++) {
        if(!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Get the name of a process given its PID
void get_process_name(char *pid, char *name) {
    char path[50];
    sprintf(path, "/proc/%s/comm", pid);
    FILE *file = fopen(path, "r");
    if(file) {
        fgets(name, 20, file); // Read up to 20 characters from the file
        fclose(file);
        // Remove newline character at the end of the name
        int length = strlen(name);
        if(length > 0 && name[length-1] == '\n') {
            name[length-1] = '\0';
        }
    } else {
        strcpy(name, "unknown");
    }
}

// Print information about a process given its PID
void print_process_info(char *pid) {
    char name[20];
    get_process_name(pid, name);

    char path[50];
    sprintf(path, "/proc/%s/stat", pid);
    FILE *file = fopen(path, "r");
    if(file) {
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        if((read = getline(&line, &len, file)) != -1) {
            // Extract the values we are interested in from the stat file
            char *token = strtok(line, " ");
            int i = 1;
            char *values[20];
            while(token != NULL && i < 23) {
                values[i-1] = token;
                token = strtok(NULL, " ");
                i++;
            }
            if(i >= 23) {
                values[22][strlen(values[22])-1] = '\0'; // Remove ")" from the end
            }

            // Print the information
            printf("%-10s %-15s %-10s %-10s %-10s %-10s %-10s\n",
                    pid, name, values[1], values[2], values[13], values[14], values[21]);
        }
        free(line);
        fclose(file);
    }
}

int main() {
    printf("%-10s %-15s %-10s %-10s %-10s %-10s %-10s\n",
            "PID", "NAME", "STATE", "PPID", "UTIME", "STIME", "VMEM");
    DIR *dir = opendir("/proc/");
    if(dir) {
        struct dirent *entry;
        while((entry = readdir(dir)) != NULL) {
            if(is_number(entry->d_name)) {
                print_process_info(entry->d_name);
            }
        }
        closedir(dir);
    }
    return 0;
}