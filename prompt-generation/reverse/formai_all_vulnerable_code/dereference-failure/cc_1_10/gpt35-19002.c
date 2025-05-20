//FormAI DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024 // maximum length of path

void print_header() {
    printf("%-10s  %-50s  %s\n", "PID", "PROCESS NAME", "STATUS");
    printf("------------------------------------------------------------\n");
}

void process_status(char status, char* result) {
    switch(status) {
        case 'R':
            strcpy(result, "Running");
            break;
        case 'S':
            strcpy(result, "Sleeping");
            break;
        case 'D':
            strcpy(result, "Waiting in Disk");
            break;
        case 'Z':
            strcpy(result, "Zombie");
            break;
        case 'T':
            strcpy(result, "Stopped");
            break;
        case 'X':
            strcpy(result, "Dead");
            break;
        default:
            strcpy(result, "Unknown");
    }
}

void get_process_list() {
    DIR* dir;
    struct dirent* entry;
    char* path = malloc(MAX_PATH_LENGTH*sizeof(char));
    
    // open the /proc directory
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    // print header
    print_header();
    
    // read the /proc directory
    while ((entry = readdir(dir)) != NULL) {
        // check if the entry is a directory
        if (entry->d_type == DT_DIR) {
            // check if the name of the directory is a number (corresponding to PID)
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                // build the full path of the status file for the process
                snprintf(path, MAX_PATH_LENGTH*sizeof(char), "/proc/%d/status", pid);
                FILE* fp = fopen(path, "r");
                if (fp == NULL) {
                    perror("Error opening file");
                    exit(EXIT_FAILURE);
                }

                // extract the process name and status from the status file
                char line[256];
                char name[256];
                char status;
                while (fgets(line, sizeof(line), fp) != NULL) {
                    if (sscanf(line, "Name:\t%s", name) == 1) {
                        name[strlen(name)-1] = '\0'; // remove the trailing colon
                    } else if (sscanf(line, "State:\t%c", &status) == 1) {
                        char* process_status_text = malloc(20*sizeof(char)); // allocate memory for the process status string
                        process_status(status, process_status_text); // translate the status character to a descriptive string
                        printf("%-10d  %-50s  %s\n", pid, name, process_status_text); // print the process information
                        free(process_status_text); // free memory for the process status string
                    }
                }

                fclose(fp);
            }
        }
    }

    free(path); // free memory for the path string
    closedir(dir);
}

int main() {
    get_process_list();
    return 0;
}