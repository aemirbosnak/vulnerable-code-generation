//FormAI DATASET v1.0 Category: System process viewer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH 1024

void display_process_info(char* pid) {
    char filename[MAX_PATH];
    char line[256];
    FILE* fp = NULL;

    sprintf(filename, "/proc/%s/status", pid);
    fp = fopen(filename, "r");
    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp)) {
            if (strncmp(line, "Name:", 5) == 0 ||
                    strncmp(line, "State:", 6) == 0 ||
                    strncmp(line, "PPid:", 5) == 0 ||
                    strncmp(line, "Tgid:", 5) == 0 ||
                    strncmp(line, "Threads:", 8) == 0) {
                printf("%s", line);
            }
        }
        printf("\n");
        fclose(fp);
    }
}

int main() {
    DIR* dir;
    struct dirent* ent;

    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error opening /proc directory\n");
        return 1;
    }

    printf("%5s %-25s %-10s %-10s %-10s\n", "PID", "NAME", "STATE", "PPID", "THREADS");

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_DIR) {
            char* pid = ent->d_name;
            int is_digit = 1;
            for (int i = 0; i < strlen(pid); i++) {
                if (!isdigit(pid[i])) {
                    is_digit = 0;
                    break;
                }
            }

            if (is_digit) {
                display_process_info(pid);
            }
        }
    }

    closedir(dir);

    return 0;
}