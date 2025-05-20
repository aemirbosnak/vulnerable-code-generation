//FormAI DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PATH_LENGTH 2048

int isNumber(char* s){
    for (int i = 0; i < strlen(s); i++){
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}

void printHeader() {
    printf("%10s %10s %10s %10s %s\n", "PID", "PPID", "STATUS", "THREADS", "EXECUTABLE");
}

void printProcessInfo(char* pidStr) {
    char path[MAX_PATH_LENGTH];
    char cmd[MAX_PATH_LENGTH];
    snprintf(path, sizeof(path), "/proc/%s/stat", pidStr);

    FILE* f = fopen(path, "r");
    if (f == NULL) {
        return;
    }

    // Read stat file
    char* line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, f);
    if (read == -1) {
        fclose(f);
        return;
    }

    // Parse stat file
    char* token;
    token = strtok(line, " ");
    int count = 0;
    char* pid = NULL;
    char* ppid = NULL;
    char* status = NULL;
    char* threads = NULL;
    while (token != NULL) {
        count++;
        if (count == 1) {
            pid = token;
        } else if (count == 4) {
            ppid = token;
        } else if (count == 3) {
            status = token;
        } else if (count == 20) {
            threads = token;
        }

        if (count >= 23) {
            // This is the command name, save up to 2047 chars as cmd
            strncpy(cmd, token, MAX_PATH_LENGTH - 1);
            cmd[MAX_PATH_LENGTH - 1] = '\0';
            break;
        }

        token = strtok(NULL, " ");
    }

    fclose(f);

    if (pid != NULL && ppid != NULL && status != NULL && threads != NULL) {
        printf("%10s %10s %10s %10s %s\n", pid, ppid, status, threads, cmd);
    }
}

void listProcesses() {
    struct dirent* dirEntry;
    DIR* dir = opendir("/proc/");
    if (dir == NULL) {
        printf("Could not open /proc/\n");
        return;
    }

    printf("\n");
    printHeader();

    while ((dirEntry = readdir(dir)) != NULL) {
        if (isNumber(dirEntry->d_name)) {
            // Cast PID string to int and add to array
            printProcessInfo(dirEntry->d_name);
        }
    }

    closedir(dir);
}

int main() {
    printf("Welcome to the Process Viewer!\n");

    char userInput[256];
    while (1) {
        printf("\nChoose an option (1: List Processes | 2: Quit): ");
        fgets(userInput, 256, stdin);
        userInput[strcspn(userInput, "\n")] = 0;

        if (strcmp(userInput, "1") == 0) {
            listProcesses();
        } else if (strcmp(userInput, "2") == 0) {
            printf("\nGoodbye!\n");
            exit(0);
        } else {
            printf("\nInvalid input. Please try again.\n");
        }
    }

    return 0;
}