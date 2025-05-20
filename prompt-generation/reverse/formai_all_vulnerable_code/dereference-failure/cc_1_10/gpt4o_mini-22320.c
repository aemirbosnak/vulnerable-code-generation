//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define PROC_PATH "/proc"
#define BUFFER_SIZE 256

void list_processes();
void display_process_info(const char* pid);
char* get_status_field(const char* pid, const char* field_name);
int get_integer_field(const char* pid, const char* field_name);

int main() {
    while (1) {
        int option;
        printf("\n--- Process Viewer ---\n");
        printf("1. List All Processes\n");
        printf("2. View Process Info\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                list_processes();
                break;
            case 2: {
                char pid[BUFFER_SIZE];
                printf("Enter PID: ");
                scanf("%s", pid);
                if (isdigit(pid[0])) {
                    display_process_info(pid);
                } else {
                    printf("Invalid PID! Please enter numeric values only.\n");
                }
                break;
            }
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    }
    return 0;
}

void list_processes() {
    DIR* dir = opendir(PROC_PATH);
    struct dirent* entry;

    if (dir == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    printf("\nPID\tCOMMAND\n");
    printf("--------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            printf("%s\t%s\n", entry->d_name, get_status_field(entry->d_name, "Name"));
        }
    }

    closedir(dir);
}

void display_process_info(const char* pid) {
    printf("\n--- Process Info for PID %s ---\n", pid);
    
    // Get and print various info
    char* name = get_status_field(pid, "Name");
    char* state = get_status_field(pid, "State");
    int ppid = get_integer_field(pid, "PPid");
    int pgrp = get_integer_field(pid, "Pgrp");
    int uid = get_integer_field(pid, "Uid");
    
    printf("Name: %s\n", name);
    printf("State: %s\n", state);
    printf("Parent PID: %d\n", ppid);
    printf("Process Group: %d\n", pgrp);
    printf("User ID: %d\n", uid);

    free(name);
    free(state);
}

char* get_status_field(const char* pid, const char* field_name) {
    char filepath[BUFFER_SIZE];
    snprintf(filepath, sizeof(filepath), "%s/%s/status", PROC_PATH, pid);

    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Could not open status file");
        return NULL;
    }

    char* value = malloc(BUFFER_SIZE);
    while (fgets(value, BUFFER_SIZE, file)) {
        if (strncmp(value, field_name, strlen(field_name)) == 0) {
            char* pos = strchr(value, ':');
            if (pos != NULL) {
                strcpy(value, pos + 1);
                value[strcspn(value, "\n")] = 0;  // Remove newline character
                fclose(file);
                return value;
            }
        }
    }
    fclose(file);
    free(value);
    return NULL;
}

int get_integer_field(const char* pid, const char* field_name) {
    char* value_str = get_status_field(pid, field_name);
    if (value_str != NULL) {
        int value = atoi(value_str);
        free(value_str);
        return value;
    }
    return -1;  // Return -1 if the field was not found or an error occurred
}