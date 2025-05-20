//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

#define PROC_PATH "/proc"
#define BUF_SIZE 256

typedef struct {
    int pid;
    char name[BUF_SIZE];
} ProcessInfo;

void getProcessInfo(ProcessInfo *process) {
    char path[BUF_SIZE];
    sprintf(path, PROC_PATH "/%d/stat", process->pid);
    
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return;
    }
    
    fscanf(fp, "%d %s", &process->pid, process->name);
    fclose(fp);
}

void listProcesses() {
    DIR *dir = opendir(PROC_PATH);
    struct dirent *entry;
    ProcessInfo process;
    
    if (!dir) {
        perror("Unable to open /proc");
        exit(EXIT_FAILURE);
    }
    
    printf("PID\tProcess Name\n");
    printf("-------------------------\n");
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                process.pid = pid;
                getProcessInfo(&process);
                printf("%d\t%s\n", process.pid, process.name);
            }
        }
    }
    
    closedir(dir);
}

void printUsage(const char *progName) {
    printf("Usage: %s [options]\n", progName);
    printf("Options:\n");
    printf("  -h    Show help message\n");
    printf("  -l    List all processes\n");
}

void runCLI(int argc, char *argv[]) {
    if (argc < 2) {
        printUsage(argv[0]);
        return;
    }

    if (strcmp(argv[1], "-h") == 0) {
        printUsage(argv[0]);
    } else if (strcmp(argv[1], "-l") == 0) {
        listProcesses();
    } else {
        fprintf(stderr, "Unknown option: %s\n", argv[1]);
        printUsage(argv[0]);
    }
}

int main(int argc, char *argv[]) {
    runCLI(argc, argv);
    return EXIT_SUCCESS;
}