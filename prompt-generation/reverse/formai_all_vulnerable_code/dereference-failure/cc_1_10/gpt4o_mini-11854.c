//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define PROC_DIR "/proc"
#define PATH_MAX 1024

void print_process_info(const char *pid) {
    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s/%s/stat", PROC_DIR, pid);

    FILE *fp = fopen(path, "r");
    if (!fp) {
        return;
    }

    char comm[256];
    char state;
    int ppid;

    fscanf(fp, "%*s %s %c %d", comm, &state, &ppid);
    fclose(fp);

    // Convert to readable strings
    char *state_desc = "";
    if (state == 'R') state_desc = "Running";
    if (state == 'S') state_desc = "Sleeping";
    if (state == 'D') state_desc = "Disk Sleep";
    if (state == 'Z') state_desc = "Zombie";

    printf("PID: %s\tCOMMAND: %s\tSTATE: %s\tPPID: %d\n", pid, comm, state_desc, ppid);
}

void traverse_proc() {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(PROC_DIR)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            print_process_info(entry->d_name);
        }
    }
    closedir(dir);
}

void print_header() {
    printf("------------------------------------------------------\n");
    printf("| PID\t| COMMAND\t| STATE\t\t| PPID |\n");
    printf("------------------------------------------------------\n");
}

void print_footer() {
    printf("------------------------------------------------------\n");
}

int main() {
    printf("Welcome to the Process Trinity Riddle!\n");
    printf("Let us unveil the mysteries of the running processes...\n");
    
    print_header();
    traverse_proc();
    print_footer();

    printf("End of the riddle! May you solve your own process mysteries.\n");
    return 0;
}