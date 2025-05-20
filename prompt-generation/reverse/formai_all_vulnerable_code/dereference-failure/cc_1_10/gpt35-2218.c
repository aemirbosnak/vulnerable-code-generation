//FormAI DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
/* 
A C System process viewer program in the style of Ken Thompson. 
Displays currently running system processes.

Author: [Your Name]

Date: [Date]

*/

#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 1024

void printHeader();
void printProcessInfo(char *pid);
int checkIfNumber(char *str);

int main() {
    DIR *dir;
    struct dirent *ent;
    char buf[BUFSIZE];
    dir = opendir("/proc"); // open /proc directory
    if (dir == NULL) { // if directory cannot be opened, print error message and exit
        perror("Cannot open /proc directory");
        exit(EXIT_FAILURE);
    }

    printHeader(); // print header for process viewer

    while ((ent = readdir(dir)) != NULL) { // loop through /proc directory
        if (checkIfNumber(ent->d_name)) { // check if directory name is a number
            printProcessInfo(ent->d_name); // print process information
        }
    }

    closedir(dir); // close /proc directory
    return 0;
}

void printHeader() {
    printf("%-10s%-30s%-15s\n", "PID", "Name", "Status/State"); // print header row for process viewer
}

void printProcessInfo(char *pid) {
    FILE *fp;
    char buf[BUFSIZE], status_file[BUFSIZE], name[BUFSIZE], state[BUFSIZE];
    sprintf(status_file, "/proc/%s/status", pid); // construct path to process status file
    fp = fopen(status_file, "r"); // open process status file
    if (fp == NULL) { // if file cannot be opened, print error message and exit
        printf("Unable to open status file for process %s\n", pid);
        return;
    }

    while (fgets(buf, BUFSIZE, fp) != NULL) { // read process status file line by line
        if (strncmp(buf, "Name:", 5) == 0) { // if line starts with "Name:", extract process name
            sscanf(buf+5, "%s", name);
        }
        if (strncmp(buf, "State:", 6) == 0) { // if line starts with "State:", extract process state
            sscanf(buf+6, "%s", state);
        }
    }

    fclose(fp); // close process status file

    // print process information in table format
    printf("%-10s%-30s%-15s\n", pid, name, state);
}

int checkIfNumber(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) { // loop through characters in string
        if (!isdigit(str[i])) { // if character is not a digit, return false
            return 0;
        }
    }
    return 1; // return true if all characters in string are digits
}