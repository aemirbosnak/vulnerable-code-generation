//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>

// Function to get the process name given its PID
char* getProcessName(pid_t pid) {
    char* path = malloc(256);
    snprintf(path, 256, "/proc/%d/comm", pid);
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        return NULL;
    }
    char* name = malloc(256);
    fscanf(file, "%s", name);
    fclose(file);
    return name;
}

// Function to get the username given the UID
char* getUsername(uid_t uid) {
    struct passwd* pw = getpwuid(uid);
    if (pw == NULL) {
        return NULL;
    }
    return pw->pw_name;
}

// Function to print the process information
void printProcessInfo(pid_t pid) {
    char* name = getProcessName(pid);
    struct stat statbuf;
    stat(name, &statbuf);
    char* username = getUsername(statbuf.st_uid);
    printf("%-5d %-15s %-15s %ld\n", pid, name, username, statbuf.st_size);
    free(name);
}

// Main function
int main() {
    DIR* dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    // Print the header
    printf("%-5s %-15s %-15s %s\n", "PID", "Name", "User", "Size");

    // Iterate over the directory and print the process information
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0) {
            printProcessInfo(atoi(entry->d_name));
        }
    }

    closedir(dir);
    return 0;
}