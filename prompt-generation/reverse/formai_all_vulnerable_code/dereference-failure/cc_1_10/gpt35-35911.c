//FormAI DATASET v1.0 Category: System process viewer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to check if the given string represents a number
int is_number(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to read the specified file and return the value as a string
char* read_file(const char* file_path) {
    FILE* fp;
    char* buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE);
    char* result = (char*)malloc(sizeof(char) * BUFFER_SIZE);
    int count = 0;

    fp = fopen(file_path, "r");
    if (fp == NULL) {
        return NULL;
    }

    while (fgets(buffer, BUFFER_SIZE, fp)) {
        count += strlen(buffer);
        strcat(result, buffer);
    }

    fclose(fp);
    free(buffer);

    return result;
}

void print_process_info(const char* pid) {
    char* stat_file_path = (char*)malloc(sizeof(char) * BUFFER_SIZE);
    snprintf(stat_file_path, BUFFER_SIZE, "/proc/%s/stat", pid);

    char* stat = read_file(stat_file_path);
    if (stat == NULL) {
        printf("Error: Could not read file /proc/%s/stat\n", pid);
        return;
    }

    char* token = strtok(stat, " ");
    int count = 1;
    while (token != NULL) {
        switch (count) {
            case 1:
                printf("PID: %s\n", token);
                break;
            case 2:
                printf("Name: %s\n", token);
                break;
            case 3:
                printf("State: %s\n", token);
                break;
            case 14:
                printf("CPU time: %d\n", atoi(token));
                break;
            case 24:
                printf("Resident set size: %ld\n", atol(token));
                break;
            default:
                break;
        }
        token = strtok(NULL, " ");
        count++;
    }

    free(stat);
    free(stat_file_path);
}

void list_processes() {
    DIR* dir;
    struct dirent* entry;

    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: Could not open directory /proc\n");
        return;
    }

    printf("%-10s%-20s%-10s\n", "PID", "Name", "State");

    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            char* stat_file_path = (char*)malloc(sizeof(char) * BUFFER_SIZE);
            snprintf(stat_file_path, BUFFER_SIZE, "/proc/%s/stat", entry->d_name);
            if (access(stat_file_path, F_OK) != -1) {
                char* stat = read_file(stat_file_path);
                if (stat != NULL) {
                    char* token = strtok(stat, " ");
                    int count = 1;
                    char* name = (char*)malloc(sizeof(char) * BUFFER_SIZE);
                    while (token != NULL) {
                        if (count == 2) {
                            snprintf(name, BUFFER_SIZE, "%s", token + 1);
                        } else if (count == 3) {
                            printf("%-10s%-20s%-10s\n", entry->d_name, name, token);
                            break;
                        }
                        token = strtok(NULL, " ");
                        count++;
                    }
                    free(stat);
                    free(name);
                }
            }
            free(stat_file_path);
        }
    }

    closedir(dir);
}

int main() {
    char* command = (char*)malloc(sizeof(char) * BUFFER_SIZE);
    char* pid = (char*)malloc(sizeof(char) * BUFFER_SIZE);

    printf("Welcome to the process viewer!\n");
    printf("Enter \"list\" to see the list of running processes.\n");
    printf("Enter a PID to see more information about a specific process.\n");
    printf("Enter \"quit\" to exit the program.\n");

    while (1) {
        printf("\n> ");
        fgets(command, BUFFER_SIZE, stdin);
        command[strlen(command) - 1] = '\0'; // remove the newline character

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "list") == 0) {
            list_processes();
        } else if (is_number(command)) {
            strcpy(pid, command);
            printf("\nInformation for process %s:\n", pid);
            print_process_info(pid);
        } else {
            printf("Error: Invalid command\n");
        }
    }

    free(command);
    free(pid);

    return 0;
}