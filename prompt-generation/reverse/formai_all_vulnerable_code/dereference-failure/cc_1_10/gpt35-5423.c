//FormAI DATASET v1.0 Category: System process viewer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");

    if (!dir) {
        printf("Failed to open directory /proc");
        exit(1);
    }

    printf("PID\tProcess Name\tStatus\n");
    printf("----------------------------------------------\n");
  
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);      // Convert directory name to integer

            if (pid != 0) {
                char filename[255];
                strcpy(filename, "/proc/");
                strcat(filename, entry->d_name);
                strcat(filename, "/status");

                FILE *file = fopen(filename, "r");
                char line[128];
                char name[128];
                char status[128];

                while (fgets(line, 128, file) != NULL) {
                    if (strstr(line, "Name:")) {
                        sscanf(line, "Name:\t%s", name);
                    }

                    if (strstr(line, "State:")) {
                        sscanf(line, "State:\t%s", status);
                    }
                }

                printf("%d\t%s\t%s\n", pid, name, status);
                fclose(file);
            }
        }
    }

    closedir(dir);
    return 0;
}