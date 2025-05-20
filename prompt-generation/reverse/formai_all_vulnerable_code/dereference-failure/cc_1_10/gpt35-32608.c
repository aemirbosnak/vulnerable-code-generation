//FormAI DATASET v1.0 Category: System process viewer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define PROC_PATH "/proc/"

typedef struct {
    int pid;
    char name[100];
    char state;
} Process;

int main() {
    DIR *d;
    struct dirent *dir;
    int totalProcs = 0;
    printf("Welcome to the Curious Process Viewer!\n");

    d = opendir(PROC_PATH);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            char path[100];
            sprintf(path, "%s%s", PROC_PATH, dir->d_name);
            if (dir->d_type == DT_DIR && atoi(dir->d_name) != 0) {
                // Process directory found
                Process p;

                // Get the PID
                p.pid = atoi(dir->d_name);

                // Open the stat file for the process
                char statFile[100];
                sprintf(statFile, "%s/stat", path);
                FILE *fp = fopen(statFile, "r");
                if (fp) {
                    fscanf(fp, "%d %s %c", &p.pid, p.name, &p.state);
                    fclose(fp);

                    // Print the process information
                    printf("PID: %d\nName: %s\nState: %c\n\n", p.pid, p.name, p.state);
                    totalProcs++;
                }
            }
        }
        closedir(d);
    }

    printf("Total number of processes found: %d\n", totalProcs);

    return 0;
}