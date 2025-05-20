//FormAI DATASET v1.0 Category: System process viewer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH 1024

int get_process_id(char *proc_name);
void print_process_info(int pid);
void print_process_list();

int main() {
    printf("Welcome to the Invasive Process Viewer!\n");
    while (1) {
        printf("Please choose an option:\n");
        printf("1. Get process info\n");
        printf("2. List all processes\n");
        printf("3. Exit\n");

        char input[10];
        fgets(input, 10, stdin);
        int choice = atoi(input);

        if (choice == 1) {
            printf("Please enter the process name:\n");
            char proc_name[MAX_PATH];
            fgets(proc_name, MAX_PATH, stdin);
            proc_name[strcspn(proc_name, "\n")] = 0;
            int pid = get_process_id(proc_name);
            if (pid == -1) {
                printf("Process not found. Please try again.\n");
            } else {
                print_process_info(pid);
            }
        } else if (choice == 2) {
            print_process_list();
        } else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}

int get_process_id(char *proc_name) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: could not open /proc directory.\n");
        exit(1);
    }

    int pid = -1;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0) {
            char path[MAX_PATH];
            snprintf(path, MAX_PATH, "/proc/%s/comm", entry->d_name);

            FILE *fp = fopen(path, "r");
            if (fp != NULL) {
                char buf[MAX_PATH];
                fgets(buf, MAX_PATH, fp);

                if (strcmp(buf, proc_name) == 0) {
                    pid = atoi(entry->d_name);
                }

                fclose(fp);
            }
        }
    }

    closedir(dir);

    return pid;
}

void print_process_info(int pid) {
    printf("\n== Process Info ==\n");

    char path[MAX_PATH];
    snprintf(path, MAX_PATH, "/proc/%d/stat", pid);

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error: could not open process stat file.\n");
        exit(1);
    }

    char buf[MAX_PATH];
    fgets(buf, MAX_PATH, fp);

    char *tok = strtok(buf, " ");

    int i = 1;
    while (tok != NULL) {
        if (i == 1) {
            printf("Process ID: %s\n", tok);
        } else if (i == 2) {
            printf("Process Name: %s\n", tok);
        } else if (i == 3) {
            printf("Process Status: %s\n", tok);
        } else if (i == 14) {
            printf("CPU Time: %s\n", tok);
        } else if (i == 23) {
            printf("Memory Usage: %s\n", tok);
        }
        tok = strtok(NULL, " ");
        i++;
    }

    fclose(fp);
}

void print_process_list() {
    printf("\n== Process List ==\n");

    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: could not open /proc directory.\n");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0) {
            char path[MAX_PATH];
            snprintf(path, MAX_PATH, "/proc/%s/comm", entry->d_name);

            FILE *fp = fopen(path, "r");
            if (fp != NULL) {
                char buf[MAX_PATH];
                fgets(buf, MAX_PATH, fp);
                printf("%s (%s)\n", buf, entry->d_name);
                fclose(fp);
            }
        }
    }

    closedir(dir);
}