//FormAI DATASET v1.0 Category: System process viewer ; Style: relaxed
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<ctype.h>
#include<unistd.h>

// function declarations
void print_proc_info(char *pid);

// main function
int main(){
    DIR *dir;
    struct dirent *entry;
    char pid[10];

    // Open directory /proc
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    // Loop through all the files and directories inside /proc
    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(*entry->d_name)) {
            continue;
        }
        strcpy(pid, entry->d_name);
        print_proc_info(pid);
        printf("\n");
    }

    // Close directory
    closedir(dir);

    return 0;
}

// function to print process information
void print_proc_info(char *pid){
    char path[50], buffer[1000];
    FILE *fp;

    // concatenate /proc/pid/status to get the status file path
    sprintf(path, "/proc/%s/status", pid);

    // Open the status file in read mode
    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error opening file /proc/%s/status", pid);
        return;
    }

    // Loop through the status file and print the required information
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strncmp("Name:", buffer, 5) == 0) {
            printf("Name:\t%s", buffer + 6);
        }
        if (strncmp("State:", buffer, 6) == 0) {
            printf("State:\t%s", buffer + 7);
        }
        if (strncmp("PPid:", buffer, 5) == 0) {
            printf("PPid:\t%s", buffer + 6);
        }
    }

    // Close the file
    fclose(fp);
}