//FormAI DATASET v1.0 Category: System process viewer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

// Struct to hold process information
typedef struct {
    int pid;
    char status;
    int parent_pid;
    char name[256];
} Process;

// Function to parse integer from string
int parseInt(char* str) {
    int num = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            num = num * 10 + (str[i] - '0');
        }
    }
    return num;
}

// Function to read process information from proc filesystem
Process readProcessInfo(char* pid) {
    Process p;

    char filename[256];
    sprintf(filename, "/proc/%s/stat", pid);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char buffer[1024];
    fgets(buffer, 1024, fp);

    // Parsing information from stat file
    char* token = strtok(buffer, " ");
    p.pid = parseInt(token);

    token = strtok(NULL, " ");
    strcpy(p.name, token);

    token = strtok(NULL, " ");
    p.status = token[0];

    for (int i = 2; i < 14; i++) {
        token = strtok(NULL, " ");
    }

    token = strtok(NULL, " ");
    p.parent_pid = parseInt(token);

    fclose(fp);
    return p;
}

// Function to print process information
void printProcessInfo(Process p) {
    printf("%-10d%-15d%-15c%-30s\n", p.pid, p.parent_pid, p.status, p.name);
}

// Function to remove character from a string
void removeChar(char* str, char c) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            for (int j = i; j < len - 1; j++) {
                str[j] = str[j + 1];
            }
            len--;
            i--;
        }
    }
    str[len] = '\0';
}

// Function to get all process ids from proc filesystem
char** getPids() {
    DIR* dir = opendir("/proc");
    if (dir == NULL) {
        printf("Could not access proc filesystem\n");
        exit(1);
    }

    char** pid_list = (char**)malloc(1024 * sizeof(char*));
    int count = 0;

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            pid_list[count] = strdup(entry->d_name);
            count++;
        }
    }

    closedir(dir);
    pid_list[count] = NULL;
    return pid_list;
}

int main() {
    char** pid_list = getPids();

    printf("%-10s%-15s%-15s%-30s\n", "PID", "Parent PID", "Status", "Name");
    for (int i = 0; pid_list[i] != NULL; i++) {
        Process p = readProcessInfo(pid_list[i]);
        printProcessInfo(p);
    }

    for (int i = 0; pid_list[i] != NULL; i++) {
        free(pid_list[i]);
    }
    free(pid_list);

    return 0;
}