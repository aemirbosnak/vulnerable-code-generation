//FormAI DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
/* 
 * C System Process Viewer example program 
 * Created by [Your Name]
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <dirent.h> 
#include <ctype.h> 
#include <string.h> 

#define MAX_PID_LENGTH 10 
#define MAX_PATH_LENGTH 255 

/* function declarations */ 
void print_process_info(char *pid); 
void print_cpu_info(); 

int main() { 
    DIR *dir; 
    struct dirent *ent; 

    /* Open /proc directory */ 
    dir = opendir("/proc"); 
    
    if (dir == NULL) { 
        perror("Error opening /proc directory"); 
        exit(EXIT_FAILURE); 
    } 

    /* loop through the directory */ 
    while ((ent = readdir(dir)) != NULL) { 
        /* check if this is a directory and if the name is a number (PID) */ 
        if (ent->d_type == DT_DIR && isdigit(ent->d_name[0])) { 
            print_process_info(ent->d_name); 
        } 
    } 

    /* close the directory */ 
    closedir(dir); 

    /* print CPU info */ 
    print_cpu_info(); 

    return 0; 
} 

/* function to print process information */ 
void print_process_info(char *pid) { 
    char path[MAX_PATH_LENGTH]; 
    char line[256]; 
    FILE *file; 

    /* create the path for the status file */ 
    snprintf(path, MAX_PATH_LENGTH, "/proc/%s/status", pid); 

    /* open the file */ 
    file = fopen(path, "r"); 

    if (file == NULL) { 
        perror("Error opening the status file"); 
        return; 
    } 

    /* read the file line by line */ 
    while (fgets(line, sizeof(line), file)) { 
        /* check for the process name */ 
        if (strncmp(line, "Name:", 5) == 0) { 
            printf("PID: %s\nName: %s", pid, line + 6); 
            break; 
        } 
    } 

    /* close the file */ 
    fclose(file); 
} 

/* function to print CPU information */ 
void print_cpu_info() { 
    char line[256]; 
    FILE *file; 

    /* open the file */ 
    file = fopen("/proc/cpuinfo", "r"); 

    if (file == NULL) { 
        perror("Error opening the cpuinfo file"); 
        return; 
    } 

    /* read the file line by line */ 
    while (fgets(line, sizeof(line), file)) { 
        /* check for the processor name */ 
        if (strncmp(line, "model name", 10) == 0) { 
            printf("CPU: %s", line + 13); 
            break; 
        } 
    } 

    /* close the file */ 
    fclose(file); 
}