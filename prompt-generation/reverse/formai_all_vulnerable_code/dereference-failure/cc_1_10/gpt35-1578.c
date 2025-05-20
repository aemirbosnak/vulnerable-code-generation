//FormAI DATASET v1.0 Category: System process viewer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>

// function to check if PID is valid number
int is_number(char *pid) {
    for (int i = 0; i < strlen(pid); i++) {
        if (!isdigit(pid[i])) {
            return 0;
        }
    }
    return 1;
}

// function to check if process directory exists in /proc
int process_exists(char *pid) {
    DIR* dir = opendir("/proc");
    if (dir) {
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_type == DT_DIR) {
                char* endptr;
                long lpid = strtol(entry->d_name, &endptr, 10);
                if (*endptr == '\0') {
                    if (lpid == strtol(pid, NULL, 10)) {
                        closedir(dir);
                        return 1;
                    }
                }
            }
        }
        closedir(dir);
    }
    return 0;
}

// function to get process information
void get_process_info(char *pid) {
    // check if process exists
    if (process_exists(pid)) {
        printf("\nPID: %s\n", pid);

        char file_path[100];
        char buffer[100];

        // get process name
        sprintf(file_path, "/proc/%s/comm", pid);
        FILE* file = fopen(file_path, "r");
        fgets(buffer, sizeof(buffer), file);
        fclose(file);
        printf("Process Name: %s", buffer);

        // get user ID of process owner
        sprintf(file_path, "/proc/%s/status", pid);
        file = fopen(file_path, "r");
        while (fgets(buffer, sizeof(buffer), file)) {
            if (strncmp(buffer, "Uid:", 4) == 0) {
                char* p = strtok(buffer, "\t");
                p = strtok(NULL, "\t");
                printf("Process Owner UID: %s\n", p);
                break;
            }
        }
        fclose(file);

        // get process start and end time
        sprintf(file_path, "/proc/%s/stat", pid);
        file = fopen(file_path, "r");
        fgets(buffer, sizeof(buffer), file);
        fclose(file);

        char* p = strtok(buffer, " ");
        int i = 0;
        while (p != NULL) {
            if (i == 21) {
                printf("Process Start Time: %s", p);
            } else if (i == 22) {
                printf("Process End Time: %s", p);
            }
            p = strtok(NULL, " ");
            i++;
        }

        printf("\n");
    } else {
        printf("\nProcess with PID %s does not exist.\n", pid);
    }
}

int main(int argc, char *argv[]) {
    printf("Paranoid C Process Viewer\n\n");

    if (argc == 1) {
        printf("Usage: %s [PID]\n", argv[0]);
        exit(0);
    }

    char *pid = argv[1];

    if (!is_number(pid)) {
        printf("Invalid PID: %s\n", pid);
        exit(0);
    }

    get_process_info(pid);

    return 0;
}