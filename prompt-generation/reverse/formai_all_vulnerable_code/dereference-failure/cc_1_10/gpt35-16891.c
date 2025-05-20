//FormAI DATASET v1.0 Category: System process viewer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

/* Function to check if string contains only digits */
int isNumber(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

/* Function to read contents of a file */
void readFile(char *filename, char *buffer) {
    FILE *fp;
    char ch;
    int i = 0;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) {
        buffer[i] = ch;
        i++;
    }
    fclose(fp);
}

/* Function to get process information from procfs */
void printProcessInfo(char *pid) {
    char path[50];
    char buffer[1024];
    char *token;
    strcpy(path, "/proc/");
    strcat(path, pid);
    strcat(path, "/stat");
    readFile(path, buffer);
    token = strtok(buffer, " ");
    printf("PID: %s\n", token);
    token = strtok(NULL, " ");
    printf("Command: %s\n", token);
    token = strtok(NULL, " ");
    printf("Status: %s\n", token);
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    printf("Memory Usage: %s\n", token);
    printf("--------------------\n");
}

/* Main function */
int main() {
    DIR *d;
    struct dirent *dir;
    char pid[10];
    printf("List of running processes: \n");
    d = opendir("/proc");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (isNumber(dir->d_name)) {
                strcpy(pid, dir->d_name);
                printProcessInfo(pid);
            }
        }
        closedir(d);
    }
    return 0;
}