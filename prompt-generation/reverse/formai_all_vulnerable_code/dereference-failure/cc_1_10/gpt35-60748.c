//FormAI DATASET v1.0 Category: System process viewer ; Style: interoperable
#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    char path[1024], line[1024];
    pid_t pid;
    char *name;

    if (argc < 2) {
        printf("Enter PID of process to view: ");
        scanf("%d", &pid);
    } else {
        pid = atoi(argv[1]);
    }

    // format the path to the status file
    snprintf(path, sizeof(path), "/proc/%d/status", pid);

    // open the status file
    FILE *file = fopen(path, "r");

    if (file) {
        // read each line in the file
        while (fgets(line, sizeof(line), file)) {

            // look for the process name
            if (strncmp(line, "Name:", 5) == 0) {
                name = line + 6;
                printf("Process name: %s", name);
            }

            // look for the process status
            if (strncmp(line, "State:", 6) == 0) {
                printf("Process status: %s", line + 7);
            }

            // look for the process memory usage
            if (strncmp(line, "VmSize:", 7) == 0) {
                printf("Process memory usage: %s", line + 7);
            }
        }

        // close the file
        fclose(file);
    } else {
        printf("Unable to open status file for process %d\n", pid);
        return 1;
    }

    return 0;
}