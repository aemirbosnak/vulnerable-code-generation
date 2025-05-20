//FormAI DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_PATH_LEN 1024
#define MAX_BUFFER_SIZE 1024

void get_process_information(char* pid) {
    char path[MAX_PATH_LEN];
    FILE* fd;

    sprintf(path, "/proc/%s/status", pid);
    fd = fopen(path, "r");

    if (!fd) {
        printf("Failed to open file: %s\n", path);
        return;
    }

    printf("PID: %s\n", pid);

    char line[MAX_BUFFER_SIZE], name[MAX_BUFFER_SIZE];
    while (fgets(line, MAX_BUFFER_SIZE, fd)) {
        if (sscanf(line, "Name:\t%s", name) == 1) {
            printf("Name: %s\n", name);
        } else if (sscanf(line, "Uid:\t%*s %*s %*s %s", name) == 1) {
            printf("User ID: %s\n", name);
        }
    }

    fclose(fd);
}

int main() {
    DIR* proc_dir = opendir("/proc");
    struct dirent* entry;

    printf("PID\t Name\t\t User ID\n");

    while (entry = readdir(proc_dir)) {
        if (!isdigit(entry->d_name[0])) {
            continue;
        }

        get_process_information(entry->d_name);
    }

    return 0;
}