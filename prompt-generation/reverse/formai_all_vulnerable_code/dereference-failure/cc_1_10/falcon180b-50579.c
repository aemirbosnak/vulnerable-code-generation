//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct process {
    char name[BUFFER_SIZE];
    int pid;
    int parent_pid;
} process_t;

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    char path[BUFFER_SIZE];
    snprintf(path, BUFFER_SIZE, "/proc/%d/cmdline", pid);

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error opening %s\n", path);
        return 1;
    }

    char cmdline[BUFFER_SIZE];
    if (fgets(cmdline, BUFFER_SIZE, fp) == NULL) {
        printf("Error reading %s\n", path);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    // Remove newline character from cmdline
    cmdline[strcspn(cmdline, "\n")] = '\0';

    char *token = strtok(cmdline, " ");
    while (token!= NULL) {
        if (strcmp(token, "--") == 0) {
            break;
        }
        printf("%s ", token);
        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}