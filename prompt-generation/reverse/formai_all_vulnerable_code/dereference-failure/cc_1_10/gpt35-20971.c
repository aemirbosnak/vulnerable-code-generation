//FormAI DATASET v1.0 Category: System process viewer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

void display_process_info(char *pid) {
    char file_path[50], process_name[50], process_status[200], process_info[200], process_state;
    FILE *fp;
    sprintf(file_path, "/proc/%s/status", pid);
    fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file. Check if process exists.\n");
        return;
    }
    while (fgets(process_info, sizeof(process_info), fp)) {
        if (strncmp(process_info, "Name:", 5) == 0) {
            sscanf(process_info + 6, "%s", process_name);
        } else if (strncmp(process_info, "State:", 6) == 0) {
            sscanf(process_info + 7, "%c", &process_state);
        }
    }
    fclose(fp);
    printf("%s\t\t%c\n", process_name, process_state);
}

void get_process_list() {
    DIR *d;
    struct dirent *dir;
    char process_list[1000][10] = {0};
    int i = 0, total_processes = 0;
    d = opendir("/proc");
    if (d == NULL) {
        printf("Error: Unable to open directory.\n");
        return;
    }
    printf("Process\tStatus\n");
    while ((dir = readdir(d)) != NULL) {
        if (isdigit(*dir->d_name)) {
            strncpy(process_list[total_processes++], dir->d_name, 10);
        }
    }
    closedir(d);
    while (i < total_processes) {
        display_process_info(process_list[i++]);
    }
}

int main() {
    int option;
    printf("Welcome to Process Viewer\n");
    do {
        printf("\nChoose an option:\n1. View List of Running Processes\n2. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                get_process_list();
                break;
            case 2:
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid Option. Try Again.\n");
        }
    } while (option != 2);
    return 0;
}