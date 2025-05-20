//FormAI DATASET v1.0 Category: System process viewer ; Style: satisfied
// C System Process Viewer example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

// Define struct to hold process information
typedef struct {
    char name[100];
    int pid;
    int ppid;
    int status;
} Process;

// Define function to get name of process by pid
char* get_process_name(int pid) {
    char* name = (char*)malloc(100);
    snprintf(name, 100, "/proc/%d/cmdline", pid);
    FILE* f = fopen(name, "r");
    if(f == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char buffer[100];
    fgets(buffer, sizeof(buffer), f);
    fclose(f);
    // Replace null characters with spaces
    for(int i=0; buffer[i]!='\0'; i++) {
        if(buffer[i] == '\0') {
            buffer[i] = ' ';
        }
    }
    strcpy(name, buffer);
    return name;
}

int main() {
    // Open the /proc directory
    DIR* dir = opendir("/proc");
    if(dir == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }
    // Loop through each file in the directory
    struct dirent *entry;
    while((entry = readdir(dir)) != NULL) {
        // Check if it is a directory and the name only contains digits
        if(entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            // Open the status file for the process
            char filename[100];
            snprintf(filename, 100, "/proc/%d/status", pid);
            FILE* f = fopen(filename, "r");
            if(f == NULL) {
                perror("Error opening file");
                exit(EXIT_FAILURE);
            }
            // Read the contents of the file
            char buffer[100];
            while(fgets(buffer, sizeof(buffer), f)) {
                // Check if it is the name of the process
                if(strncmp(buffer, "Name:", 5) == 0) {
                    char name[100];
                    sscanf(buffer+6, "%s", name);
                    // Create a Process object and set the name and PID
                    Process p;
                    strcpy(p.name, name);
                    p.pid = pid;
                    // Get the parent PID
                    char parent[100];
                    while(fgets(buffer, sizeof(buffer), f)) {
                        if(strncmp(buffer, "PPid:", 5) == 0) {
                            sscanf(buffer+6, "%s", parent);
                            p.ppid = atoi(parent);
                            break;
                        }
                    }
                    // Get the status of the process
                    char status[100];
                    snprintf(filename, 100, "/proc/%d/stat", pid);
                    FILE* s = fopen(filename, "r");
                    if(s == NULL) {
                        perror("Error opening file");
                        exit(EXIT_FAILURE);
                    }
                    fgets(buffer, sizeof(buffer), s);
                    sscanf(buffer, "%*d %*s %s", status);
                    if(status[0] == 'S') {
                        p.status = 1; // Running
                    } else {
                        p.status = 0; // Sleeping
                    }
                    fclose(s);
                    // Print the process information
                    printf("%s %d %d %d\n", p.name, p.pid, p.ppid, p.status);
                    break;
                }
            }
            fclose(f);
        }
    }
    closedir(dir);
    return 0;
}