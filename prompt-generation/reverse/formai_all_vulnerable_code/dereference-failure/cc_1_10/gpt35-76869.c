//FormAI DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void printHeader() {
    printf("\n\n                             Sherlock Holmes' Process Viewer\n");
    printf("___________________________________________________________________________\n\n");
}

void printProcessInfo(char* pid, char* name) {
    char stat_filepath[100];
    char exe_filepath[100];
    snprintf(stat_filepath, 100, "/proc/%s/stat", pid);
    snprintf(exe_filepath, 100, "/proc/%s/exe", pid);

    int fd = open(stat_filepath, O_RDONLY);
    char stat_buffer[2048];
    read(fd, &stat_buffer, 2048);

    char* command = strtok(stat_buffer, " ");
    int count = 0;
    while (command != NULL) {
        count++;
        if (count == 2) {
            printf("PID: %s\n", command);
        } else if (count == 3) {
            printf("Process name: %s\n", name);
            printf("Status: %s\n", command);
            break;
        }
        command = strtok(NULL, " ");
    }

    char exe_buffer[1024];
    int exe_readlink = readlink(exe_filepath, &exe_buffer, 1024);
    if (exe_readlink == -1) {
        printf("Error: Cannot read executable path for process %s\n", pid);
    } else {
        printf("Executable path: %s\n", exe_buffer);
    }
    printf("___________________________________________________________________________\n\n");
}

int main() {
    printHeader();
    DIR* proc_directory = opendir("/proc");
    if (proc_directory == NULL) {
        printf("Error: Cannot open /proc directory.\n");
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(proc_directory)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char* endptr;
            long int pid = strtol(entry->d_name, &endptr, 10);
            if (*endptr == '\0') {                
                char cmdline_filepath[100];
                snprintf(cmdline_filepath, 100, "/proc/%s/cmdline", entry->d_name);
                FILE* cmdline_file = fopen(cmdline_filepath, "r");
                if (cmdline_file == NULL) {
                    printf("Error: Cannot open command line file for process %s\n", entry->d_name);
                    continue;
                }
                char name_buffer[1024];
                fread(name_buffer, 1, 1024, cmdline_file);
                fclose(cmdline_file);
                printProcessInfo(entry->d_name, name_buffer);
            }
        }
    }
    closedir(proc_directory);
    return 0;
}