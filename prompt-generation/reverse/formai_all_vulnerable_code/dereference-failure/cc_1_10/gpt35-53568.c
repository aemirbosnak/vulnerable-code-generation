//FormAI DATASET v1.0 Category: System process viewer ; Style: shape shifting
// Shape-shifting System Process Viewer

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

// Define enumerated type for status of process
enum status { 
    RUNNING,
    SLEEPING,
    STOPPED,
    ZOMBIE
};

// Define struct for process information
struct process {
    char name[50];
    int pid;
    int ppid;
    enum status stat;
};

// Function to convert status code to string
char* statusToString(enum status s) {
    switch(s) {
        case RUNNING:
            return "Running";
        case SLEEPING:
            return "Sleeping";
        case STOPPED:
            return "Stopped";
        case ZOMBIE:
            return "Zombie";
        default:
            return "";
    }
}

// Function to print process information
void printProcessInfo(struct process p) {
    printf("Process name: %s\n",p.name);
    printf("PID: %d\n",p.pid);
    printf("PPID: %d\n",p.ppid);
    printf("Status: %s\n",statusToString(p.stat));
}

// Function to get process information from /proc
// Returns 0 if process information was found, -1 if not
int getProcessInfo(char* proc_path, struct process* p) {
    char buffer[1024];
    char name[50];
    int pid,ppid;
    enum status stat;
    int matches = sscanf(buffer,"%d %s %c %d",&pid,name,&stat,&ppid);
    if(matches == 4) {
        // Process information was successfully extracted
        strcpy(p->name,name);
        p->pid = pid;
        p->ppid = ppid;
        p->stat = stat;
        return 0;
    }
    return -1;
}

// Function to open /proc and search for process information
void searchProc() {
    DIR* procdir = opendir("/proc");
    if(procdir == NULL) {
        printf("Could not find /proc directory\n");
        return;
    }

    // Loop through all processes in /proc directory
    struct dirent* ent;
    while((ent = readdir(procdir)) != NULL) {
        char* name = ent->d_name;
        if(!isdigit(*name)) {
            // This is not a PID directory
            continue;
        }
        char path[50];
        strcpy(path,"/proc/");
        strcat(path,name);
        strcat(path,"/status");

        struct process p;
        if(getProcessInfo(path,&p) == 0) {
            // Process information was found
            printProcessInfo(p);
        }
    }
    closedir(procdir);
}

// Main function
int main() {
    printf("Welcome to the Shape-shifting System Process Viewer!\n");
    printf("What would you like to see?\n");
    printf("1. All processes\n");
    printf("2. Specific process\n");

    // Get user input
    int choice;
    scanf("%d",&choice);
    if(choice == 1) {
        // Show all processes
        searchProc();
    } else if(choice == 2) {
        // Ask for process PID
        printf("Enter process PID: ");
        int pid;
        scanf("%d",&pid);
        // TODO: Search for specific process by PID
    } else {
        printf("Invalid choice. Goodbye!\n");
    }

    return 0;
}