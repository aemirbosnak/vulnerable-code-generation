//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 256

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape sequence to clear the screen
}

int isNumber(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void printProcessInfo(const char *pid) {
    char path[MAX_NAME_LENGTH];
    snprintf(path, sizeof(path), "/proc/%s/stat", pid);

    FILE *file = fopen(path, "r");
    if (file) {
        char comm[MAX_NAME_LENGTH], state;
        int ppid, pgrp, session, tty_nr, tpgid;
        unsigned int flags, minflt, cminflt, majflt, cmajflt, utime, stime, cutime, cstime, priority, nice, itrealvalue, starttime;

        fscanf(file, "%*d %s %c %d %d %d %d %u %u %u %u %u %u %u %u %u %u %u %u %u %u",
               comm, &state, &ppid, &pgrp, &session, &tty_nr, &flags, &minflt, &cminflt,
               &majflt, &cmajflt, &utime, &stime, &cutime, &cstime, &priority,
               &nice, &itrealvalue, &starttime);

        printf("Process ID: %s\n", pid);
        printf("Command: %s\n", comm);
        printf("State: %c\n", state);
        fclose(file);
    } else {
        printf("Could not access information for process %s\n", pid);
    }
}

void displayProcessList() {
    struct dirent *entry;
    DIR *dp = opendir("/proc");
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Fetching the process list...\n");
    sleep(1);
    printf("\n--- Active Processes ---\n");
    
    while ((entry = readdir(dp))) {
        if (isNumber(entry->d_name)) {
            printProcessInfo(entry->d_name);
            printf("\n");
        }
    }
    
    closedir(dp);
}

int main() {
    char choice;

    while (1) {
        clearScreen();
        printf("🎉 Welcome to the C Process Viewer! 🎉\n");
        printf("==================================\n");
        printf("1. Show Active Processes\n");
        printf("2. Refresh Process List\n");
        printf("3. Exit\n");
        printf("==================================\n");
        printf("Please select an option (1-3): ");
        
        choice = getchar();
        getchar(); // To consume the newline character after input

        switch (choice) {
            case '1':
                displayProcessList();
                printf("Press Enter to continue...");
                getchar();
                break;
            case '2':
                printf("Refreshing process list...\n");
                sleep(1);
                break;
            case '3':
                printf("Exiting... Thank you for using the C Process Viewer!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                sleep(1);
                break;
        }
    }

    return 0;
}