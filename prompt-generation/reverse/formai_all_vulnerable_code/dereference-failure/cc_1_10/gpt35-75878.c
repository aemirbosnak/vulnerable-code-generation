//FormAI DATASET v1.0 Category: System process viewer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 256 // max buffer size for file reads

// function to check if the given string is a number
int is_number(char* string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (!isdigit(string[i])) {
            return 0;
        }
    }
    return 1;
}

// function to get the name of the process that corresponds to a given id
char* get_process_name(char* id) {
    char* name = (char*) malloc(sizeof(char) * BUF_SIZE);
    char path[BUF_SIZE];
    sprintf(path, "/proc/%s/cmdline", id); // cmdline file contains the name of the process

    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Error opening file %s: %s\n", path, strerror(errno));
        return "Unknown";
    }
    fgets(name, BUF_SIZE, file);
    fclose(file);

    // remove any null bytes from name (process names can be null-separated)
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == '\0') {
            name[i] = ' ';
        }
    }
    return name;
}

// function to print information about a process
void print_process_info(char* pid) {
    char path[BUF_SIZE];
    sprintf(path, "/proc/%s/stat", pid); // stat file contains various process information

    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Error opening file %s: %s\n", path, strerror(errno));
        return;
    }

    char buf[BUF_SIZE];
    fgets(buf, BUF_SIZE, file);
    fclose(file);

    char* token = strtok(buf, " "); // split the contents of stat file by space separator
    int count = 0;
    while (token != NULL && count < 23) {
        switch (count) {
            case 0: printf("%5s ", token); break; // pid
            case 1: printf("%6s ", get_process_name(pid)); break; // name
            case 2: printf("%c    ", token[0]); break; // status
            case 13: printf("%6s ", token); break; // utime
            case 14: printf("%6s ", token); break; // stime
            case 21: printf("%7s\n", token); break; // rss
        }
        token = strtok(NULL, " ");
        count++;
    }
}

// main function
int main() {
    printf("%5s %6s %s %6s %6s %7s\n", "PID", "NAME", "ST", "UTIME", "STIME", "RSS");
    struct dirent *dp;
    DIR *dir = opendir("/proc");

    if (!dir) {
        printf("Error opening directory /proc: %s\n", strerror(errno));
        exit(1);
    }

    while ( (dp=readdir(dir)) != NULL ) {
        if (is_number(dp->d_name)) {
            print_process_info(dp->d_name);
        }
    }

    closedir(dir);
    return 0;
}