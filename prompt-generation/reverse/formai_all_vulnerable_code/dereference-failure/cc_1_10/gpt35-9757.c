//FormAI DATASET v1.0 Category: System process viewer ; Style: Ada Lovelace
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

void printHeader() {
    printf("%-10s %-10s %-10s %-10s %-20s\n", "PID", "USER", "STATE", "PPID", "COMMAND");
    printf("------------------------------------------------------------\n");
}

void printProcessInfo(const char *pid) {
    char filename[25]; // buffer for the filename
    sprintf(filename, "/proc/%s/stat", pid);
    FILE *file = fopen(filename, "r"); // open the file
    if (!file) {
        return;
    }

    char buf[512]; // buffer for the contents of the file
    fread(buf, sizeof(char), sizeof(buf), file); // read the file into the buffer
    char *start = strstr(buf, "("); // find the start of the command name
    char *end = strstr(buf, ")"); // find the end of the command name

    char command[512]; // buffer for the command name
    strncpy(command, start + 1, end - start - 1); // copy the command name from the buffer
    command[end - start - 1] = '\0'; // null-terminate the string
    
    const char *delim = " ";
    char *token;
    char *ptr = buf;

    int i = 0;
    while ((token = strtok(ptr, delim)) && i <= 3) {
        i++;
        ptr = NULL;
        if (i == 1) {
            printf("%-10s ", token);
        }
        if (i == 3) {
            printf("%-10s ", token);
        }
        if (i == 4) {
            printf("%-10s ", token);
        }
    }

    fclose(file); // close the file

    // display the name of the command
    printf("%-20s\n", command);
}

void showProcesses() {
    DIR *dir = opendir("/proc"); // open the /proc directory
    struct dirent *entry;

    // print the header
    printHeader();

    // loop through each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        // check if the entry is a process directory
        if (entry->d_type == DT_DIR && atoi(entry->d_name) != 0) {
            // print the process information
            printProcessInfo(entry->d_name);
        }
    }

    closedir(dir); // close the directory
}

int main() {
    showProcesses();
    return 0;
}