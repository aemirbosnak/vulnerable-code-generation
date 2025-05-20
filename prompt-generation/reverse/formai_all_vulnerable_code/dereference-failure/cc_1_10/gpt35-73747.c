//FormAI DATASET v1.0 Category: System process viewer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define PID_LOCATION "/proc/"
#define BUFFER_SIZE 1024

int is_number(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void print_process_info(char *pid) {
    char filepath[BUFFER_SIZE];
    char cmdline[BUFFER_SIZE];

    strcpy(filepath, PID_LOCATION);
    strcat(filepath, pid);
    strcat(filepath, "/cmdline");

    FILE *cmdline_file = fopen(filepath, "r");
    if (cmdline_file == NULL) {
        return;
    }
    fgets(cmdline, BUFFER_SIZE, cmdline_file);

    printf("%-10s %s\n", "PID", pid);
    printf("%-10s %s\n", "CMD", cmdline);

    fclose(cmdline_file);
}

void active_process_viewer() {
    DIR *dir = opendir(PID_LOCATION);
    struct dirent *ent;

    if (dir == NULL) {
        printf("Error opening %s\n", PID_LOCATION);
        return;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_DIR && is_number(ent->d_name)) {
            print_process_info(ent->d_name);
        }
    }

    closedir(dir);
}

int main() {
    printf("%-10s %s\n", "PID", "CMD");

    while (1) {
        active_process_viewer();
        system("clear"); // clear screen
    }

    return 0;
}